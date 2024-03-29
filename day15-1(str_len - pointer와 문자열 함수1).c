// 문자열(string)의 특성을 이용한 문자열(string) 헤더의 함수들
//  : 그 자체가 내용과 시작주소값 전부를 의미하는 char 배열이라는 점을 적극 활용
//      ->  Call by reference 를 활용, 파라미터로 문자열(char배열)의 시작주소를 넣으면, 
//          이를 포인터로 활용하여 char배열을 메모리 주소를 사용해 데이터 읽기, 쓰기 가능함... (= 이걸로 문자열 조작을 꿈꿀수 있음)

//  # Array, pointer, string 간 삼단논법 정리
//    1. 포인터 변수 = 어떤 변수나 객체의 주소값
//    2. 배열명 그 자체 = 배열변수[0]의 주소값(시작주소)
//         -> 그래서 배열변수는 &없이 포인터변수에 대입 가능!         
// 
//            ex) a[100];     int* num = a;
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
// 
//                 ---------------------------------------------------------------------------------
//                 |   단일 자료형 변수   |     자료형 배열     |           문자열(char[])         |
//   -----------------------------------------------------------------------------------------------
//   |   주소값    |       &변수명        |       변수명        |      그 자신 혹은 변수명(대입시) |
//   -----------------------------------------------------------------------------------------------

#include <stdio.h>

// str_len(문자열 주소) : 해당 문자열의 길이 반환
int str_len(char* p) {

    // 현재 문자열 길이을 나타냄
    int n = 0;

    // 현재 참고하는 문자열 주소 위치의 값을 역참조한 값이 null이 아니면? 숫자를 1개씩 올린다.   
    //  -> 이걸 문자열이 null이 나와 끝날때까지 계속하면, 문자열 길이 체크 가능
    while (*p++) n++;

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
