#include <stdio.h>

// 1월 1일 ~ X월 X일까지의 기간을 날짜로 환산하는 프로그램
int main() {

	// 배열 주소와 일치하는 달을 매핑시켜 마지막 날짜(일)를 저장하고 배열화... (주소가 0인 배열은 그래서 값이 없음.. 0월은 없으니..)
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };		
	int i, month, day, total = 0;

	// X월 X일을 입력
	printf("해당 일까지 날짜 계산 \n");
	printf("월 : ");
	scanf_s("%d", &month);
	printf("일 : ");
	scanf_s("%d", &day);

	// 1월 ~ X월 전까지의 기간을 일로 환산
	for (i = 1; i < month; i++) {
		total += days[i];
	}

	// X월의 X일의 일수를 마지막으로 더해줌
	total += day;

	printf("\n1월1일 ~ %d월 %d일 : %d일로 변환 가능합니다\n", month, day, total);

	return 0;
}