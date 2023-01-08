// #include <iostream>
// #include <deque>
// using namespace std;

// int main(){
//     deque<int> de;
//     deque<int> de2;
//     int n, m, A, B;
//     long long int a;
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a;
//         de.push_back(a);
//     }
//     de2=de;
//     for (int i = 0; i < m; i++)
//     {
//         de=de2;
//         cin >> a;
//         for (long long int i = 0; i < a; i++)
//         {
//             A = de.front();
//             de.pop_front();
//             B = de.front();
//             de.pop_front();
//             if (A>B)
//             {
//                 de.push_front(A);
//                 de.push_back(B);
//             }
//             else {
//                 de.push_front(B);
//                 de.push_back(A);
//             }
            
//         }
//         cout << A << ' ' << B << '\n';
        
//     }
    
    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    deque<int> deq;
    // deque<int> deq2;
    // deque<int> deq3; // para la iteracion -> t == deq.size() -> n
    // vector<deque<int>> deq3;
    ll t;
    int n,q;
    cin >> n >> q;
    deque<int> deq3[n+1];
    for(int i = 0; i < n; i++){
        cin >> t;
        deq.push_back(t);
    }
    deq3[1]=deq;
    for(int i = 0; i < q; i++){
        cin >> t;
        int A,B;
        if(n>t && !deq3[t].empty()) deq=deq3[t];
        else if(n<=t && !deq3[n].empty()) deq=deq3[n];
        else{
            for(ll j = 1; j <= t && j <= n; j++){
                if(j==n){
                    deq3[n]=deq;
                    break;
                }
                if(j==t) break;
                A = deq.front();
                deq.pop_front();
                B = deq.front();
                deq.pop_front();
                if (A>B)
                {
                    deq.push_front(A);
                    deq.push_back(B);
                }
                else {
                    deq.push_front(B);
                    deq.push_back(A);
                }
                if(deq3[j+1].empty()) deq3[j+1]=deq;
            }
        }
        
        if(n<t){
            A = deq.front();
            // deq.pop_front();
            B = deq[((t-n)%(n-1))+1];
            cout << A << ' ' << B << '\n';
        }
        else {
            A = deq.front();
            deq.pop_front();
            B = deq.front();
            deq.pop_front();
            cout << A << ' ' << B << '\n';
        }
        deq=deq3[1];
    }
    return 0;
}