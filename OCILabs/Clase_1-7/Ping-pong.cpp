#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p;
  int rP, rS;
  int pP = 0, pS = 0;
  int ganador = -1;
  cin >> n >> p;
  cin >> rP >>rS;
  if (true){
    bool primero;
    if(p==1) primero = true;
    else primero = false;
    while(ganador == -1){
      if(primero){
        for(int i = 0; i<rP; i++){
          pP++;
          if(pP>=n){
            ganador = 1;
            break;
          }
        }
        if(ganador == -1) pS++;
        if(pS >= n){
          ganador = 2;
          break;
        }
      }
      else {
        for(int i = 0; i<rS; i++){
          pS++;
          if(pS>=n){
            ganador = 2;
            break;
          }
        }
        if(ganador == -1) pP++;
        if(pP >= n){
          ganador = 1;
          break;
        }
      }
      primero = !primero;
      
    }
    cout << ganador << '\n';
  }
  return 0;
}