/* Bibliothèques externes-----------------------------------------------------*/
#include <iostream>

/* Bibliothèques internes-----------------------------------------------------*/
#include "my_class.h"

using namespace std;

int main()
{
    MyClass obj1;
    obj1.printMyElement();

    MyClass obj2("Hello World !\n");
    obj2.printMyElement();

    return 0;
}