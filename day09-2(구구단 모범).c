#include <stdio.h>

// (���) ������ ����� 
//   -> (������1) sizeof ���� ���
int main() {

	// �迭 �ʱ�ȭ �Ǵ� ����
	int gugudan[9][9];

	printf("[��������]\n");

	//	sizeof(������)�� �� �״�� �ش� ������ �ν��Ͻ��� �־��� �޸� ũ�⸦ ����ϴ°Ŷ� �������迭�� �־ ��(���� �� �迭 ��ü�� �޸� ũ�⸦ ���)
	for (int i = 0; i < sizeof(gugudan) / sizeof(gugudan[0]); i++) {		

		for (int j = 0; j < sizeof(gugudan) / sizeof(gugudan[0]); j++) {
			gugudan[i][j] = (i + 1) * (j + 1);
			printf("|%3d", gugudan[i][j]);
		}
		printf("|\n");
	}

	printf("\n[��������]\n");

	for (int i = sizeof(gugudan) / sizeof(gugudan[0]) - 1; i >= 0; i--) {

		for (int j = 0; j < sizeof(gugudan) / sizeof(gugudan[0]); j++) {
			printf("|%3d", gugudan[i][j]);
		}
		printf("|\n");
	}

	return 0;
}