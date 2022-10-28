#include <iostream>
#include <vector>
using namespace std;

bool suma(vector<int> lista, int k, int primero, int segundo){
    if(lista[primero] + lista[segundo] == k){
        return true;
    }
    else if(segundo > lista.size() - 1){
        if(primero > lista.size() - 1)return false;
        else return suma(lista, k, primero+1, primero+2);
    }
    else return suma(lista, k, primero, segundo+1);
}

int main(){
    vector<int> lista;
    int n, K, numero;
    cin >> n >> K;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }
    cout << suma(lista, K, 0, 1) << '\n';
    return 0;
}