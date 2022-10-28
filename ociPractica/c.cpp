#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, d, alturaAC;
    cin >> n;
    vector<int> halturas(n);
    vector<int> montanas(n);
    alturaAC = n;
    for(int i = 0; i < n; i++){
        cin >> d;
        halturas[d]=alturaAC;
        montanas[i]=d;
        alturaAC--;
    }
    int mActual = montanas[0];
    int siguiente = montanas[1];
    int i = 1;
    bool mFinal = false;
    while(!mFinal){
        if(mActual < siguiente){
            // int distancia = siguiente-mActual;
            bool flag = false;
            for(int j = mActual+1; j < siguiente; j++){
                if(halturas[j] > halturas[mActual]){
                    flag = true;
                    i++;
                    if(i < n) siguiente = montanas[i];
                    break;
                }
            }
            if(!flag) {
                mActual = siguiente;
                i++;
                if(i < n) siguiente = montanas[i];
            }
            if(i >= n) mFinal = true;
        }
        else{
            bool flag = false;
            for(int j = mActual-1; j > siguiente; j--){
                if(halturas[j] > halturas[mActual]){
                    flag = true;
                    i++;
                    if(i < n) siguiente = montanas[i];
                    break;
                }
            }
            if(!flag) {
                mActual = siguiente;
                i++;
                if(i < n) siguiente = montanas[i];
            }
            if(i >= n) mFinal = true;
        }
    }
    cout << mActual << endl;
    return 0;
}