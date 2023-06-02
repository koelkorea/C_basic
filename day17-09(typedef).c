// struct, typedef, union, enum
   
// typedef  자료형A    B
//  : 자료형A의 또 다른 이름을 B로 정의한다 (= 사실상 치환)
//     -> B를 선언 (= 자료형A를 선언)

//   # typedef 형식 : 
//  
//       typedef struct student {
//           int no;
//           char name[20];
//           int score;
//           int rank;
//       } STU;			         <- student라는 struct 변수를 재정의 (= 사실상 struct student를 치환)
         
//       STU st1, st2, st3;      <- student 구조체 3개 선언		<- OOP의 클래스 선언 및 생성자 사용과 유사한 부분이 존재함 (기원 정도로 생각)
    
//   # (중요) typedef를 통한 구조체 재정의를 통한 구조체 선언은 oop의 클래스 인스턴스 선언과 유사함 (클래스에 얘가 숨겨져 있다고 보면 편함)
    
//   # typedef 선언 
//     : typedef 자료형 재정의명칭
// 
//         ex1) typedef unsigned char uchar;			
//              uchar i, j;							<- unsigned char i, j선언
// 
//         ex2) typedef int* intptr;								
//              intptr p;							<- unsigned int* p선언

// typedef를 통한 구조체 재정의 (student to STU)
#include <stdio.h>
typedef struct student {
	int no;
	char name[20];
	int score;
	int rank;
} STU;		// (중요) STU = struct student로서 인식 (= 일종의 단축어라 생각하면 편함)

int main() {

	// (중요) 추후 클래스 선언과 유사한 구문임
	STU st;		//  struct student st;  와 같은 인식

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
