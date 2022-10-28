#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grafo;

void crear_grafo(int n){
    for(int i = 0; i < n; i++){
        vector<int> nodo(n, 0);
        grafo.push_back(nodo);
    }
}

void crear_conexion(int nodo1, int nodo2){
    grafo[nodo1][nodo2] = 1;
    grafo[nodo2][nodo1] = 1;
}

void romper_conexion(int nodo1, int nodo2){
    grafo[nodo1][nodo2] = 0;
    grafo[nodo2][nodo1] = 0;
}

void copiados(int alumno, vector<int> notas){
    bool copiaron = false;
    for(int i = 0; i < grafo[alumno].size(); i++){
        if(grafo[alumno][i] == 1) {
            if(notas[alumno] > notas[i]) {
                if(notas[alumno] - notas[i] == 5) {
                    if(!copiaron) cout << i;
                    else cout << ' ' << i;
                    copiaron = true;
                }
            }
            else{
                if(notas[i] - notas[alumno] == 5) {
                    if(!copiaron) cout << i;
                    else cout << ' ' << i;
                    copiaron = true;
                }
            }
        }
    }
    if(!copiaron) cout << "No copio, honesto el cabro" << "\n";
    else cout << "\n";
}

int main(){
    vector<int> notas;
    int n, e, q, nota, e1, e2, consulta, alumno;
    cin >> n >> e >> q;
    crear_grafo(n);
    for(int i = 0; i < n; i++){
        cin >> nota;
        notas.push_back(nota);
    }
    for(int i = 0; i < e; i++){
        cin >> e1 >> e2;
        crear_conexion(e1, e2);
    }
    for(int i = 0; i < q; i++){
        cin >> consulta;
        if(consulta == 0) {
            cin >> alumno;
            copiados(alumno, notas);
        }
        else {
            cin >> e1 >> e2;
            romper_conexion(e1, e2);
        }
    }
    return 0;
}