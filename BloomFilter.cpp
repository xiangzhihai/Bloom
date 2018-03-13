#include "BloomFilter.h"
#include <iostream>

using namespace std;

// Initialize the bloom filter: compute k and create k hash functions
// using RandomMatrixHash
BloomFilter::BloomFilter(size_t bits, size_t expectedSetSize)
{
    //calculate k
    k = ceil((double)bits / expectedSetSize * log(2));

    hashes = (RandomMatrixHash **)malloc(k * sizeof(RandomMatrixHash*));
    //create hash functions
    size = pow(2, ceil(log2(bits)));
    for (int i = 0; i < k; i++)
        hashes[i] = new RandomMatrixHash(size);

    //create table for values
    table = new vector<int>(size);
}

// Insert x into the filter
void BloomFilter::Insert(int x)
{
    //get hash value, and set the entry in table to true
    for (int i = 0; i < k; i++)
        table->at(hashes[i]->Hash(x)) = 1;    
}

// Insert all of S into the filter
void BloomFilter::Insert(std::set<int> S)
{
    for (auto i : S)
        Insert(i);
}

// Check if x is in the set
bool BloomFilter::Query(int x)
{
    for (int i = 0; i < k; i++)
        if (table->at(hashes[i]->Hash(x)) == 0)
            return false;

    return true;
}

std::string BloomFilter::str() const
{
    return "a";
}
/*
int main()
{
    BloomFilter n(80000, 10000);
    n.Insert(123);
    cout << n.Query(123) << endl;
    cout << n.Query(321) << endl;
}
*/