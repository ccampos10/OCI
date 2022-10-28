#include <iostream>
#include <vector>
using namespace std;
vector<vector<long int> > grafo;

void crear_grafo(int n){
    for(int i = 0; i < n; i++){
        vector<long int> nodo;
        grafo.push_back(nodo);
    }
}

// bool noConectados(int a, int b){
//     for(int i = 0; i < grafo[a].size(); i++){
//         if(grafo[a][i] == b) return false;
//     }
//     return true;
// }

void crear_coneccion(int a, int b){
    // if(noConectados(a,b)) {
    //     grafo[a].push_back(b);
    //     grafo[b].push_back(a);
    // }
    grafo[a].push_back(b);
}

bool pase(int jugador, int jGrupo){
    vector<long int> aliados;
    vector<long int> enemigos;
    vector<long int> test;

    for(int i = 0; i < grafo[jugador].size(); i++) {
        if(jugador < jGrupo) {
            if(grafo[jugador][i] < jGrupo) aliados.push_back(grafo[jugador][i]);
            else enemigos.push_back(grafo[jugador][i]);
        }
        else {
            if(grafo[jugador][i] >= jGrupo) aliados.push_back(grafo[jugador][i]);
            else enemigos.push_back(grafo[jugador][i]);
        }
    }

    bool flag = true;
    for(int i = 0; i < aliados.size() && flag; i++){
        flag = false;
        int aliado = aliados[i];
        for(int j = 0; j < grafo[aliado].size() && !flag; j++){
            if(jugador < jGrupo && grafo[aliado][j] >= jGrupo){
                for(int k = 0; k < enemigos.size() && !flag; k++){
                    int enemigo = enemigos[k];
                    if(grafo[aliado][j] == enemigo) flag = true;
                }
            }
            else if(jugador >= jGrupo && grafo[aliado][j] < jGrupo){
                for(int k = 0; k < enemigos.size() && !flag; k++){
                    int enemigo = enemigos[k];
                    if(grafo[aliado][j] == enemigo) flag = true;
                }
            }
        }
    }
    return !flag;
}

int main(){
    int n, q, l, L, k;
    cin >> n >> q;
    crear_grafo(2*n);
    for(int i = 0; i < (2*n); i++){
        cin >> l;
        for(int j = 0; j < l; j++){
            cin >> L;
            crear_coneccion(i, L-1);
        }
    }
    for(int i = 0; i < q; i++){
        cin >> k;
        cout << pase(k-1,n) << '\n';
    }
    return 0;
}