#include <iostream>
#include <string>

#include "dycont.h"
#include "stack.h"
#include "list.h"
#include "queue.h"
#include "tree.h"

#include "data_time.h"
#include "new_integer.h"
#include "Adam_time.h"
#include "spare_matrix.h"

#include <gtest/gtest.h>


TEST(TestGroupMane, TestName)
{
    ASSERT_TRUE(true);
}


int main()
{
    ::testing::InitGoogleTest();
    std::cout << "Dycont:\n";
    Integer var("32832183912938");
    ADT *test1 = &var;
    Integer *test2 = new Integer(21212312);
    Dycont qwa_dycont(2);
    qwa_dycont[0] = test1;
    qwa_dycont[1] = test2;
    std::cout <<  *(qwa_dycont[0]) << std::endl;
    //test на результат сложения
    std::string qwaqwa= "32832183912938";
    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_dycont[0])).get_num_str()).c_str());
    EXPECT_FALSE(*dynamic_cast<Integer*>(qwa_dycont[0]) == *dynamic_cast<Integer*>(qwa_dycont[1]) ); 
    std::cout <<"#########################################\n";
    
    ADT *test3 = new Adam_t(5,20,15);
    qwa_dycont.push_back(test3);
    // тест на хранимые данные в qwa_dycont[2]
    EXPECT_EQ(2960, (*dynamic_cast<Adam_t*>(qwa_dycont[2])).get_Adam_year() );
    std::cout << "test: push_back "<< *dynamic_cast<Adam_t*>(qwa_dycont[2]) << std::endl;
    for(size_t i = 0; i< qwa_dycont.size(); ++i)
        std::cout <<  (*qwa_dycont[i]) << std::endl;

    std::cout <<"#########################################\n";    

    qwa_dycont.pop_back();
    // тест на хранимые данные в qwa_dycont[2]
    std::cout << "test: pop_back "<< std::endl;
    for(size_t i = 0; i< qwa_dycont.size(); ++i)
        std::cout <<  (*qwa_dycont[i]) << std::endl;

    std::cout <<"#########################################\n";

    Adam_t qwer(9,12,11);
    ADT *test5 = &qwer;
    qwa_dycont.insert(1,test5);
    // тест на хранимые данные в qwa_dycont[1]

    EXPECT_EQ(6984, (*dynamic_cast<Adam_t*>(qwa_dycont[1])).get_Adam_year() );
    std::cout << "test: insert(1,6984) " << std::endl;
        
    for(size_t i = 0; i< qwa_dycont.size(); ++i)
        std::cout <<  (*qwa_dycont[i]) << std::endl;

    std::cout << "size = " << qwa_dycont.size() << "\t capacity = " << qwa_dycont.capacity() << std::endl;
    // тест на size и capacity

    std::cout <<"###################\n";
    qwa_dycont.erase(1);
    // тест на хранимые данные в qwa[1]    

    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_dycont[0])).get_num_str()).c_str());
    std::cout << "test: erase(1)\n";
    for(size_t i = 0; i< qwa_dycont.size(); ++i)
        std::cout <<  (*qwa_dycont[i]) << std::endl; 

    std::cout << "new size = " << qwa_dycont.size() << "\t new capacity = " << qwa_dycont.capacity() << std::endl;
    // тест на size и capacity
    
    std::cout <<"#########################################\n";

    ADT *test6 = new Adam_t(5,14,10);
    qwa_dycont.emplace(0, test6);
    EXPECT_EQ(770, (*dynamic_cast<Adam_t*>(qwa_dycont[0])).get_Adam_year() );

    std::cout << "test: emaplce(0)\n";
    // тест на хранимые данные в qwa_dycont[0]
    for(size_t i = 0; i< qwa_dycont.size(); ++i)
        std::cout <<  (*qwa_dycont[i]) << std::endl; 

    
    std::cout <<"#########################################\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_dycont.empty() << '\n';
    EXPECT_FALSE(qwa_dycont.empty());
    qwa_dycont.clear();
    EXPECT_TRUE(qwa_dycont.empty());
    std::cout << "test: clear\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_dycont.empty() << '\n';

    std::cout <<"\n\n#########################################\n\n";
    std::cout << "Stack:\n";


    //Integer *test2 = new Integer(21212312);
    Stack qwa_stack(2);
    qwa_stack[0] = test1;
    qwa_stack[1] = test2;
    //std::string qwaqwa= "32832183912938";
    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_stack[0])).get_num_str()).c_str());
    EXPECT_FALSE(*dynamic_cast<Integer*>(qwa_stack[0]) == *dynamic_cast<Integer*>(qwa_stack[1]) );
    std::cout <<  *(qwa_stack[0]) << std::endl;
    std::cout <<"#########################################\n";
    
    //ADT *test3 = new Adam_t(5,20,15);
    qwa_stack.push_back(test3);
    // тест на хранимые данные в qwa_stack[2]
    EXPECT_EQ(2960, (*dynamic_cast<Adam_t*>(qwa_stack[2])).get_Adam_year() );
    std::cout << "test: push_back "<< *dynamic_cast<Adam_t*>(qwa_stack[2]) << std::endl;
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl;

    std::cout <<"#########################################\n";
        
    ADT *test4 = new Integer(12345);
    qwa_stack.push_front(test4);
    // тест на хранимые данные в qwa_stack[2]
    std::string test_int = "12345";
    EXPECT_STREQ(test_int.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_stack[0])).get_num_str()).c_str());
    std::cout << "test: push_front "<< *(qwa_stack[0]) << std::endl;
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl;

    std::cout <<"#########################################\n";

    qwa_stack.pop_back();
    // тест на хранимые данные в qwa_stack[2]
    std::cout << "test: pop_back "<< std::endl;
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl;

    std::cout <<"#########################################\n";
    qwa_stack.pop_front();
    // тест на хранимые данные в qwa_stack[2]
    std::cout << "test: pop_front "<< std::endl;
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl;

    std::cout <<"#########################################\n";

    //Adam_t qwer(9,12,11);
    //ADT *test5 = &qwer;
    qwa_stack.insert(1,test5);
    // тест на хранимые данные в qwa_stack[1]

    EXPECT_EQ(6984, (*dynamic_cast<Adam_t*>(qwa_stack[1])).get_Adam_year() );
    std::cout << "test: insert(1,6984) " << std::endl;
        
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl;

    std::cout << "size = " << qwa_stack.size() << "\t capacity = " << qwa_stack.capacity() << std::endl;
    // тест на size и capacity

    std::cout <<"###################\n";
    qwa_stack.erase(1);
    // тест на хранимые данные в qwa_stack[1]    

    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_stack[0])).get_num_str()).c_str());
    std::cout << "test: erase(1)\n";
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl; 

    std::cout << "new size = " << qwa_stack.size() << "\t new capacity = " << qwa_stack.capacity() << std::endl;
    // тест на size и capacity
    
    std::cout <<"#########################################\n";

    //ADT *test6 = new Adam_t(5,14,10);
    qwa_stack.emplace(0, test6);
    EXPECT_EQ(770, (*dynamic_cast<Adam_t*>(qwa_stack[0])).get_Adam_year() );

    std::cout << "test: emaplce(0)\n";
    // тест на хранимые данные в qwa_stack[0]
    for(size_t i = 0; i< qwa_stack.size(); ++i)
        std::cout <<  (*qwa_stack[i]) << std::endl; 

    
    std::cout <<"#########################################\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_stack.empty() << '\n';
    EXPECT_FALSE(qwa_stack.empty());
    qwa_stack.clear();
    EXPECT_TRUE(qwa_stack.empty());
    std::cout << "test: clear\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_stack.empty() << '\n';


    std::cout <<"\n\n#########################################\n\n";
    std::cout << "List:\n";

    List qwa_list;
    qwa_list.push_back(test1);
    qwa_list.push_back(test2);
    //std::string qwaqwa= "32832183912938";
    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(const_cast<ADT*>(qwa_list[0]->data))).get_num_str()).c_str());
    
    EXPECT_FALSE(*dynamic_cast<Integer*>(const_cast<ADT*>(qwa_list[0]->data)) == *dynamic_cast<Integer*>(const_cast<ADT*>(qwa_list[1]->data)) ); 
    // тест на сравнение строк
    std::cout <<"#########################################\n";
    
    //ADT *test3 = new Adam_t(5,20,15);
    qwa_list.push_back(test3);
    // тест на хранимые данные в qwa_list[2]
    std::cout << "test: push_back "<<  std::endl;
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout <<  (*qwa_list[i]->data) << std::endl;

    std::cout <<"#########################################\n";
        
    //ADT *test4 = new Integer(12345);
    qwa_list.push_front(test4);
    // тест на хранимые данные в qwa_list[2]
    std::cout << "test: push_front "<< *(qwa_list[0]->data) << std::endl;
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout <<  (*qwa_list[i]->data) << std::endl;

    std::cout <<"#########################################\n";

    qwa_list.pop_back();
    // тест на хранимые данные в qwa_list[2]
    std::cout << "test: pop_back "<< std::endl;
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout <<  *(qwa_list[i]->data) << std::endl;

    std::cout <<"#########################################\n";
    qwa_list.pop_front();
    // тест pop_front
    std::cout << "test: pop_front "<< std::endl;
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout <<  (*qwa_list[i]->data) << std::endl;

    std::cout <<"#########################################\n";

    // тест insert
    //Adam_t qwer(9,12,11);
    //ADT *test5 = &qwer;
    qwa_list.insert(1,test5);
    EXPECT_EQ(6984, (*dynamic_cast<Adam_t*>(const_cast<ADT*>(qwa_list[1]->data))).get_Adam_year() );
    std::cout << "test: insert(1,6984) " << std::endl;
        
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout <<  (*qwa_list[i]->data) << std::endl;

    // тест size
    std::cout << "size = " << qwa_list.size() << std::endl;
     
    // тест erase
    std::cout <<"###################\n";
    qwa_list.erase(1);
    std::cout << "test: erase(1)\n";
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout << (*qwa_list[i]->data) << std::endl;

    std::cout << "new size = " << qwa_list.size() << std::endl;
    
    std::cout <<"#########################################\n";

    // тест emplace
    //ADT *test6 = new Adam_t(5,14,10);
    qwa_list.emplace(0, test6);
    EXPECT_EQ(770, (*dynamic_cast<Adam_t*>(const_cast<ADT*>(qwa_list[0]->data))).get_Adam_year() );
    std::cout << "test: emaplce(0)\n";
    for(size_t i = 0; i< qwa_list.size(); ++i)
        std::cout << (*qwa_list[i]->data) << std::endl;

    // тест на empty и clear
    std::cout <<"#########################################\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_list.empty() << '\n';
    EXPECT_FALSE(qwa_list.empty());
    qwa_list.clear();
    EXPECT_TRUE(qwa_list.empty()); 
    std::cout << "test: clear\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_list.empty() << '\n';
    


    std::cout <<"\n\n############################################################\n\n";
    std::cout << "Queue:\n";


    Queue qwa_queue(3);
    qwa_queue.push_front(test1);
    qwa_queue.push_front(test2);
    //std::string qwaqwa= "32832183912938";
    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_queue[1])).get_num_str()).c_str());
    std::cout <<"#########################################\n";
        
    //ADT *test4 = new Integer(12345);
    qwa_queue.push_front(test4);
    // тест на хранимые данные в qwa_queue
    std::string sad= "12345";
    EXPECT_STREQ(sad.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_queue[0])).get_num_str()).c_str());
    std::cout << "test: push_front "<< *(qwa_queue[0]) << std::endl;
    for(size_t i = 0; i< qwa_queue.size(); ++i)
        std::cout <<  (*qwa_queue[i]) << std::endl;

    std::cout <<"#########################################\n";

    
    // тест на хранимые данные в qwa_queue
    EXPECT_STREQ(qwaqwa.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(qwa_queue.pop_back())).get_num_str()).c_str());
    std::cout << "test: pop_back " << *(qwa_queue.pop_back()) << std::endl;
    for(size_t i = 0; i< qwa_queue.size(); ++i)
        std::cout <<  (*qwa_queue[i]) << std::endl;

    std::cout <<"#########################################\n";


    //Adam_t qwer(9,12,11);
    //ADT *test5 = &qwer;
    qwa_queue.insert(1,test5);
    // тест на хранимые данные в qwa_queue
    EXPECT_EQ(6984, (*dynamic_cast<Adam_t*>(qwa_queue[1])).get_Adam_year() );
    std::cout << "test: insert(1,6984) " << std::endl;
        
    for(size_t i = 0; i< qwa_queue.size(); ++i)
        std::cout <<  (*qwa_queue[i]) << std::endl;

    std::cout <<"#########################################\n";
        
    ADT *test8 = new Integer(5432);
    qwa_queue.push_front(test8);
    // тест на хранимые данные в qwa_queue[2]
    std::cout << "test: push_front "<< *(qwa_queue[0]) << std::endl;
    for(size_t i = 0; i< qwa_queue.size(); ++i)
        std::cout <<  (*qwa_queue[i]) << std::endl;

    std::cout <<"#########################################\n";
    std::cout << "size = " << qwa_queue.size() << std::endl;
    // тест на size и capacity

    std::cout <<"###################\n";
    qwa_queue.erase(1);
    // тест на хранимые данные в qwa_queue[1]    
    std::cout << "test: erase(1)\n";
    for(size_t i = 0; i< qwa_queue.size(); ++i)
        std::cout <<  (*qwa_queue[i]) << std::endl; 

    std::cout << "new size = " << qwa_queue.size() << std::endl;
    // тест на size и capacity
    
    std::cout <<"#########################################\n";

    //ADT *test6 = new Adam_t(5,14,10);
    qwa_queue.emplace(0, test6);
    EXPECT_EQ(770, (*dynamic_cast<Adam_t*>(qwa_queue[0])).get_Adam_year() ); // тест на хранимые данные в qwa_queue[0]
    std::cout << "test: emaplce(0)\n";
    for(size_t i = 0; i< qwa_queue.size(); ++i)
        std::cout <<  (*qwa_queue[i]) << std::endl; 

    
    std::cout <<"#########################################\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_queue.empty() << '\n';
    EXPECT_FALSE(qwa_queue.empty());
    qwa_queue.clear();
    EXPECT_TRUE(qwa_queue.empty());
    std::cout << "test: clear\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_queue.empty() << '\n';


    std::cout <<"\n\n#########################################\n\n";
    std::cout << "Tree:\n";



    Tree qwa_tree;
    ADT *test11 = new Integer("123456");
    ADT *test22 = new Integer("8998");
    ADT *test33 = new Integer("5555");
    ADT *test44 = new Integer(444);

    qwa_tree.insert(4,test11);
    qwa_tree.insert(1,test22);
    qwa_tree.insert(12,test33);
    qwa_tree.insert(6,test44);

    std::string qwaqwa_tree= "123456";
    EXPECT_STREQ(qwaqwa_tree.c_str(), static_cast<std::string>((*dynamic_cast<Integer*>(const_cast<ADT*>(qwa_tree[4]))).get_num_str()).c_str());
    
    // тест insert
    //Adam_t qwer(9,12,11);
    //ADT *test5 = &qwer;
    qwa_tree.insert(2,test5);
    EXPECT_EQ(6984, (*dynamic_cast<Adam_t*>(const_cast<ADT*>(qwa_tree[2]))).get_Adam_year() );
    std::cout << "test: insert(1,6984) " << std::endl;
    qwa_tree.print(qwa_tree.get_tree(), std::cout);
    // тест erase
    std::cout <<"###################\n";
    qwa_tree.erase(6);
    std::cout << "test: erase(1)\n";
    
    qwa_tree.print(qwa_tree.get_tree(), std::cout);
    
    std::cout <<"#########################################\n";

    // тест на empty
    std::cout <<"#########################################\n";
    std::cout << "test: empty: ";
    std::cout << std::boolalpha << qwa_tree.empty() << '\n';
    EXPECT_FALSE(qwa_tree.empty());
    return RUN_ALL_TESTS();
}

