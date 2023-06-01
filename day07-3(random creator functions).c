#include <stdio.h>
#include <stdlib.h>       // srand(), rand() �Լ� ��� �����ϰ� ��
#include <time.h>         // time () �Լ� ��� �����ϰ� ��
#include <windows.h>      // sleep() �Լ� ��� �����ϰ� ��

// ���� ���� C��� �Լ�
//  1. int rand(void) 
//      : ������ seed��(srand(int)�� ��ȯ ����)�� ���� 0~32767���� ���� ��ȯ
// 
//  2. (void) srand(unsigned int seed)
//      : rand() �Լ��� ���Ǵ� seed���� ������ (�Ķ���ͷ� �� int���� seed���� ��)
// 
//  3. (long long) time(time_t *timer)
//      : �Ķ���Ͱ� NULL�̸�, ���� �ð� ��ȯ�� (time�� �Ķ������ time_t�� long long �ڷ����� ��Ī�̸� *timer�� ������ ����)
int main() {

	// srand(unsigned int seed)
	//  : rand()�� ������ �ٿ��� seed��ȯ
	//		-> �̰��� �Ķ���ͷ� time(NULL)�� �޾�, ���� �ð��� ���� rand()�� ���� ������ �Ǵ� seed���� ���ָ� �� �� ����
	srand((unsigned int)time(NULL));			//  �̸� �ּ�ȭ ��Ű��, ������ �Ȱ��� ���� ��µǴ°� �� �� ����

	for (int i = 1; i < 100; i++) {
		// rand()
		printf("%6d %10d \n", rand(), (unsigned int) time(NULL));			

		// sleep(int) : 1��(0.0001�� * 1000)�� delay�� ������� ��
		Sleep(1000);              
	}

	return 0;
}