#include <bits/stdc++.h>
using namespace std;

void dequeTuto(){
    int n, p, o;
    deque<int> picola; // es una combinacion de una pila y una cola
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> p >> o;
        (o==1 ? picola.push_front(p) : picola.push_back(p)); // notacion parecida a la de JavaScript
        cout << ':' <<  picola[(picola.size()>2 ? 2 : picola.size()-1)] << endl;
    }
}

int main(){
    // dequeTuto();
    return 0;
}