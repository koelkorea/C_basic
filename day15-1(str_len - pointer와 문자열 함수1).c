#include <stdio.h>

// str_len(문자열 주소) : 해당 문자열의 길이 반환
int str_len(char* p) {

    int n = 0;
    while (*p++)n++;
    return n;
}

int main() {

    char c[15] = "C language", d[50];
    int len;
    len = str_len(c);
    printf("문자열 길이 : %d\n", len);
    printf("문자열 입력 : ");
    scanf_s("%s", d, (int)sizeof(d));
    len = str_len(d);
    printf("문자열 길이 : %d\n", len);
    return 0;
}
