#include <stdio.h>
#include <stdlib.h>       // srand(), rand() �Լ� ��� �����ϰ� ��
#include <time.h>         // time () �Լ� ��� �����ϰ� ��
#include <windows.h>      // sleep() �Լ� ��� �����ϰ� ��

// (Ư���� 1) ��Ī�� ���� ��Ī����, ���α׷��Ӱ� �ڵ�� ��Ī���� �Է��ص�.. ��ǻ�ʹ� �������� �װ� ���ڷ� �˾Ƶ���
#define ���� 1 
#define ���� 2 
#define �� 3 
#define computer 0 
#define user 1 
#define draw 2

// (������) random �Լ��� �̿��Ͽ� ��ǻ�Ϳ� �ϴ� ����, ����, ���� ������
int main() {

	// srand(unsigned int seed)
	//  : rand()�� ������ �ٿ��� seed��ȯ
	//		-> �̰��� �Ķ���ͷ� time(NULL)�� �޾�, ���� �ð��� ���� rand()�� ���� ������ �Ǵ� seed���� ���ָ� �� �� ����
	srand((unsigned int)time(NULL));			//  �̸� �ּ�ȭ ��Ű��, ������ �Ȱ��� ���� ��µǴ°� �� �� ����


	// (Ư����2) �¸��ڸ� �����ϴ� victory ���� ���..
	int player, com, victory;			

	while (1) {

		system("cls");	// ���� ��� ȭ�� �����

		printf("1 ~ 3���� �Է��ϼ���. (���� : 1, ���� : 2, �� : 3) : ");
		scanf_s("%d", &player);
		while (getchar() != '\n');

		com = ((int)rand()) % 3 + 1;

		// (Ư���� 3) swirch ���� ���� ���� �ڵ� ���ذ� ���������� ���ϼ� �ְ� ��
		switch (player) {
			case ���� :

				printf("\nUser : ����");

				if (com == ����) {
					victory = computer, 
					printf("\ncom : ����");
				}
				else if (com == ��) {
					victory = user,
					printf("\ncom : ��");
				}
				else {
					victory = draw,
					printf("\ncom : ����");
				}
				
				break;

			case ����:

				printf("\nUser : ����");

				if (com == ��) {
					victory = computer,
					printf("\ncom : ��");
				}
				else if (com == ����) {
					victory = user,
					printf("\ncom : ����");
				}
				else {
					victory = draw,
					printf("\ncom : ����");
				}

				break;

			case ��:

				printf("\nUser : ��");

				if (com == ����) {
					victory = computer,
					printf("\ncom : ����");
				}
				else if (com == ����) {
					victory = user,
					printf("\ncom : ����");
				}
				else {
					victory = draw,
					printf("\ncom : ��");
				}

				break;
		}

		// (Ư���� 2�� ����) �¸��ڿ� ���� ����� ���
		if (victory == computer) {
			printf("\n�¸��� : computer!\n\n");
		}
		else if (victory == user) {
			printf("\n�¸��� : user!\n\n");
		}
		else {
			printf("\n���º� ����!\n\n");
		}

		system("pause");		// �ٷ� �������� �Ѿ�� ���� ��� ���߶�� �Լ�

		printf("\n\n");
	}

	return 0;
}