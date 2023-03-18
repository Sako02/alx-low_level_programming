#include <stdio.h>
/**
 * Program that prints the alphabet in lowercase, and then in uppercase, followed by a new line
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
