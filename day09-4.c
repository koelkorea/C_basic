#include <stdio.h>
#include <stdlib.h>				//srand(), rand() 함수 사용 가능하게 함
#include <time.h>				// time () 함수 사용 가능하게 함

// 50명 학생 별 국어, 수학 영어, 탐구 성적을 받을 2차원 배열 선언
//  -> 1명당 과목씩 데이터 입력 랜덤 생성(0~100점)
//  -> 과목을 선택하는 로직 만들고, 등수 매기기
//  -> 각 과목별 내림차순 (당사자도 누군지 알아야 함)
int main() {

	srand((unsigned int)time(NULL));

	// 배열 초기화 되는 예시 
	int array[30][4];			// 40명 4과목 입력
	int subject;
	int ranking[30][2];				// 랭킹용 배열
	int temp;								// 선택정렬 임시변수

	// 시작 : 성적 랜덤 주기
	printf("		    국 수 영 탐\n");

	//	sizeof(변수명)은 말 그대로 해당 변수명 인스턴스에 주어진 메모리 크기를 출력하는거라 다차원배열을 넣어도 됨(그저 그 배열 전체의 메모리 크기를 출력)
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {		

		// 학생번호 출력
		printf("%2d번 학생의 성적 : ", i+1);

		// 4과목 성적 랜덤 지급
		for (int j = 0; j <= sizeof(array)[0] / sizeof(array[0][0]) - 1; j++) {
			array[i][j] = rand() % 100 + 1;
			printf("%4d", array[i][j]);
		}
		printf("\n\n");
	}

	// 등수매기기 로직 시작

	// 과목 입력
	printf("등수를 메길 과목을 입력해주세요(1. 국어  2.수학 3.영어 4. 탐구 ) : ");
	scanf_s("%d", &subject);

	switch (subject) {
	case 0: printf("\n------------------------------------국어 등수 매기기---------------------------------------------- \n \n");
		break;
	case 1: printf("\n------------------------------------수학 등수 매기기----------------------------------------------  \n \n");
		break;
	case 2: printf("\n------------------------------------영어 등수 매기기----------------------------------------------  \n \n");
		break;
	default: printf("\n-----------------------------------탐구 등수 매기기----------------------------------------------  \n \n");
		break;
	}


	printf("[정렬 전] \n");

	// 받은 과목값을 기반으로 ranking 배열의 1번째 열에 학생번호, 2번째 열에 학생성적 저장
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {

		ranking[i][0] = i;
		ranking[i][1] = array[i][subject - 1];

		// 정렬전 학생번호 출력
		printf("%4d번", ranking[i][0]);		
	}

	printf("\n");

	// 정렬전 학생 성적 출력
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {
		printf("%4d점", ranking[i][1]);
	}

	printf("\n\n");

	printf("[정렬 후] \n");

	// 순차정렬 사용 (1~9 순차적 비교후 가장 작거나 큰 값을 가져오고, 2~9 이런식으로 같은 방식)
	for (int i = 0; i <= sizeof(ranking) / sizeof(ranking[0]) - 1; i++) {

		for (int j = i + 1; j <= sizeof(ranking) / sizeof(ranking[0]) - 1; j++) {

			// 최대값이 앞으로 오도록 함 + 학생번호, 학생성적도 같이 바꿔줌
			if (ranking[j][1] > ranking[i][1]) {
				temp = ranking[i][0];
				ranking[i][0] = ranking[j][0];
				ranking[j][0] = temp;

				temp = ranking[i][1];
				ranking[i][1] = ranking[j][1];
				ranking[j][1] = temp;
			}

		}
	}


	// 등수 출력용
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {

		printf("%4d등", i + 1);
	}

	printf("\n");

	// 정렬 후 학생번호
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {
		printf("%4d번", ranking[i][0]);
	}

	printf("\n");

	// 정렬 후 학생 성적
	for (int i = 0; i <= sizeof(array) / sizeof(array[0]) - 1; i++) {
		printf("%4d점", ranking[i][1]);
	}

	return 0;
}
