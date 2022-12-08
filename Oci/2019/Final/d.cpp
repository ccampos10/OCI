//templo
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n, k, j, y, x;
    int turno = 0;
    bool vive = true, flag = false;
    cin >> m >> n >> k;
    vector<vector<int>> plano(m,vector<int>(n,0));
    vector<vector<int>> rocas; //supongo que estan ordenadas por turno
    vector<pair<int, int>> pDoctora = {pair<int, int>(0,0)};
    vector<pair<int,int>> eliminar;
    plano[0][0] = 1; //la doctora
    for(int i = 0; i < k; i++){
        cin >> j >> y >> x;
        rocas.push_back({j,y-1,x-1});
    }

    while(vive && !flag){
        turno++;
        //primera fase
        for(int i = 0; i < rocas.size(); i++){
            if(rocas[i][0] == turno){
                if(plano[rocas[i][1]][rocas[i][2]] == 1) eliminar.push_back(pair<int,int>(rocas[i][1],rocas[i][2]));
                plano[rocas[i][1]][rocas[i][2]] = 3; //una roca
                //comprovar si donde cae la roca esta la doctora!!!!!!!!!
            }
            else if(rocas[i][0] > turno) break;
        }
        //segunda fase
        int size = pDoctora.size();
        if(size == 0) vive = false;
        for(int i = 0; i < size; i++){
            for(int h = 0; h < eliminar.size(); h++){
                if(eliminar[h].first == pDoctora[i].first && eliminar[h].second == pDoctora[i].second){
                    i++;
                    eliminar.erase(eliminar.begin()+h);
                    break;
                }
            }
            if(i >= size) break;
            pair<int,int> nuevaPos = pDoctora[i];
            nuevaPos.first--;
            if(nuevaPos.first >= 0 && plano[nuevaPos.first][nuevaPos.second] == 0){
                pDoctora.push_back(nuevaPos);
                plano[nuevaPos.first][nuevaPos.second] = 1;
                if(nuevaPos.first == m-1 && nuevaPos.second == n-1) flag = true;// llegue
            }
            nuevaPos.first++;
            nuevaPos.first++;
            if(nuevaPos.first < m && plano[nuevaPos.first][nuevaPos.second] == 0){
                pDoctora.push_back(nuevaPos);
                plano[nuevaPos.first][nuevaPos.second] = 1;
                if(nuevaPos.first == m-1 && nuevaPos.second == n-1) flag = true;// llegue
            }
            nuevaPos.first--;
            nuevaPos.second++;
            if(nuevaPos.second < n && plano[nuevaPos.first][nuevaPos.second] == 0){
                pDoctora.push_back(nuevaPos);
                plano[nuevaPos.first][nuevaPos.second] = 1;
                if(nuevaPos.first == m-1 && nuevaPos.second == n-1) flag = true;// llegue
            }
            nuevaPos.second--;
            nuevaPos.second--;
            if(nuevaPos.second >=0 && plano[nuevaPos.first][nuevaPos.second] == 0){
                pDoctora.push_back(nuevaPos);
                plano[nuevaPos.first][nuevaPos.second] = 1;
                if(nuevaPos.first == m-1 && nuevaPos.second == n-1) flag = true;// llegue
            }
            plano[pDoctora[i].first][pDoctora[i].second] = 2;// ya pase
        }
        for(int i = 0; i < size; i++) pDoctora.erase(pDoctora.begin());
    }

    cout << vive << '\n';

    return 0;
}