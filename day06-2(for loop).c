#include <stdio.h>		

// 중첩 for문 : for안에 또 for...
int main() {

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 3; j++) {
			printf("ㅁ");
		}
		printf("\n");
	}

	return 0;
}