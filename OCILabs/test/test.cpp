#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> lista = {3,4,5,6,7,8,9,10};
    int n;
    cin >> n;
    cout << *lower_bound(lista.begin(), lista.end(), n) << endl;
    cout << *lista.end() << endl;
    return 0;
}