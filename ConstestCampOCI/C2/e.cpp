//El regreso del Registro IOI
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<long int> cola; // cola sirve
    int n;
    long int p;
    char r;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> r;
        if(r == 'A'){
            if(cola.size() == 0) {
                cout << -1 << '\n';
            }
            else{
                set<long int>::iterator itr = cola.begin();
                cola.end().operator++;
                // cout << *itr << '\n';
                // cola.erase(itr);
            }
        }
        else if(r == 'L'){
            cin >> p;
            cola.insert(p); // y si hay mas de un p?
        }
    }
    return 0;
}