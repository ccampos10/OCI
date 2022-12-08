#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int inf = 2147483647;
vector<vector<pair<int,int>>> malla;

void crear_malla(int n){
    for(int i = 0; i < n; i++){
        vector<pair<int,int>> temp;
        malla.push_back(temp);
    }
}

void crear_piso(int p, int q){
    malla[p].push_back(pair<int,int>(q,inf));
}

void dijkstra(int inicio, int final){
    int edificio = 0;
    malla[edificio][inicio].second = 0;
    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> siguiente;
    siguiente.push(pair<int,int>(0,inicio));
    while(!siguiente.empty()){
        int piso = siguiente.top().second;
        int distancia = siguiente.top().first;
        siguiente.pop();
        if(edificio < final && distancia <= malla[edificio][piso].second){
            for(int i = 0; i < malla[edificio+1].size(); i++){
                int peso = 0;
                if(piso < malla[edificio+1][i].first) peso = malla[edificio+1][i].first - piso;
                if(malla[edificio+1][i].second > distancia + peso){
                    malla[edificio+1][i].second = distancia + peso;
                    siguiente.push(pair<int,int>(distancia + peso, malla[edificio+1][i].first));
                }
            }
        }
        edificio++;
    }
}

int main(){
    int n, m, p, q;
    cin >> n >> m;
    crear_malla(n);
    for(int i = 0; i < n; i++){
        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> q;
            crear_piso(i, q);
        }
    }
    dijkstra(m-1, n);
    int pesoMin;
    for(int i = 0; i < malla[n].size(); i){
        if(i == 0) pesoMin = malla[n][i].second;
        else if(pesoMin > malla[n][i].second) pesoMin = malla[n][i].second;
    }
    cout << pesoMin << endl;
    
    return 0;
}