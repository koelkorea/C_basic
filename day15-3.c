#include <stdio.h>

// pointer�� strupr(), strlwr(), strrev(), strcmp(), strchr() ����

//1. strupr() : ���ڿ��� ���Ե� �ҹ��ڸ� ��� �빮�ڷ� ��ȯ�ϴ� �Լ�
char* str_upr(char* str) {
    char* sx = str;

    while ( *str ) {

        if (*str >= 97 && *str <= 122) {
            *str -= 32;
        }
        str = str + 1;
    }
    return sx; // ���ڿ� ù �ּ� ��ȯ
}

//2. strlwr() : ���ڿ��� ���Ե� �빮�ڸ� ��� �ҹ��ڷ� ��ȯ�ϴ� �Լ�
char* str_lwr(char* str) {
    char* sx = str;

    while (*str ) {
        if (*str >= 65 && *str <= 90) {
            *str += 32;
        }
        str = str + 1;
    }
    return sx; // ���ڿ� ù �ּ� ��ȯ
}

//3. strrev()���ڿ��� ������ �ٲٴ� �Լ�
char* str_rev(char* str) {

    int n = 0;
    char* sx = str;

    // ���ڿ� ���� ���ϱ�
    while (*str) {
        n++;
        str = str + 1;
    }

    str = sx;
    // printf("%d\n", n);

    for (int i = 0; i < n/2; i++) {

        char temp;

        temp = *(str + n -1 - i);
        *(str + n -1 - i) = *(str + i);
        *(str + i) = temp;

        //printf("temp :  %c\n", temp);
        //printf(" *(str + n - i) :  %c\n", *(str + n - i));
        //printf(" * (str + i) : % c\n", *(str + i));
    }

    return sx; // ���ڿ� ù �ּ� ��ȯ
}

//4. strcmp() ver1 : ���ڿ� ���� ��ġ�ϴ� ���ڰ� �ִ��� �˻��ϴ� �Լ� (������ ������ �ּ� ��ȯ)
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

//4. strcmp() ver2: ���ڿ��� ��ġ�ϴ� ������ ���� �˻��ϴ� �Լ� (������ ���Ե� ������ ���� ��ȯ)
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

//5. strchr() : �� ���� ���ڿ��� �ƽ�Ű �ڵ� ������ �� (2���ڿ��� �� �ڸ����� ���ϴٰ� ������ ������ ���ϰ� �ֱ�)
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

    // printf("%d\n", n);

    for (int i = 0; i < n; i++) {

        if (*(str1 + i) > *(str2 + i)) {
            result = 1;
            break;

        }
        else if (*(str1 + i) < *(str2 + i)) {
            result = -1;
            break;
        }

    }

    return result;
}


int main() {
    char a[100] = "C language", * b = (char*)" Keep Calm and Carry On", c[100] = "C javaguage"; //(const char)
    //char c[100], d[50];
    //str_cat(a, b);
    printf("str_upr(a) = %s\n\n", str_upr(a));
    printf("str_lwr(a) = %s\n\n", str_lwr(a));
    printf("str_rev(a) = %s\n\n", str_rev(a));
    printf("str_chr(b, 67) = %s\n\n", str_chr(b, 67));
    printf("str_cnt(b, 67) = %d\n\n", str_cnt(b, 67));
    printf("str_cmp(a, c) = %d\n\n", str_cmp(a, c));

    return 0;
}
