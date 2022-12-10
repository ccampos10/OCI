#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int,vector< pair<int,int> > > > grafo;
vector<vector<int>> edificios;
vector<int> distancias;
int inf = 2147483647;

void crear_edificios(int cantEdi){
    for(int i=0;i<cantEdi;i++){
        edificios.push_back(vector<int>());
    }
}

void crear_conexion(int edi, int piso){
    grafo.push_back(pair<int,vector<pair<int,int>>>(piso, vector<pair<int,int> >()));
    edificios[edi].push_back(grafo.size()-1);

    if(edi != 0){
        for(int i = 0; i < edificios[edi-1].size(); i++){
            if(grafo[edificios[edi-1][i]].first >= piso){
                grafo[edificios[edi-1][i]].second.push_back(pair<int,int>(grafo.size()-1, 0));
            }
            else grafo[edificios[edi-1][i]].second.push_back(pair<int,int>(grafo.size()-1, piso-grafo[edificios[edi-1][i]].first));
        }
    }
}

void crear_distancias(){
    for(int i=0;i<grafo.size();i++){
        distancias.push_back(inf);
    }
}

void dijkstra(int maxPiso){
    int pisoOrigen = -1;
    for(int i=0; i < edificios[0].size(); i++){
        if(grafo[edificios[0][i]].first == maxPiso){
            distancias[edificios[0][i]] = 0;
            pisoOrigen = edificios[0][i];
            break;
        }
    }
    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> siguiente;
    siguiente.push(pair<int, int>(0, pisoOrigen));
    while(!siguiente.empty()){
        int piso = siguiente.top().second;
        int distancia = siguiente.top().first;
        siguiente.pop();
        bool flag = true;
        for(int i=0; i < edificios[edificios.size()-1].size(); i++) if(edificios[edificios.size()-1][i] == piso) flag = false;
        if(flag && distancia <= distancias[piso]){
            for(int i=0; i < grafo[piso].second.size(); i++) {
                int peso = grafo[piso].second[i].second;
                if(distancias[grafo[piso].second[i].first] > distancias[piso] + peso){
                    distancias[grafo[piso].second[i].first] = distancias[piso] + peso;
                    siguiente.push(pair<int, int>(distancias[piso] + peso, grafo[piso].second[i].first));
                }
            }
        }
    }
}

int main() {
    int n, m, p, s;
    cin >> n >> m;
    crear_edificios(n);
    for(int i = 0; i < n; i++){
        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> s;
            crear_conexion(i,s);
        }
    }
    crear_distancias();
    dijkstra(m-1);
    for(int i = 0; i < edificios[edificios.size()-1].size(); i++){
        cout << edificios[edificios.size()-1][i] << endl;
    }

    return 0;
}