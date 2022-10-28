#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n, x;
    string libro;
    set <string> libros;
    set <string>::iterator it;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        for(int j = 0; j < x; j++){
            cin >> libro;
            libros.insert(libro);
        }
    }
    it = libros.begin();
    for(int i = 0; i < libros.size(); i++){
        cout << *it << "\n";
        it++;
    }
    
    return 0;
}