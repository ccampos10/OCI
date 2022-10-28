#include <iostream>
#include <vector>
using namespace std;

int ordenar(vector<int> lista){
    int cambios = 0, tmp;
    for(int i = 0; i < lista.size(); i++){
        for(int j = 0 ; j < lista.size() - i - 1; j++){
            if(lista[j] > lista[j + 1]){
                tmp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = tmp;
                cambios++;
            }
        }
    }
    return cambios;
}

int main(){
    int n, l, numero;
    vector <int> totalCambios;
    vector <int> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        lista.clear();
        cin >> l;
        for(int j = 0; j < l; j++) {
            cin >> numero;
            lista.push_back(numero);
        }
        totalCambios.push_back(ordenar(lista));
    }

    for(int i = 0; i < totalCambios.size(); i++){
        cout << "Optimal train swapping takes " << totalCambios[i] << " swaps.\n";
    }

    return 0;
}