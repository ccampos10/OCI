#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> numeros;

int posicionMayor(int n){
    int divisor = 1, result = n;
    while(result != 0){
        divisor = divisor * 10;
        result = n / divisor;
    }
    return divisor / 10;
}

void encontrarNumeros(int pMayor, int resto, int n){
    if(resto != n){
        int result;
        result = (int) ((n-resto) / pMayor);
        numeros.push_back(result);
        encontrarNumeros(pMayor/10, (result*pMayor)+resto, n);
    }
}

int main(){
    int n;
    cin >> n;
    int contador = 0, resultado = n, pos;
    while(resultado > 0){
        numeros.clear();
        encontrarNumeros(posicionMayor(resultado), 0, resultado);
        sort(numeros.begin(),numeros.end());
        pos = numeros.size()-1;
        while(resultado - numeros[pos] < 0 && pos >= 0){
            pos--;
        }
        if(resultado - numeros[pos] >= 0){
            resultado = resultado - numeros[pos];
            contador++;
        }
    }
    cout << contador << '\n';
    return 0;
}