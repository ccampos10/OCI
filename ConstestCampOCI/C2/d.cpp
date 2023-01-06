//Registro IOInverso
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    stack<long int> cola; // pa k cambiar el nombre
    int n;
    long int p;
    char r;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> r;
        if(r == 'A'){
            if(cola.size() == 0) {
                cout << 1 << '\n';
            }
            else{
                cout << cola.top()*-1 << '\n';
                cola.pop();
            }
        }
        else if(r == 'L'){
            cin >> p;
            cola.push(p);
        }
    }
    return 0;
}