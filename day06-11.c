#include <stdio.h>		

// for을 통해 입력값*2가 너비와 높이가 되는 다이아몬드 그림을 그려라
int main() {

	int 입력값;

	while (1) {
		printf("원하는 다이아몬드의 반 대각선값(대충 도형변/2의 제곱근)을 입력하세요 : ");
		scanf_s("%d", &입력값);

		for (int i = 1; i <= 입력값; i++) {

			for (int j = 1; j <= 입력값 * 2; j++) {

				if (j == 입력값 - (i - 1) || j == 입력값 + i) {
					printf("★");
				}
				else {
					printf("　");
				}
			}

			printf("\n");
		}

		for (int i = 1; i <= 입력값; i++) {

			for (int j = 1; j <= 입력값 * 2; j++) {

				if (j == i || j == 입력값 * 2 - i + 1) {
					printf("★");
				}
				else {
					printf("　");
				}
			}

			printf("\n");
		}
	}

}