// - 동적 할당 관련 함수
//  3. (void*) calloc (size_t _Count, size_t _size) 
//      : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

//      # (중요) malloc과의 차이점
//        1. 할당된 메모리 값 모두 0으로 초기화
//        2. 개수를 파라미터로 놔서, 직관성을 늘림

//  4. (void*) realloc (void* _Block, size_t size)
//      : 이미 할당한 포인터 변수의 주소값을 _block하고, 재할당 할 공간의 크기를 size에 입력 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

#include <stdio.h>
#include <stdlib.h>
int main() {

    long* buffer, * oldbuffer;

    // size_t : c언어 안에서 unsigned long long이 재정의 된 이름
    size_t size;

    // (void*) calloc (size_t 개수, size_t 메모리크기)
    //  : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
    buffer = (long*)calloc(40, sizeof(long));   // long에 해당하는 만큼의 메모리를 40개 연속해서 할당한 후, 그 시작 주소값을 반환 + 메모리값들 모두를 0으로 초기화

    // calloc의 결과 값
    if (buffer != NULL) {
        printf("sizeof(long) * 40 메모리 할당 성공!\n");
    }
    else {
        printf("메모리 할당 실패...\n");
    }

    free(buffer); // 할당받은 메모리 소멸

    // (void*)malloc(size_t s)
    //  : s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
    if ( (buffer = (long*) malloc ( sizeof(long) * 1000) ) == NULL) { // long에 해당하는 만큼의 메모리를 1000개 연속해서 할당한 후, 그 할당에 성공했으면 종료
        exit(1);
    }

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    size = _msize(buffer);  // 할당에 성공했으면, 그 메모리 크기를 size라는 변수에 대입

    printf(" (long x 1000) 메모리 malloc 동적 할당 : %lld\n", size);

    oldbuffer = buffer;     // 메모리 주소 값 임시 저장, ( 재할당 실패의 경우 NULL값 덮어쓰기 됨 )

    // (void*) realloc (void* _Block, size_t size)
    //  : 이미 할당한 포인터 변수의 주소값을 _block하고, 재할당 할 공간의 크기를 size에 입력 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
    if ( (buffer = realloc(buffer, (sizeof(long) * 2000) ) ) == NULL) { // buffer에 할당한 메모리를 block하고, long에 해당하는 만큼의 메모리를 2000개 연속해서 재할당한 후, 그 할당에 성공했으면 종료
        free(oldbuffer);    // 할당 실패 : 이전에 할당받은 메모리 소멸
        exit(1);            // 에러 종료
    }

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    size = _msize(buffer);  // 할당에 성공했으면, 그 메모리 크기를 size라는 변수에 대입

    printf(" (long x 2000) 메모리 ralloc 동적 할당 : %lld\n", size);

    free(buffer);

    return 0;
}
