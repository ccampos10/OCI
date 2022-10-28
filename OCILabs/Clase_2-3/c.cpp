#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > grafo;
vector<bool> visitados;

void crear_grafo(int n){
    grafo.clear();
    visitados.clear();
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
            // visitados[vecino] = true;
            DFS(vecino);
        }
    }
}

int main(){
    int n, m, r;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, conexionesFaltantes = 0;
        cin >> m;
        crear_grafo(m);
        cin >> r;
        for(int j = 0; j < r; j++) {
            cin >> a >> b;
            crear_conexion(a, b);
        }
        DFS(0);
        for(int j = 0; j < visitados.size(); j++) {
            if(visitados[j] == false){
                conexionesFaltantes++;
                DFS(j);
            }
        }
        cout << conexionesFaltantes << '\n';
    }
    return 0;
}