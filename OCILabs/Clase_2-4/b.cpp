#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>> > grafo;
vector<long long int> distancias;
vector<int> padre;

long long int inf = 9223372036854775807;

void crear_grafo(int n){
    for(int i = 0; i < n; i++){
        distancias.push_back(inf);
        vector<pair<int, int>> lista = {};
        grafo.push_back(lista);
        padre.push_back(-1);
    }
}

void crear_arista(int nodo1, int nodo2, int peso){
    grafo[nodo1].push_back(pair<int, int>(nodo2, peso));
    grafo[nodo2].push_back(pair<int, int>(nodo1, peso));
}

long long int Dijkstra(int nodoOrigen, int nodoFinal){
    distancias[nodoOrigen] = 0;
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> siguiente;
    siguiente.push(pair<int, int>(0, nodoOrigen));
    while(!siguiente.empty()){
        int nodo = siguiente.top().second;
        int distancia = siguiente.top().first;
        siguiente.pop();
        if(nodo != nodoFinal && distancia <= distancias[nodo]){
            for(int i = 0; i < grafo[nodo].size(); i++){
                int vecino = grafo[nodo][i].first;
                int peso = grafo[nodo][i].second;
                if(distancias[vecino] > distancias[nodo] + peso){
                    distancias[vecino] = distancias[nodo] + peso;
                    siguiente.push(pair<int, int>(distancias[vecino], vecino));
                    padre[vecino] = nodo;
                }
            }
        }
    }
    return distancias[nodoFinal];
}

int buscar(int n){
    for(int i = 0; i < padre.size()-1; i++){
        if(padre[i] == n) return i;
    }
    return -1;
}

int main(){
    int n, m, a, b, w;
    cin >> n >> m;
    crear_grafo(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        crear_arista(a-1, b-1, w);
    }
    if(Dijkstra(0, n-1) != inf){
        vector<int> caminoFinal;

        for(int i = n-1; padre[i] != -1; i = padre[i]){
            caminoFinal.push_back(i);
        }
        caminoFinal.push_back(0);
        
        for(int i = caminoFinal.size() - 1; i >= 0; i--){
            cout << caminoFinal[i] + 1 << ' ';
        }
        cout << '\n';
    }
    else cout << "-1" << '\n';
    return 0;
}