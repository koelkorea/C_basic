// struct, typedef, union, enum

// 열거형(enum) 
//      : 문자열을 상수화 시켜 나열하며 정의하는 자료형 (프로그램의 가독성 ↑)
//          -> 각 문자열은 

//  # 열거형 enum  형식 및 선언 : 
//      : enum 열거형 이름 { 문자열상수1, 문자열상수2, … }; 
//         ex) enum week { SUN, MON, TUE, WED, THU, FRI, SAT };

//  # (중요!) 열거형 enum의 속성
//      1. {}안의 각 문자열들은 아무런 값이 대입되지 않으면, 1번째 위치의 문자열이 나타내는 상수값은 0이 대입      ex) SUN = 0부터 시작
//      2. {}안의 문자열이 1번째 위치가 아니라면, 그 문자열이 나타내는 상수값은 '이전 문자열의 상수값 +1' 이 됨
//      3. {}안에 문자열 중, 값을 임의로 대입한 문자열은 1,2의 조건을 쌩까고 대입된 값을 보여줌

#include <stdio.h>

// enum 사용
typedef enum week1 { SUN, MON, TUE, WED, THU, FRI, SAT } WEEK;      // <SUN = 0부터 시작>
enum week2 { SU = 2, MO = 9, TU, WE = 10, TH, FR, SA };
enum week3 { S = 9, M , T, W = 5, U, F = 10, A };

int main() {

    WEEK day1[7] = { SUN, MON, TUE, WED, THU, FRI, SAT };           
    enum week2 day2[7] = { SU, MO, TU, WE, TH, FR, SA };
    enum week3 day3[7] = { S, M, T, W, U, F, A };

    for (int i = 0; i < 7; i++) {
        printf("week1 : %d \tweek2 : %d \tweek3 : %d \n", day1[i], day2[i], day3[i]);
    }

    //  week1: 0       week2 : 2       week3 : 9
    //  week1 : 1       week2 : 9       week3 : 10
    //  week1 : 2       week2 : 10      week3 : 11
    //  week1 : 3       week2 : 10      week3 : 5
    //  week1 : 4       week2 : 11      week3 : 6
    //  week1 : 5       week2 : 12      week3 : 10
    //  week1 : 6       week2 : 13      week3 : 11

    return 0;
}
