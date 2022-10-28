#include <iostream>
using namespace std;

int main(){
    int t, pt, rt;
    int c, pc, rc;
    int costo = 0;
    cin >> t >> pt >> rt;
    cin >> c >> pc >> rc;
    if(t < c){
        int diferencia = c - t;
        if(pt < rc){
            costo = pt*diferencia;
        }
        else{
            costo = rc*diferencia;
        }
    }
    else {
        int diferencia = t - c;
        if(pc < rt){
            costo = pc*diferencia;
        }
        else {
            costo = rt*diferencia;
        }
    }
    cout << costo << '\n';
    return 0;
}