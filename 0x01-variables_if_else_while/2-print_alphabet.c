#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * Program that prints the alphabet in lowercase, followed by a new line
 * Returns
 */
int main()
{
char c;
c = 'a';
while (c <= 'z')
{
putchar(c);
c++;
}
putchar('\n');
}
