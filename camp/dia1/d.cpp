// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     int n, max, min, p;
//     string op , res;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> op >> p >> res;
//         if(op == ">="){
//             if(res == "Y"){
//                 if(i==0 || min<p) min = p;
//             }
//             else{
//                 if(i==0 || max>p) max = p-1;
//             }
//         }
//         else if(op == "<="){
//             if(res == "Y"){
//                 if(i==0 || max>p) max = p;
//             }
//             else{
//                 if(i==0 || min<p) min = p+1;
//             }
//         }
//         else if(op == ">"){
//             if(res == "Y"){
//                 if(i==0 || min<p) min = p+1;
//             }
//             else{
//                 if(i==0 || max>p) max = p;
//             }
//         }
//         else if(op == "<"){
//             if(res == "Y"){
//                 if(i==0 || max>p) max = p;
//             }
//             else{
//                 if(i==0 || min<p) min = p+1;
//             }
//         }

//     }
//     if(max<min) cout << "Impossible\n";
//     else cout << min << '\n';
    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    string op, res;
    long long bot=-2*1000000000, top=2*1000000000;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> op >> x >> res;
        if(op == ">") (res=="Y" ? (bot<x+1 ? bot=x+1 : 1+1) : (top>x ? top=x : 1+1));
        else if(op == "<") (res=="Y" ? (top>x-1 ? top=x-1 : 1+1) : (bot<x ? bot=x : 1+1));
        else if(op == ">=") (res=="Y" ? (bot<x ? bot=x : 1+1) : (top>x-1 ? top=x-1 : 1+1));
        else if(op == "<=") (res=="Y" ? (top>x ? top=x : 1+1) : (bot<x+1 ? bot=x+1 : 1+1));
    }
    if(bot > top) cout << "Impossible\n";
    else if(-2*1000000000 <= bot && bot <= 2*1000000000) cout << bot << '\n';
    else if(-2*1000000000 <= top && top <= 2*1000000000) cout << top << '\n';
    else cout << "Impossible\n";
    return 0;
}