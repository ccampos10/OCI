#include <iostream>
#include <string>
using namespace std;

bool palindromo(string palabra, int inicio, int final){
    if(inicio == final){
        return true;
    }
    else if(inicio > final){
        return true;
    }
    else{
        bool actual = palabra[inicio] == palabra[final];
        return actual && palindromo(palabra, inicio+1, final-1);
    }
}

int main(){
    string palabra;
    cin >> palabra;
    bool esPalindromo = palindromo(palabra, 0, palabra.length()-1);
    if(esPalindromo) cout << "ES PALINDROMO!!" << '\n';
    else cout << "NO ES PALINDROMO :C" << '\n';
    return 0;
}