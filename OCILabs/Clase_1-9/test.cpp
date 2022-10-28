#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> lista = {1,4,5,7};
    vector<int>::iterator itr;
    int n;
    cout << "numero: ";
    cin >> n;
    itr = lower_bound(lista.begin(), lista.end(), n);
    cout << *itr << '\n';
    int pos = itr - lista.begin();
    cout << pos << '\n';
    return 0;
}