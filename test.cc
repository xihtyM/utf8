#include <iostream>
#include "utf8.h"

int main(void)
{
    std::cout << "😃\n";
    std::cout << set_utf8() << '\n';
    std::cout << "😃\n";
    return 0;
}
