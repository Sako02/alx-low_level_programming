#include<stdio.h>
/**
 * Program that prints the alphabet in lowercase, followed by Uppecase, followed by a line
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
c = 'A';
while (c <= 'Z')
{
putchar(c);
c++;
}
putchar('\n');
}
