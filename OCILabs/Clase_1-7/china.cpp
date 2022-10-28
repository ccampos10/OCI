#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, numero;
    set<int> lista;
    set<int>::iterator itr;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>numero;
        lista.insert(numero);
    }
    itr = lista.begin();
    itr++;
    cout << *itr << '\n';

    return 0;
}