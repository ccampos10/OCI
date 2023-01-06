//El regreso del Registro IOI
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector <long int> cola;
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
                cout << cola[cola.size()-1] << '\n';
                cola.erase(cola.end()-1);
            }
        }
        else if(r == 'L'){
            cin >> p;
            cola.push_back(p);
            sort(cola.begin(), cola.end());
        }
    }
    return 0;
}