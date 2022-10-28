#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    string nombre;
    set <string> nombres;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> nombre;
        if(nombres.insert(nombre).second == true){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}