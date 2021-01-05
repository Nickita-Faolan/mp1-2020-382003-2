#include "math.h"
#include "stdio.h"
#include "locale.h"
#include "stdlib.h"

const double pi = 3.1415926535;

typedef double (*N)(double, int);
typedef double (*F)(double);


double NextSh(double x, int n)
{
	return ((x * x) / (2 * n * (2 * n + n)));
}

double NextArcctg(double x, int n)
{
	return ((((-1) * x * x) / (2 * n + 1)) * (2 * n - 1));
}

double First(double x)
{
	return x;
}


double SUM(F First, N Next, double x, int n/*, double ideal, double eps, double* a*/)
{
	int i = 0;
	double sum = First(x);
	double elem = sum;
	double elemNext;
	/*(*a) = fabs(ideal - sum);*/
	while (i < n) /*&& (*a > eps))*/
	{
		elemNext = elem * Next(x, i + 1);
		sum += elemNext;
		elem = elemNext;
		i++;
		/*(*a) = fabs(ideal - sum);*/
	}
	return sum;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	int n;
	double eps = 0;
	double* a = 0;
	double x;
	int k = 1;
	double sumsh = 0;
	double sumarcctg = 0;


	printf("����������� ������ � ���� - ");
	scanf_s("%d", &n);

	printf("������� �������� x - ");
	scanf_s("%lf", &x);

	printf("������� ����������� ������ - ");
	scanf_s("%lf", &eps);

	sumsh = SUM(First, NextSh, x, n/*, sinh(x), eps, a*/);
	sumarcctg = (0, 5 * pi) - SUM(First, NextArcctg, x, n/*, (0,5 * pi)*atan(x), eps, a*/);

	printf("����� arcctg �����:");
	printf("\n %.10f \n", sumarcctg);
	printf("��������� �������� arcctg :");
	printf("\n %.10f \n", (0, 5 * pi) - atan(x));
	printf("������� ����� ������ � ��������� ��������� Arcctg %.10f \n", fabs((0, 5 * pi) - atan(x) - sumarcctg));

	printf("����� sh �����:");
	printf("\n %.10f \n", sumsh);
	printf("��������� �������� sh:");
	printf("\n %.10f \n", sinh(x));
	printf("������� ����� ������ � ��������� ��������� Sh %.10f \n", fabs(sinh(x) - sumsh));
}