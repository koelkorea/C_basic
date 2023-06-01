#include <stdio.h>		

// 반복문 탈주 명령어(예약어) break
//  : 이 명령어를 통해, 잘 돌아가는 반복문, 조건문이 인위적으로 끊어질수 있도록 한다
//    (= 조건문과 결합하면, 의도에 더 정교하게 맞는 프로그램 설계 가능) 
//       -> 단! break문은 현재 돌아가는 반복문, 조건문에서의 탈주만 적용..  
//          (= 한번에 전체 탈주는 불가능) 

//   # {} 빠져 나오게 하는 구문
//     1. break  : 반복문, 조건문 {}를 빠져나옴
//     2. return : 함수 {}를 빠져나옴
int main() {

	for (int i = 1; i <= 15; i++) {

		for (int j = 1; j <= 10 -i; j++) {
			printf("ㅁ");
		}

		printf("\n");
	}

	for (int i = 1; i <= 15; i++) {
		
		for (int j = 1; j <= 10 - i; j++) {
			
			printf("ㅁ");
			
			if (j == 5) {		// 2번째 for문의 변수 j가 5가 되면..? 
				break;			// 2번째 해당 for문을 탈주해라
			}
		}
		printf("\n");           // 전체 for문에서 탈주한게 아니기 때문에,  \n은 작동하여 1번째 for문의 다음 반복시 줄바꿈이 되어 있음을 확인 가능하다.
	}


	return 0;
}