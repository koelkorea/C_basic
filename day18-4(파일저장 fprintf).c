// - file ���� ���ڿ� ��, ��� �Լ�
//		: (�߿�) fopen_s�� ���� ���� ��Ʈ�� ������ ������ �� ��, �ش� ���� ��Ʈ���� ��� ������ ��,��� �Լ�  

// 3.  file�� ���ڿ� ����, �ܺ� file���� ������ ��������, ���� data�� ���� ã�� �Լ�

//      # fprintf( file������, ���ڿ��� );
//          : ���Ͽ� ����ȭ�� �ڷḦ ���(save)�ϱ� ���� ���Ǵ� �Լ� (������ file �������� �ּҰ��� �ش��ϴ� �κп� ���ڿ��� ����)
// 
//              ex) int fprintf(FILE* _Stream, char const* string);
//                      ->  int fprintf(����������, ���ڿ���);�� �ؼ�


// fprintf�� ���� �����Է°� �ش� ������ txt�� ����
#include <stdio.h>
#include <stdlib.h>
#define STU_SIZE 3

typedef struct student {
    int no;
    char name[20];
    int kor, eng, mat;
}STU;

int main() {

    //���� ������ ���� & �ʱ�ȭ
    FILE* fp = NULL;

    STU sp[STU_SIZE];

    // ���ϸ��� �ޱ� ���� char �迭
    char file_name[80];
    int i;

    printf("\n�� ���ϸ� �Է� (.txt Ȯ���� �Է�!) : ");

    // ���ϸ� �Է�
    scanf_s("%s", file_name, sizeof(file_name) - 1);        // ���ڿ��� �޴� ���̱⿡ ���� �˸��� NULL����(\0)�� �� ������ 1��ŭ�� �����ؾ� �ϹǷ�, ��������� file_name�� ũ�⺸�� 1 �۰�
    while (getchar() != '\n');

    // ����ü �Է�(STU_SIZE ��ŭ �ݺ�)
    for (i = 0; i < STU_SIZE; i++) {

        sp[i].no = i + 1;    //�Ϸú�ȣ
        printf("\n��ȣ : [%03d]\n", sp[i].no);

        printf("�̸� : ");
        scanf_s("%s", sp[i].name, sizeof(sp[i].name) - 1);   // ���ڿ��� �޴� ���̱⿡ ���� �˸��� NULL����(\0)�� �� ������ 1��ŭ�� �����ؾ� �ϹǷ�, ��������� file_name�� ũ�⺸�� 1 �۰�
        while (getchar() != '\n');

        printf("���� : ");
        scanf_s("%d", &sp[i].kor);

        printf("���� : ");
        scanf_s("%d", &sp[i].eng);

        printf("���� : ");
        scanf_s("%d", &sp[i].mat);
        while (getchar() != '\n');
    }

    // file_name�� �̸����� file ������� : fopen_s ���� �� 0 ��ȯ
    if (fopen_s(&fp, file_name, "w") == 0) {


        for (i = 0; i < STU_SIZE; i++) {
            // fprintf(����������, ���ڿ���);
            //  : ���Ͽ� ����ȭ�� �ڷḦ ���(save)�ϱ� ���� ���Ǵ� �Լ�(������ file �������� �ּ���ġ�� ���ڿ� ����)
            fprintf(fp, "%d %s %d %d %d\n", sp[i].no, sp[i].name, sp[i].kor, sp[i].eng, sp[i].mat);
        }

        printf("\n\n\t\t %s ���Ͽ� �Է¿Ϸ�Ǿ����ϴ�...\n", file_name);

        // fclose(file ������) : ���� ������ �ݱ�
        fclose(fp);

    }else {
        printf("File Open Fail\n"); //���� ���� ����
    }

    return 0;
}
