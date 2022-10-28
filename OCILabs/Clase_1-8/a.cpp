#include <iostream>
#include <vector>
using namespace std;

void imprimir(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << ' ';
    }
    cout << '\n';
}

int main(){
    int n = 5, numero, temp;
    vector <int> lista;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }

    for(int i = 0; i < lista.size(); i++){
        for(int j = 0; j < lista.size() - i - 1; j++){
            if(lista[j] > lista[j + 1]){
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                imprimir(lista);
            }
        }
    }

    return 0;
}