#include<iostream>
using namespace std;

int fib(int n){
    if (n == 0) {
        return 1;
    }
    if (n == 1){
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n = 0, fibn = 0, sum = 0;
    while (fibn < 4000000) {
        fibn = fib(n);
        if (fibn%2==0){
            sum+=fibn;
        }
        ++n;
    }
    cout << sum;
    return 0;
}