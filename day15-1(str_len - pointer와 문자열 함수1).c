#include <stdio.h>

// str_len(���ڿ� �ּ�) : �ش� ���ڿ��� ���� ��ȯ
int str_len(char* p) {

    int n = 0;
    while (*p++)n++;
    return n;
}

int main() {

    char c[15] = "C language", d[50];
    int len;
    len = str_len(c);
    printf("���ڿ� ���� : %d\n", len);
    printf("���ڿ� �Է� : ");
    scanf_s("%s", d, (int)sizeof(d));
    len = str_len(d);
    printf("���ڿ� ���� : %d\n", len);
    return 0;
}
