#include <stdio.h>		

// for�� ���� �Է°�*2�� �ʺ�� ���̰� �Ǵ� ���̾Ƹ�� �׸��� �׷���
int main() {

	int �Է°�;

	while (1) {
		printf("���ϴ� ���̾Ƹ���� �� �밢����(���� ������/2�� ������)�� �Է��ϼ��� : ");
		scanf_s("%d", &�Է°�);

		for (int i = 1; i <= �Է°�; i++) {

			for (int j = 1; j <= �Է°� * 2; j++) {

				if (j == �Է°� - (i - 1) || j == �Է°� + i) {
					printf("��");
				}
				else {
					printf("��");
				}
			}

			printf("\n");
		}

		for (int i = 1; i <= �Է°�; i++) {

			for (int j = 1; j <= �Է°� * 2; j++) {

				if (j == i || j == �Է°� * 2 - i + 1) {
					printf("��");
				}
				else {
					printf("��");
				}
			}

			printf("\n");
		}
	}

}