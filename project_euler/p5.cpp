#include<iostream>
using namespace std;

int main() {
    bool alldiv = false;
    int x = 0;
    int sum;
    while (!alldiv) {
        x++;
        sum = 0;
        for (int i = 1; i < 21; i++) {
            if (x%i==0) {sum++;}
        }
        if (sum==20) {alldiv = true;}
    }
    cout << x;
    return 0;
}