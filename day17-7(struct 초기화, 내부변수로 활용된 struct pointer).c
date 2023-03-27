// [구조체 전체 정리]

// 구조체 (struct)
//      : 두 개 이상의 변수(자료형)를 묶음으로 새로운 자료형으로 재정의
//          -> 일종의 멤버변수만 존재하는 객체와 유사 (원시형 객체라고 생각해두자)

//  #구조체 struct 형식 : 
//		struct 구조체명 {
//			자료형 멤버 1;
//			자료형 멤버 2;
 //		 …;
//		};

// # 구조체(struct) 선언
//      : struct 구조체명 구조체 변수명;  
//         ex) struct human man, woman;

// # 구조체 초기화법
//      : struct 구조체명 구조체 변수명 = { 값1, 값2, … };
//        ex) struct human man = { "Michelin", 21 };

// # 구조체의 멤버변수의 참조법
//      : 구조체변수명.멤버변수명
//         ex) man.age

//  # 배열 vs 구조체
//      - 공통점 : 일종의 변수 그룹
//      - 차이점 : 배열은 같은 자료형의 그룹      <->     구조체는 다양한 자료형의 재정의


// (중요!) 구조체(struct)도 포인터를 사용가능
//		-> 구조체도 주소값 및 역참조(간접 접근)이 가능함
// 
//		# 구조체 포인터 선언법 및 형식 
//         : struct 구조체명* 포인터 변수명;
//				-> (중요!) struct의 내부변수로서 사용가능

//		#포인터를 통한 구조체(struct)의 멤버변수 값을 참조하는 3가지 방법
//          1. 포인터변수명 -> 멤버변수명			  <- 구조체에서만 사용가능한 포인터 역참조 기호
//          2. 구조체변수명.멤버변수명
//          3. (*포인터변수명).멤버변수명          <- 연산자(간접 멤버 접근 연산자)를 이용

//  ex) struct person {
//             int no;
//             char name[20];
//             int score;
//             int rank;
//         };

//			struct person per1;			<- 구조체 변수 선언
//			struct person* pt;				<- 구조체 포인터변수 선언
//			pt = &per1;						<- 구조체 포인터변수 pt에 per1의 주소 할당

//			pt->name;							<- 1. 포인터변수명 -> 멤버변수명 방식 선언
//			(*pt).name;						<- 2. (*포인터변수명).멤버변수명 방식 선언
//			per1.name;						<- 3. 구조체변수명.멤버변수명 방식 선언

//	 (결론!) pt -> name; == (*pt).name == per1.name		<- 1,2,3번 방식으로 참고하면 똑같이 멤버변수 name의 값을 참조 가능

#include <stdio.h>

typedef struct subject {
	int kor, eng, mat, his;
}subject;

typedef struct student {
	int no;
	char name[20];
	subject* sp;		// 구조체의 멤버로 다른 구조체 포인터 선언
}student;

int main() {

	student ex_std1 = { 1, "michelin" };
	subject ex_sbj1 = { 84, 98, 87, 99 };

	ex_std1.sp = &ex_sbj1;		// student의 멤버변수 중 포인터 변수인 녀석에 주소값 대입

	printf("번호 : %d\n", ex_std1.no);
	printf("이름 : %s\n", ex_std1.name);

	printf("=====================\n");
	printf("과목  점수 \n");
	printf("=====================\n");
	printf("국어 : %3d\n", ex_std1.sp->kor);		//	구조체에서의 ->는 구조체 포인터 변수가 멤버변수를 역참조를 위한 것을 명심 
	printf("영어 : %3d\n", ex_std1.sp->eng);
	printf("수학 : %3d\n", ex_std1.sp->mat);
	printf("국사 : %3d\n", ex_std1.sp->his);
	printf("=====================\n");
	return 0;
}
