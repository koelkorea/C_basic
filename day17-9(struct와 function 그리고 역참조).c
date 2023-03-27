// ����ü�� �Լ�
//		: ����ü ������ ���� ������ ���� �������� ���� �� �Ҵ縸 ���� (person A, B;  A = B; )
//			-> �� �̿� ������ �Լ��� ����� ����ü ������ ����������� ������ (Because ����ü�� �ڷ� Ÿ���̹Ƿ� �Լ��� �Ű����� or ���� ����)

//	 # ����ü ������ �Ϲ� ������ ���������� {}�� ���⿡ ���� �з��� ����
//		- ���� ���� ����(Call by Value)
//		- ���۷����� ���� ����(Call by Reference)
//			-> �׸��� �̸� ���� ����ü�� �������� �����ϸ�, �̸� �Լ��� Ȱ�뵵 ����


//x, y��ǥ�� ǥ���ϴ� ����ü�� ���� call by value, reference�� ���� �Լ� �ۼ�	+	call by reference�� ���� ����ü�� ���������� Ȱ�� ����
#include <stdio.h>

// ����ü struct ���� �� ������ (point to Spot)
typedef struct point {
	int xpos;
	int ypos;
} Spot;

// ����ü�� return���� �޴� �Լ�1
//		: call by value�� ���ο� �� �Լ� ����
Spot PointAdd(Spot a, Spot b) {		// ��ǥ 2���� ������

	Spot result;	// ���ο� ��ǥ�� ����

	result.xpos = a.xpos + b.xpos;	// �� ��ǥ�� x��  ����
	result.ypos = a.ypos + b.ypos;	// �� ��ǥ�� y��  ����

	return result;
}

// ����ü�� return���� �޴� �Լ�2
//		:  call by reference�� Ȱ���� �ּҰ��� ���� ������1
//			-> ���������� �ٸ����� �ּҰ��� ����� 
void PointAdd2(Spot* result, Spot a, Spot b) {		// ����� ��ǥ����ü �����ͺ���, ��ǥ 2���� ������

	// -> �� ����� �Ķ���ͷ� �־��� ����ü�� ������
	result -> xpos = a.xpos + b.xpos;	//	result �����ͺ����� x���� �������� ���� 2��ǥ�� x�� ������ ����
	result -> ypos = a.ypos + b.ypos;	//	result �����ͺ����� y���� �������� ���� 2��ǥ�� y�� ������ ����

	// * �����ڸ� �̿��� �Ķ���ͷ� �־��� ����ü�� ��������
	//(*result).xpos = a.xpos + b.xpos;
	//(*result).ypos = a.ypos + b.ypos;
}

// ����ü�� return���� �޴� �Լ�3 
//		: call by reference�� Ȱ���� �ּҰ��� ���� ������2
//			-> ���������� �ٸ����� �ּҰ��� ����� 
void PointAdd3(Spot result, Spot a, Spot b) {		// ����� ��ǥ ����ü����, ��ǥ 2���� ������

	// �ּҰ�.��������� ����� ������
	result.xpos = a.xpos + b.xpos;	// �ش� ����� ����ü ������ x���� 2��ǥ�� x�� ������ ����
	result.ypos = a.ypos + b.ypos;	// �ش� ����� ����ü ������ x���� 2��ǥ�� y�� ������ ����
}

int main(void) {

	// PointAdd�̿� : call by value�� ���ο� �� �Լ� �̿�
	Spot first;
	Spot second;
	Spot result1;

	printf("ù��° x, y��ǥ�� �Է��� �ּ��� : ");
	scanf_s("%d %d", &first.xpos, &first.ypos);

	printf("�ι�° x, y��ǥ�� �Է��� �ּ��� : ");
	scanf_s("%d %d", &second.xpos, &second.ypos);

	result1 = PointAdd(first, second);

	printf("ù��°�� �ι�° ��ǥ�� ���� �� : %d  %d \n\n", result1.xpos, result1.ypos);

	// PointAdd2�̿� : call by reference�� ���ο� �� �Լ� �̿�
	Spot third;
	Spot forth;
	Spot result2;

	printf("����° x, y��ǥ�� �Է��� �ּ��� : ");
	scanf_s("%d %d", &third.xpos, &third.ypos);

	printf("�׹�° x, y��ǥ�� �Է��� �ּ��� : ");
	scanf_s("%d %d", &forth.xpos, &forth.ypos);

	PointAdd2(&result2, third, forth);

	printf("����°�� �׹�° ��ǥ�� ���� �� : %d  %d \n\n", result2.xpos, result2.ypos);

	// PointAdd3�̿� : call by reference�� ���ο� �� �Լ� �̿�
	Spot fifth;
	Spot sixth;
	Spot result3;

	printf("�ټ���° x, y��ǥ�� �Է��� �ּ��� : ");
	scanf_s("%d %d", &fifth.xpos, &fifth.ypos);

	printf("������° x, y��ǥ�� �Է��� �ּ��� : ");
	scanf_s("%d %d", &sixth.xpos, &sixth.ypos);

	PointAdd2(&result3, fifth, sixth);

	printf("�ټ���°�� ������° ��ǥ�� ���� �� : %d  %d \n\n", result3.xpos, result3.ypos);

	return 0;
}
