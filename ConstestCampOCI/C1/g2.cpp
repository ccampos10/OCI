//Hamburgers
#include <iostream>
#include <string>
using namespace std;
int inf = 2000000000;

int main(){
    string rec;
    int nb,ns,nc;
    int pb,ps,pc;
    long long int r;
    long long int cantidad=0;
    cin >> rec;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    int rb=0, rs=0, rc=0;

    for(int i = 0; i < rec.length(); i++){
        if(rec[i] == 'B') rb++;
        else if(rec[i] == 'S') rs++;
        else if(rec[i] == 'C') rc++;
    }

    int temp = inf;
    if(rb !=0) temp = nb / (int)(rb);
    if(rs !=0 && ((int)ns / (rs)) < temp) temp = (int)ns / (rs);
    if(rc !=0 && ((int)nc / (rc)) < temp) temp = (int)nc / (rc);
    nb = nb - (rb * temp);
    ns = ns - (rs * temp);
    nc = nc - (rc * temp);
    cantidad += temp;

    bool flag = true;
    bool flag2 = false;

    // while(flag && r!=0)
    // {
    //     int tr=0;
    //     bool tb=false, ts=false, tc=false;
    //     if(rb > nb){
    //         tr += (rb - nb)*pb;
    //         tb = true;
    //     }
    //     if(rs > ns){
    //         tr += (rs - ns)*ps;
    //         ts = true;
    //     }
    //     if(rc > nc){
    //         tr += (rc - nc)*pc;
    //         tc = true;
    //     }
    //     if(tr <= r){
    //         r -= tr;
    //         if(r==0) flag = false;
    //         if(tb) nb = 0;
    //         else nb -= rb;
    //         if(ts) ns = 0;
    //         else ns -= rs;
    //         if(tc) nc = 0;
    //         else nc -= rc;
    //         cantidad++;
    //     }
    //     else flag = false;
    //     if(flag && nb == 0 && ns == 0 && nc == 0){
    //         flag = false;
    //         flag2 = true;
    //     }
    // }

    // if(flag2){
    //     cantidad += (long long int)r/(pb*rb + ps*rs + pc*rc);
    // }
    int g1 = (pb*nb);
    int g2 = (ps*ns);
    int g3 = (pc*nc);
    if(rb==0) g1=0;
    if(rs==0) g2=0;
    if(rc==0) g3=0;
    cantidad += (long long int)(r+(g1 + g2 + g3))/(((pb*rb) + (ps*rs) + (pc*rc)));

    cout << cantidad << '\n';

    return 0;
}