#include <stdio.h>

int main() {

	int x, y, z, i, j, a, b, c, d, re, re1, re2, re3;

	i = 5, j = 3;

	printf("%d + %d = %d\n", i, j, i + j);

	printf("%d - %d = %d\n", i, j, i - j);

	printf("%d * %d = %d\n", i, j, i * j);

	printf("%d / %d = %d\n", i, j, i / j);

	printf("%d %% %d = %d\n", i, j, i % j);

	printf("전위 연산 i = %d, j = %d\n", ++i, ++j);

	printf("후위 연산 i = %d, j = %d\n", i++, j++);

	printf("연산 i = %d, j = %d\n", i, j);

	a = 10, b = 10;

	printf("원래의 a 값 : %d\n", a);

	printf("원래의 b 값 : %d\n", b);

	printf("--a의 결과 : %d\n", --a);

	printf("--연산후의 a 값 : %d\n", a);

	printf("b--의 결과 : %d\n", b--);

	printf("--연산후의 b 값 : %d\n", b);

	x = 5;

	a = ++x * x--;

	b = x * 10;

	printf("a=%d b=%d x=%d\n", a, b, x);

	a = 2, b = 3, c = 9;

	re = ++a + ++b;                                                     // 3 + 4 = 7 

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 7, a = 3, b = 4, c = 9

	re = c++;                                                           // re = 9 (c=9에 후위연산자 ++적용하였음)		-> re = c;  (해당 코드 연산 종료 후) c = c + 1; 로 풀어서 생각하면 간단하다

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 9, a = 3, b = 4, c = 10

	re = --b * --b - b++;                                               // (2 * 2) - 2 = 4                              <- 전위턴에 --가 2개 있었기에 전위턴의 b는 2고, 해당 코드 연산이 끝난 후위턴에 ++가 한번 적용되어 해당 코드가 끝난 후의 b는 3

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 2, a = 3, b = 3, c = 10

	re = --c + c-- + a++;                                               // 9 + 9 + 3 = 21

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 21, a = 4, b = 3, c = 8

	a = 10;

	printf("원래 a값 : %d\n", a);               // 10

	printf("2를 더한 값 : %d\n", a += 2);       // 10 + 2 = 12

	printf("2를 뺀 값 : %d\n", a -= 2);         // 12 -2 = 10

	printf("2를 곱한 값 : %d\n", a *= 2);       // 10 * 2 = 20

	printf("2를 나눈 값 : %d\n", a /= 2);       // 20 / 2 = 10;

	a++;                                        // 후위 ++ : 현재 오리지널 a = 10

	printf("2를 나눈 나머지 값 : %d\n", a %= 2); // 11 % 2 = 1

	a = 4;

	re1 = a > 2;                    // re1 = true

	printf("re1= %d\n", re1);       // re1 = 1

	re2 = a < 2;                    // re2 =  false

	printf("re2= %d\n", re2);       // re2 = 0

	re3 = a == 4;                   // re3 = true

	printf("re3= %d\n", re3);       // re3= 1

	a = 3, b = 5, c = 1, d = 3;

	printf("1. %d\n", a > b);

	printf("2. %d\n", a < b);

	printf("3. %d\n", c > d);

	printf("4. %d\n", !(c < d));                // !(1 < 3) = !(false) = true = 1

	printf("5. %d\n", (a > b) && (c < d));     // (3 > 5) && (1 < 3) = false && true = 0 && 1 = 0
										       
	printf("6. %d\n", (a > b) || (c < d));     // (3 > 5) || (1 < 3) = false || true = 0 || 1 = 1
										       
	printf("7. %d\n", (a < b) && (c < d));     // (3 < 5) && (1 < 3) = true && true = 1 && 1 = 1
										       
	printf("8. %d\n", (a < b) || (c < d));     // (3 < 5) || (1 < 3) = true || true = 1 || 1 = 1

	a = 0xD1, b = 0xC4;

	printf("9. %X %X\n", a, b);                // D1 C4

	printf("10. %X %X\n", ~a, ~b);             // FFFFFF2E FFFFFF3B (16진수 값인 000000D1, 000000C4을 16진수 기준으로 반전)     <- NOT(D1), NOT(C4)로 계산해봐라

	printf("11. %X\n", a & b);                 // C0 (D1, C4를 이진(비트화) 시킨후, 각 자리가 하나라도 1이 아니면 각 자리는 0)  <- D1 AND C4로 계산해봐라

	printf("12. %X\n", a | b);                 // D5 ( D1, C4를 이진(비트화) 시킨후, 각 자리가 하나라도 1이면 각 자리는 0)      <- D1 OR C4로 계산해봐라

	printf("13. %X\n", a ^ b);                 // 15 (D1, C4를 이진(비트화) 시킨후, 각 자리가 하나라도 다르면 각 자리는 1)	    <- D1 NOR C4로 계산해봐라

	a = 209;

	printf("14. %d\n", a);

	printf("15. %d\n", a << 1);

	printf("16. %d\n", a << 2);

	printf("17. %d\n", a << 3);

	printf("18. %d\n", a >> 1);

	printf("19. %d\n", a >> 2);

	printf("20. %d\n", a >> 3);

	x = 1, y = 0, z = 1;

	re = ++x && y++ && z++;	        // re = 2 (A && B의 경우 A가 false면 B는 그냥 보지도 않고 패스)

	printf("21. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 21. re = 0, x = 2, y = 1, z = 1 (z쪽의 연산은 적용X)

	re = ++x || ++y || ++z;         // re = 2 (A || B의 경우 A가 true면 B는 그냥 보지도 않고 패스)

	printf("22. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 22. re = 1, x = 3, y = 1, z = 1 (z쪽의 연산은 적용X)

	re = --x && ++y || ++z;         // re = 2 && 2 && z = 1

	printf("23. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 23. re = 1, x = 2, y = 2, z = 1

	re = ++x || ++y && z++;         // re = 3 || 3 && 1

	printf("24. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 24. re = 1, x = 3, y = 2, z = 1

	re = (x++ < y++) ? x++ : y++;    // re = ( 3 < 2 )는 false므로, y의 값인 2이 적용되어야 하는거 같지만? 
	                                 //  -> 후위연산자가 실행되는 시점은 조건식이 끝난 직후의 시점 -> 그 다음이 re에 값이 대입되는 시점 (우선순위를 봐야함)
	                                 //	      >> ()안의 연산 1순위이기에... 괄호안의 후위연산자 ++부터 실행 
	                                 //           -> 조건식 실행( 이 시점에서 x, y는 +1완료)
	                                 //           -> 조건식 판별 후 결과값의 후위연산자 실행... + re에  3저장
	                                 //           -> 이후 x, y 다시 +1

	printf("25. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 25. re = 3, x = 4, y = 4, z = 1

	return 0;

}