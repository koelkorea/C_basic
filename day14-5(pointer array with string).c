//  - (�߿� !!!) c������ ���ڿ��� �� ��ü�� char �迭 !!!! 

//   # ���ڿ��� char �迭�� ���� Ư����
//      1. char c[] = { C, l,a,n,g,u,a,g,e,!,\0, s,e,c,re,t, s,p,a,c,e } �� ���� �ʾƵ� �� ->  char c[] = "C language!\0 secret space"; �� OK           <-  \0�� NULL�� �ǹ��ϴ� ���ڷ� ���ڿ� �̽������� ����

//      2. (���� �߿�) ���ڿ��� �迭�̶�  char c[] = "C language!\0 secret space"; �� ����
//            -> char * p = c�� ����
//            ->  char * p = "C language!\0 secret space" ��� �ᵵ �����Ѵٴ� ��ݰ� ������ ����

//      3. 2���� ���ڿ��� �迭�μ��� ������ pointer array�� �����ϸ� ������ ���� 
//            ->	char* q[3] = { "Computer","Programing","Enjoy" }            <- ���ڿ��� �迭�̱⿡ ������ ��� �ּҸ� �����ŷ� ������ �����ϴ�

//                  - q[0] =  "Computer\0"          <- ������ ������ �迭���Ĵ�� ����, *���̵� ������ ����� 
//                  - q[1] =  "Programing\0"
//                  - q[2] =  "Enjoy\0"

//      (����)
//      -------------------------------------------------------------------------------------------
//                     �޸� �ּ�	             �迭 ����	                    ���� ��
//       -------------------------------------------------------------------------------------------
//                             q	                        char* q[0]	                "Computer\0"
//                             q + 1                	    char* q[1]	                "Programing\0"
//                             q + 2                	    char* q[2]              	"Enjoy\0"

#include <stdio.h>
#include <string.h> // strlen() : ���ڿ� ���� Ȯ�� �Լ�
int main()
{
    char c[] = "C language!\0 secret space";
    char* a = "array and pointer";          // char �����ͺ��� a�� ���ڿ� �迭 "array and pointer"�� ù��° ���� �ּ� ����
    char* q[3] = { "Computer", "Programing", "Enjoy" };
    char* p = c, d[20]; 
    int i = 0, k = 0;

    // "C language! ������ �ϳ��ϳ� �Է� (\0�� NULL��������)
    while (*(p + i) != '\0') {
        printf("%c", *(p + i));
        i++;
    }

    printf("\n\n");

    // secret space������ �ϳ��ϳ� �Է�
    while (*p != '\0') {
        printf("%s\n", p);
        p++;
    }

    printf("\n\n");

    printf("%c %c \n", *(a + 4), a[4]);
    printf("pointer : %s \n", a);
    printf("  array : ");

    // a�� ���ڿ� array and pointer�� �ѱ��ھ� ����
    for (int i = 0; i < strlen(a); i++) {           // strlen() : ���ڿ� ���� Ȯ�� �Լ�
        printf("%c", a[i]);
    }

    printf("\n\n");

    // "Computer", "Programing", "Enjoy" ���
    for (int i = 0; i < 3; i++) {
        printf("%s\n", *(q + i) );          // 
    }

    printf("\n\n");

    printf("[���ڿ� �Է� 20��]\n");
    scanf_s("%s", d, (int)sizeof(d));       // �ռ� ����� char �迭 d�� ũ���� 20��ŭ�� �ش��ϴ� ���ڿ��� �Է��ؼ� d�� ���ڿ��� �Է��ض�

    p = d;

    printf("�Էµ� ���ڿ� %s\n\n", p);
    return 0;
}
