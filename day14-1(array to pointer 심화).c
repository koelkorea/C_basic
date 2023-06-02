// array to pointer decay (상수 포인터)
//  : 배열로 선언된 변수 a는 그 자체가 a[0]의 주소를 의미하며, &가 필요없다
//      -> 정확히는 pointer 변수의 값에 배열변수 a를 넣으면, 그 크기정보가 부식(decay) 되고, 시작 주소값만 남게 된다는 개념 
//          -> (중요!) 배열로 변언된 변수 스스로의 이름은 포인터라는 말

//    # (중요) p = &a[0]로 고정시, 배열 a와 포인터 p의 관계 정리
          /*  ------------------------------------ [메모리 주소값]------------------------------------ =============================[역참조값 = 배열값]==========================
              |   & a[0]    =      a           =     & p[0]    =    p        =    0x7ffffb0ee620     |   1     =    a[0]     =     * a          =     p[0]    =    * p        |    
              |   & a[1]    =      a + 1       =     & p[1]    =    p + 1    =    0x7ffffb0ee624     |   2     =    a[1]     =     * (a + 1)    =     p[1]    =    * (p + 1)  |    
              |   & a[2]    =      a + 2       =     & p[2]    =    p + 2    =    0x7ffffb0ee628     |   3     =    a[2]     =     * (a + 2)    =     p[2]    =    * (p + 2)  |    
              |   & a[3]    =      a + 3       =     & p[3]    =    p + 3    =    0x7ffffb0ee62C     |   4     =    a[3]     =     * (a + 3)    =     p[3]    =    * (p + 3)  |    
              |   & a[4]    =      a + 4       =     & p[4]    =    p + 4    =    0x7ffffb0ee632     |   5     =    a[4]     =     * (a + 4)    =     p[4]    =    * (p + 4)  |    
     
              -------------------------------------[역참조값 = 배열값]----------------------------------
              |     1      =       a[0]        =        *a           =      p[0]        =    *p       | 
              |     2      =       a[1]        =        *(a + 1)     =      p[1]        =    *(p + 1) |
              |     3      =       a[2]        =        *(a + 2)     =      p[2]        =    *(p + 2) |
              |     4      =       a[3]        =        *(a + 3)     =      p[3]        =    *(p + 3) |
              |     5      =       a[4]        =        *(a + 4)     =      p[4]        =    *(p + 4) | */


//   # (중요) C언어에서의 parameter와 정적array
//       : 어떤 함수의 parameter로 정적 array의 모든 값을 넣고 싶다면?
//         -> int p[10] 사용 X                                           <- C언어는 매개변수로 배열의 선언을 허용X  =  배열을 통째로 복사하는 방법X
//         -> int p[] 사용 ㅇ                                            <- 배열의 시작주소값을 전달하여, 배열의 값을 역참조 하여 함수에 활용할 수 있게 하면 됨!
//                                                                           -> BUT! 아시다시피 이 녀석은 배열이 아니라 크기까지 가져오진 않는다는거 명심
     

//    # (결론) 배열도 일종의 포인터 (상수 포인터)  = 다른 한편으로는 포인터도 배열개념으로 형식에 맞춰 쓸수 있다는 말이 됨 (n차원 배열도 메모리 할당은 선형성을 띄는 연속적 할당이기 때문)
//         -> 문자열도 char 배열로서 pointer array 개념이랑 연관될 수 있음
     
//            ex) 1차원 배열의 경우 (int* p = array1d명 로 가정)
              
//                포인터식 표현      배열식 표현   : 둘 다 의미는 포인터변수 p의 현재 주소값에서 (해당 자료형 메모리크기 * 3) 만큼 높은 메모리 주소를 의미  
//                  *(p + 3)     =      p[3]          -> 포인터변수라도 배열식으로 표기한다면, 기본적으로 주소값이 아닌 해당 배열의 index에 놓인 일반 값을 참조 (그냥 배열처럼 쓰면 배열같이 생각하자) 
//                    p + 3      =     &p[3]
              
//            ex) 2차원 배열의 경우1 ( 3 * 3 배열을 기준 int* p = array2d명[3] 가정 )
              
//                포인터식 표현      배열식 표현   : 2차원 배열의 포인터의 경우, 2차원 배열변수가 1차원까지만 표기한 배열이 대입되는 경우 
//                 *(p[3] + 3)   =      p[3][3]       -> 그 자체가 해당 배열의 각 1차원 라인의 시작주소값으로서 의미를 가짐 (&가 필요없음)
//                   p[3] + 3    =     &p[3][3]
              
//            ex) 2차원 배열의 경우2 ( 3 * 3 배열을 기준 int* p = array2d명 가정 )
              
//                포인터식 표현      배열식 표현   : 배열의 포인터변수가 2차원 배열변수 그 자체를 받는다면, 포인터변수 p = & array2d[0][0]; 의 의미와 같음
//                   *(p + 8)    =      p[3][3]       -> 포인터변수라도 배열식으로 표기한다면, 기본적으로 주소값이 아닌 해당 배열의 index에 놓인 일반 값을 참조 (그냥 배열처럼 쓰면 배열같이 생각하자) 
//                     p + 8     =     &p[3][3]


// (중요) N차원 배열과 포인터의 표기형식 관계...
//   : (결론) (N-1)차원까지의 배열표기 = N차원 배열에서의 해당 차원에 해당하는 주소값 의미
//       -> (중요!) But! 3차원 이상의 배열들을 관리하기 위해서는 '다차원 포인터변수로 이뤄진 X중 포인터 배열'을 다룰 수 있어야 함..
//            -> 그냥 애지간하면 1중 포인터변수 만들어 둬서, 거기다두고 꼴리는 대로 대입하면, 내가 쓴 배열주소가 X중 포인터니 뭐니 신경 쓸 필요 없이 직관적으로 사용가능!

//      1. (중요!) 1차원 array변수의 이중성
//          - 1차원 array변수 자신
//             : 해당 1차원 배열의 시작주소값을 의미하는 '포인터변수' 
//               ( 1차원배열변수 = &1차원배열변수[0] )
//      
//          - []와 함께하는 경우
//             : 배열 안에 위치하는 단순 자료형 변수 (= 포인터와 관련성이 1도 없음)
        
//               ex) int a[5] = { 1,2,3,4,5 };
//                    -> int *p = a; 라면,
//                        -> (중요) a = &a[0] 유추 가능 
                 
//                    1) a는 상수 포인터
//                    2) a는 int 자료형 타입 집합의 시작주소 위치
//                            -> *(a + 2) ==  a[2]
//                            ->   a + 2  == &a[2] 
        
//      2. (중요!) 2차원 array변수의 이중성
//          - 2차원 array변수 자신
//             : 해당 2차원 배열의 시작주소값을 의미하는 포인터변수 
//               ( 2차원배열변수 = &2차원배열변수[0][0] = 2차원배열변수[0] )
//      
//          - []와 함께하는 경우( &2차원배열변수[1][0] = 2차원배열변수[1] )
//             1. 2차원배열변수[]   : 1차원에 해당하는 부분을 의미하는 변수의 표기값 그 자체가 주소를 의미하는 '포인터변수'
//             2. 2차원배열변수[][] : 배열 안에 위치하는 단순 자료형 변수 (= 포인터와 관련성이 1도 없음)
        
//             ex) int a[5][5] = {0};
//                  -> int *p = a[2]라면,
//                      -> (중요) a[2] = &a[2][0] 유추 가능 
        
//                 1) a는 상수 포인터
//                 2) a는 int 자료형 타입 집합의 시작주소 위치
//                         -> *(a[2] + 2) ==  a[2][2]
//                         ->   a[2] + 2  == &a[2][2] 
        
//      3. (중요!) 3차원 array변수의 이중성
// 
//          - 3차원 array변수 자신
//             1. 단독으로 쓸 경우 
//                 : 쓰레기주소값 (= 단독으로 쓴 '3차원배열변수'는 진짜 3차원배열변수[0][0][0]와 어떤 연관관계도 찾을 수 없음)
//                    -> 3차원 array변수 자신값이 쓰레기인 이유
//                        : 다차원 배열의 시작 주소를 저장하고 있지만, 이 주소는 다차원 배열의 첫 번째 요소가 아니기 때문

//             2. (중요) 포인터변수에 대입 시
//                 : 해당 3차원 배열의 시작주소값을 의미하는 포인터변수 
//                   ( 3차원배열변수 = &3차원배열변수[0][0][0] = 3차원배열변수[0][0] = 3차원배열변수[0] )
        
//          - []와 함께하는 경우( &3차원배열변수[1][0][0] = 3차원배열변수[1][0] = 3차원배열변수[2])
//             1. 3차원배열변수[]     : 1차원에 해당하는 부분을 의미하는 변수의 표기값 그 자체가 주소를 의미하는 '포인터변수' 
//                  -> (중요!) 컴파일러에 따라 단독으로 쓴 '3차원배열변수[][]' 진짜 3차원배열변수[][][0]의 주소값을 저장하는 2중 포인터변수로 해석되기도 함
//             2. 3차원배열변수[][]   : 2차원에 해당하는 부분을 의미하는 변수의 표기값 그 자체가 주소를 의미하는 '포인터변수'
//             3. 3차원배열변수[][][] : 배열 안에 위치하는 단순 자료형 변수 (= 포인터와 관련성이 1도 없음)
     
     
//    # (중요!!) 3차원 이상의 배열의 경우 배열변수 의 중의성을 활용하여 주소값을 표기하는건 유용할 수는 있어도, 포인터연산이 들어가는 순간 해석에 따라 의미가 중의적으로 변할 수 있음..
//        -> 고차원 배열의 경우 배열변수를 안이하게 사용하고, 포인터연산식을 대충세우면...? 중의성으로 인해 [코드의 의미를 헷갈림 + 의도하지 못한 결과 + 유지보수 X같음] 3콤보에 시달릴 수 있음
//            -> 따라서, 고차원 배열의 포인터연산을 통해 메모리영역을 참조하는 식을 세울때는.. 최대한 ()를 많이 써서 의미를 명확하게 유도하도록 노력하자..
      
//           ex) int score_3D[5][5][5] = { 2, 4, 8, 10, .... , 250 };
//               int* pScore2 = score_3D[2];
      
//               [예시1] 
//                *(pScore2 + i) != *(score_3D[2] + i)    ->   *(pScore2 + i) = *(*(score_3D[2] + i))
//                   -> 해당 상황에서 *(pScore2 + i) = *(score_3D[2] + i)로 치환되기에 같은 값이 나와야 하지만... 전자는 제대로 역참조가 되고, 후자는 주소값이 튀어나옴
//                      -> *(pScore2 + i) = *(score_3D[2] + i)은 분명 참이지만, 컴파일러에 따라 해석되는 방식이 다른 상황에서 하필 주소값이 나온 참사... *(score_3D[2] + i)을 다시 역참조를 해주면 문제없음 
//                         -> 정황상 C언어는 score_3D[2]를 score_3D[2][0][0]의 주소값을 담은 2중 포인터변수로 두는것이 포착됨
 
//                             ex)  score_3D[2] =  score_3D[2][0] = &score_3D[2][0][0]
//                                 *score_3D[2] = *score_3D[2][0] =  score_3D[2][0][0]
      
//               [예시2] 
//                *(*score_3D[2] + i) != *(*(score_3D[2] + i))
//                   -> 비슷해 보이지만, *score_3D[2] + i와 *(score_3D[2] + i)의 ()를 씌었냐의 차이로 해석이 180도 달라짐
//                      -> *(*score_3D[2] + i)
//                           : 단순 &score_3D[2][0][0]에 i만큼의 주소값을 더해서 이를 역참조한 값(= 얘도 주소값)을 역참조한 score_3D[2][0][i]값

//                      -> *(*(score_3D[2] + i))
//                           : &score_3D[2][0][0]값을 저장한 주소값에 i만큼(이 경우는 1차원의 행에로 해당하는 배열크기만큼 영역을 움직임)의 주소값을 더해서 이를 역참조한 값(= 얘도 주소값)을 역참조한 score_3D[2][i][0]값
     


#include <stdio.h>
int main()
{
    int* p, a[5] = { 10, 20, 30, 40, 50 };

    //배열 이름은 배열의 시작주소 값이다.
    p = a;  // p = &a[0] 와 같은 의미

    printf("1. %p\n", a);              //  000000B63D5BF5F8
    printf("2. %d\n", *p);             // 10
    printf("3. %d\n", *(p + 1));       // 20
    printf("4. %d\n", p[2]);           // 30
    printf("5. %d\n\n", *(a + 3));     // 40

    // p의 주소값 자체가 변경 (후위 연산자)
    p += 1; // p = p + 1    
    //a += 2; 배열 이름은 상수 포인터로 변경 불가능

    printf("6. %p\n", p);              // 000000B63D5BF5FC  = 000000B63D5BF5F8 + 4btye      <- 후위 연산자로 인해 p의 주소값이 변경 (1과 6의 메모리 값을 보면 4btye 차이남) 
    printf("7. %d\n", *p);             // 20
    printf("8. %d\n", *(p - 1));       // 10      
    printf("9. %d\n", *(p + 1));       // 30
    printf("10. %d\n", a[3]);          //  40
    printf("11. %d\n", p[3]);          //  40        <- p[3] = p + 3 (현재 p의 메모리 위치 + (3 * 4byte)한 의미와 같다)
    printf("12. %d\n", p[-1]);         //  10
    printf("13. %d\n", *p + 2);        //  12       <- 20 + 2 = 22 

    return 0;
}
