#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() 함수 사용 가능하게 함

// 1학년 학생의 성적데이터 관리 프로그램 작성하기
//  -> 반이 총 몇개인지 입력받고
//  -> 해당 반의 학생이 몇명인지 입력받고
//  -> 그 반의 각 학생의 성적을 입력

// (풀이2) 포인터 배열과 배열 사용
int main(void) {
    srand((unsigned int)time(NULL));

    // 변수 class_num : 반의 총 개수, start_address : 점수 입력할 주소값 받을 녀석
    int class_num = 0;
    long long size = 0;
    int** class_start_address = 0;

    printf("해당 학년의 반은 몇 개인가? : ");
    scanf_s("%d", &class_num);

    // 입력받은 반의 수만큼 int 포인터변수 자료형의 동적할당 유사배열 제작(그 시작위치 주소값을 받는게 int 포인터변수 start_address)
    class_start_address = (int**)calloc(class_num, sizeof(int*));
    size = _msize(class_start_address);

    // _msize() : 포인터가 가리키는 메모리 크기를 반환하는 함수
    printf("할당된 메모리 : %lld \n\n", size);

    // 반의 총 개수만큼 반복문
    for (int i = 0; i < class_num; i++) {

        int student_num = 0;
        float class_total = 0;

        // 각 반의 학생수 입력 -> student_num에 저장
        printf("\n%d반 학생수는 몇 명인가? : ", i + 1);
        scanf_s("%d", &student_num);

        // 입력받은 반의 학생수들의 수만큼 int 자료형의 동적할당 유사배열 제작
        // (그 배열의 시작위치 주소값은 int 2중 포인터변수 class_start_address가 저장한 메모리 위치에 순차적으로 저장되어 있음)
        *(class_start_address + i) = (int*)calloc(student_num, sizeof(int));

        for (int j = 0; j < student_num; j++) {

            // 각 학생의 성적 랜덤 지급
            *(*(class_start_address + i) + j) = rand() % 101;
            printf("%d번 학생의 성적 : %d \n", j + 1, *(*(class_start_address + i) + j));
        }
    }

    printf("\n[결과 출력]\n");
    printf(" 반   학생수     평균      분산\n");

    // 평균, 분산 계산 및 프린트
    for (int i = 0; i < class_num; i++) {

        float class_total = 0;
        float average = 0;
        float varience = 0;
        int student_num = 0;

        // 학년 총점에 가산
        while (*(*(class_start_address + i) + student_num) >= 0 && *(*(class_start_address + i) + student_num) <= 100) {
            class_total += *(*(class_start_address + i) + student_num);
            student_num++;
        }

        average = class_total / student_num;

        for (int j = 0; j < student_num; j++) {

            varience += ( ( *(*(class_start_address + i) + j) - average) * ( *(*(class_start_address + i) + j) - average) );
        }

        varience /= student_num;
       
        printf("%d반  %5d명  %5.2f점  %5.2f점 \n", i + 1, student_num, average, varience);
        free(*(class_start_address + i));
    }

    free(class_start_address);

    return 0;
}