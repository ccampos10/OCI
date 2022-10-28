#include <iostream>
#include <vector>
using namespace std;

int cantidadSumas(vector<int> monedas, int x){
    vector<int> formaSumas(x+1,0);
    formaSumas[0] = -1; // no me interesa
    for(int j = 0; j < monedas.size(); j++){
        for(int i = 1; i <= x; i++){
            int numero = i-monedas[j];
            if(numero > 0 && formaSumas[numero] != 0){
                formaSumas[i] += formaSumas[numero];
            }
            else if(numero == 0){
                formaSumas[i] += 1;
            }
        }
    }
    return formaSumas[x];
}

int main(){
    vector<int> monedas;
    int n, x, a;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a;
        monedas.push_back(a);
    }
    cout << cantidadSumas(monedas, x) << '\n';

    return 0;
}