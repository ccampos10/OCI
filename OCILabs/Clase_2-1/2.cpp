#include <iostream>
using namespace std;

int fib(int n){
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else if(n%2 == 0){
        return fib(n/2) + fib(n/3);
    }
    else{
        return (fib(n-1) + fib(n-2));
    }
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << '\n';
    return 0;
}