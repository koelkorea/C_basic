#include <stdio.h>		
#include<math.h>

// while�� �̿��Ͽ�, �������� ���ϴ� ���α׷��� ������... ��, ��� ���� ��.. q, Q�� ������ ������ �ؾ���
int main() {
	
	double number;
	double result;
	char flag = 0;		

	while (flag != 81 && flag != 113) {			// ASCII�ڵ�� Q: 113, q : 81

		printf("�������� ���� ���ڸ� ��� :  ");
		scanf_s("%lf", &number);			// double�� �Ǽ��� ��¹��ڴ� f����, ������ long �ڷ������μ� lf�� ���� (scanf���� double�� ���� �������� %lf �ʼ���!)
		while (getchar() != '\n');

		result = sqrt(number);
		printf("%lf�� �������� %lf��.  \n\n", number, result);

		printf("����ҷ��� �ƹ�Ű�� �������� / ���� (Q / q) : ");

		scanf_s("%c", &flag);
		while (getchar() != '\n');

		printf(" \n");
	}

	printf("����Ϸ��߽��ϴ�. \n");

	return 0;
}