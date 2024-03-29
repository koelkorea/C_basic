#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() 함수 사용 가능하게 함
#include <time.h>				// time () 함수 사용 가능하게 함

// 홀수와 짝수 세기 (하나의 배열로 풀어보기)
// -> 1차원 배열 100칸 공간 할당하고, 1~1000까지... 
//     -> 그리고 각 칸의 값이 홀수, 짝수인지 판별 -> 홀, 짝 수량 파악
//     -> 홀수값 오름차순 정렬 : 순차정렬으로 구현 
//     	  짝수는 내림차수 정렬 : 선택정렬으로 구현
int main() {

	int array[10];

	// 홀수는 순차정렬 : 배열값 교체용 임시변수
	int temp;				

	// 짝수는 선택정렬 : 최대값과 최소값을 저장할 주소 추가 + 홀수 / 짝수 경계 주소 저장값
	int  min = 0, address = 0, even = 0, odd = 0;

	//  이를 주석화 시키면, 패턴이 똑같은 값만 출력되는걸 볼 수 있음
	srand((unsigned int)time(NULL));			

	// 배열에 임의값 100개 투입
	for (int i = 0; i <= 99; i++) {
		temp = rand() % 1000 + 1;		// 1~ 1000까지니

		// 짝수 일 경우 99-(짝수의 현재개수)에 해당하는 배열주소에 값 저장 + 짝수의 현재개수 + 1
		if (temp % 2 == 0) {	
			array[99 - even] = temp;
			even += 1;
		}
		// 홀수인 경우 i - (짝수의 현재개수) 에 해당하는 배열주소에 값 저장
		else if (temp % 2 == 1) {	
			array[i - even] = temp;
		}
	}

	// 랜덤값 지급이 끝나면 현 짝수의 개수 계산
	odd = 100 - even;
	printf("홀수의 개수 = %d개 \n", odd);
	printf("[before]\n");

	// 홀/짝 오름차순 전 배열 확인용 (없어도 됨)
	for (int i = 0; i <= 99; i++) {
		printf("array[%d] = %d \n", i, array[i]);
	}

	printf("\n");

	printf("[after]\n");

	// 얻어낸 홀수의 개수 odd를 기준으로 홀수와 짝수의 순차정렬, 선택정렬을 다르게 적용
	for (int i = 0; i <= 99; i++) {

		// i가 짝수영역일 경우 최소값은 매 회차마다 i번째 array의 값을 가져와서 초기화 + 현재 최소값의 주소도 i로 초기화 (짝수의 영역이 따로 정해져있어 이 부분 중요하다!)
		if (i > odd - 1) {
			min = array[i];
			address = i;			//	 이 부분이 아주 중요함
		}

		for (int j = i + 1; j <= 99; j++) {

			//-------------------------------------------------------------------------------------------------------------------------------------------
			if (i <= odd - 1 && j <= odd - 1) {		// 1. 주소가 odd - 1까지는 홀수만 위치하니 순차정렬 사용 (1~9 순차적 비교후 가장 작거나 큰 값을 가져오고, 2~9 이런식으로 같은 방식)

				if (array[j] < array[i]) {

					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}

			}else if (i > odd - 1 && j > odd - 1) { // 2. 주소가 odd값 이후인건 짝수들만 모여있으니 선택정렬 사용 (1~9 순차적 비교후, 최소값을 찾으면 딱 한번만 교환... 그 뒤 2~9 순차 계속)

				// 비교대상이 현 회차의 최소값보다 작으면? 
				if (array[j] < min) {
					min = array[j];		// 현재 해당 회차에서 찾아낸 최소값 따로 저장
					address = j;			// 현재 최소값이 위치한 배열주소 저장
				}

			}//------------------------------------------------------------------------------------------------------------------------------------			
		}

		//  i가 짝수영역일 경우 이번 회차에 얻은 최소값을 (1~100-i번째 배열 중 최대값)과 100-i번째 배열의 값을 서로 교환 (address값을 활용)
		if (i > odd - 1) {
			array[address] = array[i];
			array[i] = min;
		}
		printf("array[%d] = %d \n", i, array[i]);
	}

	printf("\n");
	printf("홀수 목록 : ");

	// 홀수만 sort의 결과값 처음 , 끝 출력하면 ㅇㅋ
	for (int i = 0; i <= odd - 1; i++) {
		printf(" %d", array[i]);
	}


	printf("\n짝수 목록 : ");

	// 짝수만 sort의 결과값 처음 , 끝 출력하면 ㅇㅋ
	for (int i = odd; i <= 99; i++) {
		printf(" %d", array[i]);
	}

	return 0;


}