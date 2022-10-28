#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, x, puntaje;
    string nombre;
    cin >> n;
    map <string, int> alumnos;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x == 1) {
            cin >> nombre;
            cin >> puntaje;
            if(alumnos.find(nombre) != alumnos.end()){
                alumnos.find(nombre)->second = alumnos.find(nombre)->second + puntaje;
            }
            else {
                alumnos.insert(pair<string,int>(nombre,puntaje));
            }
        }
        else if(x == 2) {
            cin >> nombre;
            alumnos.find(nombre)->second = 0;
        }
        else if(x == 3) {
            cin >> nombre;
            if(alumnos.find(nombre) == alumnos.end()){
                cout << 0 << "\n";
            }
            else {
                cout << alumnos.find(nombre)->second << endl;
            }
        }
    }
    return 0;
}