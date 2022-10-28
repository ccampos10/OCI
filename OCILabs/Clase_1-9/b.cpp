#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t, n, numero;
    vector<int> lista;
    cin >> t;
    for (int i = 0; i < t; i++){
        lista.clear();
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> numero;
            lista.push_back(numero);
        }
        sort(lista.begin(), lista.end());
        int dif, pos;
        for(int j = 0; j < lista.size() - 1; j++){
            if(j == 0){
                pos = j;
                dif = lista[j+1]-lista[j];
            }
            else if(dif > lista[j+1] - lista[j]){
                pos = j;
                dif = lista[j+1] - lista[j];
            }
            if(dif == 0) break;
        }
        cout << dif << '\n';
    }
    return 0;
}