//Hamburgers
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<char, int> receta;
    string rec;
    int nb,ns,nc;
    int pb,ps,pc;
    long long int r;
    long long int cantidad=0;
    cin >> rec;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    receta.insert(pair<char,int>('B',0));
    receta.insert(pair<char,int>('S',0));
    receta.insert(pair<char,int>('C',0));

    for(int i = 0; i < rec.length(); i++){
        // if(receta.find(rec[i]) == receta.end()){
        //     receta.insert(pair<char, int>(rec[i], 1));
        // }
        receta.find(rec[i])->second++;
    }

    int temp;
    if(receta.find('B')->second!=0 && receta.find('S')->second!=0 && receta.find('C')->second!=0){
        temp = nb / (int)(receta.find('B')->second);
        if(((int)ns / (receta.find('S')->second)) < temp) temp = (int)ns / (receta.find('S')->second);
        if(((int)nc / (receta.find('C')->second)) < temp) temp = (int)nc / (receta.find('C')->second);
        nb = nb - (receta.find('B')->second * temp);
        ns = ns - (receta.find('S')->second * temp);
        nc = nc - (receta.find('C')->second * temp);
        cantidad += temp;
    }

    bool flag = true;
    bool flag2 = false;

    while(flag && r!=0)
    {
        int tr=0;
        bool tb=false, ts=false, tc=false;
        if(receta.find('B')->second > nb){
            tr += (receta.find('B')->second - nb)*pb;
            tb = true;
        }
        if(receta.find('S')->second > ns){
            tr += (receta.find('S')->second - ns)*ps;
            ts = true;
        }
        if(receta.find('C')->second > nc){
            tr += (receta.find('C')->second - nc)*pc;
            tc = true;
        }
        if(tr <= r){
            r -= tr;
            if(r==0) flag = false;
            if(tb) nb = 0;
            else nb -= receta.find('B')->second;
            if(ts) ns = 0;
            else ns -= receta.find('S')->second;
            if(tc) nc = 0;
            else nc -= receta.find('C')->second;
            cantidad++;
        }
        else flag = false;
        if(flag && nb == 0 && ns == 0 && nc == 0){
            flag = false;
            flag2 = true;
        }
    }

    if(flag2){
        long long int total = pb + ps + pc;
        cantidad += (long long int)r/total;
    }

    cout << cantidad << '\n';

    return 0;
}