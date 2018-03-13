#include "RandomMatrixHash.h"
#include "gtest/gtest.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h> 
using testing::Test;

#define NUM_TEST_CASES 100000
#define TABLE_SLOTS 256
#define ERROR_THRESHOLD .01

// Sanity check for entries in the random matrix.
// Create NUM_TEST_CASES random matrices, 
// then use EXPECT_NEAR(x, y, threshold) where
// threshold = ERROR_THRESHOLD to verify that each entry
// of the matrix is 1 with probability 1/2
TEST(RandomMatrixSanityCheck, EachBitFieldUniformlyGenerated) {
    double sum = 0;
    for (int i = 0; i < NUM_TEST_CASES; i++)
    {
        RandomMatrixHash r(TABLE_SLOTS);
        sum += r.get1ratio();
    }
    EXPECT_NEAR((double)sum / NUM_TEST_CASES, (double)1/2, ERROR_THRESHOLD);
}

// Sanity check for distribution of keys in the table.
// Create NUM_TEST_CASES integer keys and, for each slot in the table,
// count the number of times a key hashes to that slot. You can randomly
// generate the integer keys but I used 0, 1, ..., NUM_TEST_CASES.
// Then verify that hashing to each slot in the table is roughly equally
// likely using EXPECT_NEAR(x, y, threshold) where threshold = ERROR_THRESHOLD
TEST(RandomMatrixSanityCheck, SimpleUniformHashingAssumption) {
    std::unordered_map<int, int> M;
    std::vector<int> occur;
    RandomMatrixHash r(TABLE_SLOTS);
    int sum = 0;
    //hash these values
    for (int i = 0; i < NUM_TEST_CASES; i++)
    {
        //first occurence
        if (M.find(r.Hash(i)) == M.end())
            M[r.Hash(i)] = 1;
        else
            M[r.Hash(i)]++;
    }

    //put occurence into a vector
    for (std::pair<int,int> element : M)
    {
        //std::cout << element.second << std::endl;
        occur.push_back(element.second);
        sum += element.second;
    }

    /*
     * then valculate variance 
     * occurence of 390 and 391 are considered right
     * because NUM_TEST_CASES / TABLE_SLOTS = 390.625
     * assume the fluctuation is between 2
     * which is between 389 and 392 is accepted
     */
    double mean = (double) sum / occur.size(), var = 0;
    for (double i : occur)
    {
        var += abs(i - mean) < 2 ? 0 : pow(i - mean, 2);
    }
    var /= occur.size();
    EXPECT_NEAR(var, 0, ERROR_THRESHOLD);
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}