// ���� �Ҵ�
//		: �޸� ���� �Ҵ� ��, �ʿ䰡 ���� �� �̸� �� ���� �ο��� �����ϴ� ��

// # �����Ҵ��� �ʿ伺
//		: ������ �ڿ� �޸𸮸� ȿ�������� ����ϱ� ���� ��� (�ʿ��� ���� ���, ������ ȸ��)
//			-> �ʿ���� �޸𸮰� ȸ������ �ʴ´ٸ�? �̰� �޸� ������ ������ ��

// # ���� �Ҵ� ���� �Լ�
//  1. (void*)malloc(size_t s)
//      : s byte�� �ش��ϴ� ��ŭ�� �޸� ������ �Ҵ��ϴ� �Լ�  (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)
//          -> ���� ����� ���� ����� �� �����ͺ����� �ڷ����� ��ġ��Ű�� ����ȭ�� �ϴ°� ���� 
//             (= void* ������ ������ Ư¡�� ����ϸ� ����)
 
//  2. (void) free(void* p); 
//		: ������ ���� p�� ����Ű�� �޸� ������ �����ϴ� �Լ�
//			-> �޸� ���� ���

//  ex) �迭�� ������	  (int*) malloc(sizeof(int) * n)  =  int score1[n] 		<- �̷� �ǹ��� ���ٴ� ���� �ƴ�.. 

//      int* score1;
//      score1 = (int*)malloc(sizeof(int) * n);			<- ���� �ּ�(void *)�� ������ ������(int *)�� ����ȯ �� score ����	(sizeof(int) * n byte�� �޸𸮸� �Ҵ�, �޸��� ���� �ּ�(void *)�� ��ȯ)
//      free(score1);                                   <- score1�� ����Ű�� �޸� ����

//	ex) ������ �迭�� ������  (int**) malloc(sizeof(int*) * n) =  int* score2[n]

//      int** score2;
//      score2 = (int**)malloc(sizeof(int*) * n);
//      free(score2);				                <- score2�� ����Ű�� �޸� ����

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
