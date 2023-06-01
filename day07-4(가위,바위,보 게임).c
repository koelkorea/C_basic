#include <stdio.h>
#include <stdlib.h>       // srand(), rand() �Լ� ��� �����ϰ� ��
#include <time.h>         // time () �Լ� ��� �����ϰ� ��
#include <windows.h>      // sleep() �Լ� ��� �����ϰ� ��

// ���� ���� C��� �Լ�
//  1. int rand(void) 
//      : ������ seed��(srand(int)�� ��ȯ ����)�� ���� 0~32767���� ���� ��ȯ
// 
//  2. (void) srand(unsigned int seed)
//      : rand() �Լ��� ���Ǵ� seed���� ������ (�Ķ���ͷ� �� int���� seed���� ��)
// 
//  3. (long long) time(time_t *timer)
//      : �Ķ���Ͱ� NULL�̸�, ���� �ð� ��ȯ�� (time�� �Ķ������ time_t�� long long �ڷ����� ��Ī�̸� *timer�� ������ ����)
int main() {

	// srand(unsigned int seed)
	//  : rand()�� ������ �ٿ��� seed��ȯ
	//		-> �̰��� �Ķ���ͷ� time(NULL)�� �޾�, ���� �ð��� ���� rand()�� ���� ������ �Ǵ� seed���� ���ָ� �� �� ����
	srand((unsigned int)time(NULL));			//  �̸� �ּ�ȭ ��Ű��, ������ �Ȱ��� ���� ��µǴ°� �� �� ����

	int player, com ,result;

	while (1) {

		printf("1 ~ 3���� �Է��ϼ���. (���� : 1, ���� : 2, �� : 3) : ");
		scanf_s("%d", &player);
		com = ((int)rand()) % 3 + 1;

		if (player == 1) {
			printf("\nUser : ����");
		}else if (player == 2) {
			printf("\nUser : ����");
		}else {
			printf("\nUser : ��");
		}
		printf("\n");
		if (com == 1) {
			printf("\com : ����");
		}else if (com == 2) {
			printf("\com : ����");
		}else {
			printf("\com : ��");
		}

		if (player == com) {
			printf("\n���º� ����!");
		}else {

			if (player == 1) {
				if (com == 2) {
					printf("\n�й�!");
				}else if(com == 3){
					printf("\n�¸�!");
				}
			}
			else if(player == 2) {
				if (com == 1) {
					printf("\n�¸�!");
				}
				else if(com == 3){
					printf("\n�й�!");
				}
			}
			else if (player == 3) {
				if (com == 1) {
					printf("\n�й�!");
				}
				else if(com == 2){
					printf("\n�¸�!");
				}
			}
		}

		printf("\n\n");
	}

	return 0;
}