// Call by reference 
//  : 호출 함수의 parameter로 변수나 객체를 넘겨준 경우 그 메모리 상의 위치를 참고할 수 있는 존재(포인터 변수 or 레퍼런스 변수)를 넘겨주는 방식
//     -> C언어에서는 함수의 parameter에 포인터 변수를 넘겨줌으로서, 그 주소값의 메모리 위치에 저장된 값을 역참조한 하여 접근 및 수정할 수 있음
//         -> (중요!) Call by reference 형식에서는 parameter로 들어온 변수의 주소값이나 레퍼런스 변수를 {}영역을 넘어 일종의 전역변수 같은 느낌으로 접근 가능하다고 말할 수도 있음
//                    (= 정확히는 포인터변수를 통한 메모리주소값이 {}차원간의 연결을 시켜주는 포탈이라 보면 됨)

//   # (중요) C언어에서의 parameter와 정적array
//       : 어떤 함수의 parameter로 정적 array의 모든 값을 넣고 싶다면?
//         -> int p[10] 사용 X                                           <- C언어는 매개변수로 배열의 선언을 허용X  =  배열을 통째로 복사하는 방법X
//         -> int p[] 사용 ㅇ                                            <- 배열의 시작주소값을 전달하여, 배열의 값을 역참조 하여 함수에 활용할 수 있게 하면 됨!
//                                                                           -> BUT! 아시다시피 이 녀석은 배열이 아니라 크기까지 가져오진 않는다는거 명심

#include <stdio.h>

// Call by reference 개념 설명 예시
//  -> swap()함수의 파라미터는 main()의 지역변수의 주소값이고, 그걸 활용하여 포인터 변수로 직접 대입하였기에 다른 차원의 {}간에 swap이 된걸 확인 가능하다 
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
