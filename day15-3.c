#include <stdio.h>

// pointer로 strupr(), strlwr(), strrev(), strcmp(), strchr() 구현

//1. strupr() : 문자열에 포함된 소문자를 모두 대문자로 변환하는 함수
char* str_upr(char* str) {
    char* sx = str;

    while ( *str ) {

        if (*str >= 97 && *str <= 122) {
            *str -= 32;
        }
        str = str + 1;
    }
    return sx; // 문자열 첫 주소 반환
}

//2. strlwr() : 문자열에 포함된 대문자를 모두 소문자로 변환하는 함수
char* str_lwr(char* str) {
    char* sx = str;

    while (*str ) {
        if (*str >= 65 && *str <= 90) {
            *str += 32;
        }
        str = str + 1;
    }
    return sx; // 문자열 첫 주소 반환
}

//3. strrev()문자열의 순서를 바꾸는 함수
char* str_rev(char* str) {

    int n = 0;
    char* sx = str;

    // 문자열 길이 구하기
    while (*str) {
        n++;
        str = str + 1;
    }

    str = sx;
    // printf("%d\n", n);

    for (int i = 0; i < n/2; i++) {

        char temp;

        temp = *(str + n -1 - i);
        *(str + n -1 - i) = *(str + i);
        *(str + i) = temp;

        //printf("temp :  %c\n", temp);
        //printf(" *(str + n - i) :  %c\n", *(str + n - i));
        //printf(" * (str + i) : % c\n", *(str + i));
    }

    return sx; // 문자열 첫 주소 반환
}

//4. strcmp() ver1 : 문자열 내에 일치하는 문자가 있는지 검사하는 함수 (성공시 문자의 주소 반환)
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

//4. strcmp() ver2: 문자열의 일치하는 문자의 수량 검사하는 함수 (성공시 포함된 문자의 수량 반환)
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

//5. strchr() : 두 개의 문자열을 아스키 코드 값으로 비교 (2문자열의 각 자리수를 비교하다가 판정이 나오면 리턴값 주기)
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

    // printf("%d\n", n);

    for (int i = 0; i < n; i++) {

        if (*(str1 + i) > *(str2 + i)) {
            result = 1;
            break;

        }
        else if (*(str1 + i) < *(str2 + i)) {
            result = -1;
            break;
        }

    }

    return result;
}


int main() {
    char a[100] = "C language", * b = (char*)" Keep Calm and Carry On", c[100] = "C javaguage"; //(const char)
    //char c[100], d[50];
    //str_cat(a, b);
    printf("str_upr(a) = %s\n\n", str_upr(a));
    printf("str_lwr(a) = %s\n\n", str_lwr(a));
    printf("str_rev(a) = %s\n\n", str_rev(a));
    printf("str_chr(b, 67) = %s\n\n", str_chr(b, 67));
    printf("str_cnt(b, 67) = %d\n\n", str_cnt(b, 67));
    printf("str_cmp(a, c) = %d\n\n", str_cmp(a, c));

    return 0;
}
