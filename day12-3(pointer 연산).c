//	- 포인터 연산 종류
//		1. 포인터 변수의 주소값 그 자체에 다른 변수간의 연산
//			ex) 포인터변수 + 정수 = 포인터변수 + 정수 * 포인터변수의 자료형 크기

//		2. 포인터 변수의 역참조 값과 다른 변수를 계산하는 경우
//			ex) *포인터변수 + 실수 or 정수

//		3. 포인터변수와 포인터변수의 비교 및 빼기 연산 (하단의 3번 참고)
//			-> (중요) 부등호, 뺴기만 가능

//		#포인터 연산의 기본 조건: 같은 자료형을 갖는 포인터만 대입이 가능하다는거... 

//			1. 같은 형을 갖는 포인터는 대입 가능
//				ex) int a = 10, b = 20;		->		int* ip1 = &a, * ip2 = &b;		->		ip1 = ip2;

//			2. 포인터 변수를 정수로 더하거나 빼기 가능
//				ex) ip1 + 1	(* 자료형 크기 주소);

//			3. 같은 배열을 가리키는 포인터의 빼기와 비교 가능(덧셈 불가)	: 
//				ex)	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//						int* ip1 = &a[2], * ip2 = &a[8]; 
//						ip2 - ip1 (빼기 가능)		=		ip2 > ip1(비교 가능)			<- (중요) 덧셈은 불가능
/
//			4. 0(NULL)과 비교 또는 0의 대입 가능	=> 포인터 변수의 안전한 초기화가 가능
//				ex) ip1 = 0; ip2 = NULL;

//			5. 이외 모든 연산은 불가!

#include <stdio.h>
int main() {//    p        q

    int a[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }, b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    float c[10] = { 1.5, 5.5, 9.5, 13.5, 17.5, 21.5, 25.5, 29.5, 33.5, 37.5 };

    int* p, * q; //  fp
    float* fp;

    // 배열로 선언된 변수명(= 상수 포인터) = 그 자체가 해당 배열 0번방(1번째방)의 주소를 의미 (&이 필요없는 이유)
    p = a;              // 포인터변수 p의 주소에 int 배열 변수명 a대입하여, a[0]의 주소를 대입 (array to pointer decay 예시)
    q = &a[3];      // 포인터변수 q의 주소에 int 배열 변수명 a의 4번째 위치의 주소 대입
    fp = c;             // 포인터변수 fp의 주소에 float 배열 변수 c대입하여, c[0]의 주소를 대입 (array to pointer decay 예시)

    // 전위 후위 연산자에 따른 차이 있음!
    printf("| a[0] = %d | *++p = %d | a[3] =%d | *++q = %d |\n\n", a[0], *++p, a[3], *++q);                                    // | a[0] = 1 | *++p = 3 | a[3] =7 | *++q = 9 |            
    //  *++p = * (p+1)        : int가 4btye이기 때문에, a[0]에서 4byte씩 떨어진 주소인 a[1]의 값인 3을 가져옴
     //  *++q = * (q+1)       : int가 4btye이기 때문에, a[0]에서 4byte씩 떨어진 주소인 a[4]의 값인 9을 가져옴

    printf("| c[0] = %.2f | *fp = %.2f | *fp + 2 = %.2f | *(fp + 2) = %.2f |\n\n", c[0], *fp, *fp + 2, *(fp + 2));          // | c[0] = 1.50 | *fp = 1.50 | *fp + 2 = 3.50 | *(fp + 2) = 9.50 |     
    //   *fp + 2                                       : 단순히 fq의 역참조 값에 +2를 더하였으니, 3을 출력
    //  *(fp + 2) = * (fq + (2*4) )         : (포인터 변수 연산) float가 4btye이기 때문에, c[0]에서 4byte씩 2번 떨어진 주소인 c[2]의 값인 9.5를 가져옴

    printf("| *p + 2 = %d | *(p + 2) = %d | *q - 2 =%d | *(q - 2) = %d |\n\n", *p + 2, *(p + 2), *q - 2, *(q - 2));     // | *p + 2 = 5 | *(p + 2) = 7 | *q - 2 = 7 | *(q - 2) = 5 |


    printf("| *(p - 3) = %d | *(q + 13) = %d |\n\n", *(p - 3), *(q + 13));      // | *(p - 3) = -858993460 | *(q + 13) = 2 |

    //  (중요) 결과값 = 연산결과(총 byte) / 자료형의 크기(byte) 라는 사실을 명심
    //  q : a[4]의 주소값       <- 이전 전,후위 연산자로 값이 변조
    //  p : a[1]의 주소값       <- 이전 전,후위 연산자로 값이 변조
    printf("q : %p  \t  q - p = %3d  \n", q, q - p);        // q : 000000B76C2FFB38      q - p =   3 (12byte / 4byte)
    printf("p : %p  \t  p - q = %3d  \n\n", p, p - q);    // p : 000000B76C2FFB2C      p - q =  -3

    // 3. 같은 배열을 가리키는 포인터의 빼기와 비교 가능(덧셈 불가)	:  포인터 변수는 메모리값이므로.. 높고, 낮음을 비교가능!
    if (q > p + 2/* 증가값 < 3 : (참), >= 3 (거짓) */) {

        printf("q : %p\np : %p\t참\n\n", q, p + 2);
        // q : 000000B76C2FFB38
        //  p: 000000B76C2FFB34    참
    }else {
        printf("q : %p\np : %p\t거짓\n\n", q, p + 3);
    }

    //		4. 0(NULL)과 비교 또는 0의 대입 가능	=> 포인터 변수의 안전한 초기화가 가능
    q = 0;    
    p = NULL;       //  0과 같은 의미
    
    printf("q : %p \n", q);     // q : 0000000000000000
    printf("p : %p \n", p);     // p : 0000000000000000
    
    // 포인터 변수 초기화
    p = a;      // p = a[0]의 주소값  (array to pointer decay 예시)
    fp = c;     // fp = c[0]의 주소값  (array to pointer decay 예시)

    // 물리적으로 메모리주소값을 int 자료형 크기인 4byte단위로 옮겨서 값을 찍어내다 보니... a[9]이후 쓰레기 값이 등장하는 부분도 존재
    //      -> 하지만 같은 int 배열인 b의 값들이 위치하는 곳까지 주소가 도달한다면.. 경우에 따라서는 참조가 가능하다는 것을 확인 가능
    for (int i = 0; i < 25; i++) {
        printf("  p+i 값 : %d \n", *(p + i) );
    }

    // c[9]이후의 값은 쓰레기값이 등장
    for (int i = 0; i < 15; i++) {
        printf("  q+i 값 : %f \n", *(fp + i) );
    }
    //add = p+q; 연산 불가
    //p=fp; 연산 불가 or 역참조 불가
    return 0;
}
