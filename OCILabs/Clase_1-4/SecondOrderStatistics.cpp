#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, numero;
    int primero = 0, segundo = 0;
    cin >> n;
    set <int> lista;
    // guardar los numero de la lista en un congunto para que no se repitan
    for(int i = 0 ; i < n; i++){
        cin >> numero;
        lista.insert(numero);
    }
    // crear el iterador de la lista
    set <int>::iterator itr;
    itr = lista.begin();
    if(lista.size() > 1){
        // recorer la lista
        for(int i = 0; i < lista.size(); i++){
            if(i == 0){
                primero = *itr;
                segundo = primero;
            }
            else if(i == 1){
                if(primero < *itr) segundo = *itr;
                else{
                    segundo = primero;
                    primero = *itr;
                }
            }
            else {
                if(segundo > *itr){
                    if(primero > *itr){
                        segundo = primero;
                        primero = *itr;
                    }
                    else segundo = *itr;
                }
            }
            itr++;
        }
        cout << segundo << "\n";
    }
    else cout << "NO";
    return 0;
}