#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> numeros;

// int posicionMayor(int n){
//     int divisor = 1, result = n;
//     while(result != 0){
//         divisor = divisor * 10;
//         result = n / divisor;
//     }
//     return divisor / 10;
// }

void encontrarNumeros(int pMayor, int resto, int n){
    if(resto != n){
        int result;
        result = (int) ((n-resto) / pMayor);
        numeros.push_back(result);
        encontrarNumeros(pMayor/10, (result*pMayor)+resto, n);
    }
}

int main(){
    bool Mauricio = true;
    int n, x;
    cin >> n;
    int pMayor = 1*pow(10, n-1), suma=0, nSuma = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        suma += x * pMayor;
        pMayor = pMayor / 10; 
    }
    pMayor = 1*pow(10, n-1);
    encontrarNumeros(pMayor, 0, suma);
    
    for(int j = numeros.size() - 1; j >= 0; j--){
        if(numeros[j] == 0){
            nSuma += numeros[j] * pMayor;
            pMayor = pMayor / 10;
        }
        else if(numeros[j] == 1){
            nSuma += numeros[j] * pMayor;
            pMayor = pMayor / 10;
        }
        else if(numeros[j] == 2){
            nSuma += numeros[j] * pMayor;
            pMayor = pMayor / 10;
        }
        else if(numeros[j] == 3){
            Mauricio = false;
            break;
        }
        else if(numeros[j] == 4){
            Mauricio = false;
            break;
        }
        else if(numeros[j] == 5){
            nSuma += numeros[j] * pMayor;
            pMayor = pMayor / 10;
        }
        else if(numeros[j] == 6){
            nSuma += 9 * pMayor;
            pMayor = pMayor / 10;
        }
        else if(numeros[j] == 7){
            Mauricio = false;
            break;
        }
        else if(numeros[j] == 8){
            nSuma += numeros[j] * pMayor;
            pMayor = pMayor / 10;
        }
        else if(numeros[j] == 9){
            nSuma += 6 * pMayor;
            pMayor = pMayor / 10;
        }
    }
    
    if(suma == nSuma) cout << "Mauricio" << '\n';
    else cout << "Camilo" << '\n';
    return 0;
}