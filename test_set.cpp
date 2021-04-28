#include <iostream>
#include "set.h"

int main()
{
    Set<int> a,b;
    a+1;
    a+2;
    a+3;
    a-2;

    std::cout<<a.sets_size()<<a.is_in_set(1)<<a.is_in_set(2);
    return 0;
}