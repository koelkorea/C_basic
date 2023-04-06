// pointer array
//  : 말 그대로 포인터변수로 이루어진 배열로 대표적으로는 문자열이 존재
//      ex) int * a[3] = { &b, &c, &d};

//	- 포인터 배열 선언법 ( asterisk(*) 연산자 사용)
//		: 자료형 * 포인터변수명[원소의 수]      <- 배열 내부에 특정 자료형의 포인터변수들을 저장 할 수 있는 포인터 배열 선언

//			ex1) int * a[3];                  <- '(중요) 배열크기가 3인 int형 포인트변수 배열a를 선언' 함을 의미 
//               int b = 1, c = 2, d = 3      
//               int * a[3] = { &b, &c, &d};  <- 배열안에 요소로 int 포인터변수 입력 가능 

//          ex2) int ary[5] = { 10 , 20 , 30 , 40 , 50 };
//               int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };  <- int배열의 요소값을 &를 통해 주소값으로 받아도 문제 없음

//             ex) int array_2d[5][5] = {0};
//                 int* pointer_array1[5] = { array_3d[0] , array_3d[1] , array_3d[2] , array_3d[3] , array_3d[4] };		<- 이런식으로 표기가 가능하며
//                 int* pin_point = array_3d[2];		<- 이런거도 성립


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

    return 0;
}
