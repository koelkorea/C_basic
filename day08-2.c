#include <stdio.h>

// ������ �迭 (array)
int main() {

	int score[5];
	int i, total = 0;
	float average = 0;		// score�迭�� ���� ���� = score ��üũ�� / score �ڷ� 1�� ũ��

	// sizeof(score) / sizeof(score[0]) : �迭�� ��ü �޸�ũ�� / �ڷ��� 1���� �޸� ũ�� == �迭�� ũ��
	for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++) {

		printf("%d�� �л��� ������ �Է��ϼ��� : ", i + 1);
		// scanf_s("%d", &score[i]);

		scanf_s("%d", score + i);			// (�߿�)  &score[i] = score + i     <- �� �� i��° index�� ��ġ�� �迭�� �ּҰ��� �ǹ�
		total += score[i];
	}

	// (�߿�) �迭�� ũ�⸦ sizeof�� ���� ���� ����?? 
	//  : for���̳� average���� ���� �迭ũ�� = 5�ϱ� ������ �ϵ��ڵ� �Ͽ��µ�? -> �迭�� ũ�Ⱑ 5 -> 10���� ���Ѵ� -> �ϴ� ���ľ���
	//     -> �ٵ� sizeof����? �迭 ũ�⸦ ������ �ٲٴ� ������� �迭 ����� ���� ũ�⸦ �״�� �� �� �ִٴ� ������ ����
	average = (float) total / (sizeof(score) / sizeof(score[0]));
	printf("\n������ %d���̰� ����� %.2f�� �Դϴ�.\n", tot, average);

	return 0;
}