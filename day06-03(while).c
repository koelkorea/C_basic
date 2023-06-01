#include <stdio.h>		

// 반복문 while
//  : while안의 조건식이 참이면 반복, 아니면 break
//     -> for문과 다르게 파라미터에 조건식 세팅만 가능함 (= for문처럼 초기값;조건식;증감식 이런식으로 파라미터 영역에 한번에 세부 입력 불가함... 변수 관리가 힘들수 있음)
int main() {

	int i = 1;

	while (i <= 3) {

		int j = 1;

		while (j <= 5) {
			printf("ㅁ");
			j++;
		}
		printf("\n");
		i++;
	}

	return 0;
}