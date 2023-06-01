#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() 함수 사용 가능하게 함
#include <time.h>				// time () 함수 사용 가능하게 함

// 홀수와 짝수 세기 (짝수, 홀수 각자의 배열로 풀어보기)
// -> 1차원 배열 100칸 공간 할당하고, 1~1000까지... 
//     -> 그리고 각 칸의 값이 홀수, 짝수인지 판별 -> 홀, 짝 수량 파악
//     -> 홀수값 오름차순 정렬 : 순차정렬으로 구현 
//     	  짝수는 내림차수 정렬 : 선택정렬으로 구현
int main() {

	// 100개 변수 받을 배열
	int array[100];

	// 홀수만 추려받을 배열
	int odd[100];

	// 짝수만 추려받을 배열
	int even[100];

	// 홀수는 순차정렬 : 배열 값 교체용 임시변수
	int temp;				

	// 짝수는 선택정렬 : 최소값과 최소값을 저장할 주소 추가
	int min = 0, address = 0;

	//  이를 주석화 시키면, 패턴이 똑같은 값만 출력되는걸 볼 수 있음
	srand((unsigned int)time(NULL));

	// 배열에 임의값 100개 투입
	for (int i = 0; i <= 99; i++) {

		// 100개 값 받을 배열 array의 각 요소에 배열 받기
		array[i] = rand() % 1000 + 1;		// 1~ 1000까지니

		// 홀, 짝 각 배열의 모든 공간 0으로 초기화
		odd[i] = even[i] = 0;

		printf("array[%d] = %d \n", i, array[i]);

		if (array[i] % 2 == 1) {
			odd[i] = array[i];
		}else if (array[i] % 2 == 0) {
			even[i] = array[i];
		}

	}

	// 1. 홀수는 순차정렬 사용 (1~9 순차적 비교후 가장 작거나 큰 값을 가져오고, 2~9 이런식으로 같은 방식)
	for (int i = 0; i <= 99; i++) {

		for (int j = i + 1; j <= 99; j++) {

			if (odd[j] < odd[i]) {
				temp = odd[i];
				odd[i] = odd[j];
				odd[j] = temp;
			}

		}

	}

	// 2. 짝수는 선택정렬 사용 (1~9 순차적 비교후, 최소값을 찾으면 딱 한번만 교환... 그 뒤 2~9 순차 계속)
	//		-> 이를 통해 앞에서부터 작은수를 순차적으로 골라냄
	for (int i = 0; i <= 99; i++) {

		// 최소값은 매 회차마다 i번째 array의 값을 가져와서 초기화
		min = even[i];

		for (int j = i + 1; j <= 99; j++) {

			// 비교대상이 현 회차의 최소값보다 작으면? 
			if (even[j] < min) {
				min = even[j];		    // 현재 해당 회차에서 찾아낸 최소값 따로 저장
				address = j;			// 현재 최소값이 위치한 배열주소 저장
			}
		}

		// 이번 회차에 얻은 최소값을 (i~10번째 배열 중 최소값)과 i번째 배열의 값을 서로 교환 (address값을 활용)
		even[address] = even[i];
		even[i] = min;
	}


	printf("홀수 목록 : ");

	// sort의 결과값 처음 , 끝 출력하면 ㅇㅋ
	for (int i = 0; i <= 99; i++) {

		if (odd[i] != 0) {

			printf(" %d", odd[i]);
		}
	}


	printf("\n짝수 목록 : ");

	// sort의 결과값 처음 , 끝 출력하면 ㅇㅋ
	for (int i = 0; i <= 99; i++) {

		if (even[i] != 0) {

			printf(" %d", even[i]);
		}
	}

	return 0;


}