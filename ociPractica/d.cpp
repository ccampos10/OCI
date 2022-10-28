#include <iostream>
#include <vector>
using namespace std;
vector<vector<pair<pair<int, int>, int>>> tablero(8,vector<pair<pair<int, int>, int>>(8,pair<pair<int, int>, int>(pair<int,int>(-1,-1),0)));
//matrix 8 X 8 de pares, piesa(tipo,equipo) y si esta bajo ataque

void imTablero(){
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            cout << "((" << tablero[y][x].first.first << ", " << tablero[y][x].first.second << "), " << tablero[y][x].second << ") ";
        }
        cout << endl;
    }
}

void putPiesa(int c, int p, int y, int x){
    tablero[y][x] = pair<pair<int, int>, int>(pair<int, int>(p,c),0);

    //ataque
    //torre
    if(p==0){
        //vertical
        bool flag = false;
        for(int Ly = y-1; Ly >= 0 && !flag; Ly--){
            if(tablero[Ly][x].first.first != -1) flag = true;
            if(c == 0 && tablero[Ly][x].second == 2) tablero[Ly][x].second = 3;
            else if(c == 1 && tablero[Ly][x].second == 1) tablero[Ly][x].second = 3;
            else if(tablero[Ly][x].second == 0) tablero[Ly][x].second = c+1;
        }
        flag = false;
        for(int Ly = y+1; Ly < 8 && !flag; Ly++){
            if(tablero[Ly][x].first.first != -1) flag = true;
            if(c == 0 && tablero[Ly][x].second == 2) tablero[Ly][x].second = 3;
            else if(c == 1 && tablero[Ly][x].second == 1) tablero[Ly][x].second = 3;
            else if(tablero[Ly][x].second == 0) tablero[Ly][x].second = c+1;
        }//horizontal
        flag = false;
        for(int Lx = x-1; Lx >= 0 && !flag; Lx--){
            if(tablero[y][Lx].first.first != -1) flag = true;
            if(c == 0 && tablero[y][Lx].second == 2) tablero[y][Lx].second = 3;
            else if(c == 1 && tablero[y][Lx].second == 1) tablero[y][Lx].second = 3;
            else if(tablero[y][Lx].second == 0) tablero[y][Lx].second = c+1;
        }
        flag = false;
        for(int Lx = y+1; Lx < 8 && !flag; Lx++){
            if(tablero[y][Lx].first.first != -1) flag = true;
            if(c == 0 && tablero[y][Lx].second == 2) tablero[y][Lx].second = 3;
            else if(c == 1 && tablero[y][Lx].second == 1) tablero[y][Lx].second = 3;
            else if(tablero[y][Lx].second == 0) tablero[y][Lx].second = c+1;
        }
    }
    else if(p==1){
        //arriba
        int x1=x-1, x2=x+1;
        bool flag1 = false, flag2 = false;
        for(int Ly = y-1; Ly >= 0 && !(x1 < 0 && x2 >= 8) && !(flag1 && flag2); Ly--){
            //x-
            if(x1 >= 0 && !flag1){
                if(tablero[Ly][x1].first.first != -1) flag1 = true;
                if(c == 0 && tablero[Ly][x1].second == 2) tablero[Ly][x1].second = 3;
                else if(c == 1 && tablero[Ly][x1].second == 1) tablero[Ly][x1].second = 3;
                else if(tablero[Ly][x1].second == 0) tablero[Ly][x1].second = c+1;
            }
            //x+
            if(x2 < 8 && !flag2){
                if(tablero[Ly][x2].first.first != -1) flag2 = true;
                if(c == 0 && tablero[Ly][x2].second == 2) tablero[Ly][x2].second = 3;
                else if(c == 1 && tablero[Ly][x2].second == 1) tablero[Ly][x2].second = 3;
                else if(tablero[Ly][x2].second == 0) tablero[Ly][x2].second = c+1;
            }
            x1--;
            x2++;
        }
        //abajo
        x1=x-1;
        x2=x+1;
        flag1 = false;
        flag2 = false;
        for(int Ly = y+1; Ly < 8 && !(x1 < 0 && x2 >= 8) && !(flag1 && flag2); Ly++){
            //x-
            if(x1 >= 0 && !flag1){
                if(tablero[Ly][x1].first.first != -1) flag1 = true;
                if(c == 0 && tablero[Ly][x1].second == 2) tablero[Ly][x1].second == 3;
                else if(c == 1 && tablero[Ly][x1].second == 1) tablero[Ly][x1].second == 3;
                else if(tablero[Ly][x1].second == 0) tablero[Ly][x1].second == c+1;
            }
            //x+
            if(x2 < 8 && !flag2){
                if(tablero[Ly][x2].first.first != -1) flag2 = true;
                if(c == 0 && tablero[Ly][x2].second == 2) tablero[Ly][x2].second == 3;
                else if(c == 1 && tablero[Ly][x2].second == 1) tablero[Ly][x2].second == 3;
                else if(tablero[Ly][x2].second == 0) tablero[Ly][x2].second == c+1;
            }
            x1--;
            x2++;
        }
    }
    else if(p==2){
        int x1=x-1, x2=x+1;
        bool flag1=false, flag2=false, flag3=false;
        for(int Ly = y-1; Ly >= 0 && !(x1 < 0 && x2 >= 8) && !(flag1 && flag2 && flag3); Ly--){
            if(!flag1){
                if(tablero[Ly][x].first.first != -1) flag1 = true;
                if(c == 0 && tablero[Ly][x].second == 2) tablero[Ly][x].second = 3;
                else if(c == 1 && tablero[Ly][x].second == 1) tablero[Ly][x].second = 3;
                else if(tablero[Ly][x].second == 0) tablero[Ly][x].second = c+1;
            }
            if(x1 >= 0 && !flag2){
                if(tablero[Ly][x1].first.first != -1) flag2 = true;
                if(c == 0 && tablero[Ly][x1].second == 2) tablero[Ly][x1].second = 3;
                else if(c == 1 && tablero[Ly][x1].second == 1) tablero[Ly][x1].second = 3;
                else if(tablero[Ly][x1].second == 0) tablero[Ly][x1].second = c+1;
            }
            if(x2 < 8 && !flag3){
                if(tablero[Ly][x2].first.first != -1) flag3 = true;
                if(c == 0 && tablero[Ly][x2].second == 2) tablero[Ly][x2].second = 3;
                else if(c == 1 && tablero[Ly][x2].second == 1) tablero[Ly][x2].second = 3;
                else if(tablero[Ly][x2].second == 0) tablero[Ly][x2].second = c+1;
                x1--;
                x2++;
            }
        }
        x1 = x-1;
        x2 = x+1;
        flag1 = false;
        flag2 = false;
        flag3 = false;
        for(int Ly = y+1; Ly < 8 && !(x1 < 0 && x2 >= 8) && !(flag1 && flag2 && flag3); Ly++){
            if(!flag1){
                if(tablero[Ly][x].first.first != -1) flag1 = true;
                if(c == 0 && tablero[Ly][x].second == 2) tablero[Ly][x].second = 3;
                else if(c == 1 && tablero[Ly][x].second == 1) tablero[Ly][x].second = 3;
                else if(tablero[Ly][x].second == 0) tablero[Ly][x].second = c+1;
            }
            if(x1 >= 0 && !flag2){
                if(tablero[Ly][x1].first.first != -1) flag2 = true;
                if(c == 0 && tablero[Ly][x1].second == 2) tablero[Ly][x1].second = 3;
                else if(c == 1 && tablero[Ly][x1].second == 1) tablero[Ly][x1].second = 3;
                else if(tablero[Ly][x1].second == 0) tablero[Ly][x1].second = c+1;
            }
            if(x2 < 8 && !flag3){
                if(tablero[Ly][x2].first.first != -1) flag3 = true;
                if(c == 0 && tablero[Ly][x2].second == 2) tablero[Ly][x2].second = 3;
                else if(c == 1 && tablero[Ly][x2].second == 1) tablero[Ly][x2].second = 3;
                else if(tablero[Ly][x2].second == 0) tablero[Ly][x2].second = c+1;
                x1--;
                x2++;
            }
        }
    }
    else if(p==3){
        for(int Ly = y-1; Ly <= y+1; Ly++){
            for(int Lx = x-1; Lx <= x+1; Lx++){
                if(Ly >= 0 && Ly < 8 && Lx >= 0 && Lx < 8 && tablero[Ly][Lx].first.first == -1){
                    if(c == 0 && tablero[Ly][Lx].second == 2) tablero[Ly][Lx].second = 3;
                    else if(c == 1 && tablero[Ly][Lx].second == 1) tablero[Ly][Lx].second = 3;
                    else if(tablero[Ly][Lx].second == 0) tablero[Ly][Lx].second = c+1;
                }
            }
        }
    }
    else if(p==4){}
    else if(p==5){}
    cout << "R-----" << endl;
    imTablero();
}

int main(){
    int n, c, p, y, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c >> p >> y >> x;
        putPiesa(c, p, y, x);
    }
    cout << "Final" << endl;
    imTablero();
    return 0;
}