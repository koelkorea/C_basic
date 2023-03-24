#include <stdio.h>		

// 반복문 do while : 일단 do안의 내용을 한번 실행 -> 그 후 while안의 조건식이 참이면 반복, 아니면 break
//		-> for문과 다르게 파라미터에 조건식 세팅만 가능함 (= for문처럼 초기값;조건식;증감식 이런식으로 파라미터 영역에 한번에 세부 입력 불가함... 변수 관리가 힘들수 있음)
int main() {

	int i = 1, sum = 0;

	do {
		sum += i;
		i++;

	} while (i <= 100);

	printf("1~100까지의 합 = %d \n", sum);

	return 0;
}