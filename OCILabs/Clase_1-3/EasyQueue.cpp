#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios:: fixed);

    //Aqui va su código
    queue <int> numero;
    int t, codigo, entrada;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> codigo;
        if(codigo == 1){
            cin >> entrada;
            numero.push(entrada);
        }
        else if(codigo == 2){
            if (!numero.empty()){
                numero.pop();
            }
        }
        else if(codigo == 3){
            if (!numero.empty()){
                cout << numero.front() << "\n";
            }
            else cout << "Empty!" << "\n";
        }
    }
    return 0;
}