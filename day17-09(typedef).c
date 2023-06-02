// struct, typedef, union, enum
   
// typedef  �ڷ���A    B
//  : �ڷ���A�� �� �ٸ� �̸��� B�� �����Ѵ� (= ��ǻ� ġȯ)
//     -> B�� ���� (= �ڷ���A�� ����)

//   # typedef ���� : 
//  
//       typedef struct student {
//           int no;
//           char name[20];
//           int score;
//           int rank;
//       } STU;			         <- student��� struct ������ ������ (= ��ǻ� struct student�� ġȯ)
         
//       STU st1, st2, st3;      <- student ����ü 3�� ����		<- OOP�� Ŭ���� ���� �� ������ ���� ������ �κ��� ������ (��� ������ ����)
    
//   # (�߿�) typedef�� ���� ����ü �����Ǹ� ���� ����ü ������ oop�� Ŭ���� �ν��Ͻ� ����� ������ (Ŭ������ �갡 ������ �ִٰ� ���� ����)
    
//   # typedef ���� 
//     : typedef �ڷ��� �����Ǹ�Ī
// 
//         ex1) typedef unsigned char uchar;			
//              uchar i, j;							<- unsigned char i, j����
// 
//         ex2) typedef int* intptr;								
//              intptr p;							<- unsigned int* p����

// typedef�� ���� ����ü ������ (student to STU)
#include <stdio.h>
typedef struct student {
	int no;
	char name[20];
	int score;
	int rank;
} STU;		// (�߿�) STU = struct student�μ� �ν� (= ������ ������ �����ϸ� ����)

int main() {

	// (�߿�) ���� Ŭ���� ����� ������ ������
	STU st;		//  struct student st;  �� ���� �ν�

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
