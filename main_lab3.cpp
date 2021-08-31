#include <iostream>
#include <string>

#include "dycont_t.hpp"
#include "stack_t.hpp"
#include "list_t.hpp"
#include "queue_t.hpp"
#include "tree_t.hpp"
#include <gtest/gtest.h>

class TestClasses: public ::testing::Test
{
    protected:
        Dycont_t<int> qwa_dycont;
        Stack_t<int> qwa_stack;
        List_t<int> qwa_list;
        Queue_t<int> qwa_queue{6};
        Tree_t<int> qwa_tree;
};

TEST_F(TestClasses, push_back)
{
    qwa_dycont.push_back(111);
    EXPECT_EQ( 111 , qwa_dycont[0] );
    qwa_stack.push_back(111);
    EXPECT_EQ( 111 , qwa_stack[0] );
    qwa_list.push_back(111);
    EXPECT_EQ( 111 , qwa_list[0]->data );
    qwa_tree.insert(0, 111);
    EXPECT_EQ( 111 , qwa_tree[0] );
}
TEST_F(TestClasses, push_front)
{
    qwa_stack.push_back(333);
    EXPECT_EQ( 333 , qwa_stack[0] );

    qwa_list.push_front(333);
    EXPECT_EQ( 333 , qwa_list[0]->data );

    qwa_queue.push_front(333);
    EXPECT_EQ( 333 , qwa_queue[0] );
}
TEST_F(TestClasses, insert)
{
    qwa_dycont.insert(1, 222);
    EXPECT_EQ( 222 , qwa_dycont[0] );
    qwa_stack.insert(1, 222);
    EXPECT_EQ( 222 , qwa_stack[0] );
    qwa_list.insert(1, 222);
    EXPECT_EQ( 222 , qwa_list[1]->data );
    qwa_queue.insert(1, 222);
    EXPECT_EQ( 222 , qwa_queue[0] );
    qwa_tree.insert(1, 222);
    EXPECT_EQ( 222 , qwa_tree[1] );
}
TEST_F(TestClasses, empty)
{
    EXPECT_TRUE( qwa_dycont.empty() );
    EXPECT_TRUE( qwa_stack.empty() );
    EXPECT_TRUE( qwa_list.empty() );
    EXPECT_TRUE( qwa_queue.empty() );
    EXPECT_TRUE( qwa_tree.empty() );
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    Dycont_t<int> mass(5);
    mass[0] = 0;
    mass[1] = 1;
    mass[2] = 2;
    mass[3] = 3;
    mass[4] = 4;
    mass[5] = 5;
    mass.push_back(6);
    mass.erase(1);

    for (Dycont_t<int>::Iterator<int> it = mass.begin(); it < mass.end(); ++it)
        std::cout << mass[it] << '\n';
    return RUN_ALL_TESTS();
}
