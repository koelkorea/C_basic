#include <stdio.h>

// 변수 : 말 그대로 변화할 수 있는 값

// -변수의 속성
//		1. 자료형 : 어떤 종류의 자료를 다룰 것인가
//		2. 유지시간 : 
//      -> 어디에서 선언되고(어떤 스코프 안에 위치하는지)
//      -> 초기화값이 어떻게 정해지냐? 에 따라
//      -> 모든 변수는 제한된 사용영역과 생성~소멸 기간(life time)을 갖고 있다

//	- {} 를 기준으로 따지는 변수의 종류
//		1. 전역변수 : 함수 밖이나 외부파일에서 선언 = 프로그램 전체에 걸쳐 사용될 수 있는 변수
//          -> 자동 초기화 ㅇ (숫자는 0)  
//          -> 생존기간  : forever  = 데이터 영역에 메모리(RSS)가 할당
//          -> 확장개념 : 외부 static함수, 외부변수(extern) 

//		2. 지역변수 :  선언된 블록이나 함수같은 특정 범위({} 스코프) 내에서만 통용되는 변수
//          -> 자동 초기화 X
//          -> 생존기간  : 임시로 사용(내부 static함수만 forever) = stack 영역에 메모리가 할당 
//          -> 확장개념 : 내부 static함수, 자동변수(auto), 레지스터변수(register)

//	 - 기억클래스로 나누는 변수 (대충 세부기준이라 보면 편함)
//		1. 자동변수(auto) : 함수 스코프 안에서 선언되고, 그 함수 안에서만 사용되며, 함수가 종료되면 stack메모리에서 해제 (일종의 지역변수)
//			-> 자동 초기화 X (지역변수이기에)
//			-> 함수가 실행될 때마다, 새로 초기화 된다는 점 명심! 
//			-> auto라는 예약어는 생략가능
// 
//		2. 정적 변수(static) : 컴파일 시 데이터 영역에 메모리(RSS)가 할당, 프로그램이 종료될때까지 값을 유지 (단! 자기 프로그램 내에서만 참조 가능)
//			-> 자동 초기화 ㅇ (프로그램 시작시, 딱 1번만 초기화 = 변경값은 끝까지 저장)
//  		-> 생존기간  : forever
//			-> 세부구분
//				- 2.1 외부 staric 변수
//						 : 함수 밖에서 선언되는 일반 static변수 (사실상 전역변수와 유사)
// 			- 2.2 내부 static 변수
//						 : 함수 안에서 선언되는 지역변수와 같은 static변수...  (그러니까 다른 {}차원에 존재하는 static변수)
//     	            	-> (중요) 자동변수(auto)와의 비교
//				            	- 공통점 : 지역변수
//					            - 차이점 : 함수 실행 때마다 초기화 되는 자동변수와 달리.. 해당 함수가 실행될 때만 변동이 생기지만, 변경값은 끝까지 저장..
// 
//		3. 외부변수(extern) : extern으로 선언한 전역변수는 함수의 외부에 선언되는 일종의 전역변수 = 다른 파일에서 해당 값을 참조 가능 (전역변수, 일반 정적변수는 이게 불가능) 
//			-> 자동 초기화 ㅇ (프로그램 종료때까지 유지)
//  		-> 생존기간  : forever
//			-> 메모리 할당은 static변수와 같음
//			-> (중요) 전역변수와의 비교
//					- 공통점 : 외부변수(extern)는 외부에서 선언된 전역변수와 비슷
//					- 차이점 : 전역변수는 아무리 그래도 파일 내부에 위치 + 다른 파일에서 참고는 불가능
// 
//		4. 레지스터변수(register) : 지역변수지만, CPU의 레지스터에 저장되는 지역변수 (CPU에 저장된다는거 말고는 지역변수와 같음)
//			->  기억 장소가 레지스터이므로 실행 속도가 제일 빠름
//			->  레지스터 배정이 가능한 개수만큼 할당함 (그 이외는 자동 변수로 할당)


// [종합 정리]

// 3. 외부변수(extern)  : ex_a ~ f는 외부파일에 선언된 녀석들을 참고 (day11-3.c에 선언)
extern int ex_a;            //int ex_a = 10;
extern int ex_b;            //int ex_b = 20;
extern int ex_c;            //int ex_c = 30;
extern int ex_d;            //int ex_d = 40;
extern int ex_e;            //int ex_e = 50;
extern int ex_f;             //int ex_f = 60;

#include <stdio.h>
// 1. 전역변수 : 함수 밖이나 외부파일에서 선언되어, 프로그램 전체에 걸쳐 사용될 수 있는 변수
int A;

// 2.1 외부 staric 변수 : 함수 밖에서 선언되는 일반 static변수
static int B = 30;

// 함수 check은 돌리면, A++; ++B; ++C; ex_d++; ex_e++; ex_f++;
void check() {

    // 2.2 내부 static 변수 : check() 함수 안에서 선언된 static변수 (외부 static이나, 다른 스코프 안의 내부 static과는 상관없음)
    static int C = 10;

    // 1. 자동변수(auto) : 함수 스코프 안에서 선언되고, 그 함수 안에서만 사용되며, 함수가 종료되면 stack메모리에서 해제(일종의 지역변수)
    int i = 20; A++; ++B; ++C; ex_d++; ex_e++; ex_f++;

    printf("check\n");
    printf("i = %d, A=%d, B=%d, C=%d\n", i, A, B, C);
    printf("ex_a = %d, ex_b = %d, ex_c = %d, ", ex_a, ex_b, ex_c);
    printf("ex_d = %d, ex_e = %d, ex_f = %d\n", ex_d, ex_e, ex_f);
}

// main도 일종의 함수
int main() {

    // 1. 자동변수(auto) : 함수 스코프 안에서 선언되고, 그 함수 안에서만 사용되며, 함수가 종료되면 stack메모리에서 해제(일종의 지역변수)
    int i = 10;

    // 2.2 내부 static 변수 :  main() 함수 안에서 선언된 static변수 ( check()의 변수 C와는 상관없음... 다른 차원의 C임)
    static int C = 40;

    if (i > 0) {

        // 2. 지역변수 :  선언된 블록이나 함수같은 특정 범위({} 스코프) 내에서만 통용되는 변수
        int value1 = 100;

        for (int k = 0; k < 10; k++) {  // (중요)  반복문 차원에 선언된 지역변수 k는 본차원과 관계X  이므로... 본차원의 k는 선언되기 전까지 존재 X (js 초기버전의 var가 이 스코프 처리가 개판이라.. 문제)
            printf("k = %d , value = %d\n", k, value1++);
        }

        int k = 20;
        printf("%d ", k);    // 따라서 위에 int k = 20;을 주석치면.. 여기서 에러남
    }

    int value1 = 20;        // 상단의 int value1 = 100 은 if{}차원에 선언된 지역변수이므로... 본차원의 value1는 선언되기 전까지 존재 X

    printf("%d \n", value1);    // 따라서 위에  int value1 = 20을 주석치면.. 여기서 에러남

    // (중요) {} 내 또 다른 {} : 지역함수의 또 다른 지역함수... 서로 다른 차원으로 인정 (따라서 동명의 함수가 선언되어도 컴퓨터는 다른 놈으로 인식한다)
    {
        // 2. 지역변수 
        int value11 = 11, value12 = 12, value13 = 13, value14 = 14, value15 = 15;    // {}안의 차원의 value11 ~ value15
        printf("%d %d %d %d %d \n", value11, value12, value13, value14, value15);
    }

    // 1. 자동변수(auto) : 함수 스코프 안에서 선언되고, 그 함수 안에서만 사용되며, 함수가 종료되면 stack메모리에서 해제(일종의 지역변수)
    int value11 = 21, value12 = 22, value13 = 23, value14 = 24, value15 = 25;        // 본차원의 value11 ~ value15

    printf("%d %d %d %d %d \n\n", value11, value12, value13, value14, value15);

    printf("main\n");
    A++, ++B, ++C, ex_a++, ex_b++, ex_c++;

    // A는 전역변수, B는 외부staic변수, C는 내부staic변수
    printf("i = %d, A=%d, B=%d C=%d \n", i, A, B, C);                              // i = 10, A = 1, B = 31 C = 41               : C의 경우는 main안의 static이 40으로 선언된거 참고해라
    printf("ex_a = %d, ex_b = %d, ex_c = %d, ", ex_a, ex_b, ex_c);      // ex_a = 11, ex_b = 21, ex_c = 31,
    printf("ex_d = %d, ex_e = %d, ex_f = %d\n", ex_d, ex_e, ex_f);     //  ex_d = 40, ex_e = 50, ex_f = 60

    // 함수 check은 돌리면, A++; ++B; ++C; ex_d++; ex_e++; ex_f++;
    check();
    // i = 20, A = 2, B = 32, C = 11        : 함수 check의 i는 자동변수 20, C는 내부static변수 10 (함수 안에 있음에도 값의 변화는 프로그램 끝날때까지 누적되어 유지!)
    // ex_a = 11, ex_b = 21, ex_c = 31, ex_d = 41, ex_e = 51, ex_f = 61
    check();
    // i = 20, A = 3, B = 33, C = 12         : 함수 check의 i는 자동변수 20, C는 내부static변수 11 (이전 연산의 결과)
    // ex_a = 11, ex_b = 21, ex_c = 31, ex_d = 42, ex_e = 52, ex_f = 62
    check();
    // i = 20, A = 4, B = 34, C = 13         : 함수 check의 i는 자동변수 20, C는 내부static변수 12
    // ex_a = 11, ex_b = 21, ex_c = 31, ex_d = 43, ex_e = 53, ex_f = 63

    printf("main\n");
    A++, ++B, ++C, ex_a++, ex_b++, ex_c++;

    printf("i = %d, A=%d, B=%d C=%d \n", i, A, B, C);                               // i = 10, A=5, B=35 C=42
    printf("ex_a = %d, ex_b = %d, ex_c = %d, ", ex_a, ex_b, ex_c);       // ex_a = 12, ex_b = 22, ex_c = 32,
    printf("ex_d = %d, ex_e = %d, ex_f = %d\n", ex_d, ex_e, ex_f);      // ex_d = 43, ex_e = 53, ex_f = 63

    return 0;
}