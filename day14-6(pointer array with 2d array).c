#include<stdio.h>
#define Max 5
#define line 0
#define room 0
int main() {

    //int ary[5] = { 10 , 20 , 30 , 40 , 50 };
    //int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };

    int score[Max + 1][Max + 1] = {0};
    int key = 0;

    int* pScore = &score[0][0];
    int* pSarr[Max] = { score[0] , score[1] , score[2] , score[3] , score[4] };
    int** ppScore = pSarr;

    for (int i = 0; i < Max; i++) {
        for (int j = 0; j < Max; j++) {
            score[i][j] = ++key;
        }
    }

    for (int i = 0; i < Max + 1; i++) {

        for (int j = 0; j < Max + 1; j++) {

            printf("%3d ", score[i][j]);
        }

        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < Max; i++) {

        for (int j = 0; j < Max; j++) {
            printf("%3d ", *(pScore + i * (Max + 1) + j));
        }

        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < Max; i++) {

        for (int j = 0; j < Max; j++) {
            printf("%3d ", *(*(ppScore + i) + j));          // *(pScore[i] + j) = ppScore[i]    ->  *(ppScore[i] + j) = score[i] = &score[i]
        }

        printf("\n");
    }
    printf("\n");
    return 0;
}
