#include <iostream>
#include "log.h"
void log(const char* message){
    std::cout<<message<<std::endl;
}

int main()
{
    initlog();
    std::cout << "Hello World!"<<std::endl;
    std::cin.get();
}
