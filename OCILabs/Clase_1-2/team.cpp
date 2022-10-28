#include <iostream>
using namespace std;

int main(){
    int numeroProblemas, resolver=0;
    bool amigas[3]= {0};
    cin >> numeroProblemas;

    for(int i=0; i<numeroProblemas; i++){
        for(int j=0; j<3; j++){
            cin >> amigas[j];
        }
        if(amigas[0] && (amigas[1] || amigas[2]) || (amigas[1] && amigas[2])){
            resolver++;
        }
    }
    cout << resolver;

    return 0;
}