// - 동적 할당 관련 함수
//  3. (void*) calloc (size_t _Count, size_t _size) 
//      : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

//      # (중요) malloc과의 차이점
//        1. 할당된 메모리 값 모두 0으로 초기화
//        2. 개수를 파라미터로 놔서, 직관성을 늘림

//  4. (void*) realloc (void* _Block, size_t size)
//      : 이미 할당한 포인터 변수의 주소값을 _block하고, 재할당 할 공간의 크기를 size에 입력 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() 함수 사용 가능하게 함

// N명의 학생 성적 입력 & 출력 코드를 작성하는 문제 (동적할당을 쓰도록!)
int main(void) {
    srand((unsigned int)time(NULL));

    // 변수 n : 학생의 수, start_address : 점수 입력할 주소값 받을 녀석
    int n = 0, size = 0;
    int* start_address = 0;

    // 평균, 편차, 분산, 표준편차
    float average = 0, deviation = 0, variance = 0, standard_deviation = 0;

    printf("성적을 입력할 학생은 몇 명인가? : ");
    scanf_s("%d", &n);

    // int n개 메모리 할당, 그 시작 주소를 int 포인터변수 start_address에 반환
    //  -> 이를 통해 구조체 배열 int start_address[n]을 동적으로 선언한 효과를 냄
    
    // (void*) calloc (size_t _Count, size_t _size) 
    //  : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
    start_address =  (int*) calloc(n, sizeof(int));  // int 포인터변수에 해당하는 만큼의 메모리를 n개 연속으로 동적 할당한 후, 그 시작 주소값을 int 포인터변수 start_address 반환 + 메모리값들 모두를 0으로 초기화

    size = _msize(start_address);

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    printf("할당된 메모리 : %d \n", size);

    // 동적할당된 주소값이 저장된 start_address를 역참조하여 학생들 성적 입력
    for (int i = 0; i < n; i++) {
        *(start_address + i) = rand() % 101;
        printf("학생 %d : %d\n", i + 1, *(start_address + i));

        // 평균 구하기
        average += ((float) *(start_address + i) / n);
    }

    // 같은 원리로 편차와 분산 구하기
    for (int i = 0; i < n; i++) {

        deviation = (float)(*(start_address + i) - average);
        variance += (deviation * deviation / n);
    }
    
    // 표준편차 구하기
    standard_deviation = sqrt(variance);

    printf("평균 : %3.6f점 \n", average);
    printf("분산 : %3.6f점 \n", variance);
    printf("표준편차 : %3.6f점 \n", standard_deviation);


    return 0;
}
