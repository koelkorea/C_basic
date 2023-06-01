#include <stdio.h>

// 3. 사용자 정의 함수 (우리가 아는 그 함수) 사용자 정의 함수
//     : 자료형 함수명(자료형 인수1, 자료형 인수2, …) {함수 정의};

//   # 특성
//     - 전체 프로그램을 짧은 길이의 단위 프로그램으로 나누어 정의함 (코드의 재사용성 good!)
//     - 유지 보수가 효율적이라는 장점
//     - 모듈화된 구조(Modulization, hierarchy)		<- 재사용
//     - (최소한 파라미터 자료형까지는 적어둔) 선선언 후완성으로 사용 가능한 유연성도 있긴하다
//	   - void가 자료형인 함수는 return값이 없음

// [자료형이 void인 경우]
//   -> return이 존재하지 않음 (코드까보면 존재는 하지만, 보이지 않게 조치했을거라 생각함)

// 자료형은 void이지만, 파라미터가 들어간 함수의 예시
void fun(int m) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			printf("★");
		}
		printf("\n");
	}
}

int main() {
	int n = 10;
	fun(n);
	return 0;
}