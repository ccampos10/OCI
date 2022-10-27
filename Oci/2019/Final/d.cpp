//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n, k, j, y, x;
    int turno = 1;
    bool vive = true;
    cin >> m >> n >> k;
    vector<vector<int>> plano(m,vector<int>(n,0));
    vector<vector<int>> rocas;
    for(int i = 0; i < k; i++){
        cin >> j >> y >> x;
        rocas.push_back({j,y,x});
    }

    return 0;
}