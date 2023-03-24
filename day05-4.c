#include <stdio.h>		

// if문으로 공학단위 변환기 만들기
int main() {

	int 메인선택;
	char 내부메뉴선택;
	int 숫자값 = 0;
	float 결과값;

	while (1) {
		printf("원하는 기능의 메뉴번호를 입력해주세요. \n");

		printf("1. INCH <-> CM\n");
		printf("2. 화씨 <-> 섭씨\n\n");

		scanf_s("%d", &메인선택);
		while (getchar() != '\n');

		if (메인선택 == 1) {		// 파라미터로 들어갈 조건이 정수형(int, char)만 자료형으로 사용 가능

			printf("원하는 기능 코드를 입력해주세요. \n");
			printf("a. INCH <-> CM\n");
			printf("b. CM <-> INCH\n\n");

			scanf_s("%c", &내부메뉴선택);
			while (getchar() != '\n');

			if (내부메뉴선택 == 'a') {

				printf("INCH값을 입력해줘라. \n");
				scanf_s("%d", &숫자값);
				결과값 = 숫자값 * 2.54;
				printf("당신이 입력한 %d cm = %2.7f inch \n\n", 숫자값, 결과값);

			}
			else if (내부메뉴선택 == 'b') {
				printf("CM값을 입력해줘라. \n");
				scanf_s("%d", &숫자값);
				결과값 = 숫자값 / 2.54;
				printf("당신이 입력한 %d inch = %2.7f cm \n\n", 숫자값, 결과값);
			}
			else{

				printf("a, b둘 중 하나만 입력하라고... \n");

			}
			while (getchar() != '\n');

		}else if (메인선택 == 2) {

			printf("원하는 기능 코드를 입력해주세요. \n");
			printf("a. °F(화씨) <-> °C(섭씨)\n");
			printf("b. °C(섭씨) <-> °F(화씨) \n\n");

			scanf_s("%c", &내부메뉴선택);
			while (getchar() != '\n');

			if (내부메뉴선택 == 'a') {
					printf("°F(화씨)값을 입력해줘라. \n");
					scanf_s("%d", &숫자값);
					결과값 = (숫자값 - 32) * 5.0 / 9.0;
					printf("당신이 입력한 %d °F = %2.7f °C \n\n", 숫자값, 결과값);


			}
			else if (내부메뉴선택 == 'b') {

				printf("°C(섭씨)값을 입력해줘라. \n");
				scanf_s("%d", &숫자값);
				결과값 = (float)숫자값 * 9 / 5 + 32;
				printf("당신이 입력한 %d °C = %2.7f °F \n\n", 숫자값, 결과값);
			}else{

				printf("a, b둘 중 하나만 입력하라고... \n");
			}
			while (getchar() != '\n');

		}else{

			printf("1과 2 둘 중 하나만 입력하라고... \n");
		}

		//printf("당신이 원하는 결과값 : %2.7f \n\n", 결과값);
	}

	return 0;
}