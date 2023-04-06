// 1학년 학생의 성적데이터 관리 프로그램 작성하기
//  -> 반이 총 몇개인지 입력받고
//  -> 해당 반의 학생이 몇명인지 입력받고
//  -> 그 반의 각 학생의 성적을 입력

// (특이점 1) 평균, 분산에 해당하는 배열 또한 동적할당으로 값을 저장
// (특이점 2) 메모리 해체를 print_result의 과정으로 둠
// (특이점 3) 전역변수 사용 + 2차원 배열 사용


#include <stdio.h>
#include <stdlib.h> //malloc(), free(), srand(), rand()
#include <time.h> //time()

void read_score(); // 값 쓰기
void compute_stat(); // 계산
void print_result(); // 출력
void error(char*); // 예외처리
void release_memory(); //동적 할당 해제

int no_class; // 분반 값 변수
int* no_student; // 분반 별 학생수를 가리키는 포인터
float* ave, * var; // 분반 별 평균값, 분산값 가리키는 포인터
int** score; // 분반 별 성적을 가리키는 포인터 배열
float tot_ave, tot_var; // 전체 평균 수치

int main() {
    read_score(); // 성적 입력
    compute_stat(); // 평균값, 분산값 계산
    print_result(); // 출력
    return 0;
}
void read_score() {

    srand((unsigned)time(NULL));
    printf("분반 수를 입력하세요.:");
    scanf_s("%d", &no_class);

    //int no_student[no_class]; 분반 별 학생 수 값 배열
    no_student = (int*)malloc(no_class * sizeof(int));
    
    //float ave[no_class];  분반 별 평균 값 배열
    ave = (float*)malloc(no_class * sizeof(float));
    
    //float var[no_class];  분반 별 분산 값 배열
    var = (float*)malloc(no_class * sizeof(float));
    
    //int * score[no_class]; 분반 별 성적을 가리키는 포인터 배열
    score = (int**)malloc(no_class * sizeof(int*));
    
    if (no_student == NULL || ave == NULL || var == NULL || score == NULL)
    {
        error("메모리 부족");
    }

    for (int i = 0; i < no_class; i++) {
        printf(" %d 반의 학생 수를 입력하세요.", i + 1);
        scanf_s(" %d", &no_student[i]);

        score[i] = (int*)malloc(no_student[i] * sizeof(int));

        //int score[i][no_student] 분반 당 학생 인원수의 성적 배열
        if (score[i] == NULL) { error("메모리 부족"); }

        printf(" %d 반 %d명 학생의 성적을 입력하세요.\n", i + 1, no_student[i]);

        for (int j = 0; j < no_student[i]; j++) {

            score[i][j] = rand() % 100 + 1;
            printf("%4d\n", score[i][j]);
        }
    }
}

void compute_stat() {

    int i, j;
    float sum, total_ave = 0.0, total_var = 0.0;

    for (i = 0; i < no_class; i++) {

        for (sum = 0.0, j = 0; j < no_student[i]; j++) {
            sum += score[i][j];
        }

        ave[i] = sum / no_student[i];
        total_ave += ave[i];

        for (sum = 0.0, j = 0; j < no_student[i]; j++) {
            sum += (score[i][j] - ave[i]) * (score[i][j] - ave[i]);
        }

        var[i] = sum / no_student[i];
        total_var += var[i];
    }
    tot_ave = total_ave / no_class;
    tot_var = total_var / no_class;
}

void print_result() {

    printf("%3s %7s %9s %9s\n", "분반", "학생수", "평균", "분산");

    for (int i = 0; i < no_class; i++) {
        printf("%3d %7d %11.2f %11.2f\n", i + 1, no_student[i], ave[i], var[i]);
    }

    printf("%11s %8.2f %11.2f\n", "전체 평균 수치", tot_ave, tot_var);

    release_memory();
}

void release_memory() {

    for (int i = 0; i < no_class; i++) {
        free(score[i]);
    }

    free(score);
    free(no_student);
    free(ave);
    free(var);
}

void error(char* message) {

    printf("ERR : %s \n", message);
    exit(1);
}
