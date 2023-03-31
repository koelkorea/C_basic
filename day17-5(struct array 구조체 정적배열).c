// 구조체의 정적배열 (struct array)
//	: 구조체도 재정의된 자료 타입 = 구조체 역시 정적 배열(array)의 형태로 사용 가능
//		-> 구조체도 배열화 하여 같은 형식의 여러 데이터를 한꺼번에 만들 수 있음
//		   (= OOP의 클래스 객체의 원형이자, 발상의 기원)

//      # (중요!) array변수의 이중성을 다시 기억해야 함
//          - array변수 자신 : 포인터변수 (array자신의 시작주소값을 의미)
//          - []와 함께 경우 : 배열 안에 위치하는 단순 자료형 변수 (= 포인터와 관련성이 1도 없음)

//			ex) struct person per[20];			<- 구조체 배열변수 선언 (= per1 자체는 포인터변수)

//				per->name;						<- 1. 포인터변수명 -> 멤버변수명 방식 (= per[0]의 name)
//				(*(per + 2)).name;				<- 2. (*포인터변수명).멤버변수명 방식 (= per[3]의 name)
//				per[10].name;					<- 3. 구조체변수명.멤버변수명 방식		<- (중요!) []가 붙는 순간 per[10]은 포인터변수랑은 1도 관계가 없는 배열의 index에 위치하는 값을 의미하게 됨 


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
