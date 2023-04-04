// ���� �Ҵ�
//  : �޸� ���� �Ҵ� ��, �ʿ䰡 ���� �� �̸� �� ���� �ο��� �����ϴ� ��

// - �����Ҵ��� �ʿ伺
//		: ������ �ڿ� �޸𸮸� ȿ�������� ����ϱ� ���� ��� (�ʿ��� ���� ���, ������ ȸ��)
//			-> �ʿ���� �޸𸮰� ȸ������ �ʴ´ٸ�? �̰� �޸� ������ ������ ��

// - ���� �Ҵ� ���� �Լ�
//  1. (void*) malloc (size_t s)
//      : s byte�� �ش��ϴ� ��ŭ�� �޸� ������ �Ҵ��ϴ� �Լ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)
//          -> ���� ����� ���� ����� �� �����ͺ����� �ڷ����� ��ġ��Ű�� ����ȭ�� �ϴ°� ���� 
//             (= void* ������ ������ Ư¡�� ����ϸ� ����)

//      # (�߿�) size_t s : * n �� ���� ���ϴ� ��ŭ�� �޸𸮸� ���� �Ҵ� ���� (���⼭�� *�� ���ϱ⸦ �ǹ�)

//  2. (void*) calloc (size_t _Count, size_t _size) 
//      : _count ���� * _size �޸� ũ�� �� ������ �� �ִ� �޸� ������ �Ҵ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

//      # (�߿�) malloc���� ������
//        1. �Ҵ�� �޸� �� ��� 0���� �ʱ�ȭ
//        2. ������ �Ķ���ͷ� ����, �������� �ø�

//  3. (void*) realloc (void* _Block, size_t size)
//      : �̹� �Ҵ��� ������ ������ �ּҰ��� _block�ϰ�, ���Ҵ� �� ������ ũ�⸦ size�� �Է� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

 
//  4. (void) free (void* p); 
//		: void ������ ���� p�� ����Ű�� �ּҰ��� �޸� ���� �Ҵ��� �����ϰ� �����ϴ� �Լ�
//			-> �޸� ���� ���

//      ex) �迭�� ������	  (int*) malloc(sizeof(int) * n)  =  int score1[n] �� �ش��ϴ� ��ŭ�� �޸� ������ �Ҵ��ϰ��� (�̷� �ǹ��� ���ٴ� ���� �ƴ�.. )

//          int* score1;
//          score1 = (int*) malloc (sizeof(int) * n);		<- ���� �ּ�(void *)�� ������ ������(int *)�� ����ȯ �� score ����	(sizeof(int) * n : ���⼭�� *�� ���ϱ⸦ �ǹ�, �޸��� �����ּ�(void *) ��ȯ)
//          free(score1);                                   <- score1�� ����Ű�� �޸� ����

//      ex) ������ �迭�� ������  (int**) malloc(sizeof(int*) * n)   =  int* score2[n] �� �ش��ϴ� ��ŭ�� �޸� ������ �Ҵ��ϰ��� (�̷� �ǹ��� ���ٴ� ���� �ƴ�.. )

//          int** score2;
//          score2 = (int**)malloc(sizeof(int*) * n);
//          free(score2);				                    <- score2�� ����Ű�� �޸� ����

//N�� ������ ��� �л� ���ϱ�
#include <stdio.h>
#include <stdlib.h> //malloc(), free()
int main() {
    int i, n;
    int* score; //���� �Ҵ� ���� ������ ����
    float sum, average, variance;

    printf("�� ���� ������ �Է� �ϳ���? ");
    scanf_s("%d", &n);

    // int(4byte)*n�� �޸� �Ҵ�        <- int score[n]; ���� �ǹ� ( ���������� ���X )
    score = (int*)malloc(sizeof(int) * n);      //  �޸� �����ּ� ��ȯ(void *) - (void * -> int *) �� ��ȯ
    
    for (i = 0; i < n; i++) {
        printf("�л� %2d : ", i + 1);
        scanf_s("%d", &score[i]); //score +i ���� ǥ��
    }

    for (sum = 0.0, i = 0; i < n; i++) {
        sum += score[i];
    }

    average = sum / n;

    for (sum = 0.0, i = 0; i < n; i++) {
        sum += (score[i] - average) * (score[i] - average);
    }

    variance = sum / n;

    printf("��հ� �л��� %f, %f �̴�\n", average, variance);

    free(score);    // ���� �Ҵ� ���� �޸� ����

    return 0;
}
