// 동적 할당
//  : 정해진 크기의 메모리를 미리 부여하는 정적 할당과 달리, 필요한 만큼 임의적인 크기의 메모리를 특정 주소값 위치에 할당하는(공간을 쓸수 있게 여는) 개념

//  # 메모리 영역을 할당한 후에는, 필요가 없을 시 반드시 이를 그 영역 부여를 기억해서, 코드 말미에 수동으로 해체해야 한다 (사용자가 임의적으로 배정한 메모리 공간이기 때문)
//    -> 이런 불편함이 후기의 언어들에 가비지 콜랙터(GC) 개념을 탑재하게 만들어, 메모리 누수를 위한 방어를 자동적으로 하게 유도함

//  # (중요) 정적할당과 차이점 : 할당크기를 변수로 입력 가능하냐 여부가 차이점
//    -> 정적할당 : 크기를 반드시 상수로서 결정해서 코드에 선언해야 함 (ex 정적배열 int xxx[30]  <- []안은 정수로 들어가야 함)
//    -> 동적할당 : 크기를 변수로 둘 수 있고 나중에 정해줘도 상관없음 (ex 동적배열 vector, ArrayList 등)

// - 동적할당의 필요성
//  : 한정된 자원 메모리를 효율적으로 사용하기 위한 방법 (필요할 때만 배분, 끝나면 회수) + 메모리 할당 크기에 대해서 상수로 확정지으면 많이 불편함
//     -> 필요없는 메모리가 회수되지 않는다면? 이건 메모리 누수의 원인이 됨

// - 동적할당의 특징
//  1. (중요) 동적할당을 실행하는 함수를 통한 결과값은 메모리 공간이 할당된 void 포인터변수로'주소값'
//  2. 결과값이 void* = 그 주소값에 위치하는 변수를 어떤 자료형으로 읽을지는 확정나지 않음 
//     -> (중요!) 그 자리에 역참조를 통한 값 입력이나 읽기를 하기 위해서는, 타자료형 포인터변수로 반드시 형변환을 해줘야 함
//  3. 반드시 사전에 크기를 상수로 정해줘야 하는 정적할당과 다르게, 동적할당은 크기를 변수로 둘 수 있고 나중에 정해줘도 상관없음

//  # 크기가 미정인 정적배열 int a[n], int* a[n]를 동적할당을 통해 선언하는 효과를 내는 방법 (원래는 불가능하지만 동적할당을 그런 효과를 내는 메모리공간을 할당가능)

//      ex) 동적할당으로 int score1[n] 선언하는 효과 내기 (= 동적할당 함수의 리턴값인 시작주소값이 int의 포인터변수로 해석되도록 형변환 시킴으로서 각 배열의 index에 접근)
//          -> (int*) malloc(sizeof(int) * n)  =  int score1[n] 에 해당하는 만큼의 메모리 공간을 할당하겠음 (이런 의미지 같다는 말은 아님.. )

//          int* score1;
//          score1 = (int*) malloc (sizeof(int) * n);       <- 시작 주소(void *)를 정수형 포인터(int *)로 형변환 후 score 대입	(sizeof(int) * n : 여기서의 *는 곱하기를 의미, 메모리의 시작주소(void *) 반환)
//          free(score1);                                   <- score1이 가리키는 메모리 해제

//      ex) 동적할당으로 int* score2[n] 선언하는 효과 내기(= 동적할당 함수의 리턴값인 시작주소값이 int*의 포인터변수(int의 포인터변수의 위치를 나타내는 2중포인터 변수)로 해석되도록 형변환 시킴으로서 각 포인터 배열의 index에 접근)
//          -> (int**) malloc(sizeof(int*) * n)   =  int* score2[n] 에 해당하는 만큼의 메모리 공간을 할당하겠음 (이런 의미지 같다는 말은 아님.. )

//          int** score2;
//          score2 = (int**)malloc(sizeof(int*) * n);
//          free(score2);                                   <- score2가 가리키는 메모리 해제


// - 동적 할당 관련 함수 : 결과값은 메모리 공간이 할당된 void* '주소값'(= 형변환을 통해 타자료형 포인터변수에 대입이 가능함)
//  1. (void*) malloc (size_t 메모리byte수)
//      : s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
//          -> 보통 사용할 때는 대상이 될 포인터변수의 자료형과 일치시키는 형변화를 하는게 좋음 
//             (= void* 포인터 변수의 특징을 기억하면 쉽다)

//      # (중요) size_t s : typedef를 통해 재정의 된 long long 자료형 변수
//      # 동적할당 함수이므로 할당하는 메모리 크기는 특정자료형의 size와 * n 를 통해 원하는 만큼의 메모리를 쉽게 할당 가능 (여기서의 *는 곱하기를 의미)

//  2. (void*) calloc (size_t *n갯수, size_t 메모리byte수) 
//      : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

//      # (중요) malloc과의 차이점
//        1. 할당된 메모리 값 모두 0으로 초기화
//        2. 개수를 파라미터로 놔서, 직관성을 늘림

//  3. (void*) realloc (void* block원하는주소값, size_t 재할당메모리byte수)
//      : 이미 할당한 포인터 변수의 주소값을 _block하고, 재할당 할 공간의 크기를 size에 입력 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
 
//  4. (void) free (void* p); 
//		: void 포인터 변수 p가 가리키는 주소값의 메모리 영역 할당을 프리하게 해제하는 함수(메모리 누수 대비)

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
