#include <stdio.h>


// pointer로 strcmp(), strchr() 구현

//문자열 내에 일치하는 문자가 있는지 검사하는 함수 (성공시 문자의 주소 반환)
char* str_chr(char* str1, int ch) {
    int num = 0;

    while (*str1) {

        if (*str1 == ch) {
            return str1;  // 문자열 주소 반환
        }
        str1 = str1 + 1;
    }
    return NULL; // null 반환
}

//문자열의 일치하는 문자의 수량 검사하는 함수 (성공시 포함된 문자의 수량 반환)
int str_cnt(char* str1, int ch) {
    int num = 0;

    while (*str1) {

        if (*str1 == ch) {
            num++;              // 문자열 찾을때마다 개수 반환
        }
        str1 = str1 + 1;
    }
    return num;              // 최종개수 반환
}

//두 개의 문자열을 아스키 코드 값으로 비교 (2문자열의 각 자리수를 비교하다가 판정이 나오면 리턴값 주기)
//  - str1 < str2 인 경우 - 1 반환
//  - str1 > str2 인 경우 1 반환
//  - str1 == str2 인 경우 0 반환 <- 최종
int str_cmp(char* str1, char* str2) {

    int n1 = 0;
    int n2 = 0;
    int n = 0;
    int result = 0;

    char* sx1 = str1;
    char* sx2 = str2;

    // 문자열1의 길이 구하기
    while (*str1) {
        n1++;
        str1 = str1 + 1;
    }

    // 문자열1의 길이 구하기
    while (*str2) {
        n2++;
        str2 = str2 + 1;
    }

    str1 = sx1;
    str2 = sx2;

    if (n1 != n2) {

        if (n1 > n2) {
            n = n1;
        }
        else if (n1 < n2) {
            n = n2;
        }
    }
    else {

        n = n1;
    }

    printf("%d\n", n);

    for (int i = 0; i < n; i++) {

        if (*(str1 + i) > *(str2 + i) ){
            result = 1;
            break;

        }else if (*(str1 + i) < *(str2 + i)) {
             result = -1;
             break;
        }

    }

    return result; 
}


int main() {
    char a[100] = "C language", * b = (char*)" Keep Calm and Carry On" , c[100] = "C javaguage"; //(const char)

    // char c[100], d[50];
    //str_cat(a, b);
    printf("str_chr(b, 67) = %s\n\n", str_chr(b, 67) );
    printf("str_cnt(b, 67) = %d\n\n", str_cnt(b, 67) );
    printf("str_cmp(a, c) = %d\n\n", str_cmp(a, c) );

    /*   printf("1 문자열 입력 : ");
       scanf_s("%s", c, (int)sizeof(c));
       while (getchar() != '\n');
       printf("2 문자열 입력 : ");
       scanf_s("%s", d, (int)sizeof(d));
       while (getchar() != '\n');
       printf("*c + *d = %s\n\n", str_cat(c, d));*/
    return 0;
}
