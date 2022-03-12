
#include <iostream>
#include "Map.h"

int main()
{
    Map m;
    m.insert(4, "four");
    m.insert(-1, "minus one");
    m.insert(2, "two");
    m.insert(6, "six");
    m.insert(3, "three");
    m.insert(1, "one");
    m.insert(5, "five");
    m.print();
    m.erase(-1);
    m.erase(5);
    m.print();
    try {
        //std::cout << m.find(5);
    }
    catch (const char* err) {
        std::cout << err;
    }
    
    return 0;
}

