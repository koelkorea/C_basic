#include <stdio.h>


// 절대값 변환, 소문자 변환 프로그램 함수로 짜봐라

// 절대값 함수명
int absolute(int value);

// 소문자 -> 대문자 변환
int upper(int value);

int main() {

	int input1; char input2;

	printf("절대값 전 : ");
	scanf_s("%d", &input1);
	while (getchar() != '\n');
	printf("절대값 후 : %d\n", absolute(input1) );

	printf("소문자 입력 : ");
	scanf_s("%c", &input2);
	while (getchar() != '\n');
	printf("대문자 변형 : %c\n", upper(input2));

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