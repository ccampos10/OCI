#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios:: fixed);

    int n, x, numero, primero = -1, segundo = -1;
    vector<int> lista;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }
    for(int i = 0; i < lista.size(); i++){
        if(primero != -1) break;
        for(int z = i+1; z < lista.size(); z++){
            if(lista[i]+lista[z] == x){
                primero = i;
                segundo = z;
                break;
            }
        }
    }
    if(primero == -1) cout << -1 << '\n';
    else cout << primero+1 << ' ' << segundo+1 << '\n';

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios:: fixed);

    int n, x, numero, primero = -1, segundo = -1;
    vector<int> lista;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> numero;
        lista.push_back(numero);
    }
    for(int i = 0; i < lista.size(); i++){
        if(primero != -1) break;
        for(int z = 0; z < lista.size(); z++){
            if(i != z){
                if(lista[i]+lista[z] == x){
                    primero = i;
                    segundo = z;
                    break;
                }
            }
        }
    }
    if(primero == -1) cout << -1 << '\n';
    else cout << primero+1 << ' ' << segundo+1 << '\n';

    return 0;
}