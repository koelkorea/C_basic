// pointer array
//  : 말 그대로 포인터변수로 이루어진 배열로 대표적으로는 문자열이 존재
//    ex) int * a[3] = { &b, &c, &d};

//      # (이걸 알아야 밑의 내용이 이해가능... 복습!) 
//         배열도 일종의 포인터 (상수 포인터) = 다른 한편으로는 포인터도 배열개념으로 형식에 맞춰 쓸수 있다는 말이 됨 

//           ex) 2차원 배열의 경우1 ( 3*3을 기준 int* p = array2d[3] 가정 )

//               포인터식 표현      배열식 표현   : 2차원 배열로 선언된 배열의 포인터의 경우 1차원까지를 표기한 경우는 그 자체가 주소값으로서 의미를 가짐(&가 필요없음)
//                *(p[3] + 3)   =     p[3][3]
//                  p[3] + 3    =     &p[3][3]

//           ex) 2차원 배열의 경우2 ( 3*3을 기준 int* p = array2d 가정 )

//               포인터식 표현      배열식 표현   : 2차원 배열로 선언된 배열의 포인터의 경우, 2차원 배열변수 그 자체를 받을시 p = &array2d[0][0]와 같음
//                  *(p + 8)    =     p[3][3]       -> 포인터변수라도 배열식으로 쓰면 기본적으로 주소값이 아닌 일반 값을 참조 (그냥 배열처럼 쓰면 배열같이 생각하자) 
//                    p + 8     =     &p[3][3]

//  - 포인터 배열 선언법 ( asterisk(*) 연산자 사용)
//     : 자료형 * 포인터변수명[원소의 수]      <- 배열 내부에 특정 자료형의 포인터변수들을 저장 할 수 있는 포인터 배열 선언

//      ex1) int * a[3];                    <- (중요) 배열크기가 3인 int형 포인트변수 배열a를 선언' 함을 의미 
//           int b = 1, c = 2, d = 3      
//           int * a[3] = { &b, &c, &d};  <- 배열안에 요소로 int 포인터변수 입력 가능 

//      ex2) int ary[5] = { 10 , 20 , 30 , 40 , 50 };
//           int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };  <- int배열의 요소값을 &를 통해 주소값으로 받아도 문제 없음

//  - 포인터 배열 사용 이유?
//    : N차원 배열도 메모리 할당은 선형성을 띄는 연속적 할당이라... (N-1)차원 안에서 표기한 주소값을 통해 시작위치를 지정해줄수는 있음..
//      -> But! 단지 시작위치만 지정해주는거지, 결국 *(p[3] + 3) = *(&p[3][0] + 3) = p[3][3]이나 똑같음
//          -> 1. 복잡한 다차원 배열의 경우 원하는 (N-1)차원의 행의 주소값을 순차적으로 보고 싶어질 때, 기존 포인트변수 주소값 계산법으로 이를 실현하기에는 복잡 + 번거로움
//             2. 전혀 상관없는 변수들의 주소값을 한번에 모아서 관리하려면, 관련 주소값을 한 곳에 모을 수 없는 기존 방식으로는 좀 많이 번거로움
//                 -> 포인터 배열을 사용하여 이 문제를 해결   

//      ex) int array_2d[5][5] = {0};
//          int* pin_point = array_3d[2];		                                                                    <- 이런식으로 1차원 행의 주소를 일반 int의 포인트변수로도 넣을 수 있지만
//          int* pointer_array1[5] = { array_2d[0] , array_2d[1] , array_2d[2] , array_2d[3] , array_2d[4] };		<- 이런식으로 1차원 행의 주소를 기준으로 포인트 배열을 만들면, 주소값 저장 및 관리가 더 쉬움
//          int** double_pin_point = pointer_array1;	                                                          <- int 포인트 배열의 시작주소를 int 2중 포인터 변수에 놓고, 해당 int 포인터배열의 시작주소를 저장 가능함

//          1) pointer_array1는 int 포인터변수로 구성된 포인터 배열

//          2) pointer_array1 자체는 int 포인터변수 배열의 시작주소 주소값 위치를 의미
//              -> pointer_array1 == &pointer_array1[0]
//              -> *(pointer_array1) == pointer_array1[0] = array_2d[0]

//          3) pointer_array1[2]는 int 포인터변수 배열의 2번째 값 = 2차원 배열 array_2d[1][0]의 주소값을 의미 
//              -> pointer_array1[2] == array_2d[1] == &array_2d[1][0]
//              -> *(pointer_array1[2]) == *(array_2d[1]) = array_2d[1][0]

//          4) double_pin_point는 int 포인터변수 배열의 시작주소 주소값 위치를 의미 
//             (= 역참조를 통해, int포인트배열 pointer_array1의 값을 보고, 그걸 또 역참조해서 2차원배열 array_2d의 값을 역참조 가능)
//              -> *(double_pin_point) == pointer_array1 == &pointer_array1[0]
//              -> *(*(double_pin_point)) == *(pointer_array1) == pointer_array1[0] = array_2d[0]
//              -> *(double_pin_point) + 2  == pointer_array1[2] == array_2d[1] == &array_2d[1][0]
//              -> *(*double_pin_point + 2)  == *(pointer_array1[2]) == *(array_2d[1]) = array_2d[1][0]

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
