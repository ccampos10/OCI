#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios:: fixed);

    //Aqui va su código
    
    string entrada;
    stack <char> letras;
    stack <char> letrasI;
    cin >> entrada;
    for (int i = 0; i < entrada.length(); i++){
        if(entrada[i] != '<'){
            letras.push(entrada[i]);
        }
        else if(!letras.empty()){
            letras.pop();
        }

    }
    int tamano = letras.size();
    for (int i = 0; i < tamano; i++) {
        letrasI.push(letras.top());
        letras.pop();
    }
    for (int i = 0; i < tamano; i++) {
        cout << letrasI.top();
        letrasI.pop();
    }
    return 0;
}