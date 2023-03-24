#include <stdio.h>

// char* str_cat(char 문자열 주소1, char 문자열 주소2) : 2번째 문자열을 1번째 문자열 뒤에 붙여서 복사하고 난뒤, 1번쨰 문자열 반환
char* str_cat(char* p, char* q) {
    char* sx = p;
    while (*p)p++; // p가 가리키는 곳을 문자열의 \0 문자 위치로 (문자열 끝으로) 변경
    while (*q)*p++ = *q++; // 이어 붙이기
    *p = '\0'; // 문자열 마지막 주소에 \0 값 넣기
    return sx; // 문자열 첫 주소 반환
}
int main() {
    char a[100] = "C language", * b = (char*)" Keep Calm and Carry On"; //(const char)
    char c[100], d[50];
    //str_cat(a, b);
    printf("*a + *b = %s\n\n", str_cat(a, b));
    printf("1 문자열 입력 : ");
    scanf_s("%s", c, (int)sizeof(c));
    while (getchar() != '\n');
    printf("2 문자열 입력 : ");
    scanf_s("%s", d, (int)sizeof(d));
    while (getchar() != '\n');
    printf("*c + *d = %s\n\n", str_cat(c, d));
    return 0;
}
