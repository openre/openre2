#include <iostream>
#include "gtest/gtest.h"

#include "index.hpp"
#include "types.hpp"

using namespace openre;

// The fixture for testing class OpenRE. From google test primer.
class IndexTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        IndexTest() {
            // You can do set-up work for each test here.
        }

        ~IndexTest() {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:
        void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for OpenRE.
        Index index;
};

TEST_F(IndexTest, Add) {
    /*
     * connections (tail -(connection id, i.e. index in list and to)-> head):
     *      0 -(0)-> 10
     *      0 -(4)-> 2
     *      0 -(5)-> 3
     *      1 -(1)-> 12
     *      2 -(2)-> 11
     *      3 -(3)-> 100
     *      4 -(undef)-> not connected
    */
    index.rebuild();
    index.add(0, 10);
    index.add(1, 12);
    index.add(2, 11);
    index.add(3, 100);
    index.rebuild();
    index.add(0, 2);
    index.add(0, 3);
    index.rebuild();
    const t_tail* tails = index.get_tails();
    address tails_count = index.tails_count();
    const t_tail tails_check[4] = {{0, 3}, {3, 1}, {4, 1}, {5, 1}};
    for (address i = 0; i < tails_count; i++){
        EXPECT_EQ(tails[i].heads_start, tails_check[i].heads_start);
        EXPECT_EQ(tails[i].heads_count, tails_check[i].heads_count);
    }
    const t_head* heads = index.get_heads();
    address heads_count = index.heads_count();
    const t_head heads_check[6] = {
        {10}, {3}, {2}, // 0, 3 (see tails_check)
        {12},           // 3, 1
        {11},           // 4, 1
        {100}           // 5, 1
    };
    for (address i = 0; i < heads_count; i++){
        EXPECT_EQ(heads[i].head, heads_check[i].head);
    }


/*    EXPECT_EQ(index.add(1, 12), (address)1);
    EXPECT_EQ(index.add(2, 11), (address)2);
    EXPECT_EQ(index.add(3, 100), (address)3);
    EXPECT_EQ(index.add(0, 2), (address)4);
    EXPECT_EQ(index.add(0, 3), (address)5);
    EXPECT_EQ(index.size, (address)4);
    EXPECT_EQ(index.from.size(), (vector<address>::size_type)4);
    EXPECT_EQ(index.to.size(), (vector<address>::size_type)6);
    EXPECT_EQ(index.list.size(), (vector<address>::size_type)6);
    // from = [5, 1, 2, 3, undef] contains an id of the connection (index in to and list)
    EXPECT_EQ(index.from[0], (address)5);
    EXPECT_EQ(index.from[1], (address)1);
    EXPECT_EQ(index.from[2], (address)2);
    EXPECT_EQ(index.from[3], (address)3);
    // to   = [10, 12,    11,    100,   2, 3    ] contains heads
    EXPECT_EQ(index.to[0], (address)10);
    EXPECT_EQ(index.to[1], (address)12);
    EXPECT_EQ(index.to[2], (address)11);
    EXPECT_EQ(index.to[3], (address)100);
    EXPECT_EQ(index.to[4], (address)2);
    EXPECT_EQ(index.to[5], (address)3);
    // list = [undef,  undef, undef, undef, 0, 4] conains next element in list
    EXPECT_EQ(index.list[0], undef);
    EXPECT_EQ(index.list[1], undef);
    EXPECT_EQ(index.list[2], undef);
    EXPECT_EQ(index.list[3], undef);
    EXPECT_EQ(index.list[4], (address)0);
    EXPECT_EQ(index.list[5], (address)4);*/
}

TEST_F(IndexTest, Find) {
    // find tails and connection ids by head
}

