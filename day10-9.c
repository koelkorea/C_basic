#include <stdio.h>

// �̹��� ������� ���а��� �ڵ带 ����� �Լ��� �̿��ؼ� �����
int display_menu(void);		// �޴�
int inch_cm(void);				// 1.
int cm_inch(void);				// 2.
int f_c(void);							// 3.
int c_f(void);							// 4.
void world_end();					// 5.
void nothing();

int main() {

	// �޴� �Է�
	int menu;

	// do ~ while������ ���Ῡ�� �� �޴� ��� ����
	do{
		menu = display_menu();		// �Լ��� ��ȯ������ ���� ������

		switch (menu) {

			case 1:
				inch_cm();
				break;
			case 2:
				cm_inch();
				break;
			case 3:
				f_c();
				break;
			case 4:
				c_f();
				break;
			case 5:
				world_end();
				break;
			default:
				nothing();
				break;
		}

	} while (menu != 5);

	return 0;
}


int display_menu(void) {

	int menu;		// �Լ��� ��������

	printf("[������ȯ ���α׷�]\n");
	printf("1. inch <-> cm\n");
	printf("2. cm <-> inch\n");
	printf("3. ��F <-> ��C\n");
	printf("4. ��C <-> ��F\n");
	printf("5. ������ \n");
	printf("�޴��� �������ּ��� : ");
	scanf_s("%d", &menu);
	printf("\n");

	return menu;
}

// 1.  inch <-> cm
int inch_cm(void) {

	int input;

	printf("INCH���� �Է������  : ");
	scanf_s("%d", &input);
	printf("����� �Է��� %d cm = %2.7f inch \n\n", input, input * 2.54);
}

// 2. cm <-> inch
int cm_inch(void) {

	int input;

	printf("CM���� �Է������ : ");
	scanf_s("%d", &input);
	printf("����� �Է��� %d inch = %2.7f cm \n\n", input, input / 2.54);
}

// 3. ��F <-> ��C
int f_c(void) {

	int input;

	printf("��F(ȭ��)���� �Է������ : ");
	scanf_s("%d", &input);
	printf("����� �Է��� %d ��F = %2.7f ��C \n\n", input, (input - 32) * 5.0 / 9.0);
}

// 4. ��C <-> ��F
int c_f(void) {

	int input;

	printf("��C(����)���� �Է������ : ");
	scanf_s("%d", &input);
	printf("����� �Է��� %d ��C = %2.7f ��F \n\n", input, (float)input * 9 / 5 + 32);
}

// 5. ������
void world_end() {
	printf("���α׷��� �ر��˴ϴ�...  \n");
}

void nothing() {
	printf("1 ~ 5 ������ �Է��϶��... \n");
}