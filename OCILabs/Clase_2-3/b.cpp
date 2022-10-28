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
}

void DFS(int nodo){
    // visitados[nodo] = true;
    for(int i = 0; i < grafo[nodo].size(); i++){
        int vecino = grafo[nodo][i];
        if(visitados[vecino] == false){
            visitados[vecino] = true;
            DFS(vecino);
        }
    }
}

int main(){
    vector<int> nodosIna;
    int n, m, i, k, h;
    cin >> n;
    while(n != 0){
        nodosIna.clear();
        grafo.clear();
        visitados.clear();
        crear_grafo(n);
        cin >> m;
        while (m != 0){
            cin >> i;
            while(i != 0){
                crear_conexion(m-1, i-1);
                cin >> i;
            }
            cin >> m;
        }
        cin >> k;
        for(int j = 0; j < k; j++){
            nodosIna.clear();
            cin >> h;
            DFS(h-1);
            for(int l = 0; l < visitados.size(); l++){
                if(visitados[l] == false){
                    nodosIna.push_back(l);
                }
                else visitados[l] = false;
            }
            cout << nodosIna.size();
            for(int l = 0; l < nodosIna.size(); l++){
                cout << ' ' << nodosIna[l]+1;
            }
            cout << '\n';
        }
        cin >> n;
    }
    return 0;
}