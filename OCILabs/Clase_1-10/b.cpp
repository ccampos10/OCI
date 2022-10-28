#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<long int> disponible;
    vector<long int>::iterator itr;
    long int n,m,numero,diferencia = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> numero;
        disponible.push_back(numero);
    }
    sort(disponible.begin(), disponible.end());

    for(int i = 0; i < m; i++) {
        cin >> numero;
        itr = lower_bound(disponible.begin(), disponible.end(), numero);
        if(*itr - numero > 0) diferencia += *itr - numero;
        else diferencia += (*itr - numero)*-1;
    }
    cout << diferencia << '\n';
    
    return 0;
}