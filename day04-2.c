#include <stdio.h>		

// �Է��� ������  ���밪�� ����ϴ� �ڵ�
int main() {

	int code;

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &code);

	// ���ǹ� if
	if (code  <  0) {
		printf("(-) -> (+)�� ��ȯ \n");
		code *= (-1);
	}

	printf("����� �Է��� ������ ���밪 : %d", code);

	return 0;

}