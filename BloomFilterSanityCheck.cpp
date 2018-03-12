#include "BloomFilter.h"
#include "gtest/gtest.h"

using testing::Test;

#define NUM_TEST_CASES 10000000
#define SET_SIZE 10000
#define FILTER_SIZE 8 * SET_SIZE
#define ERROR_THRESHOLD .001
#define FALSE_POSITIVE_RATE_TARGET .0047

// Sanity check for no false negatives.
// Initialize your bloom filter to have FILTER_SIZE bits.
// Add SET_SIZE elements to both a bloom filter and
// to an STL data structure (I used a vector).
// Then check that every element inserted returns "true"
// when Query is called.
TEST(BloomFilterSanityCheck, NoFalseNegatives) {
}

// Sanity check for false positive rate.
// Initialize your bloom filter to have FILTER_SIZE bits.
// Add SET_SIZE elements to the bloom filter 
TEST(BloomFilterSanityCheck, FalsePositiveRate) {
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}