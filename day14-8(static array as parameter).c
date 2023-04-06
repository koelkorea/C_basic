// (중요) C언어에서의 parameter와 정적array
//   : 함수의 파라미터 정적array의 모든 값을 넣고 싶다면?
//      -> int p[10] 사용 X          <-  C언어는 매개변수로 배열의 선언을 허용X  = 배열을 통째로 복사하는 방법X
 //     -> int p[] 사용 ㅇ             <- 그 대신 배열의 주소 값으로 전달 (아시다시피 이 녀석은 배열이 아니라 크기까지 가져오진 않는다는거 명심)


#include <stdio.h>
#include <stdlib.h> // rand() , srand()
#include <time.h> // time()
#define MAX 10
#define rand_range 5000

//함수의 파라미터로 배열주소를 배열 방식 표현 예시 (int p[] , int *p 중 int p[] 선택)

// 배열에 랜덤값 넣는 과정
void input(int p[], int cnt) {      // int p[]는 배열의 모양을 하고 있지만, 실제로는 &p[0]의 값을 가지고 있고, 배열 크기는 소실되어 있음

    srand(time(NULL));

    // 포인트변수의 메모리 크기는 8byte
    printf("sizeof : %llu, %llu, %llu, %llu  \n\n", sizeof(p), sizeof(int*), sizeof(p) / sizeof(p[0]), sizeof(p[0]));       //  8,  8,  2,  4    <- sizeof(p)는 8 / sizeof(p[0]) 4 = 2
    printf("%d개 난수 생성\n\n", cnt);

    for (int i = 0; i < cnt; i++) {

        printf("생성 %3d : ", i + 1);
        p[i] = rand() % rand_range + 1;         // p[i] = *(p+i)
        printf(" %4d\n", p[i]);
    }
}

// 최대값 판정
int num_max(int p[], int cnt) { // int p[] == int *p;

    int i, max = p[0];
    
    for (i = 1; i < cnt; i++) {
        if (max < p[i]) {
            max = p[i];
        }
    }
    
    return max;
}

// 최소값 판정
int num_min(int p[], int cnt) { // int p[] == int *p;
    
    int i, min = p[0];
    
    for (i = 1; i < cnt; i++) {
        if (min > p[i]) {
            min = p[i];
        }
    }
    return min;
}

int main() {
    int num[MAX];            // 배열의 크기는 10으로 설정
    input(num, MAX);
    printf("최대값 : %d\n", num_max(num, MAX));
    printf("최소값 : %d\n", num_min(num, MAX));
    return 0;
}
