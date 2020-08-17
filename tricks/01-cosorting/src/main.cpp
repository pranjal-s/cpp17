// A simple program thet prints "Hello World!" to the standard output

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
     cout << "Hello World!" << endl;

    int jnum = 5;
    int jlist[jnum] = {52, 3, 17, 1023, 74};
    double jlistrsq[jnum] = {100.56, 200, 25.77, 498.65, 125};

    std::vector<float> A(jlistrsq,jlistrsq+jnum);
    std::vector<int> B(jlist,jlist+jnum);
    std::vector<int> C(jlist,jlist+jnum);
    
    std::vector<int> V(A.size());
    int x=0;
    std::iota(V.begin(),V.end(),x++); //Initializing
    std::sort( V.begin(),V.end(), [&](int g,int h){return A[g]<A[h];} );
    for(int f=0;f<A.size();f++)
        C[f]=B[V[f]];
    
    std::copy(C.begin(), C.end(), jlist);

    std::cout << "A (jlistrsq) = {";
    for(int i=0;i<A.size();i++)
        std::cout << A[i] << ',';
    std::cout << "\b}\n";

    std::cout << "B (jlist) = {";
    for(int i=0;i<A.size();i++)
        std::cout << B[i] << ',';
    std::cout << "\b}\n";

    std::cout << "V (jlistrsq sorting indices) = {";
    for(int i=0;i<A.size();i++)
        std::cout << V[i] << ',';
    std::cout << "\b}\n";

    std::cout << "Asorted (sorted jlistrsq) = {";
    for(int i=0;i<A.size();i++)
        std::cout << A[V[i]] << ',';
    std::cout << "\b}\n";


    for(int i=0;i<A.size();i++)
        C[i]=B[V[i]];

    std::cout << "C (B sorted like A) = {";
    for(int i=0;i<A.size();i++)
        std::cout << C[i] << ',';
    std::cout << "\b}\n";

    std::cout << "Final jlist sorted = {";
    for(int i=0;i<jnum;i++)
        std::cout << jlist[i] << ',';
    std::cout << "\b}\n";

     return 0;
}
