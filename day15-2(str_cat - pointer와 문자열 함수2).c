#include <stdio.h>

// char* str_cat(char ���ڿ� �ּ�1, char ���ڿ� �ּ�2) : 2��° ���ڿ��� 1��° ���ڿ� �ڿ� �ٿ��� �����ϰ� ����, 1���� ���ڿ� ��ȯ
char* str_cat(char* p, char* q) {
    char* sx = p;
    while (*p)p++; // p�� ����Ű�� ���� ���ڿ��� \0 ���� ��ġ�� (���ڿ� ������) ����
    while (*q)*p++ = *q++; // �̾� ���̱�
    *p = '\0'; // ���ڿ� ������ �ּҿ� \0 �� �ֱ�
    return sx; // ���ڿ� ù �ּ� ��ȯ
}
int main() {
    char a[100] = "C language", * b = (char*)" Keep Calm and Carry On"; //(const char)
    char c[100], d[50];
    //str_cat(a, b);
    printf("*a + *b = %s\n\n", str_cat(a, b));
    printf("1 ���ڿ� �Է� : ");
    scanf_s("%s", c, (int)sizeof(c));
    while (getchar() != '\n');
    printf("2 ���ڿ� �Է� : ");
    scanf_s("%s", d, (int)sizeof(d));
    while (getchar() != '\n');
    printf("*c + *d = %s\n\n", str_cat(c, d));
    return 0;
}
