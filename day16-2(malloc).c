//  - 동적 할당 관련 함수
//     : 결과값은 메모리 공간이 할당된 void* '주소값'
//       (= 형변환을 통해 타자료형 포인터변수에 대입이 가능함)

//       1. (void*) malloc (size크기자료형 메모리byte수)
//           : s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
//               -> 보통 사용할 때는 대상이 될 포인터변수의 자료형과 일치시키는 형변화를 하는게 좋음 
//                  (= void* 포인터 변수의 특징을 기억하면 쉽다)

//            # (중요) size_t s : typedef를 통해 재정의 된 long long 자료형 변수
//            # 동적할당 함수이므로 할당하는 메모리 크기는 특정자료형의 size와 * n 를 통해 원하는 만큼의 메모리를 쉽게 할당 가능 (여기서의 *는 곱하기를 의미)

//       2. (void*) calloc (size크기자료형, size_t 메모리byte수) 
//           : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

//            # (중요) malloc과의 차이점
//              1. 할당된 메모리 값 모두 0으로 초기화
//              2. 개수를 파라미터로 놔서, 직관성을 늘림

//       3. (void*) realloc (void* block원하는주소값, size크기자료형 재할당메모리byte수)
//           : 이미 할당한 포인터 변수의 주소값을 _block하고, 재할당 할 공간의 크기를 size에 입력 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

//       4. (void) free (void* p); 
//           : void 포인터 변수 p가 가리키는 주소값의 메모리 영역 할당을 프리하게 해제하는 함수(메모리 누수 대비)


//   # 크기가 미정인 정적배열 int a[n], int* a[n]를 동적할당을 통해 선언하는 효과를 내는 방법 (원래는 불가능하지만 동적할당을 그런 효과를 내는 메모리공간을 할당가능)

//       ex) 동적할당으로 int score1[n] 선언하는 효과 내기
//           (= 동적할당 함수의 리턴값인 시작주소값이 int의 포인터변수로 해석되도록 형변환 시킴으로서 각 배열의 index처럼 순차적인 주소의 값에 접근)
//               -> (int*) malloc(sizeof(int) * n)  =  int score1[n] 에 해당하는 만큼의 메모리 공간을 할당하겠음 (이런 의미지 같다는 말은 아님.. )

//                  int* score1;
//                  score1 = (int*) malloc (sizeof(int) * n);       <- 시작 주소(void *)를 정수형 포인터(int *)로 형변환 후 score 대입	(sizeof(int) * n : 여기서의 *는 곱하기를 의미, 메모리의 시작주소(void *) 반환)
//                  free(score1);                                   <- score1이 가리키는 메모리 해제

//       ex) 동적할당으로 int* score2[n] 선언하는 효과 내기
//           (= 동적할당 함수의 리턴값인 시작주소값이 int*의 포인터변수(int의 포인터변수의 위치를 나타내는 2중포인터 변수)로 해석되도록 형변환 시킴으로서 각 포인터 배열의 index처럼 순차적인 주소에 위치한 int변수의 주소값에 접근)
//               -> (int**) malloc(sizeof(int*) * n)   =  int* score2[n] 에 해당하는 만큼의 메모리 공간을 할당하겠음 (이런 의미지 같다는 말은 아님.. )

//                  int** score2;
//                  score2 = (int**)malloc(sizeof(int*) * n);
//                  free(score2);                                   <- score2가 가리키는 메모리 해제


// 동적할당 함수 (void*) malloc (size_t 메모리byte수) 사용 예시
// -> 학생들의 수를 동적으로 입력받고, 그 숫자만큼 score라는 구조체에 학생들의 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct score {
    int kor, eng, mat, total;
    char* memo; //문자열 주소를 저장
}score;

int main() {
    
    // scanf로 메모 문자열 받기 위한 정적배열
    char buf[1024];
    
    // 구조체 score의 주소를 받을 score 포인터변수 
    //  -> 이를 매개로 역참조를 통해, 필요한 크기만큼 공간을 할당하고, 멤버변수인 char 포인트변수 memo에 그 위치를 전달해주기 위함 
    score* s;
    
    int number;

    printf("학생 수 입력 : ");
    scanf_s("%d", &number);

    // 구조체 n개 메모리 할당, 그 시작 주소를 score 포인터변수 s에 반환
    //  -> 이를 통해 구조체 배열 score s[n]을 동적으로 선언한 효과를 냄
    
    // (void*) malloc (size_t 메모리byte수)
    //   : s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
    s = (score*) malloc(sizeof(score) * number);
    
    // 학생수만큼 구조체 생성해서 역참조를 통해 정보 입력
    for (int i = 0; i < number; i++) {

        printf("\n % d번째 입력\n" , i + 1);

        printf("국어 : ");
        scanf_s("%d" , &s[i].kor);

        printf("영어 : ");
        scanf_s(" %d" , &s[i].eng);

        printf("수학 : ");
        scanf_s("%d", &s[i].mat);
        while (getchar() != '\n');

        // 메모의 내용은 처음에는 정적배열에다 저장
        printf("메모 : ");
        scanf_s("%s" , buf, (int)sizeof(buf));
        while (getchar() != '\n');

        // char정적배열 buf에 입력된 문자열 길이 + 1 (\0)만큼 메모리 할당   
        //  -> 이를 통해 char 배열 char s[i].memo[buf+1]을 동적으로 선언한 효과를 냄
        s[i].memo = (char*)malloc(strlen(buf) + 1);

        // strcpy_s : 지정한 문자열을 복사하여 원하는 위치에 옮겨오는 string 함수 (c언어 일반함수 레벨에서는 string을 사용하기 힘듦)
        strcpy_s(s[i].memo, (strlen(buf) + 1), buf);
        
        s[i].total = s[i].kor + s[i].eng + s[i].mat;
    }

    printf("\n\n *** 학생 평균 ***\n");

    for (int i = 0; i < number; i++) {
        printf("%d번. %.2f점\n", i + 1, (double)s[i].total / 3);
        printf("메모 : %s\n", s[i].memo);
    }

    printf("\n");

    // 각 구조체의 memo 문자열을 길이만큼 저장하기 위해, s[i].memo에 적혀있는 주소값에 동적으로 할당(임대)했던 메모리를 각각 해제(체크아웃)
    for (int i = 0; i < number; i++) {

        free(s[i].memo); 
    }
    
    // 구조체 n개에 해당하는 크기에 해당하는 내용을 저장하기 위해, 구조체 score 포인터변수 s에 적혀있는 주소값에 동적 할당(임대)했던 메모리를 해제(체크아웃)
    free(s); 
    return 0;
}
