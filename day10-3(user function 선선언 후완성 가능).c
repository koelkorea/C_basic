#include <stdio.h>

// 3. 사용자 정의 함수 (우리가 아는 그 함수) 사용자 정의 함수
//		 : 자료형 함수명(자료형 인수1, 자료형 인수2, …) {함수 정의};

//		# 특성
//			- 전체 프로그램을 짧은 길이의 단위 프로그램으로 나누어 정의함 (코드의 재사용성 good!)
//			- 유지 보수가 효율적이라는 장점
//			- 모듈화된 구조(Modulization, hierarchy)		<- 재사용
//			- (최소한 파라미터 자료형까지는 적어둔) 선선언 후완성으로 사용 가능한 유연성도 있긴하다

// 사용자 함수 선선언 후완성 가능 예시
int Plus(int , int );		// 1. 함수 선언 (선언시에 중요한건 결국 자료형이 뭐냐에 있다.. .그래서 파라미터 명까지는 입력하지 않아도 동작에 지장없음)

int main() {

	int a, b, c;

	a = 10, b = 20;
	c = Plus(a, b);		// 2. 함수 호출

	printf("A + B = %d\n", c);

	return 0;
}

int Plus(int x, int y) {		// 3. 함수 정의		Plus(a, b)			<- 이를 통해 Plus 함수를 계산하여 return

	int z;
	z = x + y;

	return z;
}