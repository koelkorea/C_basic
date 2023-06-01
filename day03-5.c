#include <stdio.h>

int main() {

	int x, y, z, i, j, a, b, c, d, re, re1, re2, re3;

	i = 5, j = 3;

	printf("%d + %d = %d\n", i, j, i + j);

	printf("%d - %d = %d\n", i, j, i - j);

	printf("%d * %d = %d\n", i, j, i * j);

	printf("%d / %d = %d\n", i, j, i / j);

	printf("%d %% %d = %d\n", i, j, i % j);

	printf("���� ���� i = %d, j = %d\n", ++i, ++j);

	printf("���� ���� i = %d, j = %d\n", i++, j++);

	printf("���� i = %d, j = %d\n", i, j);

	a = 10, b = 10;

	printf("������ a �� : %d\n", a);

	printf("������ b �� : %d\n", b);

	printf("--a�� ��� : %d\n", --a);

	printf("--�������� a �� : %d\n", a);

	printf("b--�� ��� : %d\n", b--);

	printf("--�������� b �� : %d\n", b);

	x = 5;

	a = ++x * x--;

	b = x * 10;

	printf("a=%d b=%d x=%d\n", a, b, x);

	a = 2, b = 3, c = 9;

	re = ++a + ++b;                                                     // 3 + 4 = 7 

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 7, a = 3, b = 4, c = 9

	re = c++;                                                           // re = 9 (c=9�� ���������� ++�����Ͽ���)		-> re = c;  (�ش� �ڵ� ���� ���� ��) c = c + 1; �� Ǯ� �����ϸ� �����ϴ�

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 9, a = 3, b = 4, c = 10

	re = --b * --b - b++;                                               // (2 * 2) - 2 = 4                              <- �����Ͽ� --�� 2�� �־��⿡ �������� b�� 2��, �ش� �ڵ� ������ ���� �����Ͽ� ++�� �ѹ� ����Ǿ� �ش� �ڵ尡 ���� ���� b�� 3

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 2, a = 3, b = 3, c = 10

	re = --c + c-- + a++;                                               // 9 + 9 + 3 = 21

	printf("re = %d, a = %d, b = %d, c = %d \n\n", re, a, b, c);        // re = 21, a = 4, b = 3, c = 8

	a = 10;

	printf("���� a�� : %d\n", a);               // 10

	printf("2�� ���� �� : %d\n", a += 2);       // 10 + 2 = 12

	printf("2�� �� �� : %d\n", a -= 2);         // 12 -2 = 10

	printf("2�� ���� �� : %d\n", a *= 2);       // 10 * 2 = 20

	printf("2�� ���� �� : %d\n", a /= 2);       // 20 / 2 = 10;

	a++;                                        // ���� ++ : ���� �������� a = 10

	printf("2�� ���� ������ �� : %d\n", a %= 2); // 11 % 2 = 1

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

	printf("10. %X %X\n", ~a, ~b);             // FFFFFF2E FFFFFF3B (16���� ���� 000000D1, 000000C4�� 16���� �������� ����)     <- NOT(D1), NOT(C4)�� ����غ���

	printf("11. %X\n", a & b);                 // C0 (D1, C4�� ����(��Ʈȭ) ��Ų��, �� �ڸ��� �ϳ��� 1�� �ƴϸ� �� �ڸ��� 0)  <- D1 AND C4�� ����غ���

	printf("12. %X\n", a | b);                 // D5 ( D1, C4�� ����(��Ʈȭ) ��Ų��, �� �ڸ��� �ϳ��� 1�̸� �� �ڸ��� 0)      <- D1 OR C4�� ����غ���

	printf("13. %X\n", a ^ b);                 // 15 (D1, C4�� ����(��Ʈȭ) ��Ų��, �� �ڸ��� �ϳ��� �ٸ��� �� �ڸ��� 1)	    <- D1 NOR C4�� ����غ���

	a = 209;

	printf("14. %d\n", a);

	printf("15. %d\n", a << 1);

	printf("16. %d\n", a << 2);

	printf("17. %d\n", a << 3);

	printf("18. %d\n", a >> 1);

	printf("19. %d\n", a >> 2);

	printf("20. %d\n", a >> 3);

	x = 1, y = 0, z = 1;

	re = ++x && y++ && z++;	        // re = 2 (A && B�� ��� A�� false�� B�� �׳� ������ �ʰ� �н�)

	printf("21. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 21. re = 0, x = 2, y = 1, z = 1 (z���� ������ ����X)

	re = ++x || ++y || ++z;         // re = 2 (A || B�� ��� A�� true�� B�� �׳� ������ �ʰ� �н�)

	printf("22. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 22. re = 1, x = 3, y = 1, z = 1 (z���� ������ ����X)

	re = --x && ++y || ++z;         // re = 2 && 2 && z = 1

	printf("23. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 23. re = 1, x = 2, y = 2, z = 1

	re = ++x || ++y && z++;         // re = 3 || 3 && 1

	printf("24. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 24. re = 1, x = 3, y = 2, z = 1

	re = (x++ < y++) ? x++ : y++;    // re = ( 3 < 2 )�� false�Ƿ�, y�� ���� 2�� ����Ǿ�� �ϴ°� ������? 
	                                 //  -> ���������ڰ� ����Ǵ� ������ ���ǽ��� ���� ������ ���� -> �� ������ re�� ���� ���ԵǴ� ���� (�켱������ ������)
	                                 //	      >> ()���� ���� 1�����̱⿡... ��ȣ���� ���������� ++���� ���� 
	                                 //           -> ���ǽ� ����( �� �������� x, y�� +1�Ϸ�)
	                                 //           -> ���ǽ� �Ǻ� �� ������� ���������� ����... + re��  3����
	                                 //           -> ���� x, y �ٽ� +1

	printf("25. re = %d, x = %d, y = %d, z = %d \n", re, x, y, z);		// 25. re = 3, x = 4, y = 4, z = 1

	return 0;

}