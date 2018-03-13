#ifndef _RANDOM_MATRIX_HASH_H_
#define _RANDOM_MATRIX_HASH_H_

#include <cstddef>

class RandomMatrixHash {
 public:
  RandomMatrixHash(unsigned int m);
  size_t Hash(int key) const;
  double get1ratio() const;

 private:
    int row, *HashMatrix;
}; // RandomMatrixHash

#endif  // _RANDOM_MATRIX_HASH_H_