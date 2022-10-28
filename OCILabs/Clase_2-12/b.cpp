#include <iostream>
#include <vector>
using namespace std;
// vector<vector<int> > fiestas;

// bool participo(int p, int f){
//     bool flag = false;
//     for(int i = 0; i < fiestas[f].size(); i++){
//         if(p == fiestas[f][i]) flag = true;
//     }
//     return flag;
// }

// bool comprobar(int p){
//     bool flag = true;
//     vector<vector<int>> vistos(p,vector<int>());
//     for(int i = 0; i < p; i++){
//         for(int j = 0; j < fiestas.size(); j++){
//             if(participo(i,j)){
//                 vistos[i] = fiestas[j];
//             }
//         }
//     }
//     for(int i = 0; i < vistos.size(); i++){
//         if(vistos[i].size() != p) flag = false;
//     }
//     return flag;
// }

bool noEsta(vector<int> lista, int persona){
    bool flag = false;
    for(int i = 0; i < lista.size(); i++) {
        if(lista[i] == persona) flag = true;
    }
    return !flag;
}

int main(){
    // vector<int> fiesta;
    // int p, f, pfs, pf;
    // cin >> p >> f;
    // for(int i = 0; i < f; i++){
    //     cin >> pfs;
    //     for(int j = 0; j < pfs; j++){
    //         cin >> pf;
    //         fiesta.push_back(pf);
    //     }
    //     fiestas.push_back(fiesta);
    // }
    // if(comprobar(p)) cout << "Yes" << endl;
    // else cout << "No" << endl;

    int p, f, pfs, pf;
    bool flag = true;
    cin >> p >> f;
    vector<vector<int>> personas(p+1,vector<int>());
    vector<int> participantes;
    for(int i = 0; i < f; i++){
        cin >> pfs;
        participantes.clear();
        for(int j = 0; j < pfs; j++){
            cin >> pf;
            for(int k = 0; k < participantes.size(); k++){
                if(noEsta(personas[participantes[k]], pf)) personas[participantes[k]].push_back(pf);
                if(noEsta(personas[pf], participantes[k])) personas[pf].push_back(participantes[k]);
            }
            participantes.push_back(pf);
        }
    }

    // for(int i = 0; i < personas.size(); i++){
    //     for(int j = 0; j < personas[i].size(); j++){
    //         cout << personas[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i < personas.size(); i++){
        if(personas[i].size() != p-1) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}