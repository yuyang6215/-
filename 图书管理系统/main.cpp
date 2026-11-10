#include"BookManager.h"
#include"FileStorage.h"
#include<iostream>

int main()
{
    //books.emplace_back("OS", "Ã¿◊””Æ", "978-7-15-68657-2", 69.80f, 10);
    //books.emplace_back("JAVA", "π¢œÈ“Â", "978-7-302-57544-3", 65.00f, 15);

    std::cout << "Welcome to Book Manager!\n";

    LoadBooks();

    Manager();

}
