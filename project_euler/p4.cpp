#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int lp = 10001, lp2;
    string lps = to_string(lp), lps2;
    string spl(lps), spl2;
    reverse(spl.begin(),spl.end());

    for (int i = 100; i < 999; i++) {
        for (int j = 100; j < 999; j++) {
            lp2 = i*j;
            lps2 = to_string(lp2);
            spl2 = lps2;
            reverse(spl2.begin(),spl2.end());

            if (lps2==spl2 && lp2>lp) {lp=lp2;}
        }
    }

    cout << lp;
    
    return 0;
}