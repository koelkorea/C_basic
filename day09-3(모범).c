#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() 함수 사용 가능하게 함
#include <time.h>				// time () 함수 사용 가능하게 함

// 6*6배열에서 5*5에 랜덤값 저장 후, 행과 열의 값과 대각의 값이 각각 6행 6열에 쭉 나오도록 해라 
int main() {

	srand((unsigned int)time(NULL));

	// 배열 초기화 되는 예시
	int array[6][6], rowSum, columnSum;

	for (int i = 0; i < sizeof(array) / sizeof(array[0]) - 1; i++) {		//	sizeof(변수명)은 말 그대로 해당 변수명 인스턴스에 주어진 메모리 크기를 출력하는거라 다차원배열을 넣어도 됨(그저 그 배열 전체의 메모리 크기를 출력)

		rowSum = 0;

		for (int j = 0; j <= sizeof(array) / sizeof(array[0]) - 1; j++) {

			if (j < sizeof(array) / sizeof(array[0]) - 1) {

				array[i][j] = rand() % 10 + 1;
				rowSum += array[i][j];
				printf("%3d", array[i][j]);

				if ((j == sizeof(array) / sizeof(array[0]) - 2)) {
					printf("|");
				}

			}
			else if (j == sizeof(array) / sizeof(array[0]) - 1) {
				printf("%3d\n", rowSum);
			}
		}

	}

	printf("--------------------\n");

	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {

		if (i == sizeof(array) / sizeof(array[0]) - 1) {
			array[5][i] = array[0][0] + array[1][1] + array[2][2] + array[3][3] + array[4][4];
			printf("|%3d", array[5][i]);
		}
		else {
			array[5][i] = array[0][i] + array[1][i] + array[2][i] + array[3][i] + array[4][i];
			printf("%3d", array[5][i]);
		}

	}

	return 0;
}
