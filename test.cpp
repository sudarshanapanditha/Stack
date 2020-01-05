#include <gtest/gtest.h>
#include "stack.h"

TEST(STACK_TEST, init_stack){
    ASSERT_NO_THROW({
        stack<int>s{5U};
    });
}

TEST(STACK_TEST, size_zero_stack){
    ASSERT_THROW({
        stack<int>s{0};
    }, stack_exception);
}

TEST(STACK_TEST, stackoverflow){
    stack<int>s{1};
    s.push(1);
    ASSERT_THROW({s.push(2);}, stack_exception);
}

TEST(STACK_TEST, stackunderflow){
    stack<int>s{1};
    s.push(1);
    s.pop();
    ASSERT_THROW({s.pop();}, stack_exception);
}

TEST(STACK_TEST, top){
    stack<int>s{1};
    s.push(1);
    s.pop();
    ASSERT_THROW({s.top();}, stack_exception);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}