// 동적 할당
//  : 메모리 영역 할당 후, 필요가 없을 시 이를 그 영역 부여를 해제하는 것

// - 동적할당의 필요성
//		: 한정된 자원 메모리를 효율적으로 사용하기 위한 방법 (필요할 때만 배분, 끝나면 회수)
//			-> 필요없는 메모리가 회수되지 않는다면? 이건 메모리 누수의 원인이 됨

// - 동적 할당 관련 함수
//  1. (void*) malloc (size_t s)
//      : s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
//          -> 보통 사용할 때는 대상이 될 포인터변수의 자료형과 일치시키는 형변화를 하는게 좋음 
//             (= void* 포인터 변수의 특징을 기억하면 쉽다)

//      # (중요) size_t s : * n 를 통해 원하는 만큼의 메모리를 쉽게 할당 가능 (여기서의 *는 곱하기를 의미)

//  2. (void*) calloc (size_t _Count, size_t _size) 
//      : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

//      # (중요) malloc과의 차이점
//        1. 할당된 메모리 값 모두 0으로 초기화
//        2. 개수를 파라미터로 놔서, 직관성을 늘림

//  3. (void*) realloc (void* _Block, size_t size)
//      : 이미 할당한 포인터 변수의 주소값을 _block하고, 재할당 할 공간의 크기를 size에 입력 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

 
//  4. (void) free (void* p); 
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

//N개 데이터 평균 분산 구하기
#include <stdio.h>
#include <stdlib.h> //malloc(), free()
int main() {
    int i, n;
    int* score; //동적 할당 받을 포인터 변수
    float sum, average, variance;

    printf("몇 명의 성적을 입력 하나요? ");
    scanf_s("%d", &n);

    // int(4byte)*n의 메모리 할당        <- int score[n]; 같은 의미 ( 증감연산자 사용X )
    score = (int*)malloc(sizeof(int) * n);      //  메모리 시작주소 반환(void *) - (void * -> int *) 형 변환
    
    for (i = 0; i < n; i++) {
        printf("학생 %2d : ", i + 1);
        scanf_s("%d", &score[i]); //score +i 같은 표현
    }

    for (sum = 0.0, i = 0; i < n; i++) {
        sum += score[i];
    }

    average = sum / n;

    for (sum = 0.0, i = 0; i < n; i++) {
        sum += (score[i] - average) * (score[i] - average);
    }

    variance = sum / n;

    printf("평균과 분산은 %f, %f 이다\n", average, variance);

    free(score);    // 동적 할당 받은 메모리 해제

    return 0;
}
