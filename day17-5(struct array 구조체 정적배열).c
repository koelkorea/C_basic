//  구조체의 정적배열 (struct array)
//      : 구조체도 재정의된 자료 타입 = 구조체 역시 정적 배열(array)의 형태로 사용 가능
//          -> 구조체도 배열화 하여 같은 형식의 여러 데이터를 한꺼번에 만들 수 있음
//              (= OOP의 클래스 객체의 원형이자, 발상의 기원)

#include <stdio.h>
#include <stdlib.h> //system() : 화면 지우기
#define MAX 3

// struct 정적array 사용 예시
// ex) 3명의 학생의 정보를 저장하는 코드
typedef struct student {
    int no;
    char name[20];
    char phone[20];
} STU;

int main() {

    STU st[MAX];        //STU 구조체 배열 선언

    for (int i = 0; i < MAX; i++) {

        system("cls");
        printf("\n\t\t*** 학생정보 입력 ***\n");

        st[i].no = i + 1; //자동일련번호
        printf("번    호 : %03d", st[i].no);

        printf("\n이    름 : ");
        scanf_s("%s", st[i].name, (int)sizeof(st[i].name));
        while (getchar() != '\n'); //입력 버퍼 비우기

        printf("전화번호 : ");
        scanf_s("%s", st[i].phone, (int)sizeof(st[i].phone));
        while (getchar() != '\n');
    }

    system("cls");
    printf("\n\t\t*** 출 력 결 과 ***\n");

    for (int i = 0; i < MAX; i++) {
        printf("\t%d. 이    름 : %s\n\t   전화번호 : %s\n\n\n", st[i].no, st[i].name, st[i].phone);
    }

    return 0;
}
