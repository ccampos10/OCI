#include <iostream>
using namespace std;

int main(){
    int n, d, suma=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d;
        suma = suma + d;
    }
    cout << suma << '\n';
    return 0;
}