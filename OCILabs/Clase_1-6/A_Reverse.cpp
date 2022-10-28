#include <iostream>
#include <string>
using namespace std;

int main(){
    int L, R;
    string S;
    char Lesimo, Resimo;
    cin >> L >> R;
    cin >> S;
    L--;
    R--;
    Lesimo = S[L];
    Resimo = S[R];
    S[L] = Resimo;
    S[R] = Lesimo;
    cout << S << '\n';

    return 0;
}