// void 포인터(void *)
//  : 포인터의 자료형이 정해지지 않은 만능 포인터 
//    (= 메모리 주소만 가지고 있는 포인터 변수 = 자료형이 정해지지 않았기 때문에 역참조 불가능!)
//      -> 주소 값만 저장 할 목적으로 포인터를 사용한다면 

//  - void 포인터변수(void *)의 특징
//      : 자료형이 정해지지 않았기 때문에 역참조 불가능? = 어떤 자료형에 대한 포인터변수인지에 대한 지정만 해주면? 해석가능
//      -> (중요!) void * 변수는 원하는 자료형의 포인터 변수로 형변환만 해주면, 의도한 자료형의 주소값을 출력 가능!!

//      ex) int a = 10;
//          int * pA = &a;

//          void * vB = pA          <- void 포인터변수 선언 (vB는 메모리주소만 가지고 있고, 역참조는 불가능함)
//          int * pd = (int *) vB   <- 이러면 vB는 int값 형식으로으로 역참조가 가능함

// 함수 포인터(* pFunction )
//  : 함수의 주소 값을 저장할 수 있는 포인터

//	- 함수 포인터 선언법 ( asterisk(*) 연산자 사용)
//		: (반환형) (* 포인터변수명 = 함수명) (매개변수1, 매개변수2, …)
//       -> 이후 포인터변수명(파라미터1, 파라미터2...) = 함수명(파라미터1, 파라미터2...)와 같은 의미를 가짐

//    # (중요!) 함수 포인터의 타입, 매개변수는 받는 함수의 반환형과 매개변수를 의미하므로 반드시 맞춰야 함

//			ex) int add (int x, int y) { return x+y; }   <- 함수의 이름 add는 함수가 위치한 메모리 시작 주소값을 의미
//          int ( * pFunction ) (int, int); 			   <- int값을 반환하며, 파라미터로 int형 2개를 받는 함수 타입의 포인터변수 선언

//          pFunction = add;                         <- 함수 포인터변수 pFunction에 함수 add의 주소값 대입
//          pFunction ( 12, 24 );                    <- add(12,24); 와 동일한 실행
#include<stdio.h>
#include<string.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

int main(void) {

  int a = 0, b = 0;
  char c = 0, buf[1025] = { 0 };

  printf("예시( 3 + 5 ) 입력 : ");
  gets_s(buf, sizeof(buf) - 1);

  for (int k = 0; k < strlen(buf); k++) {

    if ('0' <= buf[k] && buf[k] <= '9' && c == 0) {
      a = a * 10 + buf[k] - 48;
    }
    else if ('0' <= buf[k] && buf[k] <= '9' && c != 0) {
      b = b * 10 + buf[k] - 48;
    }
    else if (buf[k] != '0') {
      c = buf[k];
    }
    else break;
  }

  int (*pF)(int, int) = NULL;//(반환형) (* 포인터 변수 이름) (매개변수1, 매개변수2, …)
  
  switch (c) {
    case '+': pF = add; break; // add 함수 이름 == 메모리 시작 주소
    case '-': pF = sub; break;
    case '*': pF = mul; break;
    case '/': pF = div; break;
    default: printf("Error\n"); exit(0);
  }

  printf("\n계산 결과 값 : %5d %c %5d = %5d \n", a, c, b, pF(a, b));
  return 0;
}
