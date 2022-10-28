#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, cDuplicadas = 0;
    string nombre;
    vector<vector<string>> listas;
    vector<string> duplicadas;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vector<string> lista;
        for(int j = 0; j < m; j++){
            cin >> nombre;
            lista.push_back(nombre);
        }
        listas.push_back(lista);
    }
    for(int i = 0; i < listas[0].size(); i++){
        int cantidad = 1;
        for(int j = 1; j < listas.size(); j++){
            if(find(listas[j].begin(), listas[j].end(), listas[0][i]) != listas[j].end()) cantidad++;
        }
        if(cantidad == listas.size()) {
            cDuplicadas++;
            duplicadas.push_back(listas[0][i]);
        }
    }
    cout << cDuplicadas << endl;
    sort(duplicadas.begin(), duplicadas.end());
    for(int i = 0; i < duplicadas.size(); i++){
        cout << duplicadas[i] << endl;
    }
    return 0;
}