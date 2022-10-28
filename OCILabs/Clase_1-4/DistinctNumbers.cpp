#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, numero;
    set <int> lista;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.insert(numero);
    }
    cout << lista.size() << endl;


    return 0;
}