#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(NULL);
    cout.setf(ios :: fixed);

    // long int n;
    // cin >> n;
    // vector<int> personas;
    // vector<int> Dpos;
    // for(int i = 0; i < n; i++){
    //     personas.push_back(i+1);
    // }

    // int i = -1;
    // while(personas.size() != 0) {
    //     i += 2;
    //     if(i > personas.size()-1) {
    //         i = i - personas.size();
    //         for(int j = Dpos.size() - 1; j >= 0; j--) {
    //             personas.erase(personas.begin() + Dpos[j]);
    //         }
    //         Dpos.clear();
    //         if(personas.size() == 0) break;
    //     }
    //     cout << personas[i] << " ";
    //     Dpos.push_back(i);
    // }
    long int n;
    int sacados=0, i=-1;
    cin >> n;
    vector<int> personas;
    for(int i = 0; i < n; i++){
        personas.push_back(i+1);
    }
    while(sacados > n) {
        i += 2;
        cout << i+1 << " ";
        if(personas)
        sacados++;
    }
    return 0;
}