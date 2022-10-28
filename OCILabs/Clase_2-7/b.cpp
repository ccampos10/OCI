#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<pair<char, int>> conteo;

int main() {
  string text;
  int max = -1;
  pair<char, int> letra;
  cin >> text;
  letra = pair<char, int>(text[0], 1);
  for(int i = 1; i < text.length(); i++){
    if(letra.first == text[i]){
      letra.second++;
    }
    else {
      if(letra.second > max) max = letra.second;
      letra.first = text[i];
      letra.second = 1;
    }
  }
  if(letra.second > max) max = letra.second;
  cout << max << '\n';
  return 0;
}