#include <stdio.h>


// pointer�� strcmp(), strchr() ����

//���ڿ� ���� ��ġ�ϴ� ���ڰ� �ִ��� �˻��ϴ� �Լ� (������ ������ �ּ� ��ȯ)
char* str_chr(char* str1, int ch) {
    int num = 0;

    while (*str1) {

        if (*str1 == ch) {
            return str1;  // ���ڿ� �ּ� ��ȯ
        }
        str1 = str1 + 1;
    }
    return NULL; // null ��ȯ
}

//���ڿ��� ��ġ�ϴ� ������ ���� �˻��ϴ� �Լ� (������ ���Ե� ������ ���� ��ȯ)
int str_cnt(char* str1, int ch) {
    int num = 0;

    while (*str1) {

        if (*str1 == ch) {
            num++;              // ���ڿ� ã�������� ���� ��ȯ
        }
        str1 = str1 + 1;
    }
    return num;              // �������� ��ȯ
}

//�� ���� ���ڿ��� �ƽ�Ű �ڵ� ������ �� (2���ڿ��� �� �ڸ����� ���ϴٰ� ������ ������ ���ϰ� �ֱ�)
//  - str1 < str2 �� ��� - 1 ��ȯ
//  - str1 > str2 �� ��� 1 ��ȯ
//  - str1 == str2 �� ��� 0 ��ȯ <- ����
int str_cmp(char* str1, char* str2) {

    int n1 = 0;
    int n2 = 0;
    int n = 0;
    int result = 0;

    char* sx1 = str1;
    char* sx2 = str2;

    // ���ڿ�1�� ���� ���ϱ�
    while (*str1) {
        n1++;
        str1 = str1 + 1;
    }

    // ���ڿ�1�� ���� ���ϱ�
    while (*str2) {
        n2++;
        str2 = str2 + 1;
    }

    str1 = sx1;
    str2 = sx2;

    if (n1 != n2) {

        if (n1 > n2) {
            n = n1;
        }
        else if (n1 < n2) {
            n = n2;
        }
    }
    else {

        n = n1;
    }

    printf("%d\n", n);

    for (int i = 0; i < n; i++) {

        if (*(str1 + i) > *(str2 + i) ){
            result = 1;
            break;

        }else if (*(str1 + i) < *(str2 + i)) {
             result = -1;
             break;
        }

    }

    return result; 
}


int main() {
    char a[100] = "C language", * b = (char*)" Keep Calm and Carry On" , c[100] = "C javaguage"; //(const char)

    // char c[100], d[50];
    //str_cat(a, b);
    printf("str_chr(b, 67) = %s\n\n", str_chr(b, 67) );
    printf("str_cnt(b, 67) = %d\n\n", str_cnt(b, 67) );
    printf("str_cmp(a, c) = %d\n\n", str_cmp(a, c) );

    /*   printf("1 ���ڿ� �Է� : ");
       scanf_s("%s", c, (int)sizeof(c));
       while (getchar() != '\n');
       printf("2 ���ڿ� �Է� : ");
       scanf_s("%s", d, (int)sizeof(d));
       while (getchar() != '\n');
       printf("*c + *d = %s\n\n", str_cat(c, d));*/
    return 0;
}
