#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>> > grafo;
vector<int> distancias;

void crear_grafo(int n){
    grafo.clear();
    distancias.clear();
    for(int i = 0; i < n; i++){
        distancias.push_back(2147483647);
        vector<pair<int, int>> lista = {};
        grafo.push_back(lista);
    }
}

void crear_arista(int nodo1, int nodo2, int peso){
    grafo[nodo1].push_back(pair<int, int>(nodo2, peso));
}

void resetDistancias(int n){
    distancias.clear();
    for(int i = 0; i < n; i++) {
        distancias.push_back(2147483647);
    }
}

int Dijkstra(int nodoOrigen, int nodoFinal){
    resetDistancias(grafo.size());
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
                }
            }
        }
    }
    return distancias[nodoFinal];
}

int main(){
    int n, m, q, s;
    cin >> n >> m >> q >> s;
    while(n != 0 && q != 0){
        crear_grafo(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            crear_arista(u, v, w);
        }
        for(int i = 0; i < q; i++){
            int nodo;
            cin >> nodo;
            int resultado = Dijkstra(s, nodo);
            if(resultado != 2147483647) cout << resultado << '\n';
            else cout << "Impossible" << '\n';
        }
        cout << '\n';
        cin >> n >> m >> q >> s;
    }

    return 0;
}