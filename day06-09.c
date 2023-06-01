#include <stdio.h>		
#include<math.h>

// while을 이용하여, 화씨 -> 섭씨 변환표를 만들어라 (x°F 간격으로.. 실행되도록 해봐라)
int main() {

	int min, max, interval, level = 0;
	double result;

	printf("변환을 원하는 최소치 °F(화씨)는 얼마인가요? : ");
	scanf_s("%d", &min);

	printf("\n변환을 원하는 최대치°F(화씨)는 얼마인가요? : ");
	scanf_s("%d", &max);

	printf("\n몇  °F(화씨) 단위로 변환을 해드릴까요? : ");
	scanf_s("%d", &interval);

	while (max >= min + level * interval) {

		result = (min + level * interval - 32) * 5.0 / 9.0;
		printf("\n\n%d°F = %lf°C", min + level * interval ,result);

		level++;
	}

	return 0;
}