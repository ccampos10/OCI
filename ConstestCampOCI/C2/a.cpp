//Cartas de Pony
#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, m, p;
    map<int, int> cartas;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        cartas.insert(pair<int, int>(p, -1));
    }
    for(int i = 0; i < m; i++){
        cin >> p;
        if(cartas.find(p) == cartas.end()) cout << "No" << '\n';
        else cout << "Si" << '\n';
    }
    
    return 0;
}