#include <stdio.h>

// 일차원 배열 (array)
int main() {
	int score[5];
	int i, total = 0;
	float average = 0;		// score배열의 묶음 개수 = score 전체크기 / score 자료 1개 크기

	for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++) {		// sizeof(score) / sizeof(score[0]) : 배열의 전체 메모리크기 / 자료형 1개의 메모리 크기 == 배열의 크기
		printf("%d번 학생의 성적을 입력하세요 : ", i + 1);
		// scanf_s("%d", &score[i]);
		scanf_s("%d", score + i);			// (중요)  %d", &score[i]와 score + i의 의미는 같음
		total += score[i];
	}

	// (중요) 배열의 크기를 sizeof를 통해 쓰는 이유?? 
	//		: for문이나 average변수 계산시 배열크기 = 5니까 정수로 하드코딩 하였는데? -> 배열의 크기가 5 -> 10으로 변한다 -> 싹다 고쳐야함
	//			-> 근데 sizeof쓰면? 배열 크기를 몇으로 바꾸던 상관없이 배열 선언시 만든 크기를 그대로 쓸 수 있다는 이점이 있음
	average = (float) total / (sizeof(score) / sizeof(score[0]));
	printf("\n총점은 %d점이고 평균은 %.2f점 입니다.\n", tot, average);

	return 0;
}