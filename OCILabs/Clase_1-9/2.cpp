#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool orden(int a, int b) {
    if(a > b) return true;
    else return false;
}

int main() {
    int n, numero, buscar;
    vector<int> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }
    sort(lista.begin(), lista.end(), orden);

    cin >> buscar;
    int inicio = 0, final = lista.size(), medio;
    while(inicio != final){
        medio = (inicio + final)/2;
        if(buscar == lista[medio]){
            cout << "Si, si esta el elemento" << '\n';
            break;
        }
        else if(buscar > lista[medio]){
            final = medio - 1;
        }
        else if(buscar < lista[medio]){
            inicio = medio + 1;
        }
    }
    if(inicio == final) cout << "No, no esta" << '\n';
    return 0;
}