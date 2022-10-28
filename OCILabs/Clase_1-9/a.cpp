#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, numero;
    vector<int> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }
    sort(lista.begin(), lista.end());
    cout << lista[(lista.size())/2] << '\n';
    return 0;
}