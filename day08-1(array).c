#include <stdio.h>

// 배열 (array)
//		: 기억장치에 같은 자료형의 값을 연속적으로 저장하는 것 (자료들은 요소라고 부른다)
int main() {
	int ary1[4] = { 11, 12, 13, 14 };
	char ary2[4] = { 11, 12, 13, 14 };
	for (int i = 0; i < 4; i++) {
		printf("ary : %p , art[%d] : %d \n", ary1 + i, i, ary1[i]);			// p는 자료형이 위치한 포인트(주소)를 의미한다

		//	메모리 주소값을 보면 int의 크기인 4byte씩 차이가 남을 확인 가능
		// ary1 : 000000E34D3CF508, art[0] : 11
		// ary1 : 000000E34D3CF50C, art[1] : 12
		// ary1 : 000000E34D3CF510, art[2] : 13
		// ary1 : 000000E34D3CF514, art[3] : 14


	}

	printf("\n");

	for (int i = 0; i < 4; i++) {
		printf("ary : %p , art[%d] : %d \n", ary2 + i, i, ary2[i]);			// p는 자료형이 위치한 포인트(주소)를 의미한다

		//	메모리 주소값을 보면 chat의 경유인 1byte씩 차이가 남을 확인 가능
		// ary2: 000000FE1B37F9B4, art[0] : 11
		// ary2 : 000000FE1B37F9B5, art[1] : 12
		// ary2 : 000000FE1B37F9B6, art[2] : 13
		// ary2 : 000000FE1B37F9B7, art[3] : 14
	}
	return 0;
}