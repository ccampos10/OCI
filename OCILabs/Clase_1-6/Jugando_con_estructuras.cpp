#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n, numero;
    stack <int> pila;
    queue <int> cola;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numero;
        pila.push(numero);
        cola.push(numero);
    }
    cout << "PILA:";
    for(int i = 0; i < n; i++){
        cout << ' ' << pila.top();
        pila.pop();
    }
    cout << '\n';

    cout << "COLA:";
    for(int i = 0; i < n; i++){
        cout << ' ' << cola.front();
        cola.pop();
    }
    cout << '\n';

    return 0;
}