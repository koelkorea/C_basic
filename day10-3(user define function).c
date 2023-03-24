// function (함수) 

// 1. 표준함수
//		- C언어에서 자체적으로 제공하는 함수
//		- 헤더 파일을 #include 시켜 사용 할 수 있다.

#include <stdio.h>

// 3. 사용자 정의 함수 (우리가 아는 그 함수) 사용자 정의 함수
//		 : 자료형 함수명(자료형 인수1, 자료형 인수2, …) {함수 정의};

//		# 특성
//			- 전체 프로그램을 짧은 길이의 단위 프로그램으로 나누어 정의함 (코드의 재사용성 good!)
//			- 유지 보수가 효율적이라는 장점
//			- 모듈화된 구조(Modulization, hierarchy)		<- 재사용
//			- (최소한 파라미터 자료형까지는 적어둔) 선선언 후완성으로 사용 가능한 유연성도 있긴하다


// 선언한 사용자 정의 함수 실사용 예시
int Plus(int x, int y) {		// 가인수 x, y			<- 진짜가 아닌 함수의 파라미터 

	int z;
	z = x + y;

	return z;
}

int main() {

	int a, b, c;

	a = 10, b = 20;		
	c = Plus(a, b);		// 실인수 x,y

	printf("A + B = %d\n", c);

	return 0;
}