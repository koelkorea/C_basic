// (�߿�) C������ parameter�� ����array
//   : �Լ��� �Ķ���� ����array�� ��� ���� �ְ� �ʹٸ�?
//      -> int p[10] ��� X          <-  C���� �Ű������� �迭�� ������ ���X  = �迭�� ��°�� �����ϴ� ���X
 //     -> int p[] ��� ��             <- �� ��� �迭�� �ּ� ������ ���� (�ƽôٽ��� �� �༮�� �迭�� �ƴ϶� ũ����� �������� �ʴ´ٴ°� ���)

#include <stdio.h>
#include <stdlib.h> // rand() , srand()
#include <time.h> // time()
#define MAX 10
#define rand_range 5000

//�Լ��� �Ķ���ͷ� �迭�ּҸ� ������ ��� ǥ�� ���� (int p[] , int *p �� int p[] ����)

// �迭�� ������ �ִ� ����
void input(int *p, int cnt) {           // int p[] == int *p;

    srand(time(NULL));
    // ����Ʈ������ �޸� ũ��� 8byte
    printf("sizeof : %llu, %llu, %llu, %llu  \n\n", sizeof(p), sizeof(int*), sizeof(p) / sizeof(p[0]), sizeof(p[0]));            //  8,  8,  2,  4    <- sizeof(p)�� 8 / sizeof(p[0]) 4 = 2
    printf("%d�� ���� ����\n\n", cnt);


    // �迭ũ�⸸ŭ for���� ������, ������ �����ͺ���  p�� �޸� ���� 4byte�� �迭ũ�⸸ŭ �ݺ��ϴ� ���� ���̴�.
    for (int i = 0; i < cnt; i++) {

        printf("���� %3d : ", i + 1);
        *p = rand() % rand_range + 1;        // p[i] = *(p+i)
        printf(" %4d\n", p++);                      // �� �ڵ� ���� ���������ڷ� p = p + 1�� �����Ǿ� a�� �ּҴ� ��� �� ĭ�� �ڷ� ����
    }
}

// �ִ밪 ����
int num_max(int *p, int cnt) { // int p[] == int *p;
    
    int i, max = *p;

    for (i = 1; i < cnt; i++) {

        if (max < *++p) {
            max = *p;
        }
    }

    return max;
}

// �ּҰ� ����
int num_min(int *p, int cnt) { // int p[] == int *p;

    int i, min = *p;

    for (i = 1; i < cnt; i++) {

        if (min > *++p) {
            min = *p;
        }
    }

    return min;
}

int main() {
    int num[MAX];
    input(num, MAX);
    printf("�ִ밪 : %d\n", num_max(num, MAX));
    printf("�ּҰ� : %d\n", num_min(num, MAX));
    return 0;
}
