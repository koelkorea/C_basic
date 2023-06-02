#pragma once
#include <stdio.h>
#include<windows.h>  // exit(),  sysyem()
#define Max 10
typedef struct _book
{
    int no;          // å �Ϸù�ȣ
    char title[30];  // ������
    char author[20]; // �۰�
    int price;       // ����
    int cnt;         // ����
    int sale;        // �����(���� * ����)
}BOOK;

enum input { Input = 1, Output, Sort, Search, Exit };

// strchr() : �� ���� ���ڿ��� �ƽ�Ű �ڵ� ������ �� (2���ڿ��� �� �ڸ����� ���ϴٰ� ������ ������ ���ϰ� �ֱ�)
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

// str_len(���ڿ� �ּ�) : �ش� ���ڿ��� ���� ��ȯ
int str_len(char* p) {

    int n = 0;           // ���� ���ڿ� ������ ��Ÿ��
    while (*p++)n++;     // ���� �����ϴ� ���ڿ� �ּ� ��ġ�� ���� �������� ���� null�� �ƴϸ�? ���ڸ� 1���� �ø���.    -> �̰� ���ڿ��� null�� ���� ���������� ����ϸ�, ���ڿ� ���� üũ ����
    return n;
}

//1. ����ü ������ �Է��Լ�
void input(BOOK* p) {

    int num = 0;

    printf("������ �� �� ����Ͻðڽ��ϱ�?  : ");
    scanf_s("%d", &num);

    for (int n = 0; n < num; n++) {

        p[n].no = n + 1;
        printf("�Ϸù�ȣ  : %d\n", p[n].no);

        printf("�������� �Է����ּ���  : ");
        scanf_s("%s", p[n].title, (int)sizeof(p[n].title));
        while (getchar() != '\n');

        printf("�۰����� �Է����ּ���  : ");
        scanf_s("%s", p[n].author, (int)sizeof(p[n].author));
        while (getchar() != '\n');

        printf("������ �Է����ּ���  : ");
        scanf_s("%d", &p[n].price);
        while (getchar() != '\n');

        printf("������ �Է����ּ���  : ");
        scanf_s("%d", &p[n].cnt);
        while (getchar() != '\n');

        p[n].sale = p[n].price * p[n].cnt;
        printf("�����  : %d\n\n", p[n].sale);
    }

}

//2. ����Լ�
void output(BOOK* p) {

    int n = 0;

    while (p[n].no != 0) {

        printf("�Ϸù�ȣ  : %d \n", p[n].no);
        printf("������  : %s \n", p[n].title);
        printf("�۰���  : %s \n", p[n].author);
        printf("����  : %d \n", p[n].price);
        printf("����  : %d \n", p[n].cnt);
        printf("�����  : %d \n\n", p[n].sale);

        n++;
    }

}

//3. �۰��� a ~ z �����Լ�
void sort(BOOK* p) {

    int book_array_length = 0;

    int n = 0;

    while (p[n].no != 0) {
        book_array_length++;
        n++;
    }

    printf("���� ������ ��  : %d \n\n", book_array_length);


    // �������� ��� (1~9 ������ ���� ���� �۰ų� ū ���� ��������, 2~9 �̷������� ���� ���)
    for (int i = 0; i < book_array_length; i++) {

        for (int j = i + 1; j < book_array_length; j++) {

            BOOK temp;

            if (str_cmp(p[i].title, p[j].title) == 1) {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

            }
        }
    }

}

//4. å�̸� �˻��Լ�
void search(BOOK* p) {

    char search_word[30];         // ������ �˻�

    printf("�˻�� �Է����ּ���  : ");
    scanf_s("%s", search_word, (int)sizeof(search_word));
    while (getchar() != '\n');

    int search_length = str_len(search_word);
    printf("�˻��� ����  : %d\n\n", search_length);

    printf("---------------------------------[�˻� ���]--------------------------------------------------\n\n");

    int n = 0;

    while (p[n].no != 0) {

        int title_length = str_len(p[n].title);
        //printf("�Ϸù�ȣ %d�� �˻��� ����  : %d\n\n", p[n].no, title_length);

        for (int i = 0; i < title_length - search_length; i++) {

            int flag = 0;

            for (int j = 0; j < search_length; j++) {

                if (p[n].title[i + j] == search_word[j]) {
                    flag++;
                }
            }

            if (flag == search_length) {

                printf("�Ϸù�ȣ  : %d \n", p[n].no);
                printf("������  : %s \n", p[n].title);
                printf("�۰���  : %s \n", p[n].author);
                printf("����  : %d \n", p[n].price);
                printf("����  : %d \n", p[n].cnt);
                printf("�����  : %d \n\n", p[n].sale);
                break;
            }
        }

        n++;
    }

}