//	Call by value
//		: (C언어 함수의 호출방식)함수의 파라미터로 들어가는 값은 복사하여 전달 방식 (직접 넣는 것이 아님)
//			-> 파라미터의 원본값이 변조되지 않기에, 함수에서 아무리 지지고 볶아도 그 {} 밖을 못 벗어남 (함수형 프로그래밍의 개념1)
//				-> 따라서 연산 처리 결과값을 변경 할 경우, 그 이후 필요한 대입 연산 필요 (return이나 뭐 이런거로 값을 넘겨 받을 수단이 있어야 한다.. 아니면 전역변수로 선언된 변수를 파라미터로 받거나)
#include <stdio.h>

// Call by value 개념 설명 예시
//		-> swap()함수는 아무것도 리턴하지 않고, 파라미터는 main()의 지역변수를 복사해서 받았기에, 아무런 영향을 미치지 못하는거 확인 
void swap(int x, int y) {
	int z;
	printf("\nswap call start\n");
	printf("x %d y %d\n", x, y); //swap 전
	z = x, x = y, y = z;
	printf("x %d y %d\n", x, y); //swap 후
	printf("swap call end\n\n");
}

int main() {
	int a = 10, b = 20;
	printf("A %d B %d\n", a, b);
	swap(a, b);
	printf("A %d B %d\n", a, b);
	return 0;
}
