#include <iostream>
using namespace std;

int main(){
    int numero;
    int numeroCambiado;
    int decena = 0;
    cin >> numero;
    while (numero - (decena*10) >= 0)
    {
        decena++;
    }
    decena--;

    numeroCambiado = (numero - (decena*10))*10 + decena;
    cout << numeroCambiado << endl;
    system("pause");
    
    return 0;
}