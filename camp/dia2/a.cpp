#include <bits/stdc++.h>
using namespace std;
vector<pair<vector<int>,int>> grafo;
map<int,vector<int>> multiId;
queue<pair<int, int>> obst;
int claves[1000][1000];
int lastId = 0;

int main(){
    int n,m;
    string input;
    cin >> n >> m;
    memset(claves, -1, sizeof(claves));
    for(int linea = 0; linea < n; linea++){
        cin >> input;
        for(int caracter = 0; caracter < m; caracter++){
            //La cosa:
            if(input[caracter] == '.'){
                grafo.push_back(make_pair(vector<int>(),-1));
                claves[linea][caracter]=grafo.size()-1;
                if(linea > 0 && claves[linea-1][caracter] != -1) {
                    grafo[grafo.size()-1].first.push_back(claves[linea-1][caracter]);
                    grafo[claves[linea-1][caracter]].first.push_back(grafo.size()-1);
                    grafo[grafo.size()-1].second = grafo[claves[linea-1][caracter]].second;
                }
                if(caracter > 0 && claves[linea][caracter-1] != -1) {
                    int firstId = grafo[grafo.size()-1].second;
                    int secondId = grafo[claves[linea][caracter-1]].second;
                    grafo[grafo.size()-1].first.push_back(claves[linea][caracter-1]);
                    grafo[claves[linea][caracter-1]].first.push_back(grafo.size()-1);
                    if(firstId == -1) grafo[grafo.size()-1].second = secondId;
                    else{
                        if(multiId.count(firstId)==0){
                            multiId.insert(pair<int,vector<int>>(firstId, {secondId}));
                        }
                        else multiId[firstId].push_back(secondId);

                        if(multiId.count(secondId)==0){
                            multiId.insert(pair<int,vector<int>>(secondId, {firstId}));
                        }
                        else multiId[secondId].push_back(firstId);

                        vector<int> aux;
                        if(multiId[firstId].size() > 1){
                            aux = multiId[firstId];
                            aux.erase(aux.end()-1);
                            for(auto element : aux) multiId[secondId].push_back(element);
                        }
                        if(multiId[secondId].size() > 1){
                            aux = multiId[secondId];
                            aux.erase(aux.end()-1);
                            for(auto element : aux) multiId[firstId].push_back(element);
                        }
                    }
                }
                if(grafo[grafo.size()-1].second == -1) {
                    grafo[grafo.size()-1].second = lastId++;
                }
            }
            else if(input[caracter]=='*'){
                obst.push(make_pair(linea,caracter));
            }
        }
    }

    

    return 0;
}