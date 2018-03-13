#ifndef _BLOOM_FILTER_H_
#define _BLOOM_FILTER_H_
#include <cstddef>
#include <set>
#include <math.h>
#include <string>
#include "RandomMatrixHash.h"
#include <vector>
class BloomFilter
{
  public:
    BloomFilter(size_t bits, size_t expectedSetSize);
    void Insert(int x);
    void Insert(std::set<int> S);
    bool Query(int x);
    std::string str() const;

  private:
    int size, k;
    RandomMatrixHash **hashes;
    std::vector<int> *table;
}; // BloomFilter

#endif // _BLOOM_FILTER_H_