// struct, typedef, union, enum

// 공용체(union) 정의
//  : 여러 가지 자료형의 데이터를 하나의 기억 장소에서 공유하며 저장
//     -> 해당 공용체의 멤버 중, 가장 큰 자료형 1개의 공간만 할당 ( <-> struct는 모든 멤버변수의 메모리를 할당)
//         -> (중요) 정확히는 모든 변수들이 메모리를 공유하는데, 더 큰 값이 들어오면 이를 덮어쓰는 구조이다..
// 
//             ex) int 와 double을 가진 경우, double이 입력되도 이전에 있던 int값에는 접근이 가능하나.. 그 값은 주어진 8byte에 덮어씌워진 double 중 4byte를 int로 읽은 값에 불과함
   
   
//   # 공용체 union 형식 및 선언 : 
// 
//       union 공용체명 {
//           자료형 멤버 1;
//           자료형 멤버 2;
//           …;
//       };
         
//       ex) union int_or_float {
//              int a;
//              float b;
//           };
   
//   # 구조체(struct) vs 공용체(union)
//      - 공통점 : 원시형태의 객체형식
//      - 차이점 : 구조체는 모든 멤버변수의 메모리를 전부 할당    
//                                  <->     
//                 공용체는 멤버변수 중 가장 큰 메모리를 가진 자료형의 변수 1개에만 할당 (집단은 존재하나, 사실상 나머지는 존재하지 않는 유령회사라 생각하자)


// 구조체(struct) vs 공용체(union)의 차이 예시
#include <stdio.h>

// typedef를 통한 공용체변수 Unum의 이름 재정의 -> Unum to Union
typedef union Unum {
    double d;
    int i;
} Union;

// typedef를 통한 구조체변수 Snum의 이름 재정의 -> Snum to Struct
typedef struct Snum {
    double d;
    int i;
} Struct;

int main() {

    // 재정의 된 공용체, 구조체 정의
    Union u_num;
    Struct s_num;

    printf("Union 정수  입력 :");
    scanf_s("%d", &u_num.i);

    printf("Union 정수       : %10d \t \t union  whole size : %3d\n\n", u_num.i, (int)sizeof(u_num));

    printf("Union 실수  입력 :");
    scanf_s("%lf", &u_num.d);

    // (중요) int 와 double을 가진 경우, double이 입력되도 이전에 있던 int값에는 접근이 가능하나.. 그 값은 주어진 8byte에 덮어씌워진 double 중 4byte를 int로 읽은 값에 불과함
    printf("Union 정수 (손실): %10d \t \t union    int size : %3d\n", u_num.i, (int)sizeof(u_num.i));
    printf("Union 실수       : %10.2lf \t \t union double size : %3d\n\n", u_num.d, (int)sizeof(u_num.d));

    printf("---------------------------------------------------------------------\n\n");

    printf("Struct 정수 입력 :");
    scanf_s("%d", &s_num.i);

    printf("Struct 정수      : %10d \t \t struct  whole size : %3d\n\n", s_num.i, (int)sizeof(s_num));

    printf("Struct 실수 입력 :");
    scanf_s("%lf", &s_num.d);

    printf("Struct 정수      : %10d \t \t struct    int size : %3d\n", s_num.i, (int)sizeof(s_num.i));
    printf("Struct 실수      : %10.2lf \t \t struct double size : %3d\n\n", s_num.d, (int)sizeof(s_num.d));
    return 0;
}
