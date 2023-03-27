// 구조체 (struct, typedef, union, enum)
//      : 두 개 이상의 변수(자료형)를 묶음으로 새로운 자료형으로 재정의
//          -> 일종의 멤버변수만 존재하는 객체와 유사 (원시형 객체라고 생각해두자)

// typedef    A    B
//		: A 자료 타입의 또 다른 이름을 B로 정의한다
//			-> B를 선언 (= A를 선언)

//  # typedef 형식 : 
//		typedef struct student {
//			int no;
//			char name[20];
//			int score;
//			int rank;
//		} STU;			<- 타입 재정의

//		STU st1, st2, st3;		<- student 구조체 3개 선언

// struct, typedef, union, enum

// # typedef 선언 
//      : typedef 자료형 재정의명칭
//         ex1) typedef unsigned char uchar;			
//				     uchar i, j;												<- 선언
//         ex2) typedef int* intptr;								
//				     intptr p;													<- 선언


// typedef를 통한 구조체 재정의 (student to STU)
#include <stdio.h>
typedef struct student {
	int no;
	char name[20];
	int score;
	int rank;
} STU;		// (중요) STU = struct student로서 인식 (= 일종의 단축어라 생각하면 편함)

int main() {

	STU st;		//  struct student st;		와 같은 인식

	printf("번호를 입력하세요 :");
	scanf_s("%d", &st.no);

	printf("이름을 입력하세요 :");
	scanf_s("%s", st.name, (int)sizeof(st.name));

	printf("점수를 입력하세요 :");
	scanf_s("%d", &st.score);

	printf("순위를 입력하세요 :");
	scanf_s("%d", &st.rank);

	printf("\n");

	printf("=============================\n");
	printf("번호\t이름\t점수\t순위\n");
	printf("%4d\t%s\t%4d\t%4d\n", st.no, st.name, st.score, st.rank);
	printf("=============================\n");
	return 0;
}
