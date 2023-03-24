#include <stdio.h>		

// 별로 그림 만들기
int main() {

	// 1번째 그림
	for (int i = 1; i <= 10; i++) {

		if (i % 2 == 1) {
			for (int j = 1; j <= i; j++) {
				printf("★");
			}
			printf("\n");
		}else if (i % 2 == 0) {
			for (int j = 1; j <= i; j++) {
				printf("☆");
			}
			printf("\n");
		}
		
	}

	for (int i = 1; i <= 10; i++) {

		for (int z = 10; z > i; z--) {
			printf("　");
		}

		if (i % 2 == 1) {
			for (int j = 1; j <= i; j++) {
				printf("★");
			}
			printf("\n");
		}
		else if (i % 2 == 0) {
			for (int j = 1; j <= i; j++) {
				printf("☆");
			}
			printf("\n");
		}
		
	}

	printf("\n");

	// 2번째 그림
	for (int i = 1; i <= 10; i++) {

		if (i % 2 == 1) {
			for (int j = 1; j <= i; j++) {
				printf("★");
			}
			printf("\n");
		}
		else if (i % 2 == 0) {
			for (int j = 1; j <= i; j++) {
				printf("☆");
			}
			printf("\n");
		}

	}

	for (int i = 9; i >= 1; i--) {

		if (i % 2 == 1) {
			for (int j = 1; j <= i; j++) {
				printf("★");
			}
			printf("\n");
		}
		else if (i % 2 == 0) {
			for (int j = 1; j <= i; j++) {
				printf("☆");
			}
			printf("\n");
		}
	}

	// 3번째 그림
	for (int i = 1; i <= 10; i++) {

		for (int z = 10; z > i; z--) {
			printf("　");
		}

		if (i % 2 == 1) {
			for (int j = 1; j <= i; j++) {
				printf("★");
			}
			printf("\n");
		}
		else if (i % 2 == 0) {
			for (int j = 1; j <= i; j++) {
				printf("☆");
			}
			printf("\n");
		}

	}

	for (int i = 9; i >= 1; i--) {

		for (int z = 10; z > i; z--) {
			printf("　");
		}

		if (i % 2 == 1) {
			for (int j = 1; j <= i; j++) {
				printf("★");
			}
			printf("\n");
		}
		else if (i % 2 == 0) {
			for (int j = 1; j <= i; j++) {
				printf("☆");
			}
			printf("\n");
		}

	}

	return 0;
}