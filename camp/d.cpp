#include <bits/stdc++.h>
using namespace std;
vector<int> tiposMon;
int datos[250][50];

int cant(int n, int i){
    int cont=0;
    if(n==0) return 1;
    if(i>= tiposMon.size()) return 0;
    for(int j = i; j < tiposMon.size();j++){
        if(tiposMon[j]<=n){
            if(datos[n-tiposMon[j]][j] == -1){
                int res = cant(n-tiposMon[j],j);
                datos[n-tiposMon[j]][j] = res;
                cont += res;
            }
            else cont += datos[n-tiposMon[j]][j];
        }
    }
    return cont;
}

int main(){
    int n, m, p;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> p;
        tiposMon.push_back(p);
    }
    memset(datos,-1,sizeof(datos));
    int cont = cant(n,0);
    cout << cont << '\n';
    return 0;
}
