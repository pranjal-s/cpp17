#include<iostream>
using namespace std;

#define MAX_PRIME 10001

int main() {
    int prm[MAX_PRIME];
    int i = 2;
    prm[0] = i;
    int len = 1;
    int sum;
    while (len < MAX_PRIME) {
        sum = 0;
        for (size_t j = 0; j < len; j++) {
            if (i%prm[j]==0) {sum++;}
        }
        if (sum==0) {
            prm[len]=i;
            len++;
        }
        i++;
    }

    // for (size_t i = 0; i < len; i++) {cout << prm[i] << " ";}
    cout << prm[MAX_PRIME-1];

    return 0;
}