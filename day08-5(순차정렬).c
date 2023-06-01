#include <stdio.h>
#include <stdlib.h>	   // srand(), rand() 함수 사용 가능하게 함
#include <time.h>      // time () 함수 사용 가능하게 함

// 순차정렬
//  : 회차마다 주소 i를 기준으로 뒤쪽을 순차적으로 비교하여, 자기보다 크거나 작은 값이 나오면 그때 그때 교환하는 방법
//     -> 이놈이나 선택정렬이나 결국 2중 for문 써야함
//        (= 방법이 거기서 거기라... 시간복잡도가 n^2라는건 다른게 없음)
int main() {

	int array[10];

	// 값 교체용 임시변수
	int temp;				

	//  이를 주석화 시키면, 패턴이 똑같은 값만 출력되는걸 볼 수 있음
	srand((unsigned int)time(NULL));			

	// 배열에 임의값 500개 투입
	for (int i = 0; i <= 9; i++) {
		array[i] = rand() % 500;
		printf("array[%d] = %d \n", i, array[i]);
	}

	// 순차정렬 사용 (1~9 순차적 비교후 가장 작거나 큰 값을 가져오고, 2~9 이런식으로 같은 방식)
	for (int i = 0; i <= 9; i++) {
		
		for (int j = i + 1; j <= 9; j++) {

			if (array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}

		}

	}

	// sort의 결과값 처음 , 끝 출력하면 ㅇㅋ
	printf("최대값 : %d\n", array[9]);
	printf("최소값 : %d", array[0]);

}