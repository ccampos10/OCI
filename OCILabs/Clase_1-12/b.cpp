#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, suma = 0;
    cin >> n >> k;
    vector<int> lista(n);
    //lista de numeros
    for (int i = 0; i < n; i++) cin >> lista[i];
    sort(lista.begin(), lista.end());
    //sumar los k numeros mas grandes
    for(int i = 1; i <= k; i++) suma += lista[lista.size() - i];
    cout << suma << '\n';
    return 0;
}