// Call by value
//  : (C��� �Լ��� ȣ����) �Լ��� parameter�� ���� ���� �����Ͽ� �Լ��� �����Ͽ� �����ϴ� ��� (= ���� �ִ� ���� �ƴ�)
//      -> parameter�� �������� �������� �ʱ⿡, �Լ����� �ƹ��� ������ ���Ƶ� �� {} ���� �� ��� (�Լ��� ���α׷����� ����1)
//          -> ���� ���� ó�� ������� ���� �� ���, �� ���� �ʿ��� ���� ���� �ʿ�
//             (= return�̳� �� �̷��ŷ� ���� �Ѱ� ���� ������ �־�� �Ѵ�.. �ƴϸ� ���������� ����� ������ �Ķ���ͷ� �ްų�)
#include <stdio.h>

// Call by value ���� ���� ����
//  -> swap()�Լ��� �ƹ��͵� �������� ���� + �Ķ���ʹ� main()�� ���������� �����ؼ� �޾ұ⿡.. main()�� �ƹ��� ������ ��ġ�� ���ϴ°� Ȯ�� 
void swap(int x, int y) {

	int z;
	printf("\nswap call start\n");

	//swap ��
	printf("x %d y %d\n", x, y); 

	z = x, x = y, y = z;

	//swap ��
	printf("x %d y %d\n", x, y); 
	printf("swap call end\n\n");
}

int main() {

	int a = 10, b = 20;

	printf("A %d B %d\n", a, b);
	swap(a, b);
	printf("A %d B %d\n", a, b);

	return 0;
}
