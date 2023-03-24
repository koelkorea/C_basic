//	Call by reference 
//		: ȣ�� �Լ��� �Ķ���ͷ� �ּҰ�(�����ͺ���)�� �Ѱ��ִ� ���
//			-> �Լ��� �Ķ���ͷ� �ּҰ��� ���� ���� ������ �� ����
//					-> ������ �ּҰ��� ������ ��������ȭ �Ǿ��ٰ� ���� ���� ����
//						(��Ȯ���� �����ͺ����� ���� �޸��ּҰ��� {}�������� ������ �����ִ� ��Ż�̶� ���� ��)

#include <stdio.h>

// Call by reference ���� ���� ����
//		-> swap()�Լ��� �Ķ���ʹ� main()�� ���������� �ּҰ��̰�, �װ� Ȱ���Ͽ� ������ ������ ���� �����Ͽ��⿡ �ٸ� ������ {}���� swap�� �Ȱ� Ȯ�� �����ϴ� 
void swap(int* x, int* y) {	 // int * x = &a, int * y = &b;
	int z;
	printf("\nswap call start\n");
	printf("x %p y %p\n", x, y);
	//������ �ּ� ��
	printf("x %d y %d\n", *x, *y);
	//������ ����Ű�� �� swap ��
	z = *x, * x = *y, * y = z;
	printf("x %d y %d\n", *x, *y);
	//������ ����Ű�� �� swap ��
	printf("swap call end\n\n");
}

int main() {
	int a = 10, b = 20;
	printf("A %d B %d\n", a, b);
	printf("a %p b %p\n", &a, &b);
	swap(&a, &b);
	printf("A %d B %d\n", a, b);
	printf("a %p b %p\n", &a, &b);
	return 0;
}
