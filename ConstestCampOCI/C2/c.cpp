//Registro IOI
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    queue<long int> cola;
    long int n;
    long int p;
    char r;
    cin >> n;
    for(long int i = 0; i < n; i++){
        cin >> r;
        if(r == 'A'){
            if(cola.size() == 0) {
                cout << -1 << '\n';
            }
            else{
                cout << cola.front() << '\n';
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