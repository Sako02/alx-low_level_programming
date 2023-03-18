#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
 * Program that prints the alphabet in lowercase
 * followed by Uppecase, followed by a line
 * Return: Always 0 (Success)
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
c = 'A';
while (c <= 'Z')
{
putchar(c);
c++;
}
putchar('\n');
return (0);
}
