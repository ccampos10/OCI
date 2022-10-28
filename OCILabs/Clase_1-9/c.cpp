#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int buscar(vector<int> lista, int numero) {
    vector<int>::iterator itr;
    itr = lower_bound(lista.begin(), lista.end(), numero);
    if(*itr == numero) return itr - lista.begin() + 1;
    else return -1;
}

int main() {
    int n=-1, q=-1, numero, caso = 1;
    vector<int> lista;
    while(n != 0 && q != 0){
        lista.clear();
        cin >> n >> q;
        if(n == 0 && q == 0) break;
        for(int i = 0; i < n; i++){
            cin >> numero;
            lista.push_back(numero);
        }
        sort(lista.begin(), lista.end());
        
        cout << "CASE# " << caso << ":\n";
        for(int i = 0; i < q; i++){
            cin >> numero;
            int resultado = buscar(lista, numero);
            if(resultado != -1){
                cout << numero << " found at " << resultado << '\n';
            }
            else {
                cout << numero << " not found" << '\n';
            }
        }
        caso++;
    }
    return 0;
}