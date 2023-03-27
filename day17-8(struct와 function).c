// ����ü�� �Լ�
//		: ����ü ������ ���� ������ ���� �������� ���� �� �Ҵ縸 ���� (person A, B;  A = B; )
//			-> �� �̿� ������ �Լ��� ����� ����ü ������ ����������� ������ (Because ����ü�� �ڷ� Ÿ���̹Ƿ� �Լ��� �Ű����� or ���� ����)

//	 # ����ü ������ �Ϲ� ������ ���������� {}�� ���⿡ ���� �з��� ����
//		- ���� ���� ����(Call by Value)
//		- ���۷����� ���� ����(Call by Reference)
//			-> �׸��� �̸� ���� ����ü�� �������� �����ϸ�, �̸� �Լ��� Ȱ�뵵 ����


// swap�Լ��� ���� ����ü�� Call by Value VS Call by Reference
#include <stdio.h>
typedef struct data {
	int v1;
	int v2;
}data;

void swapVal(data d1, data d2) {
	data temp;
	temp = d1;  d1 = d2;  d2 = temp;
}

void swapRef(data* p1, data* p2) {
	data temp;
	temp = *p1;  *p1 = *p2;  *p2 = temp;
}

int main() {

	data d1 = { 10, 20 };
	data d2 = { 100, 200 };

	printf("swapVal ȣ�� �� d1 = %d %d, d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);

	swapVal(d1, d2);
	printf("swapVal ȣ�� �� d1 = %d %d, d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);		// ���� ���� ����(Call by Value) ����� �Լ��δ� return�� ���̴� main{}�� ������������ d1, d2�鿡 ���� �� �ش�

	printf("swapRef ȣ�� �� d1 = %d %d, d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);
	swapRef(&d1, &d2);
	printf("swapRef ȣ�� �� d1 = %d %d,  d2 = %d %d\n", d1.v1, d1.v2, d2.v1, d2.v2);	// ���۷����� ���� ����(Call by Reference) ����� �Լ��� �׷��� ���� d1, d2�鿡 ���� �� �ش�
	return 0;
}
