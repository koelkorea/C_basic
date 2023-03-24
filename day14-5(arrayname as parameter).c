// (중요) C언어에서의 parameter와 정적array
//   : 함수의 파라미터 정적array의 모든 값을 넣고 싶다면?
//      -> int p[10] 사용 X          <-  C언어는 매개변수로 배열의 선언을 허용X  = 배열을 통째로 복사하는 방법X
 //     -> int p[] 사용 ㅇ             <- 그 대신 배열의 주소 값으로 전달 (아시다시피 이 녀석은 배열이 아니라 크기까지 가져오진 않는다는거 명심)

//배열 방식 표현
#include <stdio.h>
#include <stdlib.h> // rand() , srand()
#include <time.h> // time()
#define MAX 10
#define rand_range 5000

void input(int p[], int cnt) { // int p[] == int *p;

    srand(time(NULL));
    printf("sizeof : %llu, %llu, %llu, %llu  \n\n", sizeof(p), sizeof(int*), sizeof(p) / sizeof(p[0]), sizeof(p[0]));
    printf("%d개 난수 생성\n\n", cnt);

    for (int i = 0; i < cnt; i++) {
        printf("생성 %3d : ", i + 1);
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
    printf("최대값 : %d\n", num_max(num, MAX));
    printf("최소값 : %d\n", num_min(num, MAX));
    return 0;
}
