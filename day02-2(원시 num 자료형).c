#include <stdio.h>		
int main() {
	
	// 변수명은 대소문자를 별개로 인식함
	int num = 97;	
	int minus = -97;

	//	char형 overflow CASE(-128 ~ 127 까지만 표현)
	char a = 130, b = -130;			

	// float는 소수점자리수가 6~7까지만 표현가능
	float n1 = 1.23456789;		
	double n2 = 123.456789;

	// char 자료형의 overflow의 경우 부호역전이 일어남 
	//  : 방식상 char의 첫자리는 +/-를 정한다 (1000000은 -128로 취급한다는 점을 알아둬라)
	//     -> 따라서 2의 8제곱으로 나타낼수 있는 256가 아니라, 2의 7승으로 나타낼수 있는 128가지의 수에 1번째 자리수가 0/1이냐에 따라 -128 ~ 127 까지만 표현
	//        (10000000는 -128, 00000000은 0이라고 치고 나머지 7자리의 수를 여기에 더하면 숫자가 나옴)
	//     -> 그런데 char 자료형에서 -128 ~ 127을 넘어설 경우, 그 넘어선 수는 맨 앞의 부호에 해당하는 수를 건들게 됨.. 
	//         -> 하지만 그거랑 별개로 컴퓨터는 그 수를 기존 char 형식대로 계산해 읽기에 문제가 생김

	printf("a : %d \n", a);                        // -126 (원래 a는 +130)
	printf("b : % d \n", b);	                   //  126 (원래 b는 -130)


	// %(0 or -)숫자1.숫자2문자
	//  : 어떤 변수를 특정 문자로 숫자1에 해당하는 자리수로 고정하고, 숫자2만큼의 소수점 자리수 만큼만 반올림해서 표기 
	//		->  '%숫자1.숫자2문자' 앞에 0이 붙어 있다면
	//          : 숫자1에 해당하는 자리에 부족한 수만큼을 0으로 채운다.

	//		-> '%숫자1.숫자2문자' 앞에 -가 붙어있다면
	//          : 숫자1에 해당하는 자리수를 왼쪽이 아닌 오른쪽을 기준으로 표기한다

	printf("n1 (실수형) : %.2f \n", n1);           // 1.23
	printf("n1 (지수형) : %.2e \n", n1);           // 1.23e+00

	// 실수형에 자리수를 규정한다면? 
	//  -> ㅈ도 관계없이 왠만하면 전체 실수를 다 표기
	printf("n1 (실수형) : %4lf \n", n1);           // 1.234568
	printf("n1 (지수형) : %4le \n", n1);           // 1.234568e+00
	printf("n2 (실수형) : %4lf \n", n2);           // 123.456789
	printf("n2 (지수형) : %4le \n", n2);           // 1.234568e+02

	// 실수를 억지로 정수로 표기한다면?
	//		-> 소수점은 물론이고 걍 값이 깨진다
	printf("n1 (실수형을 10진 소수점 2자리로?) : %.2d \n", n1); // 1.23
	printf("n1 (지수형을 10진 소수점 2자리로?) : %.2d \n", n1); // 1.23e+00
	printf("n1 (실수형을 10진으로?) : %4ld \n", n1);            // 1.234568
	printf("n1 (지수형을 10진으로?) : %4ld \n", n1);            // 1.234568e+00

	// 같은 값도 진수에 따라 다르게 출력
	printf("num : %5d \n", num);
	printf("num : %5o \n", num);
	printf("num : %5x \n", num);
	printf("num : %5u \n", num);
	printf("num : %5c \n", num);

	// -값을 타 진수로 한다면?
	printf("minus : %5d \n", minus);               // -97
	printf("minus : %5o \n", minus);               // 37777777637
	printf("minus : %5x \n", minus);               // ffffff9f
	printf("minus : %5u \n", minus);               // 4294967199
	printf("minus : %5c \n", minus);               // ?

	// 줄맞춤에도 유용
	printf("%20s\n", "문자열 % s출력");

}