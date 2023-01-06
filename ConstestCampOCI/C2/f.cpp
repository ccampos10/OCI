//Cut Ribbon
#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int calculo(int n, int a, int b, int c){
    int res=-1;
    if(n==0) return 0;
    else if(n>=c) {
        if(n%c==0) res = (n/c)-1;
        else if(n-c >= b) res = calculo(n-c, a, b, c);
    }
    if(res>=0) return 1+res;

    if(n>=b) {
        res = calculo(n-b, a, b, c);
    }
    if(res >=0) return 1+res;

    if(n>=a) res = calculo(n-a, a, b, c);
    if(res>=0) return 1+res;

    return -n;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> op(3,-1);
    int n, p;
    cin>>n;
    for(int i=0; i<3; i++) cin>>op[i];
    
    // sort(op.begin(), op.end());
    //ordenar
    int t;
    if(op[0] > op[1]){
        t = op[0];
        op[0] = op[1];
        op[1] = t;
    }
    if(op[1] > op[2]){
        t = op[1];
        op[1] = op[2];
        op[2] = t;
    }
    if(op[0] > op[1]){
        t = op[0];
        op[0] = op[1];
        op[1] = t;
    }


    cout << calculo(n, op[2], op[1], op[0]) << '\n';
}