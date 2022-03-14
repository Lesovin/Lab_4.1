
#include <iostream>
#include <conio.h>
#include "Map.h"

int main()
{
    Map m;
    int menu;
    int key;
    std::string data;
    std::cout << "Laboratory work #1. Class: Map"<<"\n";
    system("pause");
    for (;;)
    {
        system("cls");
        std::cout << "1.Insert element" << "\n";
        std::cout << "2.Get a data by key" << "\n";
        std::cout << "3.Erase element" << "\n";
        std::cout << "Esc.Exit" << "\n";
        std::cout << "Current tree:" << "\n";
        m.print();
        menu = _getch();
        if (menu == 27) break;
        switch (menu)
        {
        case 49:
            std::cout << "Enter the key:";
            std::cin >> key;
            std::cout << "Enter the data:";
            std::cin >> data;
            try {
                m.insert(key, data);
            }
            catch (const char* err)
            {
                std::cout << err;
                system("pause");
                break;
            }
            break;
        case 50:
            std::cout << "Enter the key:";
            std::cin >> key;
            try {
                std::cout<<"Data with this key:"<<m.find(key)<<"\n";
                system("pause");
            }
            catch (const char* err)
            {
                std::cout << err;
                system("pause");
                break;
            }
            break;
        case 51:
            std::cout << "Enter the key:";
            std::cin >> key;
            try {
                m.erase(key);
            }
            catch (const char* err)
            {
                std::cout << err;
                system("pause");
                break;
            }
        }
    }

    return 0;
}

