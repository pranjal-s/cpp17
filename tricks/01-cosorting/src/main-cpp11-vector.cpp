// A simple program thet prints "Hello World!" to the standard output

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
     cout << "Hello World!" << endl;

    vector<float> A = {2,4,3,1};
    vector<float> B = {1,2,3,4};

    //Assume A is a given vector with N elements
    vector<int> V(A.size());
    int x=0;
    iota(V.begin(),V.end(),x++); //Initializing
    sort( V.begin(),V.end(), [&](int i,int j){return A[i]<A[j];} );

    std::cout << "A = {";
    for(int i=0;i<A.size();i++)
        std::cout << A[i] << ',';
    std::cout << "\b}\n";

    std::cout << "B = {";
    for(int i=0;i<A.size();i++)
        std::cout << B[i] << ',';
    std::cout << "\b}\n";

    std::cout << "A's sorting indices = {";
    for(int i=0;i<A.size();i++)
        std::cout << V[i] << ',';
    std::cout << "\b}\n";

    std::cout << "Sorted A = {";
    for(int i=0;i<A.size();i++)
        std::cout << A[V[i]] << ',';
    std::cout << "\b}\n";

    std::cout << "B sorted like A = {";
    for(int i=0;i<A.size();i++)
        std::cout << B[V[i]] << ',';
    std::cout << "\b}\n";

     return 0;
}
