#include <stdio.h>		

// switch������ ���д��� ��ȯ�� �����
int main() {

	int ���μ���;
	char ���θ޴�����;
	int ���ڰ� = 0;
	float �����;

	while (1) {
		printf("���ϴ� ����� �޴���ȣ�� �Է����ּ���. \n");

		printf("1. INCH <-> CM\n");
		printf("2. ȭ�� <-> ����\n\n");

		scanf_s("%d", &���μ���);
		while (getchar() != '\n');

		switch (���μ���) {		// �Ķ���ͷ� �� ������ ������(int, char)�� �ڷ������� ��� ����

		case 1:

			printf("���ϴ� ��� �ڵ带 �Է����ּ���. \n");
			printf("a. INCH <-> CM\n");
			printf("b. CM <-> INCH\n\n");

			scanf_s("%c", &���θ޴�����);
			while (getchar() != '\n');

			switch (���θ޴�����) {

			case 'a':
				printf("INCH���� �Է������. \n");
				scanf_s("%d", &���ڰ�);
				����� = ���ڰ� * 2.54;
				printf("����� �Է��� %d cm = %2.7f inch \n\n", ���ڰ�, �����);
				break;

			case 'b':
				printf("CM���� �Է������. \n");
				scanf_s("%d", &���ڰ�);
				����� = ���ڰ� / 2.54;
				printf("����� �Է��� %d inch = %2.7f cm \n\n", ���ڰ�, �����);
				break;

			default:
				printf("a, b�� �� �ϳ��� �Է��϶��... \n");
				break;
			}
			while (getchar() != '\n');
			break;

		case 2:

			printf("���ϴ� ��� �ڵ带 �Է����ּ���. \n");
			printf("a. ��F(ȭ��) <-> ��C(����)\n");
			printf("b. ��C(����) <-> ��F(ȭ��) \n\n");

			scanf_s("%c", &���θ޴�����);
			while (getchar() != '\n');
			switch (���θ޴�����) {

			case 'a':
				printf("��F(ȭ��)���� �Է������. \n");
				scanf_s("%d", &���ڰ�);
				����� =  (���ڰ� - 32) * 5.0/9.0;
				printf("����� �Է��� %d ��F = %2.7f ��C \n\n", ���ڰ�, �����);
				break;

			case 'b':
				printf("��C(����)���� �Է������. \n");
				scanf_s("%d", &���ڰ�);
				����� = (float) ���ڰ� * 9/5 + 32;
				printf("����� �Է��� %d ��C = %2.7f ��F \n\n", ���ڰ�, �����);
				break;

			default:
				printf("a, b�� �� �ϳ��� �Է��϶��... \n");
				break;
			}
			while (getchar() != '\n');
			break;

		default:
			printf("1�� 2 �� �� �ϳ��� �Է��϶��... \n");
			break;					// default�� ���ǹ��� else�� �ش��ϴ� �༮
		}

		//printf("����� ���ϴ� ����� : %2.7f \n\n", �����);
	}

	return 0;
}