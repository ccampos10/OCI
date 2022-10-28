#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> llave;
    vector<int> serrojo;
    int n, m, d, limar=0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> d;
        llave.push_back(d);
    }
    for(int i = 0; i < n; i++){
        cin >> d;
        serrojo.push_back(d);
    }
    for(int i = 0; i < n; i++){
        if(limar > m) break;
        if(llave[i] > serrojo[i]) limar++;
    }
    if(limar > m) cout << "no" << endl;
    else cout << "si" << endl;
    return 0;
}