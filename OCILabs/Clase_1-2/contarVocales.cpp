#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);
    cout << frase;
    int vocales=0;
    for(int i = 0; i<frase.length(); i++){
        if (frase[i] == 'a' || frase[i] == 'A'){
            vocales++;
        }
        else if (frase[i] == 'e' || frase[i] == 'E'){
            vocales++;
        }
        else if (frase[i] == 'i' || frase[i] == 'I'){
            vocales++;
        }
        else if (frase[i] == 'o' || frase[i] == 'O'){
            vocales++;
        }
        else if (frase[i] == 'u' || frase[i] == 'U'){
            vocales++;
        }
    }
    cout << vocales;
    // string frase;
    // getline(cin, frase);
    // int vocales = 0, i=0;
    // while(i < frase.length()){
    //     if (frase[i] == 'a' || frase[i] == 'A'){
    //         vocales++;
    //     }
    //     else if (frase[i] == 'e' || frase[i] == 'E'){
    //         vocales++;
    //     }
    //     else if (frase[i] == 'i' || frase[i] == 'I'){
    //         vocales++;
    //     }
    //     else if (frase[i] == 'o' || frase[i] == 'O'){
    //         vocales++;
    //     }
    //     else if (frase[i] == 'u' || frase[i] == 'U'){
    //         vocales++;
    //     }
    //     i++;
    // }
    // cout << vocales;
    return 0;
}