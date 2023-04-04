// - 동적 할당 관련 함수
//  1. (void*) malloc (size_t s)
//      : s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
//          -> 보통 사용할 때는 대상이 될 포인터변수의 자료형과 일치시키는 형변화를 하는게 좋음 
//             (= void* 포인터 변수의 특징을 기억하면 쉽다)

//      # (중요) size_t s : * n 를 통해 원하는 만큼의 메모리를 쉽게 할당 가능 (여기서의 *는 곱하기를 의미)

//  2. (void) free (void* p); 
//		: void 포인터 변수 p가 가리키는 주소값의 메모리 영역 할당을 프리하게 해제하는 함수
//			-> 메모리 누수 대비

//      ex) 배열의 포인터	  (int*) malloc(sizeof(int) * n)  =  int score1[n] 에 해당하는 만큼의 메모리 공간을 할당하겠음 (이런 의미지 같다는 말은 아님.. )

//          int* score1;
//          score1 = (int*) malloc (sizeof(int) * n);		<- 시작 주소(void *)를 정수형 포인터(int *)로 형변환 후 score 대입	(sizeof(int) * n : 여기서의 *는 곱하기를 의미, 메모리의 시작주소(void *) 반환)
//          free(score1);                                   <- score1이 가리키는 메모리 해제

//      ex) 포인터 배열의 포인터  (int**) malloc(sizeof(int*) * n)   =  int* score2[n] 에 해당하는 만큼의 메모리 공간을 할당하겠음 (이런 의미지 같다는 말은 아님.. )

//          int** score2;
//          score2 = (int**)malloc(sizeof(int*) * n);
//          free(score2);				                    <- score2가 가리키는 메모리 해제

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct score {
    int kor, eng, mat, total;
    char* memo; //문자열 주소를 저장
}score;

int main() {

    char buf[1024];
    score* s;
    int number, i;

    printf("학생 수 입력 : ");
    scanf_s("%d", &number);

    // 구조체 n개 메모리 할당, 그 시작 주소를 반환
    s = (score*)malloc(sizeof(score) * number);                 // score s[n];
    
    for (i = 0; i < number; i++) {

        printf("\n % d번째 입력\n" , i + 1);

        printf("국어 : ");
        scanf_s("%d" , &s[i].kor);

        printf("영어 : ");
        scanf_s(" %d" , &s[i].eng);

        printf("수학 : ");
        scanf_s("%d", &s[i].mat);
        while (getchar() != '\n');

        printf("메모 : ");
        scanf_s("%s" , buf, (int)sizeof(buf));
        while (getchar() != '\n');

        //buf에 입력된 문자열 길이 + 1 (\0)만큼 메모리 할당         
        s[i].memo = (char*)malloc(strlen(buf) + 1);                        // char s[i].memo[buf+1];            <- 할당 받은 메모리의 시작 주소를 반환

        strcpy_s(s[i].memo, (strlen(buf) + 1), buf);
        s[i].total = s[i].kor + s[i].eng + s[i].mat;
    }

    printf("\n\n *** 학생 평균 ***\n");

    for (i = 0; i < number; i++) {
        printf("%d번. %.2f점\n", i + 1, (double)s[i].total / 3);
        printf("메모 : %s\n", s[i].memo);
    }

    printf("\n");

    for (i = 0; i < number; i++) {
        free(s[i].memo); // 구조체 배열 크기만큼 해제
    }

    free(s); //s가 가리키는 메모리 해제
    return 0;
}
