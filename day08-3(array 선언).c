#include <stdio.h>

// 배열 (array) 초기화
//	: 선언과 동시에 초기 값을 중괄호{} 안에 차례대로 입력.
//     -> 배열의 크기를 생략하고 초기 값을 입력 할 경우, 초기 값의 개수가 배열의 크기가 됨
//     -> (중요) 배열의 크기보다 적은 개수의 초기 값을 할당 할 경우, 뒤의 값은 무조건 0으로 초기화.
//     -> static 선언 시 모든 배열의 요소는 0으로 초기화 (static은 해당 영역 안에서 전역스코프처럼 쓰이는 속성으로 프로그램 시작과 동시에 초기화 완료)
//     -> 배열의 주소값은 [0]이 1번째임.. 주소가 N인 배열의 마지막 요소의 주소는 [N-1]
int main() {

	// 배열 초기화 되는 예시 
	//	-> (중요) 단! 초기화가 되려면, 반드시 {}는 최소한 만들어 줘야 함
	int a[4] = { 11, 12, 13, 14 };  // 정석 중에 정석
	int b[] = { 1, 2, 3, 4, 5 };    // []에 값이 없어도, {}안에 값을 넣으면, 알아서 배열의 길이를 잡아서 생성
	int c[6] = { 1 };               // 크기보다 적게 값을 넣어도 int 배열이라 나머지 공간은 0으로 초기화
	static int d[7];                //  static 변수로 선언시 모든 배열요소는 시작과 동시에 0으로 초기화	( {}안에 값 할당 불가능 )

	// 배열 초기화 안 되는 예시 
	//  -> 애초에 논리적으로도 틀린 값이고.. 할당된 메모리도 그 값을 받을만큼 크게 안 준거라 컴파일부터가 문제가 됨

	int e[2] = { 11, 12, 13, 14 };			//	 선언된 배열의 크기보다, {} 안에 값이 더 많이 들어가면 그건 문제가 있다 

	printf("%d %d %d %d \n", a[0], a[1], a[2], a[3]);
	printf("%d %d %d %d %d \n", b[0], b[1], b[2], b[3], b[4]);
	printf("%d %d %d %d %d %d\n", c[0], c[1], c[2], c[3], c[4], c[5]);              // 1 0 0 0 0 0    : 값을 할당한 첫번쨰 배열 빼면 나머지는 0으로 초기화
	printf("%d %d %d %d %d %d %d\n", d[0], d[1], d[2], d[3], d[4], d[5], d[6]);     // 0 0 0 0 0 0 0  : static배열로 선언하면 해당 배열 요소들 전부 프로그램 시작시 0으로 초기화( {}안에 값 할당 불가능 )

	return 0;
}