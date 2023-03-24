//포인터 방식 표현
#include <stdio.h>
#include <stdlib.h> // rand() , srand()
#include <time.h> // time()
#define MAX 10
#define rand_range 5000

void input(int *p, int cnt) { // int p[] == int *p;

    srand(time(NULL));
    printf("sizeof : %llu, %llu, %llu, %llu  \n\n", sizeof(p), sizeof(int*), sizeof(p) / sizeof(p[0]), sizeof(p[0]));
    printf("%d개 난수 생성\n\n", cnt);

    for (int i = 0; i < cnt; i++) {

        printf("생성 %3d : ", i + 1);
        *p = rand() % rand_range + 1;
        printf(" %4d\n", p++);
    }
}

int num_max(int *p, int cnt) { // int p[] == int *p;
    
    int i, max = *p;

    for (i = 1; i < cnt; i++) {

        if (max < *++p) {
            max = *p;
        }
    }

    return max;
}

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
    printf("최대값 : %d\n", num_max(num, MAX));
    printf("최소값 : %d\n", num_min(num, MAX));
    return 0;
}
