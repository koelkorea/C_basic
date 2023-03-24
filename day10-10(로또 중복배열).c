#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() �Լ� ��� �����ϰ� ��

// �ζ� ��ȣ 6���� n�� �����ϴ� ��� �Լ��� �Ἥ ����
//		-> ������ ���� ����
//		-> 1��° �ζ� ��ȣ 6�� ���� + �ߺ��˻�
//		-> ������ �༮�� ���� (����, ����)
//		-> ��ȣ ���

// (��ü)�ζ� buy_num����ŭ �߱� (lotto_generate, lotto_sort �� ���ο� ���� �� �ݺ�)
void lotto_repeat(int buy_num);

// (1�κ�) �ζ� �̴� ����(lotto_generate, lotto_duplication_check, lotto_sort ����)
void lotto_one_cycle(void);

//	(������ ���� 3��)
int lotto_generate(void);				// 1) ���� �ζ� ��ȣ �߱�
int lotto_duplication_check(int check_num, int duplication_check[46]);		// 2) 1����Ŭ �̴� �� �ߺ�üũ
void lotto_sort(int array[6]);		// 3) ������ ����

int main() {
	srand((unsigned int)time(NULL));

	int buy_num = 0;

	printf_s("�ζǸ� �� �� ��ðڽ��ϱ�? : ");
	scanf_s("%d", &buy_num);
	
	// ������ ���� ��ŭ �ζ� ������ (lotto_generate, lotto_sort �� ���ο� ���� �� �ݺ�)
	lotto_repeat(buy_num);

	return 0;
}

// 1. ���� �ζ� ��ȣ �߱�
int lotto_generate(void) {

	int lotto_result = rand() % 45 + 1;

	return lotto_result;
}

// 2. 1����Ŭ �̴� �� �ߺ�üũ
int lotto_duplication_check(int check_num, int duplication_check[46]) {

	if (duplication_check[check_num] == 1) {

		printf("�ߺ�����(%d) ", check_num);
		return 0;

	}
	else if (duplication_check[check_num] == 0) {

		duplication_check[check_num] = 1;
		return 1;
	}

}

// 3. ���� �ζ� ��ȣ �߱�
void lotto_sort(int array[]) {

	int temp;

	for (int i = 0; i < 6 ; i++) {

		for (int j = i + 1; j < 6 ; j++) {

			if (array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}


// (1�κ�) �ζ� �̴� ����(lotto_generate, lotto_duplication_check, lotto_sort ����)
void lotto_one_cycle(void) {

	int duplication_check[46] = { 0 };
	int lotto_array[6] = { 0 };

	for (int i = 0; i < sizeof(lotto_array) / sizeof(lotto_array[0]) ; i++) {

		int duplication_status = 1;

		do {
			lotto_array[i] = lotto_generate();		// 1. ���� �̱�
			duplication_status = lotto_duplication_check(lotto_array[i], duplication_check);		// 2. ���� �༮ �ߺ����� üũ (0�̸� �ߺ���)

		} while (duplication_status == 0);

	}

	lotto_sort(lotto_array);		// 3. ������ ����

	// 1, 2, 3 ���� �Ϸ� ��.. �ش� ȸ�� �ζ� ���� ���� ��� 
	for (int i = 0; i < sizeof(lotto_array) / sizeof(lotto_array[0]) ; i++) {
		printf("%d ", lotto_array[i]);
	}

	printf("\n");
}

// (��ü)�ζ� buy_num����ŭ �߱� (lotto_generate, lotto_sort �� ���ο� ���� �� �ݺ�)
void lotto_repeat(int buy_num) {

	for (int j = 1; j <= buy_num; j++) {

		printf("%d ��° �ζ� ��ȣ : ", j);
		lotto_one_cycle();
	}
}