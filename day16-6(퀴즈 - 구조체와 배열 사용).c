#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() 함수 사용 가능하게 함

// 1학년 학생의 성적데이터 관리 프로그램 작성하기
//  -> 반이 총 몇개인지 입력받고
//  -> 해당 반의 학생이 몇명인지 입력받고
//  -> 그 반의 각 학생의 성적을 입력

// (풀이1) 구조체와 배열 사용
typedef struct class {
    int student_num;     // 학생의 수
    int* student_array;  // 학생들 성적배열의 시작위치 저장
    float average;
    float varience;
}class;

void read_score(); // 값 쓰기
void compute_average(); // 평균계산
void compute_varience(); // 분산계산
void print_result(); // 출력
void error(char*); // 예외처리
void release_memory(); //동적 할당 해제

int main(void) {

    srand((unsigned int)time(NULL));

    // 변수 class_num : 반의 총 개수, start_address : 점수 입력할 주소값 받을 녀석
    int class_num = 0;
    long long size = 0;

    // 구조체 class의 주소를 받을 class 포인터변수 
    //  -> 이를 매개로 역참조를 통해, 필요한 크기만큼 공간을 할당하고, 멤버변수인 class 포인트변수 class_start_address에 그 위치를 전달해주기 위함 
    class* class_start_address = 0;

    printf("해당 학년의 반은 몇 개인가? : ");
    scanf_s("%d", &class_num);

    // 입력받은 반의 수만큼 class 구조체의 동적할당 유사배열 제작(그 시작위치 주소값을 받는게 class구조체 포인터변수 start_address)
    class_start_address = (class*)calloc(class_num, sizeof(class));
    size = _msize(class_start_address);

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    printf("할당된 메모리 : %lld \n\n", size);

    read_score(class_start_address, class_num);

    compute_average(class_start_address, class_num);
    compute_varience(class_start_address, class_num);

    print_result(class_start_address, class_num);
    release_memory(class_start_address, class_num);

    return 0;
}

// 값 쓰기(class 구조체 포인터변수, 생성한 class 개수)
void read_score(class* class_pointer, int class_num) {

    // 생성한 class 개수만큼 반의 학생수를 동적으로 제시하고, 성적 순차적 입력
    for (int i = 0; i < class_num; i++) {

        // 각 반의 학생수 입력 -> student_num에 저장
        printf("\n%d반 학생수는 몇 명인가? : ", i + 1);
        scanf_s("%d", &((class_pointer + i) -> student_num));

        // 입력받은 반의 학생수들의 수만큼 int 자료형의 동적할당 유사배열 제작(그 배열의 시작위치 주소값을 받는게 int 포인터변수 student_start_address)
        (class_pointer + i) -> student_array = (class*)calloc((class_pointer + i)->student_num, sizeof(int));

        // 생성한 학생의 수만큼 생성된 동적 int배열에 성적 순차적 입력
        for (int j = 0; j < (class_pointer + i) -> student_num; j++) {

            // 각 학생의 성적 랜덤 지급
            *((class_pointer + i) -> student_array + j) = rand() % 101;
            printf("%d번 학생의 성적 : %d \n", j + 1, *((class_pointer + i) -> student_array + j));
        }
    }
}

// 평균계산
void compute_average(class* class_pointer, int class_num) {

    // 생성한 class 개수만큼 반의 학생수를 동적으로 제시하고, 주어진 성적을 이용해 반 평균 구하기
    for (int i = 0; i < class_num; i++) {

        (class_pointer + i)->average = 0;

        // 생성한 반의 학생의 수만큼 역참조를 통해 성적을 가져오고 이를 통해 평균 계산
        for (int j = 0; j < (class_pointer + i)->student_num; j++) {

            (class_pointer + i)->average += (*((class_pointer + i)->student_array + j) / (float)(class_pointer + i)->student_num);
        }
    }
}

// 분산계산
void compute_varience(class* class_pointer, int class_num) {

    // 생성한 class 개수만큼 반의 학생수를 동적으로 제시하고, 주어진 성적을 이용해 분산 구하기
    for (int i = 0; i < class_num; i++) {

        (class_pointer + i) -> varience = 0;

        // 생성한 반의 학생의 수만큼 역참조를 통해 성적을 가져오고 이를 통해 분산 계산
        for (int j = 0; j < (class_pointer + i)->student_num; j++) {

            (class_pointer + i) -> varience
                += (float)(((*((class_pointer + i)->student_array + j) - (class_pointer + i)->average)
                    * (*((class_pointer + i)->student_array + j) - (class_pointer + i)->average)) / (float)(class_pointer + i)->student_num);
        }
    }
}

// 출력
void print_result(class* class_pointer, int class_num) {

    printf("\n[결과 출력]\n");
    printf("  반  학생수      평균      분산\n");

    // 생성한 class 개수만큼 반의 학생수를 동적으로 제시하고, 출력
    for (int i = 0; i < class_num; i++) {

        printf("%d반  %5d명  %6.2f점  %6.2f점 \n", i + 1, (class_pointer + i)->student_num, (class_pointer + i)->average, (class_pointer + i)->varience);
    }
}

void error(char*); // 예외처리

//동적 할당 해제
void release_memory(class* class_pointer, int class_num) {

    // 각 구조체의 학생들의 수만큼의 성적울 저장하기 위해, 각 class의 name에 적혀있는 주소값에 동적으로 할당(임대)했던 메모리를 각각 해제(체크아웃)
    for (int i = 0; i < class_num; i++) {

        free((class_pointer + i)->student_array);
    }

    // 구조체 n개에 해당하는 크기에 해당하는 내용을 저장하기 위해, 구조체 class 포인터변수 class_pointer에 적혀있는 주소값에 동적 할당(임대)했던 메모리를 해제(체크아웃)
    free(class_pointer);
}
