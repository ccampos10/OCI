#include <iostream>
using namespace std;

int main(){
    int n, numeros, suma = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numeros;
        suma += numeros;
    }
    cout << suma << '\n';
}