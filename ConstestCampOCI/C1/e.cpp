//New Year Transportation
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> LineWorld;
    bool sePuede = false;
    int n, t, p;
    cin >> n >> t;
    for(int i = 0; i < n-1; i++) {
        cin >> p;
        LineWorld.push_back(p);
    }
    for(int i = 0; i <= t-1 && i <= LineWorld.size(); i+=LineWorld[i]) {
        if(i == t-1){
            sePuede = true;
            break;
        }
    }
    if(sePuede) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}