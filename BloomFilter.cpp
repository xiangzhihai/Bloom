#include "BloomFilter.h"

// Initialize the bloom filter: compute k and create k hash functions
// using RandomMatrixHash
BloomFilter::BloomFilter(size_t bits, size_t expectedSetSize) {
}

// Insert x into the filter
void BloomFilter::Insert(int x) {
}

// Insert all of S into the filter
void BloomFilter::Insert(std::set<int> S) {
}

// Check if x is in the set
bool BloomFilter::Query(int x) {
}

std::string BloomFilter::str() const {
}