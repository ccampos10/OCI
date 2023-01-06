//Mail Stamps
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector <vector<int>> ruta;
vector <bool> visitados;
vector <int> anterior;
map <int, int> mapa;
map <int, int> mapa2;
int lastIndex = 0;

void crear_ruta(int n){
    for(int i = 0; i < n; i++){
        ruta.push_back(vector<int>());
        visitados.push_back(false);
        anterior.push_back(-1);
    }
}

void conectar(int p, int k){
    if(mapa.find(p) == mapa.end()){
        ruta[lastIndex].push_back(k);
        mapa.insert(pair<int,int>(p,lastIndex));
        mapa2.insert(pair<int,int>(lastIndex,p));
        lastIndex++;
    }
    else{
        ruta[mapa.find(p) -> second].push_back(k);
    }

    if(mapa.find(k) == mapa.end()){
        ruta[lastIndex].push_back(p);
        mapa.insert(pair<int,int>(k,lastIndex));
        mapa2.insert(pair<int,int>(lastIndex,k));
        lastIndex++;
    }
    else{
        ruta[mapa.find(k) -> second].push_back(p);
    }
}

void dfs(int inicio){
    visitados[inicio] = true;
    for(int i = 0; i < ruta[inicio].size(); i++){
        int vesino = mapa.find(ruta[inicio][i])->second;
        if(visitados[vesino] == false){
            dfs(vesino);
            anterior[vesino] = inicio;
        }
    }
}

int main(){
    int n, p, k, final;
    bool inicio = false;
    cin >> n;
    crear_ruta(n+1);
    for(int i = 0; i < n; i++){
        cin >> p >> k;
        conectar(p,k);
    }
    for(int i = 0; i < n+1; i++){
        if(ruta[i].size() == 1 && !inicio){
            inicio = true;
            dfs(i);
        }
        else if(ruta[i].size() == 1 && inicio){
            final = i;
            break;
        }
    }
    cout << mapa2.find(final)->second;
    for (int i = anterior[final]; i != -1; i=anterior[i])
    {
        cout << ' ' << mapa2.find(i)->second;
    }
    

    return 0;
}