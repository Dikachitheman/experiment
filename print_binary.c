#include <stdio.h>
#include <stdlib.h>



int print_binary(va_list args)
{
	int n = va_arg(args, int);
	int b = 1, i, j, len = 0;
	int *ar;
	ar = (int*)malloc(n * sizeof(char));

	for (i = 0; b < n ; i++)
		{
			ar[i] = b;
			b = b * 2;
			len++;
		}

	// for (i = 0; i < len; i++)
	// 	{
	// 		if (ar[i])
	// 		{
	// 			printf("%d, %d, %d\n", ar[i], b, len);
	// 		}
	// 	}

		// printf("\n");

	int dif = n;
	int p, k = 1, u = 0;
	int pr[len];

	for (u; u < len; u++)
	{
		pr[j] = dif;
		if (dif >= ar[len - k])
		{
			dif = dif - ar[len - k];
			pr[j] = dif;
			putchar('0' + 1);
			j++;
		}
		else 
		{
			putchar('0' + 0);
		}
        k++;
	}
}