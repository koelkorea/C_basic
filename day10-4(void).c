#include <stdio.h>

//   # void ������
//     : return�� �������� �ʴ� �ڷ��� (�ڵ��� ����� ������, ������ �ʰ� ��ġ�����Ŷ� ������)
//        -> ���� return ���� �ʿ���� �ʿ��� �۾��� �ݺ������ϰ� �ϰų�, parameter�� ���� call by reference �������� ������ �������� ������ ���������� ������ �ʿ䰡 ������ ����ϱ⿡..
//            -> void �ڷ��� �Լ��� �ش� �Լ��� �뵵�� �Ͻ��Ѵٰ� �� �� ����

//   # �Լ� ����� ()���� void
//     : parameter�� ������ �ǹ� (���� : �Ķ���� void�� ������ �����ϴ�)
//        -> void voidFunction(void); = void voidFunction();

// void �ڷ����� ������� void
void display_menu(void) {

	printf("[������ȯ ���α׷�]\n");
	printf("1. inch <-> cm\n");
	printf("2. cm <-> inch\n");
	printf("3. ��F <-> ��C\n");
	printf("4. ��C <-> ��F\n");
	printf("5. ������ \n");
	printf("�޴��� �������ּ���\n");
}

int main() {

	display_menu();
	return 0;
}