#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > grafo;

void crear_grafo(int n){
    for(int i = 0; i < n; i++){
        vector<int> nodo;
        grafo.push_back(nodo);
    }
}

void crear_conexion(int nodo1, int nodo2){
    grafo[nodo1].push_back(nodo2);
    grafo[nodo2].push_back(nodo1);
}

bool amistad(int nodo1, int nodo2){
    for(int i = 0; i < grafo[nodo1].size(); i++){
        if(nodo2 == grafo[nodo1][i]) return true;
    }
    return false;
}

bool amistad_transitiva(int nodo1, int nodo2){
    if(!amistad(nodo1, nodo2)){
        for(int i = 0; i < grafo[nodo1].size(); i++){
            if(amistad(grafo[nodo1][i], nodo2)) return true;
        }
    }
    return false;
}

int main(){
    int n, q, e1, e2, q1, q2;
    long int e;
    cin >> n >> e >> q;
    crear_grafo(n);
    for(int i = 0; i < e; i++){
        cin >> e1 >> e2;
        crear_conexion(e1, e2);
    }
    for(int i = 0; i < q; i++){
        cin >> q1 >> q2;
        cout << amistad_transitiva(q1, q2) << '\n';
    }

    return 0;
}