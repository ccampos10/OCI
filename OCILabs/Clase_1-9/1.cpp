#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool orden(int a, int b) {
    if(a > b) return true;
    else return false;
}

int main() {
    int n, numero;
    vector<int> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }
    sort(lista.begin(), lista.end(), orden);
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << '\n';
    }
    return 0;
}