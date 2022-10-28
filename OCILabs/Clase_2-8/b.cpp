#include <iostream>
#include <vector>
using namespace std;
int v1, v2;

int Bifoccani(int n){
    vector<unsigned long long int> B(n+1);
    B[0] = -1;
    B[1] = v1;
    B[2] = v2;
    for(int i = 3; i <= n; i++){
        B[i] = (B[i-1]*B[i-1]) + B[i-2];
    }
    return B[n];
}

int main(){
    int n;
    cin >> v1 >> v2 >> n;

    cout << Bifoccani(n) << '\n';
    return 0;
}