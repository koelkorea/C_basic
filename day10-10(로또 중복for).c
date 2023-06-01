#include <stdio.h>
#include <stdlib.h>				//	srand(), rand() 함수 사용 가능하게 함

// 로또 번호 6개를 n개 생성하는 기능 함수를 써서 구현 (중복체크를 for문을 통한 비교)
//  -> 생성할 개수 저장
//  -> 1번째 로또 번호 6개 생성 + 중복검사
//  -> 생성된 녀석을 정렬 (순차, 선택)
//  -> 번호 출력

// lotto_repeat()
//  : (전체) 로또 buy_num개만큼 lotto_one_cycle 반복 발권 (lotto_generate, lotto_sort 가 내부에 포함 후 반복)
void lotto_repeat(int buy_num);

// lotto_one_cycle()
//  : (1인분) 로또 뽑는 로직(lotto_generate, lotto_duplication_check, lotto_sort 포함)
void lotto_one_cycle(void);

//-----------------------------(lotto_one_cycle 포함 로직 3개)--------------------------------------

// 1) lotto_generate()
//     : 개별 로또 번호 발급
int lotto_generate(void);		

// 2) lotto_duplication_check(int, int)
//     : 1싸이클 뽑는 중 중복체크
int lotto_duplication_check(int check_num, int duplication_check[46]);		

// 3) lotto_sort(int 배열[6])
//     : 뽑은 로또 숫자 정렬
void lotto_sort(int array[6]);		

int main() {
	srand((unsigned int)time(NULL));

	int buy_num = 0;

	printf_s("로또를 몇 장 사시겠습니까? : ");
	scanf_s("%d", &buy_num);

	// 정해진 횟수 만큼 로또 돌리기 (lotto_generate, lotto_sort 가 내부에 포함 후 반복)
	lotto_repeat(buy_num);

	return 0;
}

// 1. 개별 로또 번호 발급
int lotto_generate(void) {

	int lotto_result = rand() % 45 + 1;

	return lotto_result;
}

// 2. 1싸이클 뽑는 중 중복체크(단순 요소 비교)
int lotto_duplication_check(int check_num1, int check_num2) {

	if (check_num1 == check_num2) {

		printf("중복감지(%d) ", check_num1);
		return 0;
	}

	return 1;
}

// 3. 개별 로또 번호 발급
void lotto_sort(int array[]) {

	int temp;

	for (int i = 0; i < 6; i++) {

		for (int j = i + 1; j < 6; j++) {

			if (array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}


// (1인분) 로또 뽑는 로직(lotto_generate, lotto_duplication_check, lotto_sort 포함)
void lotto_one_cycle(void) {

	int lotto_array[6] = { 0 };

	for (int i = 0; i < sizeof(lotto_array) / sizeof(lotto_array[0]); i++) {

		int duplication_status = 1;

		do {
			// 1. 개별 뽑기
			lotto_array[i] = lotto_generate();		

			// 배열의 두번째 요소를 반복
			for (int j = 0; j < sizeof(lotto_array) / sizeof(lotto_array[0]); j++) {

				// 자기 자신이면 제외
				if (i != j) {
					//비교대상이 0이면 제외
					if (lotto_array[j] != 0) {
						
						duplication_status = lotto_duplication_check(lotto_array[i], lotto_array[j]);		// 2. 뽑은 녀석 중복여부 체크 (0이면 중복임)

						// 중복 확정이면 for문 빠져나가고 while 반복
						if (duplication_status == 0) {
							break;
						}
					}
				}
			}

		} while (duplication_status == 0);

	}

	// 3. 뽑은거 정렬
	lotto_sort(lotto_array);		

	// 1, 2, 3 과정 완료 후.. 해당 회차 로또 뽑은 내역 출력 
	for (int i = 0; i < sizeof(lotto_array) / sizeof(lotto_array[0]); i++) {
		printf("%d ", lotto_array[i]);
	}

	printf("\n");
}

// (전체)로또 buy_num개만큼 발권 (lotto_generate, lotto_sort 가 내부에 포함 후 반복)
void lotto_repeat(int buy_num) {

	for (int j = 1; j <= buy_num; j++) {

		printf("%d 번째 로또 번호 : ", j);
		lotto_one_cycle();
	}
}