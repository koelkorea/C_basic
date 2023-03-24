#include <stdio.h>

// 이번에 만들었던 공학계산기 코드를 사용자 함수를 이용해서 만들기
int display_menu(void);		// 메뉴
int inch_cm(void);				// 1.
int cm_inch(void);				// 2.
int f_c(void);							// 3.
int c_f(void);							// 4.
void world_end();					// 5.
void nothing();

int main() {

	// 메뉴 입력
	int menu;

	// do ~ while문으로 종료여부 및 메뉴 기능 결정
	do{
		menu = display_menu();		// 함수의 반환값으로 값을 가져옴

		switch (menu) {

			case 1:
				inch_cm();
				break;
			case 2:
				cm_inch();
				break;
			case 3:
				f_c();
				break;
			case 4:
				c_f();
				break;
			case 5:
				world_end();
				break;
			default:
				nothing();
				break;
		}

	} while (menu != 5);

	return 0;
}


int display_menu(void) {

	int menu;		// 함수의 지역변수

	printf("[단위변환 프로그램]\n");
	printf("1. inch <-> cm\n");
	printf("2. cm <-> inch\n");
	printf("3. °F <-> °C\n");
	printf("4. °C <-> °F\n");
	printf("5. 끝내기 \n");
	printf("메뉴를 선택해주세요 : ");
	scanf_s("%d", &menu);
	printf("\n");

	return menu;
}

// 1.  inch <-> cm
int inch_cm(void) {

	int input;

	printf("INCH값을 입력해줘라  : ");
	scanf_s("%d", &input);
	printf("당신이 입력한 %d cm = %2.7f inch \n\n", input, input * 2.54);
}

// 2. cm <-> inch
int cm_inch(void) {

	int input;

	printf("CM값을 입력해줘라 : ");
	scanf_s("%d", &input);
	printf("당신이 입력한 %d inch = %2.7f cm \n\n", input, input / 2.54);
}

// 3. °F <-> °C
int f_c(void) {

	int input;

	printf("°F(화씨)값을 입력해줘라 : ");
	scanf_s("%d", &input);
	printf("당신이 입력한 %d °F = %2.7f °C \n\n", input, (input - 32) * 5.0 / 9.0);
}

// 4. °C <-> °F
int c_f(void) {

	int input;

	printf("°C(섭씨)값을 입력해줘라 : ");
	scanf_s("%d", &input);
	printf("당신이 입력한 %d °C = %2.7f °F \n\n", input, (float)input * 9 / 5 + 32);
}

// 5. 끝내기
void world_end() {
	printf("프로그램이 붕괴됩니다...  \n");
}

void nothing() {
	printf("1 ~ 5 까지만 입력하라고... \n");
}