#include <stdio.h>


// ���⸦ �Լ��� ����ؼ� ������
float addition(float a, float b);
float subtract(float a, float b);
float multiplication(float a, float b);
float divide(float a, float b);

int main() {

	float input1; float input2;

	printf("���� �ΰ��� �Է����ּ��� : ");
	scanf_s("%f %f", &input1, &input2);
	while (getchar() != '\n');

	printf("X + Y = %f\n", addition(input1, input2));
	printf("X - Y = %f\n", subtract(input1, input2));
	printf("X * Y = %f\n", multiplication(input1, input2));
	printf("X / Y = %f\n", divide(input1, input2));

	return 0;
}

float addition(float a, float b) {
	return a + b;
}
float subtract(float a, float b) {
	return a - b;
}
float multiplication(float a, float b) {
	return a * b;
}
float divide(float a, float b) {
	return a / b;
}