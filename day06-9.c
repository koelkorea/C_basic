#include <stdio.h>		
#include<math.h>

// while�� �̿��Ͽ�, ȭ�� -> ���� ��ȯǥ�� ������ (x��F ��������.. ����ǵ��� �غ���)
int main() {

	int min, max, interval, level = 0;
	double result;

	printf("��ȯ�� ���ϴ� �ּ�ġ ��F(ȭ��)�� ���ΰ���? : ");
	scanf_s("%d", &min);

	printf("\n��ȯ�� ���ϴ� �ִ�ġ��F(ȭ��)�� ���ΰ���? : ");
	scanf_s("%d", &max);

	printf("\n��  ��F(ȭ��) ������ ��ȯ�� �ص帱���? : ");
	scanf_s("%d", &interval);

	while (max >= min + level * interval) {

		result = (min + level * interval - 32) * 5.0 / 9.0;
		printf("\n\n%d��F = %lf��C", min + level * interval ,result);

		level++;
	}

	return 0;
}