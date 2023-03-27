// ����ü (struct, typedef, union, enum)
//      : �� �� �̻��� ����(�ڷ���)�� �������� ���ο� �ڷ������� ������
//          -> ������ ��������� �����ϴ� ��ü�� ���� (������ ��ü��� �����ص���)

// typedef    A    B
//		: A �ڷ� Ÿ���� �� �ٸ� �̸��� B�� �����Ѵ�
//			-> B�� ���� (= A�� ����)

//  # typedef ���� : 
//		typedef struct student {
//			int no;
//			char name[20];
//			int score;
//			int rank;
//		} STU;			<- Ÿ�� ������

//		STU st1, st2, st3;		<- student ����ü 3�� ����

// struct, typedef, union, enum

// # typedef ���� 
//      : typedef �ڷ��� �����Ǹ�Ī
//         ex1) typedef unsigned char uchar;			
//				     uchar i, j;												<- ����
//         ex2) typedef int* intptr;								
//				     intptr p;													<- ����


// typedef�� ���� ����ü ������ (student to STU)
#include <stdio.h>
typedef struct student {
	int no;
	char name[20];
	int score;
	int rank;
} STU;		// (�߿�) STU = struct student�μ� �ν� (= ������ ������ �����ϸ� ����)

int main() {

	STU st;		//  struct student st;		�� ���� �ν�

	printf("��ȣ�� �Է��ϼ��� :");
	scanf_s("%d", &st.no);

	printf("�̸��� �Է��ϼ��� :");
	scanf_s("%s", st.name, (int)sizeof(st.name));

	printf("������ �Է��ϼ��� :");
	scanf_s("%d", &st.score);

	printf("������ �Է��ϼ��� :");
	scanf_s("%d", &st.rank);

	printf("\n");

	printf("=============================\n");
	printf("��ȣ\t�̸�\t����\t����\n");
	printf("%4d\t%s\t%4d\t%4d\n", st.no, st.name, st.score, st.rank);
	printf("=============================\n");
	return 0;
}
