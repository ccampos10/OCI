#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool comparar(string p1, string p2){
    bool mayor;
    if(p1.length() > p2.length()){
        mayor = true;
        for(int i = 0; i < p1.length(); i++) {
            if(p1[i] > p2[i]){
                mayor = true;
                break;
            }
            else if(p1[i] < p2[i]){
                mayor = false;
                break;
            }
        }
    }
    else {
        mayor = false;
        for(int i = 0; i < p2.length(); i++) {
            if(p1[i] > p2[i]){
                mayor = true;
                break;
            }
            else if(p1[i] < p2[i]){
                mayor = false;
                break;
            }
        }
    }
    return mayor;
}

int main(){
    string palabra, temp;
    int n, j;
    vector<string> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> palabra;
        lista.push_back(palabra);
    }

    for(int i = 0; i < lista.size(); i++){
        j = i-1;
        temp = lista[i];
        while(j >= 0 && comparar(lista[j], temp)){
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = temp;

    }
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << ' ';
    }
    cout << '\n';
    return 0;
}