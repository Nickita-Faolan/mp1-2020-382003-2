#include <locale.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	const int k = 4;
	int n = 0, sum = 0;
	int** pArr = NULL;
	printf("������� ���������� ����������: ");
	scanf("%d", &n);
	pArr = (int**)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		pArr[i] = (int*)malloc(k * sizeof(int));
		pArr[i][0] = i + 1;
		for(int j = 1; j < k; j++)
		{
			pArr[i][j] = 0;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		printf("������� �������� �������� � %d �� ���: ", i + 1);
		scanf("%d", &pArr[i][1]);
		printf("������� ����� ������ �������� � %d : ", i + 1);
		scanf("%d", &pArr[i][2]);
		printf("\n");
		pArr[i][3] = pArr[i][2] * pArr[i][1];
		sum += pArr[i][3];
	}
	system("cls");

	
	

	printf("������� � \t�������� �� ���: \t����� ������:    \t�������� �� �����: ");
	for(int i = 0; i < n; ++i)
	{
		printf("\n");
		for(int j = 0; j < k; j++)
		{
			printf("%d\t\t\t", pArr[i][j]);
		}
	}
	printf("\n���� �����������: %d", sum);
}
