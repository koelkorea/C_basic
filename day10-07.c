#include <stdio.h>


// ���밪 ��ȯ, �ҹ��� ��ȯ ���α׷� �Լ��� ¥����

// ���밪 �Լ���
int absolute(int value);

// �ҹ��� -> �빮�� ��ȯ
int upper(int value);

int main() {

	int input1; char input2;

	printf("���밪 �� : ");
	scanf_s("%d", &input1);
	while (getchar() != '\n');
	printf("���밪 �� : %d\n", absolute(input1) );

	printf("�ҹ��� �Է� : ");
	scanf_s("%c", &input2);
	while (getchar() != '\n');
	printf("�빮�� ���� : %c\n", upper(input2));

	return 0;
}

int absolute(int value) {

	if (value >= 0) {
		return value;
	}
	else {
		return value * (-1);
	}
}

int upper(int value) {

	if (value >= 97 && value <= 122) {
		return value -= 32;
	}
	else {
		return value;
	}



}