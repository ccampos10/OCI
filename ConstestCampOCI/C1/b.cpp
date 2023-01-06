//Desorden
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector <int> poleras;
    int n, p;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        poleras.push_back(p);
    }
    sort(poleras.begin(), poleras.end());
    cout << poleras[0];
    for (int i = 1; i < poleras.size(); i++)
    {
        cout << ' ' << poleras[i];
    }
    
    return 0;
}