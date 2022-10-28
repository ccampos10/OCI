#include <iostream>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    if(n % s == 0) cout << n/s << '\n';
    else cout << -1 << '\n';
    return 0;
}