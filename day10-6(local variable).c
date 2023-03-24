#include <stdio.h>

// 3. 사용자 정의 함수 (우리가 아는 그 함수) 사용자 정의 함수
//		 : 자료형 함수명(자료형 인수1, 자료형 인수2, …) {함수 정의};

//		# 특성
//			- 전체 프로그램을 짧은 길이의 단위 프로그램으로 나누어 정의함 (코드의 재사용성 good!)
//			- 유지 보수가 효율적이라는 장점
//			- 모듈화된 구조(Modulization, hierarchy)		<- 재사용
//			- (최소한 파라미터 자료형까지는 적어둔) 선선언 후완성으로 사용 가능한 유연성도 있긴하다

// 함수의 지역함수 사용 예시 (같은 변수명도 다른 함수 영역에 썼으면 다름)
//		-> 지역변수는 꼭 초기화를 해줘야함... (안하면 쓰레기값으로 자동 초기화가 안 됨)
int display_menu(void) {

	int menu;		// 함수의 지역변수

	printf("[단위변환 프로그램]\n");
	printf("1. inch <-> cm\n");
	printf("2. cm <-> inch\n");
	printf("3. °F <-> °C\n");
	printf("4. °C <-> °F\n");
	printf("5. 끝내기 \n");
	printf("메뉴를 선택해주세요\n");
	scanf_s("%d", &menu);

	return menu;
}

int main() {

	// main의 menu와 display_menu에서 쓰인 menu는 전혀 다른 변수로 취급된다
	int menu = display_menu();		// 함수의 반환값으로 값을 가져옴
	printf("%d", menu);
	return 0;
}