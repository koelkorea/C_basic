#include <stdio.h>		

// switch문
//		: 파라미터로 들어가는 변수(수식이면 수식의 결과)값에 따라 처리되는 경우가 달라지는 조건문
//			-> (주의사항) 
//					1.  파라미터로 들어갈 조건이 정수형(int, char)만 자료형으로 사용 가능
//					2. case별 스코프 {}가 없고 switch문당 하나 뿐이라... = if문과 다르게, 지역변수가 케이스별로 구분되기 쉽지 않다..
//					3. 중첩 switch문도 가능은 하다.. 근데 많이 비직관적이므로 ... 걍 중복if문 써..
//					4. 문법이 많이 엄격하다... 하지만 속도는 많이 유리하기에... 한 조건의 경우의 수가 많으면 많을수록 switch가 유리
//						-> if문은 구조상 일일히 조건을 다 봐야하지만, switch문은 조건 하나를 보고 정답을 찾아가는거라 로직상 유리
int main() {

	char c;
	printf("f, e, h 문자만 입력하시길 바랍니다 : ");
	scanf_s("%c", &c);

	switch (c) {		// 파라미터로 들어갈 조건이 정수형(int, char)만 자료형으로 사용 가능

		case 'f' : printf("file menu \n"); break;		//	'case 케이스명 : 작동코드'로 경우의 수에 따른 코딩 가능, 단 break문을 써줘야 그 조건에서 조건문이 종료된다 (안 끊으면 그 밑의 경우의 수 코드도 다 작동..)
		case 'e' : printf("edit menu \n"); break;	// break : 여기서 조건문, 반복문을 끝내고 빠져나오라는 코드 (정확히는 스코프{}를 빠져나오라는 말)
		case 'h' : printf("help menu \n"); break;
		default: printf("error! ");								// default는 조건문의 else에 해당하는 녀석
	}

	return 0;
}