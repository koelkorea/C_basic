#include <stdio.h>		

// 입력한 숫자의  절대값을 출력하는 코드
int main() {

	int code;

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &code);

	// 조건문 if
	if (code  <  0) {
		printf("(-) -> (+)로 변환 \n");
		code *= (-1);
	}

	printf("당신이 입력한 숫자의 절대값 : %d", code);

	return 0;

}