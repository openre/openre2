#include <iostream>
#include "gtest/gtest.h"

#include "shape.hpp"
#include "types.hpp"

using namespace openre;

// The fixture for testing class OpenRE. From google test primer.
class ShapeTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        ShapeTest() {
            // You can do set-up work for each test here.
        }

        virtual ~ShapeTest() {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:
        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for OpenRE.
        Shape shape{0, 1, 10, 20};
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(ShapeTest, Create) {
    EXPECT_EQ(shape.x, (address)0);
    EXPECT_EQ(shape.y, (address)1);
    EXPECT_EQ(shape.width, (address)10);
    EXPECT_EQ(shape.height, (address)20);
}

