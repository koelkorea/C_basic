#include <stdio.h>		
#include <conio.h>		// (헤더) conio.h (console and port I/0의 약자) :  c언어의 콘솔 입출력 함수를 제공
int main() {

	char 문자;
	int 정수;

	// LFCR : Line Feed 다음 줄로 이동 CR : Cariage Return 첫째칸으로 이동에 대한 묶음 말
	printf("10(LF : Line Feed 다음 줄로 이동), 13 (CR : Cariage Return 이 첫째칸으로 이동) \n");
	printf("문자를 입력하세요 : ");

	scanf_s("%d", &정수);	// 여기서 정수 + 문자열을 입력시... ? 정수는 정수라는 변수명에 저장되고, 표준 입력 스트림에는 문자열만 남음
	printf("%d\n", &정수);

	while (1) {

		// getchar() : 표준 입력 스트림인 키보드로부터 하나의 문자를 입력받음
		
		//	-getchar()의 특이사항
		//		1.  복수의 문자열을 입력했을 때? 
		//				-> 다음 while 순환때 순차적으로 입력
		//		2.. 이전의 scan을 통한 값 입력 중, 자료형에 부합하지 않은 경우에 해당하는 경우... ?
		//				-> 그 저장되지 않은 입력값들이 전부 getchar()를 실행할 때의 결과값으로 인식됨..
		//						ex) 75d 라는 값을 입력하면... 정수라는 변수명에 75는 저장.. d는 다음 getchar() 코드 수행시 입력된 문자로 판정
		printf("\n getchar : ");
		문자 = getchar();
		while (getchar() != '\n');		// 표준 입력 스트림에  연속된 값이 입력된 경우.. 추후 프로그램의 기능에 해당 값이 영향을 미치지 않게 입력된 모든 입력값을 전부 빼내기 위한 코드..  (특이사항1번에 따른 연속된 문자열이 추후 while 순환에 영향 안 미침)
		printf("\n 입력한 문자 : ");
		putchar(문자);						// int putchar(int) : 표준 출력 스트림에 하나의 문자를 쓰는 함수
		printf("\n ASCII코드 값은 %d 입니다. \n", 문자);


		//  _getch() , _getche()
		//		- 공통점 : 표준 입력 버퍼를 사용하지 않음
		//		- 차이점 : 에코 여부

		// _getch() : (값을 입력할 때까지 대기했다가) 콘솔 입력으로 표준 입력 버퍼에 저장되지 않고, 입력된 키값을 즉시반환 (에코 X)
		//		-> 표준 입력 버퍼를 사용하지 않음 = getchar()와 관계가 없음
		printf("\n _getch : ");
		문자 = _getch();		// Enter 없이 바로 입력, 에코(입력한 키값을 다시 보여주는지 여부) X
		printf("\n 입력한 문자 : ");
		putchar(문자);
		printf("\n ASCII코드 값은 %d 입니다. \n", 문자);

		// _getche() : (값을 입력할 때까지 대기했다가) 콘솔 입력으로 표준 입력 버퍼에 저장되지 않고, 입력된 키값을 즉시반환 (에코 ㅇ)
		//		-> 표준 입력 버퍼를 사용하지 않음 = getchar()와 관계가 없음
		printf("\n _getche : ");
		문자 = _getche();		// Enter 없이 바로 입력, 에코(입력한 키값을 다시 보여주는지 여부) ㅇ
		printf("\n 입력한 문자 : ");
		putchar(문자);
		printf("\n ASCII코드 값은 %d 입니다. \n", 문자);

	}


}