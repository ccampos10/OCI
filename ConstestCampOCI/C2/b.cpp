//Cartas de Pony 2!
#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, m, p, t;
    map<int, int> cartas;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if(cartas.find(p) == cartas.end()) cartas.insert(pair<int, int>(p, 1));
        else cartas.find(p)->second++;
    }
    for(int i = 0; i < m; i++){
        cin >> p >> t;
        map<int, int>::iterator itr = cartas.find(p);
        if(itr == cartas.end()) cout << "No hay cambio" << '\n';
        else{
            if(itr->second > 0) {
                cout << "Cambio" << '\n';
                itr->second--;
                itr = cartas.find(t);
                if(itr == cartas.end()) cartas.insert(pair<int, int>(t, 1));
                else itr->second++;
            }
            else cout << "No hay cambio" << '\n';
        }
    }
    
    return 0;
}