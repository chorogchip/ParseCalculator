
#include <iostream>

#include"Parser.h"


int main()
{
    Parser p(std::cin, std::cout);
    while (true)
        p.parse();
    
}

