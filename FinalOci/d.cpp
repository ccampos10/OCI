#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,vector<int>>> grafo;
vector<bool> visitados;
vector<int> distancias;
int inf = 2147483647;

void crear_grafo(int tamano){
    for(int i = 0; i < tamano; i++){
        visitados.push_back(false);
        distancias.push_back(inf);
        grafo.push_back(pair<int,vector<int>>());
    }
}

void llenar_datos(int pos, int dato){
    grafo[pos].first = dato;
}

void crear_conexion(int nHijo, int nPadre){
    if(grafo[nPadre].first != grafo[nHijo].first) grafo[nPadre].second.push_back(nHijo);
}

bool bfs(int inicio, int final){
    queue<int> cola;
    visitados[inicio] = true;
    cola.push(inicio);
    distancias[inicio]=0;
    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();
        for(int i = 0; i < grafo[actual].second.size(); i++){
            if(visitados[grafo[actual].second[i]] == false){
                visitados[grafo[actual].second[i]] = true;
                cola.push(grafo[actual].second[i]);
                distancias[grafo[actual].second[i]] = distancias[actual]+1;
                if(grafo[actual].second[i] == final) return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m,k, p;
    cin >> n >> m >> k;
    crear_grafo(n*m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> p;
            llenar_datos((i*n)+j,p);
            if(j>0) crear_conexion((i*n)+j,(i*n)+j-1);
            if(i>0) crear_conexion((i*n)+j,((i-1)*n)+j);
        }
    }
    if(bfs(0,(n*m)-1)) cout << distancias[(n*m)-1] << '\n';
    else cout << -1 << '\n';

    return 0;
}