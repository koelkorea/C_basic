#include <stdio.h>
#include <stdlib.h>       // srand(), rand() 함수 사용 가능하게 함
#include <time.h>         // time () 함수 사용 가능하게 함
#include <windows.h>      // sleep() 함수 사용 가능하게 함

// (특이점 1) 별칭과 값을 매칭시켜, 프로그래머가 코드는 별칭으로 입력해도.. 컴퓨터는 찰떡같이 그걸 숫자로 알아들음
#define 가위 1 
#define 바위 2 
#define 보 3 
#define computer 0 
#define user 1 
#define draw 2

// (모범답안) random 함수를 이용하여 컴퓨터와 하는 가위, 바위, 보를 만들어라
int main() {

	// srand(unsigned int seed)
	//  : rand()의 패턴의 근원인 seed변환
	//		-> 이것의 파라미터로 time(NULL)을 받아, 현재 시간에 따라 rand()의 실행 패턴이 되는 seed값에 변주를 줄 수 있음
	srand((unsigned int)time(NULL));			//  이를 주석화 시키면, 패턴이 똑같은 값만 출력되는걸 볼 수 있음


	// (특이점2) 승리자를 저장하는 victory 변수 사용..
	int player, com, victory;			

	while (1) {

		system("cls");	// 지난 출력 화면 지우기

		printf("1 ~ 3번을 입력하세요. (가위 : 1, 바위 : 2, 보 : 3) : ");
		scanf_s("%d", &player);
		while (getchar() != '\n');

		com = ((int)rand()) % 3 + 1;

		// (특이점 3) swirch 문을 통해 조금 코드 이해가 직관적으로 보일수 있게 함
		switch (player) {
			case 가위 :

				printf("\nUser : 가위");

				if (com == 바위) {
					victory = computer, 
					printf("\ncom : 가위");
				}
				else if (com == 보) {
					victory = user,
					printf("\ncom : 보");
				}
				else {
					victory = draw,
					printf("\ncom : 가위");
				}
				
				break;

			case 바위:

				printf("\nUser : 바위");

				if (com == 보) {
					victory = computer,
					printf("\ncom : 보");
				}
				else if (com == 가위) {
					victory = user,
					printf("\ncom : 가위");
				}
				else {
					victory = draw,
					printf("\ncom : 바위");
				}

				break;

			case 보:

				printf("\nUser : 보");

				if (com == 가위) {
					victory = computer,
					printf("\ncom : 가위");
				}
				else if (com == 바위) {
					victory = user,
					printf("\ncom : 바위");
				}
				else {
					victory = draw,
					printf("\ncom : 보");
				}

				break;
		}

		// (특이점 2의 연장) 승리자에 따른 결과값 출력
		if (victory == computer) {
			printf("\n승리자 : computer!\n\n");
		}
		else if (victory == user) {
			printf("\n승리자 : user!\n\n");
		}
		else {
			printf("\n무승부 데스!\n\n");
		}

		system("pause");		// 바로 다음으로 넘어가지 말고 잠깐 멈추라는 함수

		printf("\n\n");
	}

	return 0;
}