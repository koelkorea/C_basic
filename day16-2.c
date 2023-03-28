#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct score {
    int kor, eng, mat, total;
    char* memo; //���ڿ� �ּҸ� ����
}score;

int main() {

    char buf[1024];
    score* s;
    int number, i;

    printf("�л� �� �Է� : ");
    scanf_s("%d", &number);

    // ����ü n�� �޸� �Ҵ�, �� ���� �ּҸ� ��ȯ
    s = (score*)malloc(sizeof(score) * number);                 // score s[n];
    
    for (i = 0; i < number; i++) {

        printf("\n % d��° �Է�\n" , i + 1);

        printf("���� : ");
        scanf_s("%d" , &s[i].kor);

        printf("���� : ");
        scanf_s(" %d" , &s[i].eng);

        printf("���� : ");
        scanf_s("%d", &s[i].mat);
        while (getchar() != '\n');

        printf("�޸� : ");
        scanf_s("%s" , buf, (int)sizeof(buf));
        while (getchar() != '\n');

        //buf�� �Էµ� ���ڿ� ���� + 1 (\0)��ŭ �޸� �Ҵ�         
        s[i].memo = (char*)malloc(strlen(buf) + 1);                        // char s[i].memo[buf+1];            <- �Ҵ� ���� �޸��� ���� �ּҸ� ��ȯ

        strcpy_s(s[i].memo, (strlen(buf) + 1), buf);
        s[i].total = s[i].kor + s[i].eng + s[i].mat;
    }

    printf("\n\n *** �л� ��� ***\n");

    for (i = 0; i < number; i++) {
        printf("%d��. %.2f��\n", i + 1, (double)s[i].total / 3);
        printf("�޸� : %s\n", s[i].memo);
    }

    printf("\n");

    for (i = 0; i < number; i++) {
        free(s[i].memo); // ����ü �迭 ũ�⸸ŭ ����
    }

    free(s); //s�� ����Ű�� �޸� ����
    return 0;
}
