#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> si;

int main(){
    queue<si> cola;
    map<string,int> p;
    set<string> nameMax;
    int n, t;
    string name;
    int max=-2000000000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> t;
        if(p.count(name) == 0){
            p.insert(si(name,t));
            cola.push(si(name,t));
        }
        else{
            p[name]+=t;
            cola.push(si(name,p[name]));
        }
        if(max < p[name]) {
            max=p[name];
            nameMax.clear();
            nameMax.insert(name);
        }
        else if(max == p[name]) nameMax.insert(name);
        else if(max == p[name]-t) {
            nameMax.extract(name);
            if(nameMax.size() == 0){
                set<string> nMax;
                max = -2000000000;
                for(auto element : p){
                    if(element.second > max){
                        nMax.clear();
                        nMax.insert(element.first);
                        max = element.second;
                    }
                    else if(element.second == max) nMax.insert(element.first);
                }
                nameMax=nMax;
            }
        }
    }

    // for(auto element : p){
    //     if(element.second > max) max=element.second;
    // }


    if(nameMax.size()==1) cout << *nameMax.begin() << '\n';
    else{
        for(int i = 0; i < n;i++){
            if(cola.front().second >= max && nameMax.count(cola.front().first)!=0) {
                cout << cola.front().first << '\n';
                break;
            }
            cola.pop();
        }
    }



    // while(!cola.empty()){
    //     if(cola.front().second >= max && p[cola.front().first] == max) {
    //         cout << cola.front().first << '\n';
    //         return 0;
    //         break;
    //     }
    //     cola.pop();
    // }
    return 0;
}