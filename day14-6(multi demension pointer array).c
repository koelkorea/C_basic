// multi demension pointer array (다중 포인트 배열)
//  : 3차원 이상의 다차원 배열을 관리하기 위한 포인트 배열... 

//  - (중요!) 3차원 이상의 다차원 배열 관리의 애로사항
//      : 3차원 이상이 될 경우, 'array_2d[5]' 이런 형식만으로는 주소값으로 인식되지 않음 
//          -> 3차원 이상의 배열의 포인터들을 다루기 위한 다차원 포인터 배열을 위한 전용 형식이 필요 	

//  - (중요!) 3차원 이상의 다차원 배열을 관리하기 위해서는?
//      : 다차원 배열은 각 차원의 시작점 주소값을 해당 차원 이하의 크기를 가지는 포인터 배열에 순차적으로 저장하여 훨씬 더 손쉽게 관리 가능

//        ex) [1:1 매칭] : int* pointer_array3d[5][5][5] = { &array_3d[0][0][0], &array_3d[0][0][1], ... , &array_3d[5][5][5]}; 
//             -> 이것을 성립 ㅇ...

//  - 기존 포인터변수 선언 (자료형 * 포인터변수명) 의 문제점 
//      : 자료형과 * 포인트변수 만으로는 만드는 포인터배열이 어떤 자료형으로 만들어졌는지만 상정하게 되는데... 
//        -> 이 경우 3차원 이상의 배열들의 주소값을 저장해야 하는 일이 생길때, 자료형은 지정이 되지만, 그게 어떤 차원에 해당하는 주소값을 저장하는지까지는 지정할 수 없음
//           (설령 할 수 있다쳐도 인간의 대가리로는 *만 늘려서는 이걸 해결이 불가능함)

//        ex) [1:5 매칭] : int** pointer_array3d[5][5] = { &array_3d[0][0], &array_3d[0][1], ... , &array_3d[5][5]}; 같은 건 성립하지 않음
//             -> 이것을 성립 X...  
//                -> 해당 케이스에서 2차원 포인트 배열은 참조하려는 3차원 배열의 2차원 시작점을 각각 넣고 싶어하는 것인데, 
//                   -> (중요) 문제는 3차원 이상의 배열에서 어떤 차원의 주소값을 담는 포인터배열을 '자료형', '*', '포인터변수명'만 쓰는 기존 방식으로는 도저히 정의할 수 없음

//            -> *의 역할은....




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


//				   (이를 위해서는 다중 포인터 개념(day12-4.c로...)이 선행되어야 하며, 다차원 배열과 포인터와 관련된 내용을 배워야함 (day14-6.c로..) )

//			   ex) int array_2d[5][5] = {0};
//			       int* pointer_array1[5] = { array_3d[0] , array_3d[1] , array_3d[2] , array_3d[3] , array_3d[4] };		<- 이런식으로 표기가 가능하며
//			       int* pin_point = array_3d[2];		<- 이런거도 성립


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
