#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > grafo;
vector<bool> visitados;

void crear_grafo(int n){
    for(int i = 0; i < n; i++){
        visitados.push_back(false);
        vector<int> vesinos= {};
        grafo.push_back(vesinos);
    }
}

void crear_conexion(int nodo1, int nodo2){
    grafo[nodo1].push_back(nodo2);
    grafo[nodo2].push_back(nodo1);
}

void DFS(int nodo){
    visitados[nodo] = true;

    for(int i = 0; i < grafo[nodo].size(); i++){
        int vecino = grafo[nodo][i];
        if(visitados[vecino] == false){
            DFS(vecino);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    crear_grafo(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        crear_conexion(a-1, b-1);
    }
    DFS(1-1);
    bool desconectadas = false;
    for(int i = 0; i < visitados.size(); i++){
        if(visitados[i] == false){
            desconectadas = true;
            cout << i+1 << '\n';
        }
    }
    if(desconectadas == false) cout << "Connected" << '\n';
    return 0;
}