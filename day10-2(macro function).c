// function (함수) 

// 1. 표준함수
//		- C언어에서 자체적으로 제공하는 함수
//		- 헤더 파일을 #include 시켜 사용 할 수 있다.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//	 2. 매크로 함수 : #define을 사용한 선행처리기 명령어

//			# 선행처리기
//				 : 코드를 생성하는 것이 아니라, 컴파일러가 컴파일하기 좋도록 소스를 재구성해 주는 역할을 하는 것.

//			1) 단순매크로 : 상수를 치환	(말 그대로 특정 상수를 바꿔만 줌)
//				: #define 매크로이름   치환리스트 (함수명, 숫자, 문자열)

//				ex1) #define 리오넬메시		10								<- 리오넬메시 라는 변수명을 10이란 값으로 치환 가능
//				ex2) #define 리오넬메시		"올타임 레전드"		<- 리오넬메시 라는 변수명을 만나면 문자열로 바꿔줌
//				ex3) #define 리오넬메시		printf()						<- 리오넬메시("호날두를 싫어해") 라는 것을 printf("호날두를 싫어해")를 작동가능

//			2) 매크로 함수 : 매크로를 통해 함수를 흉내낼 수 있음
//				: #define 매크로이름(매개변수)  { 매개변수포함문자열 }
//					-> (참고) #undef  매크로이름(매개변수)	로 전에 선언한 매크로를 취소가능		

//				# 매크로 사용에 주의사항
//					: 연산이 아닌 단지 파라미터가 들어간 식으로 치환하기에 추천하지 않음 
//						 (따라서 ()문제나 우선순위 문제로 사람이 예측못하는 실수 나옴)


// 매크로 함수(#define함수)와 사용자정의 함수의 유사성 예시 (단지 이 녀석도 치환을 해주지만, 파라미터를 변환해 줌)
#define swap(type, a ,b) { type temp = a; a = b; b = temp;}			//		 swap(파라미터들..)을 쓰면, 다음과 같은 내용을 파라미터의 형식에 맞게 입력하면 반영해 줌
																												//		(이 예제에서 나온 temp는 전역변수라는건 이 코드가 리얼 함수가 아니라 치환한 흉내임을 암시)
int main() {

	int m = 3, n = 4, temp;
	double x = 3.5, y = 8.4;

	printf("m = %d m = %d\n", m, n );
	printf("x = %.2f y = %.2f\n", x, y);

	swap(int, m, n);

	// swap(int, m, n);의 전개 방식
	// 
	//	swap(int, m, n) {
	//		int temp = m;
	//		m = n; 
	//		n = temp;
	//	}

	swap(double, x, y);

	printf("m = %d n = %d\n", m, n);
	printf("x = %.2f y = %.2f\n", x, y);

	return 0;
}