#include "RandomMatrixHash.h"
#include <limits>
#include <stdlib.h>
#include <iostream>

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
    HashMatrix = (int*)malloc(row * sizeof(int));
    for (int i = 0; i < row; i++)
        HashMatrix[i] = rand() * (rand() % 2 ? 1 : -1);

}

bool parity(unsigned int x){
    unsigned int count = 0, i, b = 1;

    for(i = 0; i < 32; i++)
        if( x & (b << i) ) 
            count++;
    
    if(count % 2)
        return false;

    return true;
}

// Use mod 2 matrix multiplication for your hash function.
size_t RandomMatrixHash::Hash(int key) const {
    int hash = 0;
    for (int i = 0; i < row; i++)
    {
        hash <<= 1;
        hash |= parity(key & HashMatrix[i]);
    }
    return hash;
}


int main()
{
    RandomMatrixHash r(256);
    cout << endl << r.Hash(16) << endl;

}