#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main(){
    int n, x;
    set <int> lista;
    pair <set <int>::iterator, bool> test;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        test = lista.insert(x);
        while(!test.second){
            
        }
        
    }
    return 0;
}