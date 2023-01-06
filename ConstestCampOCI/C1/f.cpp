//Two Buttons
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
queue <pair<int,int>> ruta; // numero, pasos para llegar
int aM = 10001; // maximo valor de m y n

void buscar(int n, int m, int p){
    if(n == m && aM > p) aM = p;
    else if(p < aM){
        if(m > n){
            int loga = (int) log2((int) m/n);
            if(loga < aM) buscar(n*2^(loga), m, p+loga); //boton rojo
            buscar(n-1, m, p+1); //boton azul
        }
        else buscar(m,m,p+n-m);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if(m < n) cout << n-m << '\n';
    else if(m == n) cout << 0 << '\n';
    else{
        buscar(n, m, 0);
        cout << aM << '\n';
    }
    return 0;
}