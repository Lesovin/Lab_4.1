
#include <iostream>
#include "Map.h"

int main()
{
    Map m;
    m.insert(1, "one");
    m.insert(3, "three");
    m.insert(2, "two");
    m.insert(4, "four");
    m.print();
    return 0;
}

