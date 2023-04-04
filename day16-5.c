#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() 함수 사용 가능하게 함

typedef struct score {
    char* name;     // 문자열의 주소를 저장
    int kor, eng, math, total;
    float avg;
}score;

// str_len(문자열 주소) : 해당 문자열의 길이 반환
int str_len(char* p) {

    int n = 0;              // 현재 문자열 길이을 나타냄
    while (*p++)n++;        // 현재 참고하는 문자열 주소 위치의 값을 역참조한 값이 null이 아니면? 숫자를 1개씩 올린다.    -> 이걸 문자열이 null이 나와 끝날때까지 계속하면, 문자열 길이 체크 가능
    return n;
}

void input(score* pS, int number);
void output(score* pS, int number);
void freeMemory(score* pS, int number);

// [ N명의 학생 성적 & 이름 저장 ] 코드 작성
int main(void) {
    srand((unsigned int)time(NULL));

    // 변수 n : 학생의 수, start_address : 점수 입력할 주소값 받을 녀석
    int n = 0;
    long long size = 0;
    score* start_address = 0;

    printf("성적을 입력할 학생은 몇 명인가? : ");
    scanf_s("%d", &n);

    start_address = (score*)calloc(n, sizeof(score));
    size = _msize(start_address);

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    printf("할당된 메모리 : %lld \n", size);

    for (int i = 0; i < n; i++) {

        char input[1000] = {0};

        (start_address + i)->kor = rand() % 101;
        (start_address + i)->math = rand() % 101;
        (start_address + i)->eng = rand() % 101;
        (start_address + i)->total = (start_address + i)->kor + (start_address + i)->math + (start_address + i)->eng;
        (start_address + i)->avg = (start_address + i)->total / 3;

        printf("[학생 %d 정보 입력]\n", i + 1);
        printf("국어 : %d\n", (start_address + i)->kor);
        printf("수학 : %d\n", (start_address + i)->math);
        printf("영어 : %d\n", (start_address + i)->eng);
        printf("이름 : ");
        scanf_s("%s", input, sizeof(input) );

        // 동적 할당시... 문자열과 연관된 걸 할때는 그끝을 알리는 null 문자까지 포함해줘야함
        (start_address + i)->name = (char*)calloc(str_len(input)+1, (sizeof(char)));

        if ((start_address + i)->name != NULL) {

            for (int j = 0; j <= str_len(input); j++) {
                *(((start_address + i)->name) + j) = input[j];
            }
        }
        printf("옮긴 이름 확인 : %s\n\n", (start_address + i)->name);
        //free(input);          <- 지역변수는 free의 대상이 아님
    }

    for (int i = 0; i < n; i++) {
        printf("학생 %d번. 이름 : %s, 총점 : %d점, 평균 : %4.2f점 \n", i+1, (start_address + i)->name, (start_address + i)->total, (start_address + i)->avg);
        free(((start_address + i)->name));
    }

    free(start_address);

    return 0;
}

void input(score* pS, int number) {

}
void output(score* pS, int number) {

}
void freeMemory(score* pS, int number) {


}
