#ifndef _BLOOM_FILTER_H_
#define _BLOOM_FILTER_H_
#include <cstddef>
#include <set>
class BloomFilter {
 public:
  BloomFilter(size_t bits, size_t expectedSetSize);
  void Insert(int x);
  void Insert(std::set<int> S);
  bool Query(int x);

 private:
};  // BloomFilter

#endif  // _BLOOM_FILTER_H_