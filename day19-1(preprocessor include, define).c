// ��ũ�� �� ���Ǻ� ������ ������
   
// ��ó��(Preprocessor) ����
//  : ������ - ��޾� ��ǻ�Ͱ� ���� �����ϵ��� ��ȯ ����
//     -> ���� ���� ���� �ǵ���, �ش��ϴ� �ܺ� �ڵ���� ���� �ٿ��ְ� ������ �� �� �ְ� �ϴ� �����̶� �����ϸ� ��
   
// 1. #include <filename> or "filename"
// 
//     - <filename>    
//        : Ư�� ��ο��� ��������� �������� ��������°� �ǹ�
// 	   
//     - "filename"    
//        : �ҽ����ϰ� ���� �������� 1�� �˻� -> <filename> �� ������ ��ο��� 2�� �˻�
   
// 2. #define token expression
//     : token�� expression���� ��ġ (��! �ٸ� ���Ͽ����� ������ �Ұ����ϴ�)
   
// 3. #ifdef
//     : ��ó�� �������� ���ǿ� ���� ������ ��� ���Խ�Ű�ų� ���ܽ�Ű�� ����
// 	     (���ǽ��� ��ũ�� ����� ���� ����, ���� ���� �򰡽�, �� ��)
   
//     - #ifdef _Header_PSK
//        : _Header_PSK ����Ǿ� �ִٸ� ������ ����
// 
//     - #ifndef _Header_PSK
//        : _Header_PSK ������� �ʾҴٸ� ������ ����
   
// 5. #if
//     : ��ũ���� ���̳�, ���� ���� ������ �����Ͽ� ������ ���θ� ����
       
//     - #if    ����1  �ڵ�1
//        : ����1�� �����ϸ� �ڵ�1�� ������

//     - #elif  ����2  �ڵ�2          
//        : ����2�� �����ϸ� �ڵ�2�� ������

//     - #else  ����3  �ڵ�3   
//        : ��� ������ �� ������ �ڵ�3 ������

//     - #endif
   
// 	# ���ǽ� �ۼ�����
// 		-> ���, �� ������ ����� �����ϴ�. == , != , > , < , >= , <=
// 		-> �� ����� ���� ��� ����(�Ǽ�, ���ڿ� �Ұ�)
// 		-> �� ������ ��� ����


//��� ���� ���� 
//include guard

// ifdef
//  : ��ó�� �������� ���ǿ� ���� ������ ��� ���Խ�Ű�ų� ���ܽ�Ű�� ����
//    (���ǽ��� ��ũ�� ����� ���� ����, ���� ���� �򰡽�, �� ��)

// PSK_H ������� �ʾҴٸ�, �����Ͽ� �����ϱ�
#ifndef _psk_H

// PSK_H ����
#define _psk_H

// include <filename> or "filename"
//  <filename>   : Ư�� ��ο��� ��������� �������� ��������°� �ǹ�
//  "filename"     �ҽ����ϰ� ���� �������� 1�� �˻� -> <filename> �� ������ ��ο��� 2�� �˻�
#include<stdio.h>

// #define token expression
//  : token�� expression���� ��ġ (��! �ٸ� ���Ͽ����� ������ �Ұ����ϴ�)
#define PI 3.141592
#define SQRT(X) X*X

typedef struct _Person {

	char name[10];
	int age;
	char address[128];
}Person;

typedef long int file_size_t;
extern long long arr_len;

void hello_display() {
	printf("hello world\n");
}
#endif

//�ҽ����� ����
#define A  1 // 0 or 1
#include<stdio.h>
#include"psk.h"


int main() {

	file_size_t a;
	Person p1;

	// if
	// : ��ũ���� ���̳�, ���� ���� ������ �����Ͽ� ������ ���θ� ����

	#if A == 0
		printf("define A == 0\n");
	#elif A == 1
		printf("define A == 1\n");
	#endif
		hello_display();

	return 0;
}
