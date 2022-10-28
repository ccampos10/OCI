#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, d, m ,a;
    string nombre, temp;
    vector<int> fecha;
    vector<string> nombres;
    map <string, vector<int> > clase;
    cin >> n;
    for(int i = 0; i < n; i++){
        fecha.clear();
        cin >> nombre;
        cin >> d;
        cin >> m;
        cin >> a;
        fecha.push_back(d);
        fecha.push_back(m);
        fecha.push_back(a);
        clase.insert(pair<string, vector<int> >(nombre, fecha));
        nombres.push_back(nombre);
    }

    for(int i = 0; i < nombres.size(); i++){
        for(int j = 0; j < nombres.size() - i - 1; j++){
            if(clase[nombres[j]][2] > clase[nombres[j + 1]][2]) {
                temp = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = temp;
            }
            else if(clase[nombres[j]][2] == clase[nombres[j + 1]][2]){
                if(clase[nombres[j]][1] > clase[nombres[j + 1]][1]){
                    temp = nombres[j];
                    nombres[j] = nombres[j + 1];
                    nombres[j + 1] = temp;
                }
                else if(clase[nombres[j]][1] == clase[nombres[j + 1]][1]) {
                    if(clase[nombres[j]][0] > clase[nombres[j + 1]][0]){
                        temp = nombres[j];
                        nombres[j] = nombres[j + 1];
                        nombres[j + 1] = temp;
                    }
                }
            }
        }
    }
    cout << nombres[nombres.size()-1] << '\n';
    cout << nombres[0] << '\n';

    return 0;
}