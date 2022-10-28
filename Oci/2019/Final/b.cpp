//Cubos
#include <iostream>
#include <vector>
using namespace std;

int main(){
    bool flag = false;
    vector<int> cubo1(6,-1);
    vector<int> cubo2(6,-1);//        1           2           3           4           5           6
    vector<vector<int>> vesinos={{6,5,4,3,2},{3,4,5,6,1},{1,4,2,6,5},{1,5,2,3,6},{1,6,2,4,3},{1,3,2,5,4}};
    for(int i = 0; i < 12; i++){
        if(i<6) cin >> cubo1[i];
        else cin >> cubo2[i-6];
    }
    for(int i = 0; i < 6 && !flag; i++){
        if(cubo1[0] == cubo2[i]){
            for(int k = 0; k < 4; k++){
                if(cubo1[(vesinos[0][0]-1)] == cubo2[vesinos[i][k]-1]){
                    flag = true;
                    for(int j = 1; j <= 3; j++){
                        int corrector = 0;
                        if(k+j >= 4) corrector = 4;
                        if(cubo1[(vesinos[0][j]-1)] != cubo2[vesinos[i][k+j-corrector]-1]){
                            j = 4;
                            flag = false;
                        }
                        else if(j==3){
                            k = 4;
                        }
                    }
                }
            }
        }
        if(flag){
            if(cubo1[vesinos[0][4]-1] != cubo2[vesinos[i][4]-1]) flag = false;
        }
    }
    cout << flag << '\n';
    return 0;
}