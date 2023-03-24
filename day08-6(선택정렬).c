#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() 함수 사용 가능하게 함
#include <time.h>				// time () 함수 사용 가능하게 함

// 선택정렬 : 각 회차의 최대/최소값을 찾아서, 매회차마다 1번씩만 주소i에 있는 값을 현재기준 최소값과 교환해준다.
int main() {

	int array[10], min	, address;		// 최소값과 최소값을 저장할 주소 추가

	srand((unsigned int)time(NULL));			//  이를 주석화 시키면, 패턴이 똑같은 값만 출력되는걸 볼 수 있음

	// 배열에 임의값 10개 투입
	for (int i = 0; i <= 9; i++) {
		array[i] = rand() % 500;
		printf("array[%d] = %d \n", i, array[i]);
	}

	// 선택정렬 사용 (1~9 순차적 비교후, 최소값을 찾으면 딱 한번만 교환... 그 뒤 2~9 순차 계속)
	//		-> 이를 통해 앞에서부터 작은수를 순차적으로 골라냄
	for (int i = 0; i <= 9; i++) {

		// 최소값은 매 회차마다 i번째 array의 값을 가져와서 초기화
		min = array[i];

		for (int j = i + 1; j <= 9; j++) {

			// 비교대상이 현 회차의 최소값보다 작으면? 
			if (array[j] < min) {
				min = array[j];		// 현재 해당 회차에서 찾아낸 최소값 따로 저장
				address = j;			// 현재 최소값이 위치한 배열주소 저장
			}
		}
		
		// 이번 회차에 얻은 최소값을 (i~10번째 배열 중 최소값)과 i번째 배열의 값을 서로 교환 (address값을 활용)
		array[address] = array[i];
		array[i] = min;						
	}

	// sort의 결과값 처음 , 끝 출력하면 ㅇㅋ
	printf("최대값 : %d\n", array[9]);
	printf("최소값 : %d", array[0]);

}