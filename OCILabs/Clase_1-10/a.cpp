#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, numero;
    vector<int> arr, brr, faltantes;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numero;
        arr.push_back(numero);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> numero;
        brr.push_back(numero);
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int pos = 0;
    for(int i = 0; i < brr.size(); i++){
        if(brr[i] == arr[pos]){
            pos++;
            if(pos >= arr.size()){
                for(int j = i+1; j < brr.size(); j++) {
                    if(faltantes.size() != 0 && faltantes[faltantes.size()-1] != brr[j]) faltantes.push_back(brr[j]);
                    else if(faltantes.size() == 0) faltantes.push_back(brr[j]);
                }
                break;
            }
        }
        else if(brr[i] != arr[pos]){
            if(faltantes.size() != 0 && faltantes[faltantes.size()-1] != brr[i]) faltantes.push_back(brr[i]);
            else if(faltantes.size() == 0) faltantes.push_back(brr[i]);
        }
    }
    for(int i = 0; i < faltantes.size(); i++){
        cout << faltantes[i] << ' ';
    }
    cout << '\n';
    return 0;
}