#include <stdio.h>		
#include<math.h>

// while을 이용하여, 제곱근을 구하는 프로그램을 만들어라... 단, 기능 수행 후.. q, Q를 누르면 나가게 해야함
int main() {
	
	double number;
	double result;
	char flag = 0;		

	while (flag != 81 && flag != 113) {			// ASCII코드로 Q: 113, q : 81

		printf("제곱근을 구할 숫자를 써라 :  ");
		scanf_s("%lf", &number);			// double도 실수로 출력문자는 f지만, 일종의 long 자료형으로서 lf로 쓴다 (scanf에서 double로 값을 받으려면 %lf 필수다!)
		while (getchar() != '\n');

		result = sqrt(number);
		printf("%lf의 제곱근은 %lf다.  \n\n", number, result);

		printf("계속할려면 아무키나 누르세요 / 종료 (Q / q) : ");

		scanf_s("%c", &flag);
		while (getchar() != '\n');

		printf(" \n");
	}

	printf("종료완료했습니다. \n");

	return 0;
}