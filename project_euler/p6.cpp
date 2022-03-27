#include<iostream>
using namespace std;

int main() {
    int a = 0, b = 0;
    for (size_t i = 1; i < 101; i++) {a+=i*i;}
    for (size_t i = 1; i < 101; i++) {b+=i;}
    b=b*b;
    cout << b-a;
    return 0;
}