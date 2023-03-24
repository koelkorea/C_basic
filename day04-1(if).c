#include <stdio.h>		

int main() {

	int code;

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &code);

	// 조건문 if
	if (code == 1) {

		printf("1을 입력했습니다. \n");
	}
	printf("END \n");

	return 0;

}