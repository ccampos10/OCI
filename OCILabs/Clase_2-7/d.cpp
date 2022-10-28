#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<long long int, long long int>>> grafo;
vector<long long int> distancias;
long long int tope = 9223372036854775807;

void crear_grafo(long long int n){
    for(long long int i = 0; i < n; i++){
        distancias.push_back(tope);
        vector<pair<long long int, long long int>> nodo;
        grafo.push_back(nodo);
    }
}

void crear_conexion(long long int nodo1, long long int nodo2, long long int peso){
    grafo[nodo1].push_back(pair<long long int, long long int>(nodo2, peso));
}

void reset(long long int n){
    distancias.clear();
    for(long long int i = 0; i < n; i++) {
        distancias.push_back(tope);
    }
}

long long int dijkstra(long long int nodoOrigen, long long int nodoFinal){
    distancias[nodoOrigen] = 0;
    priority_queue<pair<long long int, long long int>,
                    vector<pair<long long int, long long int>>,
                    greater<pair<long long int, long long int> > > siguiente;
    siguiente.push(pair<long long int, long long int>(0, nodoOrigen));
    while(!siguiente.empty()){
        long long int nodo = siguiente.top().second;
        long long int distancia = siguiente.top().first;
        siguiente.pop();
        if(nodo != nodoFinal && distancia <= distancias[nodo]){
            for(long long int i = 0; i < grafo[nodo].size(); i++){
                long long int vecino = grafo[nodo][i].first;
                long long int peso = grafo[nodo][i].second;
                if(distancias[vecino] > distancias[nodo] + peso){
                    distancias[vecino] = distancias[nodo] + peso;
                    siguiente.push(pair<long long int, long long int>(distancias[vecino],vecino));
                }
            }
        }
    }
    return distancias[nodoFinal];
}

int main() {
    long long int n, m, a,b,c;
    cin >> n >> m;
    crear_grafo(n);
    for(long long int i = 0; i < m; i++){
        cin >> a >> b >> c;
        crear_conexion(a-1,b-1,c);
    }
    cout << dijkstra(0, 0);
    for(long long int i = 1; i < n; i++){
        reset(n);
        cout << ' ' << dijkstra(0, i);
    }
    cout << '\n';
    return 0;
}