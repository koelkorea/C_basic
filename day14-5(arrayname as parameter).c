// (�߿�) C������ parameter�� ����array
//   : �Լ��� �Ķ���� ����array�� ��� ���� �ְ� �ʹٸ�?
//      -> int p[10] ��� X          <-  C���� �Ű������� �迭�� ������ ���X  = �迭�� ��°�� �����ϴ� ���X
 //     -> int p[] ��� ��             <- �� ��� �迭�� �ּ� ������ ���� (�ƽôٽ��� �� �༮�� �迭�� �ƴ϶� ũ����� �������� �ʴ´ٴ°� ���)

//�迭 ��� ǥ��
#include <stdio.h>
#include <stdlib.h> // rand() , srand()
#include <time.h> // time()
#define MAX 10
#define rand_range 5000

void input(int p[], int cnt) { // int p[] == int *p;

    srand(time(NULL));
    printf("sizeof : %llu, %llu, %llu, %llu  \n\n", sizeof(p), sizeof(int*), sizeof(p) / sizeof(p[0]), sizeof(p[0]));
    printf("%d�� ���� ����\n\n", cnt);

    for (int i = 0; i < cnt; i++) {
        printf("���� %3d : ", i + 1);
        p[i] = rand() % rand_range + 1;         // p[i] = *(p+i)
        printf(" %4d\n", p[i]);
    }
}

int num_max(int p[], int cnt) { // int p[] == int *p;
    int i, max = p[0];
    for (i = 1; i < cnt; i++) if (max < p[i]) max = p[i];
    return max;
}

int num_min(int p[], int cnt) { // int p[] == int *p;
    int i, min = p[0];
    for (i = 1; i < cnt; i++) if (min > p[i]) min = p[i];
    return min;
}

int main() {
    int num[MAX];
    input(num, MAX);
    printf("�ִ밪 : %d\n", num_max(num, MAX));
    printf("�ּҰ� : %d\n", num_min(num, MAX));
    return 0;
}
