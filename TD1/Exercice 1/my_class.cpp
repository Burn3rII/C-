/* Bibliothèques internes-----------------------------------------------------*/
#include "my_class.h"

/* Constructeurs--------------------------------------------------------------*/

MyClass::MyClass():
text("Hello World par défaut!\n")
{

}

MyClass::MyClass(const string& str):
text(str)
{
    
}

/* Méthodes-------------------------------------------------------------------*/

void MyClass::printMyElement() const
{
    cout << text;
}
