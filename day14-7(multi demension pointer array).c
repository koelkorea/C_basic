// multi demension pointer array (고차원 포인트 배열)
//  : 3차원 이상의 다차원 배열을 관리하기 위한 포인트 배열... 

//  - 기존 3차원 이상의 다차원 배열의 관리를 위한 포인터 배열 제조 상의 문제? 
//      : 만들어진 포인터 배열에 일일이 주소를 다 입력하고 자빠져야 함 
//          ex) int array_2d[5][5] = {0};
//              int* pointer_array1[5] = { array_2d[0] , array_2d[1] , array_2d[2] , array_2d[3] , array_2d[4] };   <- 이런식으로 수동으로 포인터 지정을 해줘야함..


//      # (문제 인식) 매번 이렇게 포인터를 지정해줘서야 굳이 포인터배열을 쓸 필요가 있는가? ( = 기존 포인터변수 선언 (자료형 * 포인터변수명) 의 문제점 발견)
//          : 기존의 고차원 배열을 포인터 배열로 매칭하여 표기할 수 있는 표기법이 필요함
//            -> (n-i)포인터로 요소를 이루는 포인터변수명을 선언하고 i차원 배열로 해당 고차원 배열을 치환할수 있도록 하면 될거 같음
//                -> HOW? score의 i차원에 위치하는 값을 참조하는 (n-i)중 포인터 변수가 있다고 가정하고, 그 변수를 (n-i)중으로 역참조한 값을 i차원 배열로 만들게 하자


//  - 자료형 (*x 역참조하는수 X중포인트배열명)[참조하는 고차원배열 1차원크기].....[참조하는 고차원배열 i차원크기] = 해당 고차원 배열명;
//    : 크기가 [1차원크기]...[i차원크기]인 해당 자료형의 배열은 고차원 배열명의 주소를 (n-1)중으로 참조하는 X중포인트배열명의 주소값을 i번 역참조 한 값을 순차적으로 주소값을 이동하며 배열의 요소를 채운다

//      ex) int score[5][5][5];
//          int (**pScore2)[5] = score;   <- pScore2[i] => score[i][0][0]으로 치환될 수 있음 
//                                           (= 크기가 5인 int배열은 (pScore2 + i) 주소값이 2번 역참조한 결과물인 score[i][0][0]의 값을 순차적으로 배열의 값으로 넣는다) 

//         (과정) -> 다음의 과정을 2중 포인터변수명, 고차원 배열명을 파라미터로 받아 일종의 함수화 시켜놓은 결과물
//          int score[5][5][5];
//          int** pScore2 = score[0];   <- pScore2 + i => &score[i][0][0]   (= 아시다시피 행단위로 의도하대로 움직일거면 꼭 치환해줘야 함)
//          int pScore2[5] = {(**pScore2), (**(pScore2 + 1)), (**(pScore2 + 2)), (**(pScore2 + 3)), (**(pScore2 + 4))}

//          -> 1. 2중 포인터변수 pScore2가 내부적으로 선언되고, 그 값은 score의 1차원 행을 주소값을 시작으로 대입된다 (= pScore2의 주소값 연산은 1차원 단위로 움직임)
//             2. score의 1차원 행의 크기인 5만큼의 int를 받는 배열명 pScore2를 통해 2중 포인터변수 pScore2의 값들을 대입해준다.
//             3. pScore2[i] = *score[i][0][0] 의 의미를 가지게 되며, pScore2 배열은 score[i]의 2중 역참조 값으로 구성
//                (= 아시다시피 행단위로 의도하대로 움직일거면 꼭 치환해줘야 함)


//      # 잘못된 예시
//			ex1) int score[5][5];
//               int* pScore[5] = score;   <- 컴파일 오류 유발

//      # 좋은 예시
//          ex2) int score[5][5];
//               int (*pScore)[5] = score;  <- score[i]의 1차원 행을 역참조 한 값으로 구성된 int 배열 pScore의 탄생으로 받아들이자

#include<stdio.h>
#define Max 5
#define line 0
#define room 0
int main() {

    //int ary[5] = { 10 , 20 , 30 , 40 , 50 };
    //int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };

    int score[Max + 1][Max + 1] = {0};
    int key = 0;

    // 기존 방식의 2차원 배열의 포인터배열 매칭 
    int* pScore = &score[0][0];
    int* pSarr[Max] = { score[0] , score[1] , score[2] , score[3] , score[4] };
    int** ppScore = pSarr;

    // 새로운 방식으로 score 1차원 행의 역참조값으로 구성된 pScore2 
    int (*pScore2)[5] = score;

    printf("[2차원 배열을 2중 포인터 변수를 역참조 하여 배열 구현] \n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%3d ", (i + 1) * ( (**ppScore) + j ) );
        }
        printf("\n");
    }

    printf("\n");

    printf("[2차원 배열을 1중 포인터 변수를 역참조 하여 배열 구현] \n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%3d ", *pScore++);
        }
        printf("\n");
    }

    printf("\n");

    printf("[2차원 배열을 2중 포인터 변수를 역참조 한 포인터 배열에 접근하여 배열 구현] \n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%3d ", *(pSarr[i] + j) );
        }
        printf("\n");
    }

    printf("--------------------------------------------------------------\n\n");

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
