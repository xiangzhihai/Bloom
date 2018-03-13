#include "RandomMatrixHash.h"
#include <limits>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//m shoud be 2^n 0 <= n
RandomMatrixHash::RandomMatrixHash(unsigned int m) 
{
    row = 0;
    //calculate how many bits need to represent m
    while (m >>= 1)
        row++;
    
    //this can only used in linux which RANDMAX is INT_MAX
    srand(time(NULL));
    vector<int> r;
    for (int i = 0; i < row * 16; i++)
    {
        r.push_back(0);
        r.push_back(1);
    }
    random_shuffle(r.begin(), r.end());
    HashMatrix = (int*)malloc(row * sizeof(int));

    
    for (int i = 0; i < row; i++)
    {
        int num = 0;
        for (int j = 0; j < 32; j++)
        {
            num <<= 1;
            num |= r[i * 32 + j];
            
        }
        HashMatrix[i] = num;
    }
}

bool parity(unsigned int x)
{
    unsigned int count = 0, b = 1;

    for(int i = 0; i < 32; i++)
        if(x & (b << i)) 
            count++;
    
    if(count % 2)
        return false;

    return true;
}

double RandomMatrixHash::get1ratio() const 
{
    int count = 0, b = 1;
    for (int i = 0; i < row; i++)
    {
        int t = HashMatrix[i];
        for (int j = 0; j < 32; j++)
        {
            if (HashMatrix[i] & (b << j))
            {
                count++;
            }  
        }
    }
    return (double) count / (32 * row);
}

// Use mod 2 matrix multiplication for your hash function.
size_t RandomMatrixHash::Hash(int key) const 
{
    int hash = 0;
    for (int i = 0; i < row; i++)
    {
        hash <<= 1;
        hash |= parity(key & HashMatrix[i]);
    }
    return hash;
}
/*
int main()
{
    RandomMatrixHash r(256);
    cout << r.Hash(16) << endl;
    cout << r.get1ratio() << endl;
}
*/