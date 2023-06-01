#include <stdio.h>		

// 반복문 for(초기값; 조건식(필수... 없으면 무한루프); 증감식)
int main() {

	// 초기값을 증감값을 통해 조건식에 true면 증감값을 통해 대상값 i에 변동 후 반복, false면 break 
	//  -> 초기값은 main에서 선언해도 되고, 증감식은 for문 스코프{}에 설정해줘도 됨
	//      -> 조건식을 비운다면? 걍 무한루프 (true로 시작되는 상태를 false로 판단할 조건이 없음)
	for (int i = 1; i <= 10; i++) {
		printf("%d ", i);
	}

	printf("\n");

	return 0;
}