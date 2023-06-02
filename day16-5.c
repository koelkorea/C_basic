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


// [ N명의 학생 성적 & 이름 저장 ] 코드 작성
#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() 함수 사용 가능하게 함

typedef struct score {

    // 이름에 해당하는 문자열의 주소를 저장 (동적할당 후 그 위치를 받아 역참조를 통해 출력할 예정)
    char* name;
    int kor, eng, math, total;
    float avg;

}score;

// str_len(문자열 주소) : 해당 문자열의 길이 반환
int str_len(char* p) {

    int n = 0;              // 현재 문자열 길이을 나타냄
    while (*p++)n++;        // 현재 참고하는 문자열 주소 위치의 값을 역참조한 값이 null이 아니면? 숫자를 1개씩 올린다.    -> 이걸 문자열이 null이 나와 끝날때까지 계속하면, 문자열 길이 체크 가능
    return n;
}

// 성적 입력
void input(score* pS, int number);

// 성적 출력
void output(score* pS, int number);

// 동적할당 해제
void freeMemory(score* pS, int number);

int main(void) {
    srand((unsigned int)time(NULL));

    // 변수 n : 학생의 수, 
    int n = 0;
    long long size = 0;

    // start_address : 구조체 score 포인터변수 (n명의 학생수만큼에 해당하는 메모리크기를 동적할당 후 그 위치를 받아 역참조를 통해 성적과 이름 입력할 예정)
    score* start_address = 0;

    printf("성적을 입력할 학생은 몇 명인가? : ");
    scanf_s("%d", &n);

    // 입력받은 학생의 수만큼 score 구조체의 동적할당 유사배열 제작(그 시작위치 주소값을 받는게 score구조체 포인터변수 start_address)
    start_address = (score*)calloc(n, sizeof(score));
    size = _msize(start_address);

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    printf("할당된 메모리 : %lld \n", size);

    input(start_address, n);
    output(start_address, n);
    freeMemory(start_address, n);

    return 0;
}

// 성적 입력
void input(score* pS, int number) {

    // 학생수만큼 구조체 생성해서 역참조를 통해 정보 입력
    for (int i = 0; i < number; i++) {

        // scanf로 name 문자열 받기 위한 char 정적배열
        char input[1000] = { 0 };

        (pS + i)->kor = rand() % 101;
        (pS + i)->math = rand() % 101;
        (pS + i)->eng = rand() % 101;
        (pS + i)->total = (pS + i)->kor + (pS + i)->math + (pS + i)->eng;
        (pS + i)->avg = (pS + i)->total / 3;

        printf("[학생 %d 정보 입력]\n", i + 1);
        printf("국어 : %d\n", (pS + i)->kor);
        printf("수학 : %d\n", (pS + i)->math);
        printf("영어 : %d\n", (pS + i)->eng);
        printf("이름 : ");
        scanf_s("%s", input, sizeof(input));

        // (void*) calloc (size_t 개수, size_t 메모리크기)
        //  : _count 개수 * _size 메모리 크기 를 저장할 수 있는 메모리 공간을 할당 (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)

        // (중요) 문자열(char배열)을 동적 할당시... 문자열과 연관된 걸 할때는 그끝을 알리는 null 문자(\0)까지 포함해줘야 함
        (pS + i)->name = (char*)calloc(str_len(input) + 1, (sizeof(char)));

        // 역참조한 i번째 학생의 score 구조체의 name항목이 NULL이 아니라면..?
        if ((pS + i)->name != NULL) {

            // scanf로 입력한 name의 값을 받은 char배열 input의 내용을 i번째 학생의 score 구조체의 name항목(char임)을 저장하는 메모리에 이름의 길이에 해당하는만큼 반복적으로 저장하기
            // (= string함수인 strcpy_s를 통해 문자열을 복사해서 놔도 됨)
            for (int j = 0; j <= str_len(input); j++) {

                *(((pS + i)->name) + j) = input[j];
            }
        }

        printf("옮긴 이름 확인 : %s\n\n", (pS + i)->name);

        //free(input);          <- 지역변수는 free의 대상이 아님
    }

}

// 성적 출력
void output(score* pS, int number) {

    for (int i = 0; i < number; i++) {
        printf("학생 %d번. 이름 : %s, 총점 : %d점, 평균 : %4.2f점 \n", i + 1, (pS + i)->name, (pS + i)->total, (pS + i)->avg);
    }
}

// 동적할당 해제
void freeMemory(score* pS, int number) {

    // 각 구조체의 name 문자열을 길이만큼 저장하기 위해, score[i].name에 적혀있는 주소값에 동적으로 할당(임대)했던 메모리를 각각 해제(체크아웃)
    for (int i = 0; i < number; i++) {
        free((pS + i)->name);
    }

    // 구조체 n개에 해당하는 크기에 해당하는 내용을 저장하기 위해, 구조체 score 포인터변수 ps에 적혀있는 주소값에 동적 할당(임대)했던 메모리를 해제(체크아웃)
    free(pS);
}
