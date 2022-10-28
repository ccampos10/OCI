#include <iostream>
using namespace std;

int main(){
    int tamanoPlataformas, pocision=0;
    cin >> tamanoPlataformas;

    int Plataformas[tamanoPlataformas] = {0};
    for(int i = 0; i < tamanoPlataformas; i++){
        cin >> Plataformas[i];
        if(i!=0){
            if((Plataformas[i] > Plataformas[pocision]) && (i-1 == pocision)){
                pocision = i;
            }
        }
    }
    cout << Plataformas[pocision];
    

    return 0;
}