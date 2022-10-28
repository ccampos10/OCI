#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>> > grafo;
vector<int> distancias;
// vector<int> padre;

void crear_grafo(int n){
    grafo.clear();
    distancias.clear();
    // padre.clear();
    for(int i = 0; i < n; i++){
        distancias.push_back(2147483647);
        vector<pair<int, int>> lista = {};
        grafo.push_back(lista);
        // padre.push_back(-1);
    }
}

void crear_arista(int nodo1, int nodo2, int peso){
    grafo[nodo1].push_back(pair<int, int>(nodo2, peso));
    grafo[nodo2].push_back(pair<int, int>(nodo1, peso));
}

int Dijkstra(int nodoOrigen, int nodoFinal){
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
                    // padre[vecino] = nodo;
                }
            }
        }
    }
    return distancias[nodoFinal];
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        crear_grafo(n);
        for(int j = 0; j < m; j++){
            int a, b, w;
            cin >> a >> b >> w;
            crear_arista(a, b, w);
        }
        int resultado = Dijkstra(s, t);
        if(resultado != 2147483647) cout << "Case #" << i+1 << ": " << resultado << '\n';
        else cout << "Case #" << i+1 << ": unreachable" << '\n';
    }
    return 0;
}