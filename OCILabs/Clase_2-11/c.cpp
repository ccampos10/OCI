#include <iostream>
#include <vector>
#include <string>
using namespace std;
// vector<int> numeros;

// int posicionMayor(int n){
//     int divisor = 1, result = n;
//     while(result != 0){
//         divisor = divisor * 10;
//         result = n / divisor;
//     }
//     return divisor / 10;
// }

// void encontrarNumeros(int pMayor, int resto, int n){
//     if(resto != n){
//         int result;
//         result = (int) ((n-resto) / pMayor);
//         numeros.push_back(result);
//         encontrarNumeros(pMayor/10, (result*pMayor)+resto, n);
//     }
// }

int main(){
    string n;
    cin >> n;
    vector<int> numeros;
    // for(int i = 0; i < n.length(); i++) cout << (int) n[i]-48 << '\n';
    int suma=0, pMayor = 1, lastN= (int) n[1]-48, cantidad = (int) n[0]-48, sumaTotal=0;
    for(int i = 1; i < n.length(); i++){
        if(numeros.size() <= cantidad){
            if(n[i]-48 == lastN){
                suma += n[i]-48 * pMayor;
                pMayor = pMayor * 10;
            }
            else{
                numeros.push_back(suma);
                cout << numeros.size() << ' ' << cantidad;
                if(numeros.size() == cantidad){
                    pMayor = n.length() - i;
                    sumaTotal += n[i]-48 * pMayor;
                    cout << "1: _____________________" << endl;
                    cout << n[i]-48 << ' ' << pMayor << ' ' << sumaTotal << endl;
                    cout << "________________________" << endl;
                }
                else{
                    pMayor = 1;
                    lastN = n[i]-48;
                    suma = n[i]-48;
                }
            }
        }
        else{
            pMayor = n.length() - i;
            sumaTotal += n[i]-48 * pMayor;
            cout << "2: _____________________" << endl;
            cout << n[i]-48 << ' ' << pMayor << ' ' << sumaTotal << endl;
            cout << "________________________" << endl;
        }
    }

    cout << cantidad << ' ';
    for(int i = 0; i < numeros.size(); i++) cout << numeros[i] << ' ';
    cout << sumaTotal << '\n';
    // for(int i = 0; i < n.length(); i++) cout << n[i]-48 << '\n';
    return 0;
}