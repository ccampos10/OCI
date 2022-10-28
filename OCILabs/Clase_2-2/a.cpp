#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> crear_grafo(vector<vector<int>> grafo, int n){
    for(int i = 0; i < n; i++){
        vector<int> nodo(n, 0);
        grafo.push_back(nodo);
    }
    return grafo;
}

vector<vector<int>> agregar_conexion(vector<vector<int>> grafo, int nodo1, int nodo2){
    grafo[nodo1][nodo2] = 1;
    grafo[nodo2][nodo1] = 1;
    return grafo;
}

bool comparar(vector<vector<int>> grafo1, vector<vector<int>> grafo2){
    bool sonIguales = true;
    for(int fila = 0; fila < grafo1.size(); fila++){
        for(int colum = 0; colum < grafo1.size(); colum++){
            if(grafo1[fila][colum] != grafo2[fila][colum]) sonIguales = false;
        }
    }
    return sonIguales;
}

int main(){
    vector<vector<int>> grafo1;
    vector<vector<int>> grafo2;

    int n1, e1, n2, e2, nodo1, nodo2;
    cin >> n1 >> e1;
    grafo1 = crear_grafo(grafo1, n1);
    for(int i = 0; i < e1; i++){
        cin >> nodo1 >> nodo2;
        grafo1 = agregar_conexion(grafo1, nodo1, nodo2);
    }
    cin >> n2 >> e2;
    grafo2 = crear_grafo(grafo2, n2);
    for(int i = 0; i < e2; i++) {
        cin >> nodo1 >> nodo2;
        grafo2 = agregar_conexion(grafo2, nodo1, nodo2);
    }
    
    bool sonIguales = false;
    if(n1 == n2 && e1 == e2) sonIguales = comparar(grafo1, grafo2);

    if(sonIguales) cout << "Son iguales" << "\n";
    else cout << "No son iguales" << "\n";

    return 0;
}