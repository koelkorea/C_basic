// �Լ������͸� ����ؼ�, ���⸦ �����غ��� (��, ������ �������� �ѹ��� �� �޾ƾ� ��)
//  -> ���� �ٸ��� : scanf_s ��� gets_s�� ���ڿ��� ����
#include<stdio.h>
#include<string.h>

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

int main(void) {

    int a = 0, b = 0;
    char c = 0, buf[1025] = { 0 };

    printf("����( 3 + 5 ) �Է� : ");
    gets_s(buf, sizeof(buf) - 1);

    for (int k = 0; k < strlen(buf); k++) {

        if ('0' <= buf[k] && buf[k] <= '9' && c == 0) {
            a = a * 10 + buf[k] - 48;
        }

        else if ('0' <= buf[k] && buf[k] <= '9' && c != 0) {
            b = b * 10 + buf[k] - 48;
        }

        else if (buf[k] != '0') c = buf[k];

        else break;
    }

    int (*pF)(int, int) = NULL;//(��ȯ��) (* ������ ���� �̸�) (�Ű�����1, �Ű�����2, ��)

    switch (c) {
        case '+': pF = add; break; // add �Լ� �̸� == �޸� ���� �ּ�
        case '-': pF = sub; break;
        case '*': pF = mul; break;
        case '/': pF = div; break;
        default: printf("Error\n"); exit(0);
    }

    printf("\n��� ��� �� : %5d %c %5d = %5d \n", a, c, b, pF(a, b));
    return 0;
}
