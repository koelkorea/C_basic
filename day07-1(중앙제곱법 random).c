#include <stdio.h>		
#include<math.h>

// 난수(Random Number)
//  : 무작위, 예측불가능(주기조차), 재현불가(같은 패턴이 안 나와야..)
//     -> 방법론1) 중앙제곱법 (폰 노이만식) 난수
//         : 8자리의 임의의 수 등장 -> 3~6자리만 때옴 -> 걔를 제곱해서 8자리 수 얻음 -> 반복
int main() {

	long long num1 = 100000000, num2 = 100;
	long double k = 741963	, temp, temp1, temp2;     // k는 seed값 (이 녀석은 6자리로 가정) <- 이걸 100으로 나누어 4자리로 만듦

	printf("%d %d \n", sizeof(num1), sizeof(k));      // long, double의 확장형이라 16이 나와야 정상(환경 따라 변할 수 있음)

	for (int i = 1; i <= 100; i++) {
		temp1 = pow(k, 2);                            // 741963를 제곱
		temp = (long) (temp1 / num1);                 // 741963 / 100 = 7419.63를 강제로 정수 7419로 만들기 (사실상 초기 제공 4자리)
		temp2 = temp1 - temp * num1;                  // 741963^2 - 741900000000
		temp = (long) (temp2 / num2);
		printf("%20.0lf\n", temp);
		k = temp;
	}

	return 0;

}