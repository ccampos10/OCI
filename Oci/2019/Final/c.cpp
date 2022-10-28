//Candado
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int contador=0;
    vector<int> pInicial(4);
    vector<int> pFinal(4);
    for(int i = 0; i < 8; i++){
        if(i < 4) cin >> pInicial[i];
        else cin >> pFinal[i-4];
    }
    for(int i = 0; i < 4; i++){
        while(pFinal[i] != pInicial[i]){
            int contrario = pInicial[i]+5;
            if(contrario > 9) contrario -= 10;
            // if(contrario > pFinal[i] || pFinal[i] > pInicial[i]) pInicial[i]++;
            // else pInicial[i]--;
            if(pInicial[i] <= 4){
                if(contrario > pFinal[i] && pInicial[i] < pFinal[i]) pInicial[i]++;
                else pInicial[i]--;
            }
            else{
                if(pInicial[i] > pFinal[i] && contrario < pFinal[i]) pInicial[i]--;
                else pInicial[i]++;
            }

            if(pInicial[i] == -1) pInicial[i] = 9;
            else if(pInicial[i] == 10) pInicial[i] = 0;
            contador++;
        }
    }
    cout << contador << '\n';

    return 0;
}