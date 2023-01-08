#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    stack<char> pila;
    cin >> in;
    for(int i = 0; i<in.length();i++){
        if(!pila.empty() && pila.top() == in[i]) pila.pop();
        else pila.push(in[i]);
    }
    if(pila.empty()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}