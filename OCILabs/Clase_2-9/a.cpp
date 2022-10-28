#include <iostream>
#include <vector>
#include <string>
using namespace std;

int contarCaminos(vector<string> &grilla){
    int n = (int) grilla.size();
    vector<vector<long long int>> res(n, vector<long long int>(n, 0));
    res[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grilla[i][j] != '*'){
                if(i > 0){
                    res[i][j] = (res[i][j] + res[i - 1][j]);
                }
                if(j > 0){
                    res[i][j] = (res[i][j] + res[i][j - 1]);
                }
            }
        }
    }
    return res[n - 1][n - 1];
}

int main(){
    vector<string> grilla;
    long long int n;
    string c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        grilla.push_back(c);
    }
    if(grilla[0][0] == '*') cout << 0 << '\n';
    else cout << contarCaminos(grilla) << '\n';
    return 0;
}