#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>> > grafo;
vector<int> distancias;

void crear_grafo(int n){
    for(int i = 0; i < n; i++){
        distancias.push_back(2147483647);
        vector<pair<int, int>> nodo = {};
        grafo.push_back(nodo);
    }
}

void crear_conexion(int a, int b, int peso){
    grafo[a].push_back(pair<int, int>(b, peso));
    grafo[b].push_back(pair<int, int>(a, peso));
}

int dijkstra(int nodoOrigen, int nodoFinal){
    distancias[nodoOrigen] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> siguiente;
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
    int n, m ,r, x, y;
    int a, b, c;
    cin >> n >> m >> r >> x >> y;
    crear_grafo(n);
    for(int i = 0; i < r; i++){
        cin >> a >> b >> c;
        crear_conexion(a-1, b-1, c);
    }
    int distanMinima = dijkstra(x-1, y-1);
    if(distanMinima <= m) cout << "alive " << distanMinima << '\n';
    else cout << "died" << '\n';
    return 0;
}