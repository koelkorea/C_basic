#include <stdio.h>
#include <stdlib.h>				//srand(), rand() �Լ� ��� �����ϰ� ��
#include <time.h>				// time () �Լ� ��� �����ϰ� ��

// 50�� �л� �� ����, ���� ����, Ž�� ������ ���� 2���� �迭 ����
//  -> 1��� ���� ������ �Է� ���� ����(0~100��)
//  -> ������ �����ϴ� ���� �����, ��� �ű��
//  -> �� ���� �������� (����ڵ� ������ �˾ƾ� ��)
int main() {

	srand((unsigned int)time(NULL));

	// �迭 �ʱ�ȭ �Ǵ� ���� 
	int array[30][4];			// 40�� 4���� �Է�
	int subject;
	int ranking[30][2];				// ��ŷ�� �迭
	int temp;								// �������� �ӽú���

	// ���� : ���� ���� �ֱ�
	printf("		    �� �� �� Ž\n");

	//	sizeof(������)�� �� �״�� �ش� ������ �ν��Ͻ��� �־��� �޸� ũ�⸦ ����ϴ°Ŷ� �������迭�� �־ ��(���� �� �迭 ��ü�� �޸� ũ�⸦ ���)
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {		

		// �л���ȣ ���
		printf("%2d�� �л��� ���� : ", i+1);

		// 4���� ���� ���� ����
		for (int j = 0; j <= sizeof(array)[0] / sizeof(array[0][0]) - 1; j++) {
			array[i][j] = rand() % 100 + 1;
			printf("%4d", array[i][j]);
		}
		printf("\n\n");
	}

	// ����ű�� ���� ����

	// ���� �Է�
	printf("����� �ޱ� ������ �Է����ּ���(1. ����  2.���� 3.���� 4. Ž�� ) : ");
	scanf_s("%d", &subject);

	switch (subject) {
	case 0: printf("\n------------------------------------���� ��� �ű��---------------------------------------------- \n \n");
		break;
	case 1: printf("\n------------------------------------���� ��� �ű��----------------------------------------------  \n \n");
		break;
	case 2: printf("\n------------------------------------���� ��� �ű��----------------------------------------------  \n \n");
		break;
	default: printf("\n-----------------------------------Ž�� ��� �ű��----------------------------------------------  \n \n");
		break;
	}


	printf("[���� ��] \n");

	// ���� ������ ������� ranking �迭�� 1��° ���� �л���ȣ, 2��° ���� �л����� ����
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {

		ranking[i][0] = i;
		ranking[i][1] = array[i][subject - 1];

		// ������ �л���ȣ ���
		printf("%4d��", ranking[i][0]);		
	}

	printf("\n");

	// ������ �л� ���� ���
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {
		printf("%4d��", ranking[i][1]);
	}

	printf("\n\n");

	printf("[���� ��] \n");

	// �������� ��� (1~9 ������ ���� ���� �۰ų� ū ���� ��������, 2~9 �̷������� ���� ���)
	for (int i = 0; i <= sizeof(ranking) / sizeof(ranking[0]) - 1; i++) {

		for (int j = i + 1; j <= sizeof(ranking) / sizeof(ranking[0]) - 1; j++) {

			// �ִ밪�� ������ ������ �� + �л���ȣ, �л������� ���� �ٲ���
			if (ranking[j][1] > ranking[i][1]) {
				temp = ranking[i][0];
				ranking[i][0] = ranking[j][0];
				ranking[j][0] = temp;

				temp = ranking[i][1];
				ranking[i][1] = ranking[j][1];
				ranking[j][1] = temp;
			}

		}
	}


	// ��� ��¿�
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {

		printf("%4d��", i + 1);
	}

	printf("\n");

	// ���� �� �л���ȣ
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {
		printf("%4d��", ranking[i][0]);
	}

	printf("\n");

	// ���� �� �л� ����
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {
		printf("%4d��", ranking[i][1]);
	}

	return 0;
}
