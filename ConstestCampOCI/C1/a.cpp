//Benjiornos
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> precios;
    int n, m, p;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> p;
            if(i == 0){
                precios.push_back(p);
            }
            else{
                precios[j]+=p;
            }
        }
    }
    cout << precios[0];
    for(int i = 1; i < precios.size(); i++){
        cout << ' ' << precios[i];
    }
    return 0;
}