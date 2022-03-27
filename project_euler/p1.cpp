#include<iostream>
using namespace std;

int main() {
    // Always optimize after the clean brute force. 
    // The super fast approach below doesn't give correct solution.
    
    // int i3 = 1000/3, i5 = 1000/5, i15 = 1000/15;
    // int sum = 3*i3*(i3+1)/2+5*i5*(i5+1)/2-15*i15*(i15+1)/2;

    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (i%3==0 || i%5==0){
            sum+=i;
        }
    }
    cout << sum << endl;

    return 0;
}