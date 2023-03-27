// 구조체와 함수
//		: 구조체 변수는 대입 연산을 통한 지역변수 내의 값 할당만 가능 (person A, B;  A = B; )
//			-> 그 이외 연산은 함수를 만들어 구조체 변수의 멤버접근으로 연산함 (Because 구조체도 자료 타입이므로 함수의 매개변수 or 리턴 가능)

//	 # 구조체 변수도 일반 변수와 마찬가지로 {}의 영향에 따른 분류가 같음
//		- 값에 의한 전달(Call by Value)
//		- 레퍼런스에 의한 전달(Call by Reference)
//			-> 그리고 이를 통해 구조체도 역참조가 가능하며, 이를 함수에 활용도 가능


//x, y좌표를 표현하는 구조체를 통한 call by value, reference에 따른 함수 작성	+	call by reference를 통한 구조체의 역참조까지 활용 예시
#include <stdio.h>

// 구조체 struct 형식 및 재정의 (point to Spot)
typedef struct point {
	int xpos;
	int ypos;
} Spot;

// 구조체를 return으로 받는 함수1
//		: call by value를 염두에 둔 함수 예시
Spot PointAdd(Spot a, Spot b) {		// 좌표 2개를 받으면

	Spot result;	// 새로운 좌표를 선언

	result.xpos = a.xpos + b.xpos;	// 각 좌표의 x값  더함
	result.ypos = a.ypos + b.ypos;	// 각 좌표의 y값  더함

	return result;
}

// 구조체를 return으로 받는 함수2
//		:  call by reference를 활용한 주소값을 통한 역참조1
//			-> 전역변수나 다름없는 주소값에 덮어쓰기 
void PointAdd2(Spot* result, Spot a, Spot b) {		// 결과값 좌표구조체 포인터변수, 좌표 2개를 받으면

	// -> 를 사용한 파라미터로 주어진 구조체를 역참조
	result -> xpos = a.xpos + b.xpos;	//	result 포인터변수의 x값을 역참조한 값을 2좌표의 x값 합으로 대입
	result -> ypos = a.ypos + b.ypos;	//	result 포인터변수의 y값을 역참조한 값을 2좌표의 y값 합으로 대입

	// * 연산자를 이용한 파라미터로 주어진 구조체를 간접참조
	//(*result).xpos = a.xpos + b.xpos;
	//(*result).ypos = a.ypos + b.ypos;
}

// 구조체를 return으로 받는 함수3 
//		: call by reference를 활용한 주소값을 통한 역참조2
//			-> 전역변수나 다름없는 주소값에 덮어쓰기 
void PointAdd3(Spot result, Spot a, Spot b) {		// 결과값 좌표 구조체변수, 좌표 2개를 받으면

	// 주소값.멤버변수를 사용한 역참조
	result.xpos = a.xpos + b.xpos;	// 해당 결과값 구조체 변수의 x값을 2좌표의 x값 합으로 대입
	result.ypos = a.ypos + b.ypos;	// 해당 결과값 구조체 변수의 x값을 2좌표의 y값 합으로 대입
}

int main(void) {

	// PointAdd이용 : call by value를 염두에 둔 함수 이용
	Spot first;
	Spot second;
	Spot result1;

	printf("첫번째 x, y좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &first.xpos, &first.ypos);

	printf("두번째 x, y좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &second.xpos, &second.ypos);

	result1 = PointAdd(first, second);

	printf("첫번째와 두번째 좌표를 더한 값 : %d  %d \n\n", result1.xpos, result1.ypos);

	// PointAdd2이용 : call by reference를 염두에 둔 함수 이용
	Spot third;
	Spot forth;
	Spot result2;

	printf("세번째 x, y좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &third.xpos, &third.ypos);

	printf("네번째 x, y좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &forth.xpos, &forth.ypos);

	PointAdd2(&result2, third, forth);

	printf("세번째와 네번째 좌표를 더한 값 : %d  %d \n\n", result2.xpos, result2.ypos);

	// PointAdd3이용 : call by reference를 염두에 둔 함수 이용
	Spot fifth;
	Spot sixth;
	Spot result3;

	printf("다섯번째 x, y좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &fifth.xpos, &fifth.ypos);

	printf("여섯번째 x, y좌표를 입력해 주세요 : ");
	scanf_s("%d %d", &sixth.xpos, &sixth.ypos);

	PointAdd2(&result3, fifth, sixth);

	printf("다섯번째와 여섯번째 좌표를 더한 값 : %d  %d \n\n", result3.xpos, result3.ypos);

	return 0;
}
