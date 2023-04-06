// (중요) N차원 배열과 포인터의 표기형식 관계...

//      3. (중요!) 3차원 array변수의 이중성
//          - 3차원 array변수 자신 : 포인터변수 (3차원 array 자신의 시작주소값(= &3차원배열변수[0][0][0] = 3차원배열변수[0][0])을 의미)
//          - []와 함께 경우( &3차원배열변수[1][0][0] = 3차원배열변수[1][0] = 3차원배열변수[2])
//             1. 3차원배열변수[]     : 1차원에 해당하는 부분을 의미하는 변수의 표기값 그 자체가 주소를 의미하는 '포인터변수'
//             2. 3차원배열변수[][]   : 2차원에 해당하는 부분을 의미하는 변수의 표기값 그 자체가 주소를 의미하는 '포인터변수'
//             3. 3차원배열변수[][][] : 배열 안에 위치하는 단순 자료형 변수 (= 포인터와 관련성이 1도 없음)

//      # (결론) (N-1)차원까지의 배열표기 = N차원 배열에서의 해당 차원에 해당하는 주소값 의미
//        -> (중요!) But! 3차원 이상의 배열들을 관리하기 위해서는 '다차원 포인터변수로 이뤄진 X중 포인터 배열'을 다룰 수 있어야 함..
//           -> 이를 위해서는 다중 포인터 개념(day12-4.c로...)이 선행되어야 하며, 다차원 배열과 포인터와 관련된 내용을 배워야함 (day14-6.c로..) )

#include<stdio.h>
int main() {

    // 3차원 배열 score_3D
    int score_3D[5][5][5] = { 0 };

    // pScore1 = score_3D = &score_3D[0][0][0]
    int* pScore1 = score_3D;
    
    // pScore2 = score_3D[2] = &score_3D[2][0][0]
    int* pScore2 = score_3D[2];
    
    // pScore3 = score_3D[3][4] = &score_3D[3][4][0]
    int* pScore3 = score_3D[3][4];

    int key = 0;

    // 3차원 배열 채우기
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            for (int u = 0; u < 5; u++) {

                key += 2;
                score_3D[i][j][u] = key;
                printf("%3d ", score_3D[i][j][u]);
            }

            // 1차원이 끝날때마다 |로 표기
            printf(" | ");
        }
        // 2차원이 끝날때마다 줄 바꿈
        printf("\n");
    }

    printf("\n");

    // pScore1 = score_3D = &score_3D[0][0][0]를 의미함을 확인
    for (int i = 0; i < 5; i++) {

        printf("%3d ", *(pScore1 + i));
        printf("%3d ", *(score_3D + i));
    }

    printf("\n");

    // pScore2 = score_3D[2] = &score_3D[2][0][0]를 의미함을 확인
    for (int i = 0; i < 5; i++) {

        printf("%3d ", *(pScore2 + i));
        printf("%3d ", *(score_3D[2] + i));
    }

    printf("\n");

    // pScore3 = score_3D[3][4] = &score_3D[3][4][0]를 의미함을 확인
    for (int i = 0; i < 5; i++) {

        printf("%3d ", *(pScore3 + i));
        printf("%3d ", *(score_3D[3][4] + i));
    }

    return 0;
}
