#include "main.h"

int print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
    unsigned int num2;
    char c = 'A';
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}

/**
 * print_unsignedIntToHex - prints unsigned int to hexadecimal.
 * @num: number to print
 * @_case: letter `a` on the case to print it (upper or lower)
 * Return: number or char printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
    unsigned int num2;
    char c = 'a';
	int i, j, remainder, nbrCharacters = 0;
	char *numhex;

	for (num2 = num; num2 != 0; nbrCharacters++, num2 /= 16)
	;

	numhex = malloc(nbrCharacters);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			numhex[i] = remainder + '0';
		else
			numhex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		putchar(numhex[j]);
	free(numhex);
	return (nbrCharacters);
}

int main()
{
   print_hex (987);
   printf("\n");
   print_HEX (987);
      printf("\n");

	printf("Unsigned hexadecimal:[%x, %X]\n", 987, 987);
}