#include <iostream>
using namespace std;

int unidades(int n){
    int posision = 1, resultado = n;
    while(resultado != 0){
        resultado = n/posision;
        if(resultado != 0) posision = posision*10;
    }
    return posision/10;
}

int numeros(int n, int maxPosision, int resta = 0){
    int resultado = (n - resta)/maxPosision;
    if(maxPosision/10 >= 1) {
        if(resultado != 0 && n%resultado == 0) return 1 + numeros(n, maxPosision/10, (resta + (resultado*maxPosision)) );
        else return numeros(n, maxPosision/10, (resta + (resultado*maxPosision)) );
    }
    else {
        if(resultado != 0 && n%resultado == 0) return 1;
        else return 0;
    };
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << numeros(m, unidades(m)) << '\n';
    }
    return 0;
}