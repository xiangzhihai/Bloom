#include "RandomMatrixHash.h"
#include "gtest/gtest.h"

using testing::Test;

#define NUM_TEST_CASES 100000
#define TABLE_SLOTS 256
#define ERROR_THRESHOLD .001

// Sanity check for entries in the random matrix.
// Create NUM_TEST_CASES random matrices, 
// then use EXPECT_NEAR(x, y, threshold) where
// threshold = ERROR_THRESHOLD to verify that each entry
// of the matrix is 1 with probability 1/2
TEST(RandomMatrixSanityCheck, EachBitFieldUniformlyGenerated) {
}

// Sanity check for distribution of keys in the table.
// Create NUM_TEST_CASES integer keys and, for each slot in the table,
// count the number of times a key hashes to that slot. You can randomly
// generate the integer keys but I used 0, 1, ..., NUM_TEST_CASES.
// Then verify that hashing to each slot in the table is roughly equally
// likely using EXPECT_NEAR(x, y, threshold) where threshold = ERROR_THRESHOLD
TEST(RandomMatrixSanityCheck, SimpleUniformHashingAssumption) {
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}