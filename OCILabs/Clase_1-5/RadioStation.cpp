#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, m;
    string nombre, ip;
    cin >> n >> m;
    map <string, string> principales;
    // map <string, string> secundarios;
    for (int i = 0; i < n; i++) {
        cin >> nombre >> ip;
        principales.insert(pair <string, string>(ip+';', nombre));
    }
    for (int i = 0; i < m; i++) {
        cin >> nombre >> ip;
        cout << nombre << ' ' << ip << ' ' << '#' << principales.find(ip)->second << "\n";
    }
    return 0;
}