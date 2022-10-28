#include <iostream>
using namespace std;

void algo(long int n){
  if(n != 1){
    cout << n << " ";
    if(n%2 == 0){
      algo(n/2);
    }
    else algo((n*3)+1);
  }
  else cout << n << "\n";
}

int main() {
  long int n;
  cin >> n;
  algo(n);
  return 0;
}