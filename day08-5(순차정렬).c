#include <stdio.h>
#include <stdlib.h>	   // srand(), rand() �Լ� ��� �����ϰ� ��
#include <time.h>      // time () �Լ� ��� �����ϰ� ��

// ��������
//  : ȸ������ �ּ� i�� �������� ������ ���������� ���Ͽ�, �ڱ⺸�� ũ�ų� ���� ���� ������ �׶� �׶� ��ȯ�ϴ� ���
//     -> �̳��̳� ���������̳� �ᱹ 2�� for�� �����
//        (= ����� �ű⼭ �ű��... �ð����⵵�� n^2��°� �ٸ��� ����)
int main() {

	int array[10];

	// �� ��ü�� �ӽú���
	int temp;				

	//  �̸� �ּ�ȭ ��Ű��, ������ �Ȱ��� ���� ��µǴ°� �� �� ����
	srand((unsigned int)time(NULL));			

	// �迭�� ���ǰ� 500�� ����
	for (int i = 0; i <= 9; i++) {
		array[i] = rand() % 500;
		printf("array[%d] = %d \n", i, array[i]);
	}

	// �������� ��� (1~9 ������ ���� ���� �۰ų� ū ���� ��������, 2~9 �̷������� ���� ���)
	for (int i = 0; i <= 9; i++) {
		
		for (int j = i + 1; j <= 9; j++) {

			if (array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}

		}

	}

	// sort�� ����� ó�� , �� ����ϸ� ����
	printf("�ִ밪 : %d\n", array[9]);
	printf("�ּҰ� : %d", array[0]);

}