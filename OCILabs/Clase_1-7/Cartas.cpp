#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main() {
  int n, q, numero;
  stack <int> mazo;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> numero;
    mazo.push(numero);
  }
  for(int i = 0; i < q; i++){
    cin >> numero;
    for(int j = 0; j < numero; j++){
      cout << mazo.top() << " ";
      mazo.pop();
    }
    cout << "\n";
  }
  return 0;
}