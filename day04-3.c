#include <stdio.h>		

// 입력한 소문자 -> 대문자 변환 코드
int main() {

	char code;

	while (1) {

		printf("영문 소문자를 입력하세요 : ");
		code = _getche();

		// 조건문 if
		if (code >= 97 && code <= 122) {

			code -= 32;
			printf("\n소문자 -> 대문자로 변환 ");
			printf("\n당신이 입력한 소문자 -> 대문자 결과 : %c \n\n", code);
		}
		else if (code >= 65 && code <= 90) {

			printf("\n당신은 대문자 %c를 입력했습니다 \n\n", code);
		}
		else {

			printf("\n영문 소문자만 입력해라...  \n\n");
		}
	}

	return 0;

}