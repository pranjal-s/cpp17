// A simple program that implements zip for co-sorting
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

// Fill the zipped vector with pairs consisting of the
// corresponding elements of a and b. (This assumes 
// that the vectors have equal length)
template <typename A, typename B>
void zip(
    const std::vector<A> &a, 
    const std::vector<B> &b, 
    std::vector<std::pair<A,B>> &zipped)
{
    for(size_t i=0; i<a.size(); ++i)
    {
        zipped.push_back(std::make_pair(a[i], b[i]));
    }
}

// Write the first and second element of the pairs in 
// the given zipped vector into a and b. (This assumes 
// that the vectors have equal length)
template <typename A, typename B>
void unzip(
    const std::vector<std::pair<A, B>> &zipped, 
    std::vector<A> &a, 
    std::vector<B> &b)
{
    for(size_t i=0; i<a.size(); i++)
    {
        a[i] = zipped[i].first;
        b[i] = zipped[i].second;
    }
}


int main(int argc, char* argv[])
{
    std::vector<std::string> names {"Karl", "Martin", "Paul", "Jennie"};
    std::vector<int> score {45, 5, 14, 24};

    // Zip the vectors together
    std::vector<std::pair<std::string,int>> zipped;
    zip(names, score, zipped);

    // Sort the vector of pairs
    std::sort(std::begin(zipped), std::end(zipped), 
        [&](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    // Write the sorted pairs back to the original vectors
    unzip(zipped, names, score);

    for(size_t i=0; i<names.size(); i++)
    {
        std::cout << names[i] << " : " << score[i] << std::endl;
    }
    return 0;
}
