//El teclado de Nicho
#include <iostream>
#include <string>
using namespace std;

int main(){
    string palabra;
    cin >> palabra;
    for (int i = 0; i < palabra.length(); i++)
    {
        if(palabra[i] == 97) palabra[i] = 122; // si es a cambiar a z
        else if(palabra[i] == 65) palabra[i] = 90; // si es A cambiar a Z
        else palabra[i] = palabra[i]-1;
    }
    cout << palabra << '\n';
    
    return 0;
}