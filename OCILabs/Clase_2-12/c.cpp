#include <iostream>
#include <string>
using namespace std;

int main(){
    int x, y, avitaciones = 0;
    string l, lA;
    cin >> x >> y;
    for(int i = 0; i < x; i++){
        cin >> l;
        if(i == 0){
            lA = l;
            bool racha=false;
            for(int j = 0; j < l.length(); j++){
                if(l[j] == '.' && !racha) {
                    avitaciones++;
                    racha = true;
                }
                else if(l[j] == '#' && racha) racha = false;
            }
        }
        else{
            bool racha=false, avC=false;
            for(int j = 0; j < l.length(); j++){
                // cout << l << " " << l.length() << " " << l[j] << " " << lA << " " << lA[j] << endl;
                if(l[j] == '.' && lA[j] == '#' && !racha){
                    avitaciones++;
                    avC=true;
                    racha = true;
                }
                else if(l[j] == '.' && lA[j] == '#' && racha){}
                else if(l[j] == '.' && lA[j] == '.' && !racha){
                    racha = true;
                }
                else if(l[j] == '.' && lA[j] == '.' && racha){
                    if(lA[i-1] == '#' && avC) avitaciones--;
                }
                else if(l[j] == '#' && !racha){}
                else if(l[j] == '#' && racha) {
                    racha = false;
                    avC = false;
                }
            }
            lA = l;
        }
    }
    cout << avitaciones << endl;
    return 0;
}