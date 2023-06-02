// 매크로 및 조건부 컴파일 지시자
   
// 전처리(Preprocessor) 정의
//  : 컴파일 - 고급언어를 컴퓨터가 실행 가능하도록 변환 과정
//     -> 대충 논리상 말이 되도록, 해당하는 외부 코드들을 위에 붙여넣고 컴파일 할 수 있게 하는 과정이라 생각하면 됨
   
// 1. #include <filename> or "filename"
// 
//     - <filename>    
//        : 특정 경로에서 헤더파일을 폴더에서 가져오라는거 의미
// 	   
//     - "filename"    
//        : 소스파일과 같은 폴더에서 1차 검색 -> <filename> 와 동일한 경로에서 2차 검색
   
// 2. #define token expression
//     : token을 expression으로 대치 (단! 다른 파일에서는 접근이 불가능하다)
   
// 3. #ifdef
//     : 전처리 과정에서 조건에 따라 컴파일 대상에 포함시키거나 제외시키는 역할
// 	     (조건식은 매크로 상수의 존재 여부, 값에 대한 평가식, … 등)
   
//     - #ifdef _Header_PSK
//        : _Header_PSK 선언되어 있다면 컴파일 포함
// 
//     - #ifndef _Header_PSK
//        : _Header_PSK 선언되지 않았다면 컴파일 포함
   
// 5. #if
//     : 매크로의 값이나, 여러 가지 조건을 결합하여 컴파일 여부를 결정
       
//     - #if    조건1  코드1
//        : 조건1을 만족하면 코드1을 컴파일

//     - #elif  조건2  코드2          
//        : 조건2을 만족하면 코드2을 컴파일

//     - #else  조건3  코드3   
//        : 모든 조건이 안 맞으면 코드3 컴파일

//     - #endif
   
// 	# 조건식 작성조건
// 		-> 상등, 비교 연산자 사용이 가능하다. == , != , > , < , >= , <=
// 		-> 비교 대상은 정수 상수 가능(실수, 문자열 불가)
// 		-> 논리 연산자 사용 가능


//헤더 파일 예시 
//include guard

// ifdef
//  : 전처리 과정에서 조건에 따라 컴파일 대상에 포함시키거나 제외시키는 역할
//    (조건식은 매크로 상수의 존재 여부, 값에 대한 평가식, … 등)

// PSK_H 선언되지 않았다면, 컴파일에 포함하기
#ifndef _psk_H

// PSK_H 선언
#define _psk_H

// include <filename> or "filename"
//  <filename>   : 특정 경로에서 헤더파일을 폴더에서 가져오라는거 의미
//  "filename"     소스파일과 같은 폴더에서 1차 검색 -> <filename> 와 동일한 경로에서 2차 검색
#include<stdio.h>

// #define token expression
//  : token을 expression으로 대치 (단! 다른 파일에서는 접근이 불가능하다)
#define PI 3.141592
#define SQRT(X) X*X

typedef struct _Person {

	char name[10];
	int age;
	char address[128];
}Person;

typedef long int file_size_t;
extern long long arr_len;

void hello_display() {
	printf("hello world\n");
}
#endif

//소스파일 예시
#define A  1 // 0 or 1
#include<stdio.h>
#include"psk.h"


int main() {

	file_size_t a;
	Person p1;

	// if
	// : 매크로의 값이나, 여러 가지 조건을 결합하여 컴파일 여부를 결정

	#if A == 0
		printf("define A == 0\n");
	#elif A == 1
		printf("define A == 1\n");
	#endif
		hello_display();

	return 0;
}
