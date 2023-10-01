#include "utf8.hh"
#include <iostream>

int main(void)
{
    set_utf8();
    std::cout << "\u1234";
    return 0;
}
