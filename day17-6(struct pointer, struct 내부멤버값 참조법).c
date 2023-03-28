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
typedef struct score {
	int kor, eng, mat, sum;
}SCO;

// 구조체의 멤버변수값 역참조하기 예시
int main() {

	SCO st = { 100, 100, 100 };		// {값1, 값2 ...} : 구조체 선언 후, 값 할당하는 방법
	SCO* p;
	p = &st;			// 구조체 포인터변수 pt에 per1의 주소 할당

	printf("%d %d %d %d\n", st.kor, st.eng, st.mat, st.sum);
	printf("%d %d %d %d\n", st.kor, st.eng, st.mat, st.kor + st.eng + st.mat);								//sum == 0
	printf("%d %d %d %d\n", p->kor, p->eng, p->mat, p->kor + p->eng + p->mat);					//sum == 0
	printf("%d %d %d %d\n", (*p).kor, (*p).eng, (*p).mat, (*p).kor + (*p).eng + (*p).mat);		//sum == 0
	printf("%d %d %d %d\n", st.kor, st.eng, st.mat, st.sum);

	p->sum = p->kor + p->eng + p->mat;																							//sum == 300

	printf("1. sum = %d\n", st.sum);
	printf("2. sum = %d\n", p->sum);
	printf("3. sum = %d\n", (*p).sum);

	return 0;
}
