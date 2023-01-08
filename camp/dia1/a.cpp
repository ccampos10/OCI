#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, int> nombres;
    string nombre;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nombre;
        if(nombres.count(nombre)==0){
            nombres.insert(pair<string,int>(nombre,1));
            cout << "OK\n";
        }
        else{
            cout << nombre << nombres[nombre] << "\n";
            nombres[nombre]++;
        }
    }

    return 0;
}