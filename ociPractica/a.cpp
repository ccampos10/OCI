#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> lista;
    int n, x, z, espacioD;
    cin >> n >> x;
    espacioD = x;
    for(int i = 0; i < n; i++){
        cin >> z;
        lista.push_back(z);
    }
    sort(lista.begin(), lista.end());
    for(int i = lista.size()-1; i >= 0; i--) {
        if(espacioD > 0){
            if(lista[i] <= espacioD){
                espacioD -= lista[i];
            }
            if((float) espacioD < (float) x/2) break;
        }
    }
    if((float) espacioD < (float) x/2){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
    return 0;
}