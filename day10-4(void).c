#include <stdio.h>

// 3. 사용자 정의 함수 (우리가 아는 그 함수) 사용자 정의 함수
//		 : 자료형 함수명(자료형 인수1, 자료형 인수2, …) {함수 정의};

//		# 특성
//			- 전체 프로그램을 짧은 길이의 단위 프로그램으로 나누어 정의함 (코드의 재사용성 good!)
//			- 유지 보수가 효율적이라는 장점
//			- 모듈화된 구조(Modulization, hierarchy)		<- 재사용
//			- (최소한 파라미터 자료형까지는 적어둔) 선선언 후완성으로 사용 가능한 유연성도 있긴하다

//	void : 말 그대로 비어있다는거

//	[파라미터가 void인 경우]
//		-> 말 그대로 비어있다는 뜻으로, 반환값도 없고, 파라미터도 없음
//			(참고 : 파라미터 void는 생략이 가능하다)
void display_menu(void) {

	printf("[단위변환 프로그램]\n");
	printf("1. inch <-> cm\n");
	printf("2. cm <-> inch\n");
	printf("3. °F <-> °C\n");
	printf("4. °C <-> °F\n");
	printf("5. 끝내기 \n");
	printf("메뉴를 선택해주세요\n");
}

int main() {

	display_menu();
	return 0;
}