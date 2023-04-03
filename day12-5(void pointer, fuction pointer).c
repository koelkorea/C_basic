// void 포인터(void *)
//  : 포인터의 자료형이 정해지지 않은 만능 포인터 
//    (= 메모리 주소만 가지고 있는 포인터 변수 = 자료형이 정해지지 않았기 때문에 역참조 불가능!)
//      -> 주소값만 저장 할 목적으로 포인터를 사용한다면 void *를 사용 

//  - void 포인터변수(void *)의 특징
//      : 자료형이 정해지지 않았기 때문에 역참조 불가능? = 어떤 자료형에 대한 포인터변수 여부를 지정만 해주면? 해석가능
//          -> (중요!) void * 변수는 원하는 자료형의 포인터 변수로 형변환만 해주면, 의도한 자료형의 주소값을 출력 가능!!

//      ex) int a = 10;
//          int * pA = &a;

//          void * vB = pA          <- void 포인터변수 선언 (vB는 메모리주소만 가지고 있고, 역참조는 불가능함)
//          int * pd = (int *) vB   <- 이러면 vB는 int값 형식으로으로 데이터를 읽어 void 포인터변수 vB의 값을 역참조가 가능함

// 함수 포인터(* pFunction )
//  : 함수의 주소 값을 저장할 수 있는 포인터

//	- 함수 포인터 선언법 ( asterisk(*) 연산자 사용)
//		: (반환형) (* 포인터변수명 = 함수명) (매개변수1, 매개변수2, …)
//          -> 이후 포인터변수명(파라미터1, 파라미터2...) = 함수명(파라미터1, 파라미터2...)와 같은 의미를 가짐

//      ex) int add (int x, int y) { return x+y; }     <- 함수의 이름 add는 함수가 위치한 메모리 시작 주소값을 의미
//          int ( * pFunction ) (int, int);            <- int값을 반환하며, 파라미터로 int형 2개를 받는 함수 타입의 포인터변수 선언
                                                       
//          pFunction = add;                           <- 함수 포인터변수 pFunction에 함수 add의 주소값 대입
//          pFunction ( 12, 24 );                      <- add(12,24); 와 동일한 실행

//    # (중요) 함수의 이름은 메모리 시작 주소 값을 의미 (= 그 주소값을 기반으로 stack에 함수프레임을 만들어서 지역변수와 return값을 할당할 주소를 할당함)
//    # (중요) 함수 포인터의 타입, 매개변수는 받는 함수의 반환형과 매개변수를 의미하므로 반드시 맞춰야 함
//    # 함수포인터도 역시 초기화 해줘야함 (NULL이나 0을 추천)

//    # 함수 포인터를 쓰는 이유
//      1) 함수 포인터를 쓰는 이유는 이를 통해 나중에 함수를 1급 시민(1급 객체) 개념으로 쓸수가 있음(First-class Function)
//      2) 조건에 따라 다른 함수를 대입해서 코드 작성이 쉬워지는 이점이 존재


// 함수포인터를 사용해서, 계산기를 구현해봐라 (단, 연산을 받을때는 한번에 다 받아야 함)
#include<stdio.h>
#include<string.h>
#include<math.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

// str_len(문자열 주소) : 해당 문자열의 길이 반환
int str_len(char* p) {

    int n = 0;              // 현재 문자열 길이을 나타냄
    while (*p++)n++;        // 현재 참고하는 문자열 주소 위치의 값을 역참조한 값이 null이 아니면? 숫자를 1개씩 올린다.    -> 이걸 문자열이 null이 나와 끝날때까지 계속하면, 문자열 길이 체크 가능
    return n;
}

int main(void) {

  // 변수 a, b 받을 녀석, 부호의 현재위치 값
  int a = 0, b = 0, location = 0, result;

  // 부호 받을 c, 식을 받을 input배열
  char c = 0, input[1025] = { 0 }; 

  printf("+, -, *, /를 사용하여 계산식을 입력해주세요(ex: 3 + 5) : ");

  // scanf_s : 문자열을 받을 경우에 쓰게 될 것이며, 반드시 파라미터로 메모리 크기를 할당해줘야 함
  scanf_s("%s", input, sizeof(input));

  int (*pFunction) (int, int) = NULL;       //(반환형) (* 포인터 변수 이름) (매개변수1, 매개변수2, …)
  
  // 문자열 길이만큼 for문을 돌리고, 부호를 찾으면 부호가 무엇인지 + 그 위치를 받는다
  for (int i = 0; i < str_len(input); i++) {

      if ((input[i] == 42 || input[i] == 43 || input[i] == 45 || input[i] == 47)) {
          c = input[i];
          break;
      }
      location++;
  }

  printf("\n부호위치 : %d , %c", location, input[location]);

  // 부호위치를 기준으로 앞쪽의 값을 a로 대입 (단, 문자열을 분리하는 과정이므로.. 그걸 정수로 만드는건 알아서 대입)
  for (int i = 0; i < location; i++) {

      if (input[i] >= 48 && input[i] <= 57 ) {

          int temp = 0;
          temp = input[i] - 48;

          a += temp * pow(10.0 , (location - (i + 1)));
      }
  }

  printf("\na값 : %d ", a);

  // 부호위치를 기준으로 뒤쪽의 값을 b로 대입 (단, 문자열을 분리하는 과정이므로.. 그걸 정수로 만드는건 알아서 대입)
  for (int i = location; i < str_len(input); i++) {

      if (input[i] >= 48 && input[i] <= 57) {

          int temp = 0;
          temp = input[i] - 48;

          b += temp * pow(10, ( (str_len(input) - 1 -  i )));
      }
  }

  printf("\nb값 : %d ", b);


  // 부호값에 따라 함수 포인터 pFunction의 주소가 달라짐(정확히는 실행하는 함수의 주소를 다르게 넣는 것!)
  if (c == '+') {
      pFunction = add;
  }
  else if (c == '-') {
      pFunction = sub;
  }
  else if (c == '*') {
      pFunction = mul;
  }
  else if (c == '/') {
      pFunction = div;
  }

  // pFunction을 놔도 연산이 가능하다 
  printf("\n계산 결과 값 : %d %c %d = %5d \n", a, c, b, pFunction(a, b));
  return 0;
}
