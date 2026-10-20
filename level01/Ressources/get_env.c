#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("%p\n", getenv("shellcode"));
	return(0);
}