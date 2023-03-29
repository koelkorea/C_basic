// - file ���� ���ڿ� ��, ��� �Լ�
//		: (�߿�) fopen_s�� ���� ���� ��Ʈ�� ������ ������ �� ��, �ش� ���� ��Ʈ���� ��� ������ ��,��� �Լ�  
// 
//  1.  file�� ���Ϲ��� ��, ��� �Լ�

//      # (���� ���� ��� �Լ�) fputc(��������, ����������)
//          : ���Ϸκ��� ���� ���ڸ� ����Ͽ� ��ȯ
//            (���� �߻��� EOF(-1) ��ȯ)
//              ex) int fputc(int c, FILE* stream);

//      # (���� ���� �Է� �Լ�) fgetc(��������, ����������)
//          : ���Ϸκ��� ���� ���ڸ� �а�, �� ���ڸ� ��ȯ
//            (������ ���� �����ų�, ���� �߻��� EOF(-1) ��ȯ)
//              ex) int fputc(int c, FILE* stream);


// ���Ϲ��� �Է�(fgetc) ���(fputc) �Լ��� ���, ���� �Է��� �ؽ�Ʈ���� txt ���Ϸ� ���� + �б�
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>      //_getch()
int main() {

    //file ������ ���� & �ʱ�ȭ (file�� �̹� ���ʺ��� struct �����ε�, typedef�� FILE�̶�� �����ǰ� �Ǿ� ����)
    FILE* fp = NULL;

    int ch;

    // 1. file ������� : fopen_s ���� �� 0 ��ȯ
    if (fopen_s(&fp, "out.txt", "w") == 0) {            // "out.txt" �̶�� ������ �����ض�

        printf("���� �Է�(����:0)\n");

        // 0�� �Է��ϱ� �������� ���Ϲ��� �Է��϶�� do ~ while
        do {

            ch = _getch();

            printf("�Էµ� ���� : %c\n", ch);

            // fputc : ��Ʈ���� ���� ���
            fputc(ch, fp);

        } while (ch != '0');

        printf("\n \t ���α׷� ����\n");

        // fclose(file ������) : ���� ������ �ݱ�
        fclose(fp);


    }
    else {     // ���� ���� ���� (fopen_s�� ����� 0�� ��ȯ���� ���� ��)

        printf("File Open Fail\n");

    }


    // 2. 1���� ������ file �б� ��� :  fopen_s ���� �� 0 ��ȯ
    if (fopen_s(&fp, "out.txt", "r") == 0) {

        printf("���� ����\n");

        // �ؽ�Ʈ ������ ���� ������ EOF ���� �ޱ���� ch�� ����ϴ� while��
        while ((ch = fgetc(fp)) != EOF) {

            //  \r : ĳ���� ���� (�ش����� ù°�ٷ� �̵�)
            if (ch != '\r') {
                printf("%c", ch);
            }
            else {
                printf("\n");
            }
        }

        // fclose(file ������) : ���� ������ �ݱ�
        fclose(fp);

    }
    else {      // ���� ���� ���� (fopen_s�� ����� 0�� ��ȯ���� ���� ��)

        printf("File Open Fail\n");
    }

    return 0;

}