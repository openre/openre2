#include <iostream>
#include "gtest/gtest.h"

#include "layer.hpp"
#include "types.hpp"

using namespace openre;

// The fixture for testing class OpenRE. From google test primer.
class LayerTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        LayerTest() {
            // You can do set-up work for each test here.
        }

        virtual ~LayerTest() {
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
        Layer layer{"test name", 10, 20};
        Layer layer2;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(LayerTest, Create) {
    EXPECT_EQ(layer.name, "test name");
    EXPECT_EQ(layer.width, (address)10);
    EXPECT_EQ(layer.height, (address)20);

    EXPECT_EQ(layer2.name, "");
    EXPECT_EQ(layer2.width, (address)0);
    EXPECT_EQ(layer2.height, (address)0);

    EXPECT_EQ(layer.shapes.size(), (size_t)0);

    try {
        layer.addShape(0, 0, 10, 21);
        FAIL() << "Expected std::invalid_argument";

    }
    catch(invalid_argument const & err) {
        EXPECT_EQ(
            err.what(),
            string("Layer(\"test name\", 10, 20) does not fit Shape(0, 0, 10, 21)")
        );

    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    EXPECT_EQ(layer.shapes.size(), (size_t) 0);
    layer.addShape(0, 0, 10, 20);
    EXPECT_EQ(layer.shapes.size(), (size_t) 1);
    EXPECT_EQ(layer.shapes[0]->x, (address) 0);
    EXPECT_EQ(layer.shapes[0]->y, (address) 0);
    EXPECT_EQ(layer.shapes[0]->width, (address) 10);
    EXPECT_EQ(layer.shapes[0]->height, (address) 20);
}

