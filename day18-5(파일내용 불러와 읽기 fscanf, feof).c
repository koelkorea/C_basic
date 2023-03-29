// - file ���� ���ڿ� ��, ��� �Լ�
//		: (�߿�) fopen_s�� ���� ���� ��Ʈ�� ������ ������ �� ��, �ش� ���� ��Ʈ���� ��� ������ ��,��� �Լ�  


// 3.  file�� ���ڿ� ����, �ܺ� file���� ������ ��������, ���� data�� ���� ã�� �Լ�

//      # fscanf( file������, ���ڿ��� );
//          :  �ܺ� ���Ͽ��� ����ȭ�� �ڷḦ �Է� �ޱ� ���� ���Ǵ� �Լ�
// 
//              ex) int fscanf(FILE* _Stream, char const* string);
//                      ->  int fscanf(����������, ���ڿ���);�� �ؼ�

//      # feof( file������ );
//          :  (feof : File End Of Flag) ������ ������(EOF) 0�� �ƴ� ���� ���� = ������ ���� �ƴϸ� 0����
// 
//              ex) int feof(FILE* _Stream)
//                      ->  int fscanf(����������, ���ڿ���);�� �ؼ�


// fscanf, feof�� ����Ͽ� day18-5���� ������ txt���� �б�
#include <stdio.h>
#include <stdlib.h>
#define STU_SIZE 20

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
    int i = 0, j;

    printf("\n�� ���ϸ� �Է� (.txt Ȯ���� �Է�!) : ");

    //�ҷ��� txt ���ϸ� �Է��ؼ� ����
    scanf_s("%s", file_name, sizeof(file_name) - 1);         // ���ڿ��� �޴� ���̱⿡ ���� �˸��� NULL����(\0)�� �� ������ 1��ŭ�� �����ؾ� �ϹǷ�, ��������� file_name�� ũ�⺸�� 1 �۰�
    while (getchar() != '\n');

    // file �б� ���(r) :  fopen_s ���� �� 0 ��ȯ
    if (0 == fopen_s(&fp, file_name, "r")) {

        // feof(����������);
        //  :  ������ ������(EOF) 0�� �ƴ� ���� ���� = ������ ���� �ƴϸ� 0����
        //      -> �ܺ� ������ ���� ��, ��� �������� �����ϰ��ϱ� ���� ���
        while (!feof(fp)) {

            // fscanf(����������, ���ڿ���);
            //  :  �ܺ�����(scanf_s�� ���� ���������ͷ� �� ��ġ�� �����Ǿ���)�� ����ȭ�� �ڷḦ ���ʿ� �Է� �ޱ� ���� ���Ǵ� �Լ�
            //      -> �ܺ� ������ ������ ���� ������ ������ �Ѱܹޱ� ���� �Լ��� �ǹ� (��! �ܺ������� ������ ������ ������ �ְ�, ������ �ٲܼ��� ����)
            fscanf_s(fp, "%d %s %d %d %d\n", &sp[i].no, sp[i].name, (int)sizeof(sp[i].name), &sp[i].kor, &sp[i].eng, &sp[i].mat);
            i++;
        }

        // fclose(file ������) : ���� ������ �ݱ�
        fclose(fp);

    }else {
        printf("File Open Fail\n"); //���� ���� ����
    }

    printf("\n\n%7s%10s%8s%8s%8s\n", "��ȣ", "�̸�", "����", "����", "����");
    printf("������������������������������������������������������������������������������������������\n");

    for (j = 0; j < i; j++) {

        printf("%7d%10s%8d%8d%8d\n", sp[j].no, sp[j].name, sp[j].kor, sp[j].eng, sp[j].mat);
    }

    return 0;
}
