#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() �Լ� ��� �����ϰ� ��
#include <time.h>				// time () �Լ� ��� �����ϰ� ��

// 6*6�迭���� 5*5�� ������ ���� ��, ��� ���� ���� �밢�� ���� ���� 6�� 6���� �� �������� �ض� 
int main() {

	srand((unsigned int)time(NULL));

	// �迭 �ʱ�ȭ �Ǵ� ����
	int array[6][6], rowSum, columnSum;

	for (int i = 0; i < sizeof(array) / sizeof(array[0]) - 1; i++) {		//	sizeof(������)�� �� �״�� �ش� ������ �ν��Ͻ��� �־��� �޸� ũ�⸦ ����ϴ°Ŷ� �������迭�� �־ ��(���� �� �迭 ��ü�� �޸� ũ�⸦ ���)

		rowSum = 0;

		for (int j = 0; j <= sizeof(array) / sizeof(array[0]) - 1; j++) {

			if (j < sizeof(array) / sizeof(array[0]) - 1) {

				array[i][j] = rand() % 10 + 1;
				rowSum += array[i][j];
				printf("%3d", array[i][j]);

				if ((j == sizeof(array) / sizeof(array[0]) - 2)) {
					printf("|");
				}

			}
			else if (j == sizeof(array) / sizeof(array[0]) - 1) {
				printf("%3d\n", rowSum);
			}
		}

	}

	printf("--------------------\n");

	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {

		if (i == sizeof(array) / sizeof(array[0]) - 1) {
			array[5][i] = array[0][0] + array[1][1] + array[2][2] + array[3][3] + array[4][4];
			printf("|%3d", array[5][i]);
		}
		else {
			array[5][i] = array[0][i] + array[1][i] + array[2][i] + array[3][i] + array[4][i];
			printf("%3d", array[5][i]);
		}

	}

	return 0;
}
