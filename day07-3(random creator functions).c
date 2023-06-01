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

	for (int i = 1; i < 100; i++) {
		// rand()
		printf("%6d %10d \n", rand(), (unsigned int) time(NULL));			

		// sleep(int) : 1초(0.0001초 * 1000)의 delay를 가지라는 말
		Sleep(1000);              
	}

	return 0;
}