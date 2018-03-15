#include "BloomFilter.h"
#include "gtest/gtest.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
using testing::Test;
using namespace std;
#define NUM_TEST_CASES 10000000
#define SET_SIZE 10000
#define FILTER_SIZE 8 * SET_SIZE
#define ERROR_THRESHOLD .01
#define FALSE_POSITIVE_RATE_TARGET .0047

// Sanity check for no false negatives.
// Initialize your bloom filter to have FILTER_SIZE bits.
// Add SET_SIZE elements to both a bloom filter and
// to an STL data structure (I used a vector).
// Then check that every element inserted returns "true"
// when Query is called.
TEST(BloomFilterSanityCheck, NoFalseNegatives) {
    srand(time(NULL));
    BloomFilter n(FILTER_SIZE, SET_SIZE);
    vector<int> num;
    for (int i = 0; i < SET_SIZE; i++)
    {
        num.push_back((int)rand());
        n.Insert(num[i]);
    }

    for (int i = 0; i < SET_SIZE; i++)
        EXPECT_EQ(n.Query(num[i]), true);
}

// Sanity check for false positive rate.
// Initialize your bloom filter to have FILTER_SIZE bits.
// Add SET_SIZE elements to the bloom filter 
TEST(BloomFilterSanityCheck, FalsePositiveRate) {
    srand(time(NULL));
    BloomFilter n(FILTER_SIZE, SET_SIZE);
    vector<int> num;
    for (int i = 0; i < SET_SIZE ; i++)
    {
        num.push_back((int)rand());
        n.Insert(num[i]);
    }
    int f = 0;
    for (int i = 0; i < (SET_SIZE / 210); i++)
        if (!n.Query((int)rand()))
            f++;

    cout << f << endl;  
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}