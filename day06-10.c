#include <stdio.h>		
#include<math.h>

// for�� �̿��Ͽ�, ȭ�� -> ���� ��ȯǥ�� ������ (x��F ��������.. ����ǵ��� �غ���)
int main() {

	int min, max, interval;
	double result;

	printf("��ȯ�� ���ϴ� �ּ�ġ ��F(ȭ��)�� ���ΰ���? : ");
	scanf_s("%d", &min);

	printf("\n��ȯ�� ���ϴ� �ִ�ġ��F(ȭ��)�� ���ΰ���? : ");
	scanf_s("%d", &max);

	printf("\n��  ��F(ȭ��) ������ ��ȯ�� �ص帱���? : ");
	scanf_s("%d", &interval);

	for (int level = 0; level <= (max - min) / interval; level++) {

		result = (min + level * interval - 32) * 5.0 / 9.0;
		printf("\n\n%d��F = %lf��C", min + level * interval, result);
	}

	return 0;
}