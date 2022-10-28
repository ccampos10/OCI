#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int temp;
    string suma;
    vector<char> numeros;
    cin >> suma;
    for(int i = 1; i <= suma.size(); i++){
        if(i % 2 != 0){
            numeros.push_back(suma[i-1]);
        }
    }

    for(int i = 0; i < numeros.size(); i++){
        for(int j = 0; j < numeros.size() - i - 1; j++){
            if(numeros[j] > numeros[j + 1]){
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < numeros.size(); i++){
        cout << numeros[i];
        if(i < numeros.size()-1) cout << '+';
    }
    cout << '\n';
    
    return 0;
}