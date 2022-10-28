#include <iostream>
#include <vector>
using namespace std;

int main(){
    char letra;
    int n, temp, j;
    vector<char> lista;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> letra;
        lista.push_back(letra);
    }

    for(int i = 0; i < lista.size(); i++){
        j = i-1;
        temp = lista[i];
        while(j >= 0 && lista[j] > temp){
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