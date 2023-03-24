//	Call by reference 
//		: 호출 함수의 파라미터로 주소값(포인터변수)을 넘겨주는 방식
//			-> 함수의 파라미터로 주소값을 통해 간접 접근할 수 있음
//					-> 변수의 주소값은 일종의 전역변수화 되었다고 말할 수도 있음
//						(정확히는 포인터변수를 통한 메모리주소값이 {}차원간의 연결을 시켜주는 포탈이라 보면 됨)

#include <stdio.h>

// Call by reference 개념 설명 예시
//		-> swap()함수의 파라미터는 main()의 지역변수의 주소값이고, 그걸 활용하여 포인터 변수로 직접 대입하였기에 다른 차원의 {}간에 swap이 된걸 확인 가능하다 
void swap(int* x, int* y) {	 // int * x = &a, int * y = &b;
	int z;
	printf("\nswap call start\n");
	printf("x %p y %p\n", x, y);
	//포인터 주소 값
	printf("x %d y %d\n", *x, *y);
	//포인터 가리키는 값 swap 전
	z = *x, * x = *y, * y = z;
	printf("x %d y %d\n", *x, *y);
	//포인터 가리키는 값 swap 후
	printf("swap call end\n\n");
}

int main() {
	int a = 10, b = 20;
	printf("A %d B %d\n", a, b);
	printf("a %p b %p\n", &a, &b);
	swap(&a, &b);
	printf("A %d B %d\n", a, b);
	printf("a %p b %p\n", &a, &b);
	return 0;
}
