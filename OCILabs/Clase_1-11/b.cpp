#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, iMayor=0;
    string nombre;
    vector<string> candidatos;
    vector<string>::iterator itr;
    vector<int> votos;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nombre;
        itr = find(candidatos.begin(),candidatos.end(), nombre);
        if(itr == candidatos.end()){
            candidatos.push_back(nombre);
            votos.push_back(1);
        }
        else{
            votos[itr-candidatos.begin()]++;
        }
    }
    for(int i = 0; i < votos.size(); i++){
        if(votos[iMayor] < votos[i]) iMayor = i;
    }
    cout << candidatos[iMayor] << '\n';
    return 0;
}