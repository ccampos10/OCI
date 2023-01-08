#include <bits/stdc++.h>
using namespace std;

int formula(int x, int d) {
    int result = x + ((d+x)/(x+1));
    return result;
}

int main(){
    // primera solucion
    // int t, n, d, resultado;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
    //     cin >> n >> d;
    //     if (d<=n)
    //     {
    //         cout << "yes\n";
    //     }
    //     else {
    //         int x=n/2;
    //         while (x+((d+x)/(x+1))>n && x>1)
    //         {
    //             x=x/2;
    //             if(x<x/2.0) x++;
    //         }
    //         if(x+((d+x)/(x+1))>n) cout << "no\n";
    //         else cout << "yes\n";

    //     }
    // }

    // segunda solucions
    int t, n , d;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> d;
        if(d<=n) cout << "yes\n";
        else{
            int bot=0, top=d, mid = 1;
            while(bot < top && mid!=bot && mid!=top){
                mid = (bot+top)/2;
                if(formula(mid, d) <= n) break;
                else if(formula(mid, d) > formula(mid+1,d)) bot=mid+1;
                else top=mid-1;
            }
            if(formula(mid, d) <= n) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}