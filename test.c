#include "utf8.h"

int main(void)
{
    printf("😃\n");
    printf("%s\n", set_utf8());
    printf("😃\n");
    return 0;
}
