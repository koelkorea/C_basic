// 문자열(string)의 특성을 이용한 문자열(string) 헤더의 함수들
//  : 그 자체가 내용과 시작주소값 전부를 의미하는 char 배열이라는 점을 적극 활용
//      ->  Call by reference 를 활용, 파라미터로 문자열(char배열)의 시작주소를 넣으면, 
//          이를 포인터로 활용하여 char배열을 메모리 주소를 사용해 데이터 읽기, 쓰기 가능함... (= 이걸로 문자열 조작을 꿈꿀수 있음)

//  # Array, pointer, string 간 삼단논법 정리
//    1. 포인터 변수 = 어떤 변수나 객체의 주소값
//    2. 배열명 그 자체 = 배열변수[0]의 주소값(시작주소)
//         -> 그래서 배열변수는 &없이 포인터변수에 대입 가능!         
// 
//            ex) a[100];     int *num = a;
// 
//    3. string =  char []   
//        -> 문자열 그 자체 = 해당 문자열(char배열)의 주소값(시작주소)    
//            -> (결론) 그래서 문자열은 &도 없고 변수명도 없어도 포인터 변수에 대입이 쌉가능하다..      
//
//               ex) char* char1 = "아 포인터 ㅈㄴ 어렵다";      <-  이딴게 가능하다

//  # (중요) 문자열의 특성
//      : 문자열은 1. 문자 내용도 갖지만, 2. 그 자체로도 자신의 시작주소를 가지는 어이없는 존재다!
//         -> 문자열 = char [] = char [] 시작주소값(= 본 문자열 시작점의 주소값)  ==  char배열로서 변수 대입도 없이 포인터 변수에 문자열 그대로 대입이 가능하고, 주소로 인정된다...
//              <-> 최소한 배열은 포인터변수에 자신의 요소값을 직접 넣을수도 없다는 점이 아주 다르며... 보통의 변수들은 &가 있어야 입력가능하다..
//                   -> (중요) C++에서 문자열 char[]이 상수 char 포인터 'const char*'으로 자료형이 구분되어 쓸 수 있는 이유 

//  # 자료 형태별 주소값 (포인터 변수 대입 가능여부)
//                          단일 자료형 변수       타자료형 배열                     문자열(char배열)
//      주소값               &변수명                      변수명                     그 자신 혹은 변수명(대입시)




// pointer로 strupr(), strlwr(), strrev(), strcmp(), strchr() 구현 예시코드
#include <stdio.h>

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
