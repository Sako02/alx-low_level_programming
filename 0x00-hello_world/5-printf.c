#include <stdio.h>

int main(void)
{
        char str[] = "Hello";
        int i;

        for (i = 5; i >= 0; i--)
        {
                printf("%c", str[i]);
        }
        return 0;
}
