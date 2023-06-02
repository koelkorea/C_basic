// 구조체 자체의 연산
//  : 구조체 변수 자체는 {}영역 안에 존재하는 지역 struct 구조체 타입 변수에 한해서, 대입 연산을 값만 할당 가능
// 
//     ex) person A, B;  
//         A = B;

// 구조체와 함수
//  : 대입 이외 다른 연산자를 활용한 계산은 구조체 변수의 멤버변수들에 역참조를 통한 접근으로 연산하며, 이를 위해 구조체 포인터변수를 parameter로 넣는 함수 또한 제작이 가능
//     -> 왜냐하면, 구조체도 자료 타입이므로 함수의 parameter로 대입 or return되는 자료형으로 활용 가능하기에, 구조체 포인터도 예외 없이 가능

//   # 구조체 변수도 일반 변수와 마찬가지로 {}의 영향에 따른 분류가 같음
//     - 값에 의한 전달(Call by Value)
//     - 레퍼런스에 의한 전달(Call by Reference)
//        -> 그리고 이를 통해 구조체도 역참조가 가능하며, 이를 함수에 활용도 가능


// swap함수를 통한 구조체의 Call by Value VS Call by Reference
#include <stdio.h>
typedef struct data {
	int v1;
	int v2;
}data;

void swapVal(data d1, data d2) {
	data temp;
	temp = d1;  d1 = d2;  d2 = temp;
}

void swapRef(data* p1, data* p2) {
	data temp;
	temp = *p1;  *p1 = *p2;  *p2 = temp;
}

int main() {

	data d1 = { 10, 20 };
	data d2 = { 100, 200 };

	printf("swapVal 호출 전 d1 = %d %d, d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);

	swapVal(d1, d2);
	printf("swapVal 호출 후 d1 = %d %d, d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);		// 값에 의한 전달(Call by Value) 방식의 함수로는 return값 없이는 main{}의 지역변수들인 d1, d2들에 영향 못 준다

	printf("swapRef 호출 전 d1 = %d %d, d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);
	swapRef(&d1, &d2);
	printf("swapRef 호출 후 d1 = %d %d,  d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);	// 레퍼런스에 의한 전달(Call by Reference) 방식의 함수는 그런거 없이 d1, d2들에 영향 잘 준다

	return 0;
}
