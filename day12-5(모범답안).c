// 함수포인터를 사용해서, 계산기를 구현해봐라 (단, 연산을 받을때는 한번에 다 받아야 함)
//  -> 나와 다른점 : scanf_s 대신 gets_s로 문자열을 받음
#include<stdio.h>
#include<string.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

int main(void) {

    // 변수 a, b 받을 녀석
    int a = 0, b = 0;

    // 부호 받을 c, 식을 받을 input배열
    char c = 0, buf[1025] = { 0 };

    printf("예시( 3 + 5 ) 입력 : ");

    // gets_s : 입력된 문자열 1줄을 지정하는 char 배열에 넣어줌, 반드시 파라미터로 메모리 크기를 할당해줘야 함
    gets_s(buf, sizeof(buf) - 1);

    // 반복문을 돌리되, buf[k]가 처음으로 0~9까지 이외의 값이 나온 시기를 기점으로 값이 변한거까지 3개 조건으로 설정
    for (int k = 0; k < strlen(buf); k++) {

        // buf[k]가 숫자인데 부호인 c가 초기값이 0이면, a값을 구하는데 연산
        if ('0' <= buf[k] && buf[k] <= '9' && c == 0) {
            a = a * 10 + buf[k] - 48;
        }

        // buf[k]가 숫자인데 부호인 c가 초기값이 아닌 0이면(부호가 확정나면), b값을 구하는데 연산
        else if ('0' <= buf[k] && buf[k] <= '9' && c != 0) {
            b = b * 10 + buf[k] - 48;
        }

        // buf[k]가 숫자 이외의 부호값이 나오면, 확정
        else if (buf[k] != '0') c = buf[k];

        else break;
    }

    // 함수 포인터 선언법 ( asterisk(*) 연산자 사용)
    //  : 자료형 (* 함수포인터변수명) (매개변수1, 매개변수2, …)
    int (*pF)(int, int) = NULL;

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
