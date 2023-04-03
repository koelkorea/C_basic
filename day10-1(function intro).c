// function (함수) 
//	: [파라미터(입력) -> { 그 파라미터를 이행} -> return 값 출력] 해주는 독립적으로 설계된 프로그램 코드의 집합

//	  # (중요) 함수의 이름은 메모리 시작 주소 값을 의미한다
//		-> 그 주소값을 기반으로 stack에 함수프레임을 만들어서 지역변수와 return값을 할당할 주소를 할당함


// 1. 표준함수
//		- C언어에서 자체적으로 제공하는 함수
//		- 헤더 파일을 #include 시켜 사용 할 수 있다.

#include <stdio.h>		// 입,출력, 파일                        (입, 출력) printf, scanf, getchar, … (파일) fopen, fclose, fprintf, …
#include <conio.h>		// 콘솔 입,출력                         putch, cputs, cprintf, …
#include <string.h>		// 문자열처리                           strcat, strcmp, strcpy, …
#include <math.h>		// 수학                                 sqrt, sin, cos, tan, log, exp, pow, …
#include <ctype.h>		// 문자형태 판별, 변환                   (문자형태 변환) isalpha, isdigit, islower, … (문자 변환)  tolower, toupper, …
#include <stdlib.h>		// 난수, 정렬, 수치 변환 관련            (난수) rand, srand (정렬) qsqrt, lfind, …  (수치) atoi, atoa
#include <time.h>		// 시간 관련                            clock, ctime, localtime, mktime, …


// 2. 매크로 함수 : #define을 사용한 선행처리기 명령어
// 
//	1) 단순매크로 : 상수를 치환	(말 그대로 특정 상수를 바꿔만 줌)
//		: #define 매크로이름   치환리스트 (함수명, 숫자, 문자열)

//		ex1) #define 리오넬메시		10                   <- 리오넬메시 라는 변수명을 10이란 값으로 치환 가능
//		ex2) #define 리오넬메시		"올타임 레전드"       <- 리오넬메시 라는 변수명을 만나면 문자열로 바꿔줌
//		ex3) #define 리오넬메시		printf()             <- 리오넬메시("호날두를 싫어해") 라는 것을 printf("호날두를 싫어해")를 작동가능

//	2) 매크로 함수 : 매크로를 통해 함수를 흉내낼 수 있음
//		: #define 매크로이름(매개변수)  { 매개변수포함문자열 }
//			-> (참고) #undef  매크로이름(매개변수)	로 전에 선언한 매크로를 취소가능		

//		# 선행처리기 : 코드를 생성하는 것이 아니라, 컴파일러가 컴파일하기 좋도록 소스를 재구성해 주는 역할을 하는 것.
// 
//		# 매크로 사용에 주의사항
//			: 연산이 아닌 단지 파라미터가 들어간 식으로 치환하기에 추천하지 않음 
//				 -> 따라서 ()문제나 우선순위 문제로 사람이 예측못하는 실수 나옴

// 3. 사용자 정의 함수 (우리가 아는 그 함수) 사용자 정의 함수
//		 : 자료형 함수명(자료형 인수1, 자료형 인수2, …) {함수 정의};

//		# 특성
//			- 전체 프로그램을 짧은 길이의 단위 프로그램으로 나누어 정의함 (코드의 재사용성 good!)
//			- 유지 보수가 효율적이라는 장점
//			- 모듈화된 구조(Modulization, hierarchy)		<- 재사용
//			- (최소한 파라미터 자료형까지는 적어둔) 선선언 후완성으로 사용 가능한 유연성도 있긴하다


// ex) 매크로함수 치환만 하는게 왜 문제인지 보여줌 예시
#define square1(x) x*x			//	 ()를 쓰지 않았을때 생기는 일을 위함
#define square2(x) (x)*(x)

// 매크로 함수(define)에서 ()를 쓰지 않을 경우, 연산 우선순위가 사람과 컴퓨터가 생각하는것과 다를수 있음 예시
int main() {

	// 매크로 함수(define)는 단지 파라미터를 쓴 대로 치환을 해주지, 우선순위까지 맞춰주지 않기에 비슷해 보이지만 다른 결과를 낼 수 있음..
	printf("%d\n", square1(1 + 2) );		// 1 + 2 * 1 + 2 = 1 +2 +2 = 5			<- (1+2) * (1+2)가 아니다!
	printf("%d\n", square2(1 + 2) );		// 3 * 3 = 9

	printf("%f\n", square1(1.1) );			// 1.210000
	printf("%d\n", square2('d') );			// 10000						d= 100	<-	아스키코드

	return 0;
}