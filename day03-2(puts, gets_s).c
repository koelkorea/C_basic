#include <stdio.h>		
#include <conio.h>

int main() {

	char GetName[20], Sname[20];

	// puts("����") : ǥ�� ��� ��Ʈ���� Ű����κ��� ���ڿ��� ��¹���
	//		-> printf("����") �� ���������, ���ڿ��� ��� (printf()�� ����ȣȯ)

	// gets("����") :  
	//		-> scanf("����") �� ���������, enterŰ( \n )�� ������ �������� ��� ���� �Է¹���
	//			ex) Lee Seung Ho �Է½�... 
	//					- gets("Lee Seung Ho") : Lee Seung Ho
	//					- scanf("Lee Seung Ho") : Lee
	puts("���� �̸��� �Է��ϼ���.");		
	puts("gets_s : ");
	gets_s(GetName, sizeof(GetName));
	printf("�̸��� : %s �Դϴ�. \n", GetName);
	puts(GetName);

	puts("scanf_s : ");
	scanf_s("%s", Sname, (int)sizeof(Sname));
	printf("�̸��� : %s �Դϴ�. \n", Sname);
	puts(Sname);

	return 0; 

}