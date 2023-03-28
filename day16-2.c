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
