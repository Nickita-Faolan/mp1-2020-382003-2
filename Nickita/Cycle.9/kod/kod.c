#include "stdio.h"
#include "math.h"
void menu()
{
	printf("\n����:\n");
	printf("1. �� ����������� � ��������\n");
	printf("2. �� �������� � ����������\n");
}
void dvoi()
{
	int b, n, p;
	printf("Enter the number \n");
	scanf_s("%d", &n);
	p = 1;
	b = 0;
	while (n > 0)
	{
		b += (n % 2) * p ;
		p *= 10;
		n = n / 2;
	}
	printf("%d", b);
}
void des()
{
	int a, d, c;
	printf("Enter the number \n");
	scanf_s("%d", &a);

	while (n > 0)
	{
		d += (a % 2) * c;
		c *= 10;
		a = a / 2;
	}
	printf("%d", d);
}

