#include <stdio.h>		

// �Է��� �ҹ��� -> �빮�� ��ȯ �ڵ�
int main() {

	char code;

	while (1) {

		printf("���� �ҹ��ڸ� �Է��ϼ��� : ");
		code = _getche();

		// ���ǹ� if
		if (code >= 97 && code <= 122) {

			code -= 32;
			printf("\n�ҹ��� -> �빮�ڷ� ��ȯ ");
			printf("\n����� �Է��� �ҹ��� -> �빮�� ��� : %c \n\n", code);
		}
		else if (code >= 65 && code <= 90) {

			printf("\n����� �빮�� %c�� �Է��߽��ϴ� \n\n", code);
		}
		else {

			printf("\n���� �ҹ��ڸ� �Է��ض�...  \n\n");
		}
	}

	return 0;

}