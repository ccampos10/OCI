//Formula1
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q , a, b;
    cin >> n >> q;
    vector<int> lista(n);
    vector<int> distancias(n, 0);
    for(int i = 0; i < n; i++) cin >> lista[i];

    //calcular distancias
    for(int i = 1; i < n; i++){
        distancias[i] = distancias[i-1] + lista[i];
    }
    
    //consultas
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << distancias[b-1] - distancias[a-1] << '\n';
    }
    return 0;
}