#include "test_set.h"
#include <iostream>
#include <cassert>
#include "set.h"
#include <string>

void test_set::test_add_ele()
{
    Set<int> int_set;
    Set<std::string> string_set;
    int_set + 1;
    int_set + 5;
    assert (int_set.sets_size() == 2 && int_set[0] == 1 && int_set[1] == 5);
    string_set + "cat";
    string_set + "dog";
    assert (string_set.sets_size() == 2 && string_set[0] == "cat"  && string_set[1] == "dog");
    std::cout<<"Adding element works\n";
}
void test_set::test_rm_ele()
{
    Set<int> int_set;
    Set<std::string> string_set;
    int_set + 1;
    int_set + 5;
    int_set - 1;
    assert (int_set.sets_size() == 1 && int_set[0] == 5);
    string_set + "cat";
    string_set + "dog";
    string_set - "dog";
    assert (string_set.sets_size() == 1 && string_set[0] == "cat");
    std::cout<<"Removing element works\n";
}
void test_set::test_is_in_set()
{
    Set<int> int_set;
    Set<std::string> string_set;
    int_set + 1;
    int_set + 5;
    assert (int_set.is_in_set(5) == true && int_set.is_in_set(12) == false);
    string_set + "cat";
    string_set + "dog";
    assert (string_set.is_in_set("dog") == true && string_set.is_in_set("asd") == false);
    std::cout<<"Checking if element is in the set works\n";
}
void test_set::test_sets_size()
{
    Set<int> int_set;
    Set<std::string> string_set;
    int_set + 1;
    int_set + 5;
    assert (int_set.sets_size() == 2);
    string_set + "cat";
    string_set + "dog";
    assert (string_set.sets_size() == 2);
    std::cout<<"Getting set's element count works\n";
}
void test_set::test_sets_sum()
{
    Set<int> int_set1{}, int_set2{};
    Set<std::string> string_set1{}, string_set2{};
    int_set1 + 1;
    int_set1 + 5;
    int_set2 + 6;
    int_set2 + 1;
    int_set1 + int_set2;
    assert (int_set1.sets_size() == 3 && int_set1[0] == 1 && int_set1[1] == 5 && int_set1[2] == 6);
    string_set1 + "cat";
    string_set1 + "dog";
    string_set2 + "bat";
    string_set2 + "sat";
    string_set1 + string_set2;
    assert (string_set1.sets_size() == 4 && string_set1[0] == "cat"  && string_set1[1] == "dog" && string_set1[2] == "bat" && string_set1[3] == "sat");
    std::cout<<"Adding sets works\n";
}
void test_set::test_sets_difference()
{
    Set<int> int_set1, int_set2;
    Set<std::string> string_set1, string_set2;
    int_set1 + 1;
    int_set1 + 5;
    int_set2 + 6;
    int_set2 + 1;
    int_set1 - int_set2;
    assert (int_set1.sets_size() == 1 && int_set1[0] == 5);
    string_set1 + "cat";
    string_set1 + "dog";
    string_set2 + "cat";
    string_set2 + "sat";
    string_set1 - string_set2;
    assert (string_set1.sets_size() == 1 && string_set1[0] == "dog" );
    std::cout<<"Subtracion of sets works\n";
}
void test_set::test_intersection()
{
    Set<int> int_set1, int_set2;
    Set<std::string> string_set1, string_set2;
    int_set1 + 1;
    int_set1 + 5;
    int_set2 + 6;
    int_set2 + 1;
    int_set1.intersection(int_set2);
    assert (int_set1.sets_size() == 1 && int_set1[0] == 1);
    string_set1 + "cat";
    string_set1 + "dog";
    string_set2 + "bat";
    string_set2 + "sat";
    string_set1.intersection(string_set2);
    assert (string_set1.sets_size() == 0);
    std::cout<<"Intersecting sets works\n";
}
void test_set::test_comparing()
{
    Set<int> int_set1, int_set2;
    Set<std::string> string_set1, string_set2;
    int_set1 + 1;
    int_set1 + 5;
    int_set2 + 5;
    int_set2 + 1;
    assert (int_set2 == int_set1);
    string_set1 + "cat";
    string_set1 + "dog";
    string_set2 + "bat";
    string_set2 + "sat";
    assert ((string_set2 == string_set1) == false);
    std::cout<<"Comparing sets works\n";
}
void test_set::full_test()
{
    test_set::test_add_ele();
    test_set::test_rm_ele();
    test_set::test_is_in_set();
    test_set::test_sets_size();
    test_set::test_sets_sum();
    test_set::test_sets_difference();
    test_set::test_intersection();
    test_set::test_comparing();
}