#include <stdio.h>

// (모범) 구구단 만들기 
//   -> (차이점1) sizeof 적극 사용
int main() {

	// 배열 초기화 되는 예시
	int gugudan[9][9];

	printf("[오름차순]\n");

	//	sizeof(변수명)은 말 그대로 해당 변수명 인스턴스에 주어진 메모리 크기를 출력하는거라 다차원배열을 넣어도 됨(그저 그 배열 전체의 메모리 크기를 출력)
	for (int i = 0; i < sizeof(gugudan) / sizeof(gugudan[0]); i++) {		

		for (int j = 0; j < sizeof(gugudan) / sizeof(gugudan[0]); j++) {
			gugudan[i][j] = (i + 1) * (j + 1);
			printf("|%3d", gugudan[i][j]);
		}
		printf("|\n");
	}

	printf("\n[내림차순]\n");

	for (int i = sizeof(gugudan) / sizeof(gugudan[0]) - 1; i >= 0; i--) {

		for (int j = 0; j < sizeof(gugudan) / sizeof(gugudan[0]); j++) {
			printf("|%3d", gugudan[i][j]);
		}
		printf("|\n");
	}

	return 0;
}