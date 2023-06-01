#include <stdio.h>
#include <stdlib.h>       // srand(), rand() 함수 사용 가능하게 함
#include <time.h>         // time () 함수 사용 가능하게 함
#include <windows.h>      // sleep() 함수 사용 가능하게 함

// 난수 관련 C언어 함수
//  1. int rand(void) 
//      : 정해진 seed값(srand(int)로 변환 가능)에 따라 0~32767값을 랜덤 반환
// 
//  2. (void) srand(unsigned int seed)
//      : rand() 함수에 사용되는 seed값을 변경함 (파라미터로 들어간 int값이 seed값이 됨)
// 
//  3. (long long) time(time_t *timer)
//      : 파라미터가 NULL이면, 현재 시간 반환함 (time의 파라미터인 time_t는 long long 자료형의 별칭이며 *timer는 포인터 변수)
int main() {

	// srand(unsigned int seed)
	//  : rand()의 패턴의 근원인 seed변환
	//		-> 이것의 파라미터로 time(NULL)을 받아, 현재 시간에 따라 rand()의 실행 패턴이 되는 seed값에 변주를 줄 수 있음
	srand((unsigned int)time(NULL));			//  이를 주석화 시키면, 패턴이 똑같은 값만 출력되는걸 볼 수 있음

	int player, com ,result;

	while (1) {

		printf("1 ~ 3번을 입력하세요. (가위 : 1, 바위 : 2, 보 : 3) : ");
		scanf_s("%d", &player);
		com = ((int)rand()) % 3 + 1;

		if (player == 1) {
			printf("\nUser : 가위");
		}else if (player == 2) {
			printf("\nUser : 바위");
		}else {
			printf("\nUser : 보");
		}
		printf("\n");
		if (com == 1) {
			printf("\com : 가위");
		}else if (com == 2) {
			printf("\com : 바위");
		}else {
			printf("\com : 보");
		}

		if (player == com) {
			printf("\n무승부 데스!");
		}else {

			if (player == 1) {
				if (com == 2) {
					printf("\n패배!");
				}else if(com == 3){
					printf("\n승리!");
				}
			}
			else if(player == 2) {
				if (com == 1) {
					printf("\n승리!");
				}
				else if(com == 3){
					printf("\n패배!");
				}
			}
			else if (player == 3) {
				if (com == 1) {
					printf("\n패배!");
				}
				else if(com == 2){
					printf("\n승리!");
				}
			}
		}

		printf("\n\n");
	}

	return 0;
}