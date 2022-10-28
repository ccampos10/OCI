#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // int n, s, numero, minDif;
    // vector<int> pos;
    // vector<int> nums;
    // cin >> n >> s;
    // for(int i = 0; i < n; i++) {
    //     cin >> numero;
    //     pos.push_back(numero);
    // }
    // sort(pos.begin(), pos.end());

    // int maxDif = pos[pos.size()-1] - pos[0];
    // if(n == 2) {
    //     cout << maxDif << '\n';
    //     return 0;
    // }
    // nums.push_back(pos[0]);
    // maxDif = maxDif / (s-1);
    // for(int i = 1; i <= s-2; i++) {
    //     numero = *lower_bound(pos.begin(), pos.end(), maxDif*i);
    //     nums.push_back(numero);

    //     // minDif = numero - pos[0];
    //     // if(minDif > pos[pos.size()-1] - numero) minDif = pos[pos.size()-1] - numero;
    // }
    // nums.push_back(pos[pos.size()-1]);
    // for(int i = 0; i < nums.size()-1; i++) {
    //     if(i == 0) minDif = nums[i+1] - nums[i];
    //     else {
    //         if(minDif > nums[i+1] - nums[i]) minDif = nums[i+1] - nums[i];
    //     }
    // }
    // cout << minDif << '\n';

    int n, s, minimaDif, lastNumer;
    cin >> n >> s;
    vector<int> pos(n);
    vector<int>::iterator itr;
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    // cout << "-----------------------------" << '\n' << '\n' << '{';
    // for(int i = 0; i < pos.size(); i++) {
    //     cout << pos[i] << ", ";
    // }
    // cout << '}' << '\n' << '\n' << "-----------------------------" << '\n';

    int rango = pos[pos.size()-1] - pos[0];
    for(int i = 0; i < s; i++) {
        int num = ((i*rango)/(s-1))+pos[0], dif;
        itr = lower_bound(pos.begin(), pos.end(), num);
        if(i != 0){
            if(itr != pos.end()) {
                dif = *itr - num;
                if(dif > num - *(itr - 1)){
                    if(i == 1) minimaDif = *(itr - 1) - lastNumer;
                    else {
                        if(minimaDif > *(itr - 1) - lastNumer) minimaDif = *(itr - 1) - lastNumer;
                    }
                    lastNumer = *(itr - 1);
                }
                else{
                    if(i == 1) minimaDif = *(itr) - lastNumer;
                    else {
                        if(minimaDif > *(itr) - lastNumer) minimaDif = *(itr) - lastNumer;
                    }
                    lastNumer = *(itr);
                }
            }
        }
        else {
            lastNumer = pos[0];
        }
    }
    cout << minimaDif << '\n';

    return 0;
}