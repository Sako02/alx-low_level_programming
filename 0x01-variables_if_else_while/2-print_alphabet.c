#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 *main -> A program that prints the alphabet in lowercase, followed by a new line.
 *Return: Always 0 (Success)
 */
int main(void)
{
char c;
c = 'a';
while (c <= 'z')
{
putchar(c);
c++;
}
putchar('\n');
return (0);
}
