#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() �Լ� ��� �����ϰ� ��

// �ζ� ��ȣ 6���� n�� �����ϴ� ��� �Լ��� �Ἥ ���� (�ߺ�üũ�� for���� ���� ��)
//  -> ������ ���� ����
//  -> 1��° �ζ� ��ȣ 6�� ���� + �ߺ��˻�
//  -> ������ �༮�� ���� (����, ����)
//  -> ��ȣ ���

// lotto_repeat()
//  : (��ü) �ζ� buy_num����ŭ lotto_one_cycle �ݺ� �߱� (lotto_generate, lotto_sort �� ���ο� ���� �� �ݺ�)
void lotto_repeat(int buy_num);

// lotto_one_cycle()
//  : (1�κ�) �ζ� �̴� ����(lotto_generate, lotto_duplication_check, lotto_sort ����)
void lotto_one_cycle(void);

//-----------------------------(lotto_one_cycle ���� ���� 3��)--------------------------------------

// 1) lotto_generate()
//     : ���� �ζ� ��ȣ �߱�
int lotto_generate(void);		

// 2) lotto_duplication_check(int, int)
//     : 1����Ŭ �̴� �� �ߺ�üũ
int lotto_duplication_check(int check_num, int duplication_check[46]);		

// 3) lotto_sort(int �迭[6])
//     : ���� �ζ� ���� ����
void lotto_sort(int array[6]);		

int main() {
	srand((unsigned int)time(NULL));

	int buy_num = 0;

	printf_s("�ζǸ� �� �� ��ðڽ��ϱ�? : ");
	scanf_s("%d", &buy_num);

	// ������ Ƚ�� ��ŭ �ζ� ������ (lotto_generate, lotto_sort �� ���ο� ���� �� �ݺ�)
	lotto_repeat(buy_num);

	return 0;
}

// 1. ���� �ζ� ��ȣ �߱�
int lotto_generate(void) {

	int lotto_result = rand() % 45 + 1;

	return lotto_result;
}

// 2. 1����Ŭ �̴� �� �ߺ�üũ(�ܼ� ��� ��)
int lotto_duplication_check(int check_num1, int check_num2) {

	if (check_num1 == check_num2) {

		printf("�ߺ�����(%d) ", check_num1);
		return 0;
	}

	return 1;
}

// 3. ���� �ζ� ��ȣ �߱�
void lotto_sort(int array[]) {

	int temp;

	for (int i = 0; i < 6; i++) {

		for (int j = i + 1; j < 6; j++) {

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

	int lotto_array[6] = { 0 };

	for (int i = 0; i < sizeof(lotto_array) / sizeof(lotto_array[0]); i++) {

		int duplication_status = 1;

		do {
			// 1. ���� �̱�
			lotto_array[i] = lotto_generate();		

			// �迭�� �ι�° ��Ҹ� �ݺ�
			for (int j = 0; j < sizeof(lotto_array) / sizeof(lotto_array[0]); j++) {

				// �ڱ� �ڽ��̸� ����
				if (i != j) {
					//�񱳴���� 0�̸� ����
					if (lotto_array[j] != 0) {
						
						duplication_status = lotto_duplication_check(lotto_array[i], lotto_array[j]);		// 2. ���� �༮ �ߺ����� üũ (0�̸� �ߺ���)

						// �ߺ� Ȯ���̸� for�� ���������� while �ݺ�
						if (duplication_status == 0) {
							break;
						}
					}
				}
			}

		} while (duplication_status == 0);

	}

	// 3. ������ ����
	lotto_sort(lotto_array);		

	// 1, 2, 3 ���� �Ϸ� ��.. �ش� ȸ�� �ζ� ���� ���� ��� 
	for (int i = 0; i < sizeof(lotto_array) / sizeof(lotto_array[0]); i++) {
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