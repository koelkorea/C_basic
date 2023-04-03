// pointer array
//  : 말 그대로 포인터변수로 이루어진 배열로 대표적으로는 문자열이 존재
//      ex) int * a[3] = { &b, &c, &d};

//	- 포인터 배열 선언법 ( asterisk(*) 연산자 사용)
//		: 자료형 * 포인터변수명[원소의 수]	   <= 배열 내부에 특정 자료형의 포인터변수들을 저장 할 수 있는 포인터 배열 선언
//			ex1) int * a[3];                  <- 안에 int 자료형의 주소를 저장하는 크기가 3인 포인터 배열인 a를 선언
//               int b = 1, c = 2, d = 3      
//               int * a[3] = { &b, &c, &d};  <- 배열안에 요소로 int 포인터변수 입력 가능 

//          ex2) int ary[5] = { 10 , 20 , 30 , 40 , 50 };
//               int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };  <- int배열의 요소값을 &를 통해 주소값으로 받아도 문제 없음

//  - (중요!) 다차원 배열과 다중 포인트 배열
//      : 다차원 배열은 각 차원의 시작점 주소값을 포인터 배열에 순차적으로 저장하여 훨씬 더 손쉽게 관리 가능함
//        (다차원 배열의 메모리 구조가 [0][0]을 시작으로 자료형 크기 만큼 움직이며 순차적으로 메모리에 할당된다는 특성으로 인해, 각 index시작점을 배열마다 저장)

//      # (주의사항!) x차원 배열의 관리를 위한 포인터 배열의 차원은 (x-1)차원이어야 함


//      # 잘못된 예시들

//			ex1) int score[5][5];
//               int* pScore = score;     <- 2차원 배열 score를 받는 포인터변수를 단순 포인터 변수로 받을 경우, pScore의 값은 score배열의 시작점인 &score[0][0]로 고정되며
//                                           데이터 구조가 배열이 아니라, pScore[3]이런게 불가능함

//			ex2) int score[5][5];
//               int* pScore[5] = score;   <- 컴파일 오류 유발

//      # 좋은된 예시들

//          ex1) int score[5][5];
//               int* pScore[5] = { score[0] , score[1] , score[2] , score[3] , score[4] }; [주소값]
//               int** ppScore = pScore;

//          ex2) int score[5][5];
//               int (*pScore)[5] = score;

#include<stdio.h>
int main() {

  int ary[5] = { 10 , 20 , 30 , 40 , 50 };
  int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };

  int score[5][5];

  // 2차원 배열 score
  int* pScore = &score[0][0];
  int* pSarr[5] = { score[0] , score[1] , score[2] , score[3] , score[4] };
  int** ppScore = pSarr;

  int key = 0;

    for (int i = 0; i < 5; i++) {

        printf("%3d ", ary[i]);
    }

    printf("\n");
    
    for (int i = 0; i < 5; i++) {

        printf("%3d ", *pAry[i]);
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            score[i][j] = ++key;
            printf("%3d ", score[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        
        printf("%3d ", *(pScore + i));
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%3d ", *pSarr[i]);
        printf("\n");
    }

    printf("\n");


    printf("--------------------------------------------------------------\n\n");


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



    return 0;
}
