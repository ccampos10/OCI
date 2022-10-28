#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios:: fixed);

    //Aqui va su código
    
    int cantidad;
    cin >> cantidad;
    for(int i = 0; i < cantidad; i++){
        string cadena;
        cin >> cadena;
        if(cadena == ""){
            cout << "Yes\n";
        }
        else {
            stack <char> pila;
            bool correcto = true;
            for(int j = 0; j < cadena.length(); j++){
                if (cadena[j] == '('){
                    pila.push('(');
                }
                else if(cadena[j] == '['){
                    pila.push('[');
                }
                else if(cadena[j] == ')' && !pila.empty() && pila.top() == '('){
                    pila.pop();
                }
                else if(cadena[j] == ']' && !pila.empty() && pila.top() == '['){
                    pila.pop();
                }
                else {
                    correcto = false;
                    break;
                }
            }
            if(!pila.empty()) correcto = false;
            
            if(correcto) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}