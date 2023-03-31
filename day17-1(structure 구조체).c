// struct, typedef, union, enum
 
// 구조체 (struct)
//	: 두 개 이상의 변수(자료형)를 묶음으로 새로운 자료형으로 재정의
//		-> 일종의 멤버변수만 존재하는 객체와 유사 (원시형 객체라고 생각해두자)

//		#구조체 struct 형식 : 
//			struct 구조체명 {
//				자료형 멤버 1;
//				자료형 멤버 2;
//			 …;
//			};

//		# 구조체(struct) 선언
//		     : struct 구조체명 구조체 변수명;  
//		        ex) struct human man, woman;

//		# 구조체 초기화법
//		     : struct 구조체명 구조체 변수명 = { 값1, 값2, … };
//		       ex) struct human man = { "Michelin", 21 };

//		# 구조체의 멤버변수의 참조법
//		     : 구조체변수명.멤버변수명
//		        ex) man.age

//		# (주의) 구조체가 그렇다고 배열은 아니다 = 구조체변수 그 자체는 주소값을 가지지 않는다 = 포인터변수에 구조체변수만 대입할 수 없음
//				ex) struct * s_pointer = man (X)
//				    struct * s_pointer = &man (O)		<- 배열이 아니라 & 사용 필요

//		# 배열 vs 구조체
//			- 공통점 : 일종의 변수 그룹
//			- 차이점 : 배열은 같은 자료형의 그룹      <->     구조체는 다양한 자료형의 재정의


// (중요!) 
// 구조체(struct)도 포인터를 사용가능
//	-> 구조체도 주소값 및 역참조(간접 접근)이 가능함

//		# 구조체 포인터 선언법 및 형식 
//		   : struct 구조체명* 포인터 변수명;
//				-> (중요!) struct의 내부변수로서 사용가능

//		#포인터를 통한 구조체(struct)의 멤버변수 값을 참조하는 3가지 방법
//		    1. 포인터변수명 -> 멤버변수명			<- 구조체에서만 사용가능한 포인터 역참조 기호
//		    2. 구조체변수명.멤버변수명
//		    3. (*포인터변수명).멤버변수명			<- 연산자(간접 멤버 접근 연산자)를 이용

//			ex) struct person {
//				    int no;
//				    char name[20];
//				    int score;
//				    int rank;
//				};

//				struct person per1;				<- 구조체 변수 선언
//				struct person* pt;				<- 구조체 포인터변수 선언
//				pt = &per1;						<- 구조체 포인터변수 pt에 per1의 주소 할당

//				pt->name;						<- 1. 포인터변수명 -> 멤버변수명 방식 선언
//				(*pt).name;						<- 2. (*포인터변수명).멤버변수명 방식 선언
//				per1.name;						<- 3. 구조체변수명.멤버변수명 방식 선언

//				(결론!) pt -> name; == (*pt).name == per1.name		<- 1,2,3번 방식으로 참고하면 똑같이 멤버변수 name의 값을 참조 가능

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
