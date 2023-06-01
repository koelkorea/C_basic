#include <stdio.h>		
#include<math.h>

// ����(Random Number)
//  : ������, �����Ұ���(�ֱ�����), �����Ұ�(���� ������ �� ���;�..)
//     -> �����1) �߾������� (�� ���̸���) ����
//         : 8�ڸ��� ������ �� ���� -> 3~6�ڸ��� ���� -> �¸� �����ؼ� 8�ڸ� �� ���� -> �ݺ�
int main() {

	long long num1 = 100000000, num2 = 100;
	long double k = 741963	, temp, temp1, temp2;     // k�� seed�� (�� �༮�� 6�ڸ��� ����) <- �̰� 100���� ������ 4�ڸ��� ����

	printf("%d %d \n", sizeof(num1), sizeof(k));      // long, double�� Ȯ�����̶� 16�� ���;� ����(ȯ�� ���� ���� �� ����)

	for (int i = 1; i <= 100; i++) {
		temp1 = pow(k, 2);                            // 741963�� ����
		temp = (long) (temp1 / num1);                 // 741963 / 100 = 7419.63�� ������ ���� 7419�� ����� (��ǻ� �ʱ� ���� 4�ڸ�)
		temp2 = temp1 - temp * num1;                  // 741963^2 - 741900000000
		temp = (long) (temp2 / num2);
		printf("%20.0lf\n", temp);
		k = temp;
	}

	return 0;

}