// 함수포인터를 사용해서, 계산기를 구현해봐라 (단, 연산을 받을때는 한번에 다 받아야 함)
//  -> 나와 다른점 : scanf_s 대신 gets_s로 문자열을 받음
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

        else if (buf[k] != '0') c = buf[k];

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
