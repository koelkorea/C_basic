#include <stdio.h>		

// sizeof(parameter)
//  : �Ķ���ͷ� ���� �ڷ����� �޸��� ũ�⸦ ���Ѵ� (byte ����)
int main() {

	char str[10];

	printf("char = %lu \n", sizeof(("asdfg������")));       // ���ڿ��� �ν� (a��� ���� �ڿ��� null���� \0�� ���ԵǾ� ����  : 12 (11+1)
	printf("char = %lu \n", sizeof(('a')));                 // ���ڷ� �ν� (���⼭�� int�� �ش��ϴ°� ������ �ü���� ȯ�濡 ���� ��ǻ�Ͱ� �ν��ϴ� ���� �ٸ��� ����.. ȣȯ�� �����ϸ� ���� �����غ�����) : 4
	printf("char[10] = %lu \n", sizeof((str)));             // ũ�� 10�� ���ڹ迭�� ũ��(���� �� �迭�ּҿ� �� ���� ����) : 10
	printf("int = %lu \n", sizeof(int));                    // 4
	printf("long = %lu \n", sizeof(long));                  // 4 (�ü���� ȯ�濡 ���� ��ǻ�Ͱ� �ν��ϴ� ���� �ٸ��� ����.. ȣȯ�� �����ϸ� ���� �����غ�����)
	printf("float = %lu \n", sizeof(float));
	printf("double = %lu \n", sizeof(double));
	printf("long double = %lu \n", sizeof(long double));

	return 0;
}