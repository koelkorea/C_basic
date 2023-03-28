// struct, typedef, union, enum
 
// ����ü (struct)
//      : �� �� �̻��� ����(�ڷ���)�� �������� ���ο� �ڷ������� ������
//          -> ������ ��������� �����ϴ� ��ü�� ���� (������ ��ü��� �����ص���)

//  #����ü struct ���� : 
//		struct ����ü�� {
//			�ڷ��� ��� 1;
//			�ڷ��� ��� 2;
 //		 ��;
//		};

// # ����ü(struct) ����
//      : struct ����ü�� ����ü ������;  
//         ex) struct human man, woman;

// # ����ü �ʱ�ȭ��
//      : struct ����ü�� ����ü ������ = { ��1, ��2, �� };
//        ex) struct human man = { "Michelin", 21 };

// # ����ü�� ��������� ������
//      : ����ü������.���������
//         ex) man.age

//	# (����) ����ü�� �׷��ٰ� �迭�� �ƴϴ� = ����ü���� �� ��ü�� �ּҰ��� ������ �ʴ´� = �����ͺ����� ����ü������ ������ �� ����
//		-> ex)  struct * s_pointer = man (X)
//					struct * s_pointer = &man (O)		<- �迭�� �ƴ϶� & ��� �ʿ�

//  # �迭 vs ����ü
//      - ������ : ������ ���� �׷�
//      - ������ : �迭�� ���� �ڷ����� �׷�      <->     ����ü�� �پ��� �ڷ����� ������

#include <stdio.h>
#include <string.h>

// ����ü struct ��� ����
struct student {

	int  no; // �й� ��� ����
	int  age; // ���� ��� ����
	char name[20]; // �̸� ��� ����
	char phone[20]; // ��ȭ��ȣ ��� ����
};

int main() {
	//����ü ���� ���� : struct ����ü�� ����ü ������;  
	struct student st1, st2, st3;		
	
	st1.no = 1;			// ����ü �ν��Ͻ� st1�� ������� int no�� �� �Ҵ�
	st1.age = 35;		// ����ü �ν��Ͻ� st1�� ������� int age�� �� �Ҵ�

	// strcpy_s(���� ��ġ, �޸� ũ��, "���ڿ�") : string copy�� ���Ӹ��� '���ڿ��� �����Ѵ�'�� �ǹ� 
	//		-> (�߿�) c���� ���ڿ��� char[]�� �׳� ���ڿ��� ������ �ϸ�, �ݵ�� ������ ����� (string�� �����Ǵ� �ڷ����� ����, char�� �����ϰԴ� ���� ���ڴ����ϴ� �ڷ���)
	strcpy_s(st1.name, sizeof(st1.name), "James Robert");			//st1.name = "James Robert"; ����!
	strcpy_s(st1.phone, sizeof(st1.phone), "010-1234-5678");

	st2.no = 2;
	st2.age = 24;
	strcpy_s(st2.name, sizeof(st2.name), "William Michael");
	strcpy_s(st2.phone, sizeof(st2.phone), "010-5678-1234");

	st3.no = 3;
	st3.age = 20;
	strcpy_s(st3.name, sizeof(st3.name), "Joshua David");
	strcpy_s(st3.phone, sizeof(st3.phone), "010-4321-8765");

	printf("%5d  %20s %4d %20s\n", st1.no, st1.name, st1.age, st1.phone);
	printf("%5d  %20s %4d %20s\n", st2.no, st2.name, st2.age, st2.phone);
	printf("%5d  %20s %4d %20s\n", st3.no, st3.name, st3.age, st3.phone);

	return 0;
}
