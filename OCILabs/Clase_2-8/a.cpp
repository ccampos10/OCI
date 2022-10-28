#include <iostream>
#include <vector>
using namespace std;
vector<int> monedas;

int intercambioMonedas(int x, int n){
    vector<int> valores(x+1,2147483647);
    valores[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - monedas[j] >= 0 && valores[i - monedas[j]] != 2147483647){
                valores[i] = (min(valores[i - monedas[j]] + 1, valores[i]));
            }
        }
    }
    if(valores[x] == 2147483647){
        return -1;
    }
    else return valores[x];
}

int main(){
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        int moneda;
        cin >> moneda;
        monedas.push_back(moneda);
    }

    cout << intercambioMonedas(x, n) << '\n';
    return 0;
}