#include <stdio.h>		

// for을 통해 직사각형 그리는 프로그램 만들어라
//	-> 0을 입력하면 종료
//		가로 세로 두께를 입력하면 그대로 나오게 해라.. 두께에 따라 내부 공백의 길이가 변화해야 함
int main() {

	int 가로, 세로, 굵기, 종료값 = 1;

	while (종료값 == 1) {
		printf("가로 길이는? : ");
		scanf_s("%d", &가로);

		printf("세로 길이는? : ");
		scanf_s("%d", &세로);

		printf("굵기는? : ");
		scanf_s("%d", &굵기);

		if (가로 == 0 || 세로 == 0) {
			printf("변이 0이면 아무것도 못하니 종료함\n");
			break;
		}


		for (int i = 1; i <= 세로; i++) {		// 1번째 for
			for (int j = 1; j <= 가로; j++) { // 2번째 for

				if (i <= 굵기 || i > 세로 - 굵기) { // 1번째 if-----------------------------------

					printf("★");

				}else {

					if (j <= 굵기) {// 2번째 if

						printf("★");

					}else if (j > 굵기) {

						if (j > 가로 - 굵기) { // 3번째 if
							printf("★");
						}
						else {
							printf("　");
						} // 3번째 if
					} // 2번째 if
				} // 1번째 if------------------------------------------------

			}	// 2번째 for

			printf("\n");
		}	// 1번째 for

		printf("\n종료하시려면 0를 눌러주세요(계속하려면 아무키나 누르시길) : ");
		scanf_s("%d", &종료값);
		while (getchar() != '\n');
		printf("\n");
	}
	

	return 0;
}