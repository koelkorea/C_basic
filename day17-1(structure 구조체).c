// struct, typedef, union, enum
 
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

//	# (주의) 구조체가 그렇다고 배열은 아니다 = 구조체변수 그 자체는 주소값을 가지지 않는다 = 포인터변수에 구조체변수만 대입할 수 없음
//		-> ex)  struct * s_pointer = man (X)
//					struct * s_pointer = &man (O)		<- 배열이 아니라 & 사용 필요

//  # 배열 vs 구조체
//      - 공통점 : 일종의 변수 그룹
//      - 차이점 : 배열은 같은 자료형의 그룹      <->     구조체는 다양한 자료형의 재정의

#include <stdio.h>
#include <string.h>

// 구조체 struct 사용 예시
struct student {

	int  no; // 학번 멤버 변수
	int  age; // 나이 멤버 변수
	char name[20]; // 이름 멤버 변수
	char phone[20]; // 전화번호 멤버 변수
};

int main() {
	//구조체 변수 선언 : struct 구조체명 구조체 변수명;  
	struct student st1, st2, st3;		
	
	st1.no = 1;			// 구조체 인스턴스 st1의 멤버변수 int no에 값 할당
	st1.age = 35;		// 구조체 인스턴스 st1의 멤버변수 int age에 값 할당

	// strcpy_s(복사 위치, 메모리 크기, "문자열") : string copy의 줄임말로 '문자열을 복사한다'는 의미 
	//		-> (중요) c에서 문자열은 char[]로 그냥 문자열을 대입을 하면, 반드시 에러가 생긴다 (string에 대응되는 자료형이 없고, char는 엄밀하게는 단일 문자대응하는 자료형)
	strcpy_s(st1.name, sizeof(st1.name), "James Robert");			//st1.name = "James Robert"; 에러!
	strcpy_s(st1.phone, sizeof(st1.phone), "010-1234-5678");

	st2.no = 2;
	st2.age = 24;
	strcpy_s(st2.name, sizeof(st2.name), "William Michael");
	strcpy_s(st2.phone, sizeof(st2.phone), "010-5678-1234");

	st3.no = 3;
	st3.age = 20;
	strcpy_s(st3.name, sizeof(st3.name), "Joshua David");
	strcpy_s(st3.phone, sizeof(st3.phone), "010-4321-8765");

	printf("%5d  %20s %4d %20s\n", st1.no, st1.name, st1.age, st1.phone);
	printf("%5d  %20s %4d %20s\n", st2.no, st2.name, st2.age, st2.phone);
	printf("%5d  %20s %4d %20s\n", st3.no, st3.name, st3.age, st3.phone);

	return 0;
}
