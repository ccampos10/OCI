#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ordenar(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    if(a.first < b.first) return true;
    else return false;
}

int main(){
    long long int n, a, b;
    vector<pair<long long int, long long int>> horas;
    // vector<pair<long long int, long long int>>::iterator it;
    vector<int> primerasHoras;
    pair<long long int, long long int> hora;
    int maxG = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        hora.first = a;
        hora.second = b;
        horas.push_back(hora);
        primerasHoras.push_back(a);
    }
    sort(horas.begin(), horas.end(), ordenar);
    sort(primerasHoras.begin(), primerasHoras.end());

    // for(it = horas.begin(); it < horas.end(); it++){
    //     int max = 0;
    //     vector<pair<long long int, long long int>>::iterator itr = it;
    //     bool end = false;
    //     while(!end){
    //         max++;
    //         int pos = lower_bound(primerasHoras.begin(),primerasHoras.end(), itr->second) - primerasHoras.begin();
    //         if(pos == primerasHoras.size()) end = true;
    //         else {
    //             itr = horas.begin() + pos;
    //         }
    //     }
    //     if(max > maxG) maxG = max;
    // }

    for(int i = 0; i < horas.size(); i++){
        int pelicula = i, max = 0;
        bool end = false;
        while(!end){
            max++;
            int pos = lower_bound(primerasHoras.begin(),primerasHoras.end(), horas[pelicula].second) - primerasHoras.begin();
            if(pos == primerasHoras.size()) end = true;
            else {
                pelicula = pos;
            }
        }
        if(max > maxG) maxG = max;
    }

    cout << maxG << '\n';

    return 0;
}