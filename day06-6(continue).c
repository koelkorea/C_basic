#include <stdio.h>		

// 반복문 제한 탈주 명령어(예약어) continue
//		: 이 명령어를 통해, 잘 돌아가는 반복문의 loop문이 부분적으로 끊어지되 전체적으로는 계속될 수 있도록 한다
//		  (= 조건문과 결합하면, 의도에 더 정교하게 맞는 프로그램 설계 가능) 
//				-> 단! continue문은 현재 돌아가는 for문의 해당 trun에서의 탈주만 적용..  
//					(= 해당 loop턴의 스코프{}안의 명령어는 skip되고 다음 루프로 넘어가나, 어쨌든 for문은 break문을 만나거나 끝날때까지 계속된다) 
int main() {

	for (int i = 1; i <= 15; i++) {

		for (int j = 1; j <= i; j++) {

			if (5 < j && j < 10) {		
				printf("□");
			}

			printf("■");
		}

		printf("\n");
	}

	for (int i = 1; i <= 15; i++) {

		for (int j = 1; j <= i; j++) {	// 2번째 for문은 1번째 for문의 현 loop가 몇번째인지 영향을 받고, j는 1번째 for문의 turn값을 못 넘긴다

			if (5 < j && j < 10) {		// 2번째 for문의 변수 j가 5~10 안에 들어가면..? 
				printf("□");					// □를 ■보다 먼저 ㅊ출력해라
				continue;					// continue를 만나면...	for문의 다음 turn으로 강제진행		<- 이 이후의 {}안의 코드 printf("■");는 진행X
			}
			printf("■");					//	(= 그래서 ■는 continue이후 배치되어 있기에, continue발동되는 5 < j < 10인 턴의 for반복에서 나오지 않는다)
		}
		printf("\n");						// continue도 해당 for문 안에서만 영향을 발휘함 (= 1번쨰  for문의 내용에는 관여하지 못하기에, 줄바꿈은 계속 존재할 수 있음)
	}


	return 0;
}