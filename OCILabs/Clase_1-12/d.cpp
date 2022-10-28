#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(NULL);
    cout.setf(ios :: fixed);

    int n, k, maxPrecio;
    cin >> n >> k;
    vector<int> pTikets(n);
    vector<int>::iterator itr;
    for (int i = 0; i < n; i++) cin >> pTikets[i];
    sort(pTikets.begin(), pTikets.end());
    for (int i = 0; i < k; i++){
        cin >> maxPrecio;
        itr = lower_bound(pTikets.begin(), pTikets.end(), maxPrecio);
        if(itr != pTikets.end()){
            if(itr == pTikets.begin() && maxPrecio < *itr) cout << -1 << '\n';
            else if(maxPrecio == *itr) {
                cout << *itr << '\n';
                pTikets.erase(itr);
            }
            else if (maxPrecio < *itr) {
                cout << *(itr-1) << '\n';
                pTikets.erase(itr-1);
            }
        }
        else {
            if(pTikets.size() != 0){
                cout << *(pTikets.end() - 1) << '\n';
                pTikets.erase(pTikets.end()-1);
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}