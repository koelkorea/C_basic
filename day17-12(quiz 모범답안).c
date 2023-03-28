#include <stdio.h>
#include <stdlib.h> //system(), exit()
#include <conio.h>  //_getch()
#include <string.h> //strcmp() : �� ���ڿ��� ����� ������ ���θ� ��
#define MAX 3


// ���� �ý��� (������)
//		- strcmp() �Լ��� �׳� ������ �� 
//		    -> ��, �̰ɷ� �˻��� ������ �� �� �Ἥ �������� ȿ�� ���
typedef struct _book
{
    int no;                       // å �Ϸù�ȣ
    char title[30];          // ������
    char author[20];     // �۰�
    int price;                   // ����
    int cnt;                      // ����
    int sale;                    // �����(���� * ����)
}BOOK;

void input(BOOK* p);  //�Է��Լ�
void output(BOOK* p); //����Լ�
void sort(BOOK* p);   //�����Լ�
void search(BOOK* p); //�˻��Լ�

int main() {
    int n;
    BOOK bo[MAX];
    while (1) {//���ѷ���    for(;;) ���ѷ���
        system("cls");//ȭ�� �����
        printf("\n *** �������� �޴� ***\n\n");
        printf("  1. �Է�\n");
        printf("  2. ���\n");
        printf("  3. ����\n");
        printf("  4. �˻�\n");
        printf("  5. ����\n\n");
        printf("  ���� : [ ]\b\b");
        scanf_s("%d", &n);

        switch (n) {
        case 1:
            input(bo);
            break;
        case 2:
            output(bo);
            break;
        case 3:
            sort(bo);
            break;
        case 4:
            search(bo);
            break;
        case 5:
            printf("\n\n\t\t���α׷��� �����մϴ�.\n");
            exit(0); //���α׷� ��������
        }//end switch
        printf("\n\n\t\t�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.");
        _getch(); //�Է��Լ�(���ڱ��X, Enter�ʿ����) ��� ����
    }//end while
    return 0;
}//end main


void input(BOOK* p) {
    for (int i = 0; i < MAX; i++) {
        system("cls");
        printf("\n\n*** ���� ���� �Է� ***\n\n");
        p[i].no = i + 1; //�Ϸù�ȣ �ڵ��Ҵ�
        printf("[%d��° �Է�]\n", p[i].no);
        printf("������ : ");
        scanf_s("%s", p[i].title, (int)sizeof(p[i].title));
        printf("��  �� : ");
        scanf_s("%s", p[i].author, (int)sizeof(p[i].author));
        printf("��  �� : ");
        scanf_s("%d", &p[i].price);
        printf("��  �� : ");
        scanf_s("%d", &p[i].cnt);
        p[i].sale = p[i].price * p[i].cnt;   //����� = ���� * ����
    }
}//end input

void output(BOOK* p) {
    system("cls");
    printf("\n\n\t\t\t *** ���� ���� ��� ***\n\n");
    printf("%5s %27s %20s %7s %5s %8s\n", "��ȣ", "������", "�۰�", "����", "����", "�����");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < MAX; i++) {
        printf("  %03d %27s %20s %7d %5d %8d\n", p[i].no, p[i].title, p[i].author, p[i].price, p[i].cnt, p[i].sale);
    }
}//end output

void sort(BOOK* p) {
    BOOK temp;
    for (int i = 0; i < MAX - 1; i++) { //��������
        for (int j = i + 1; j < MAX; j++) {//�ּҰ� ã��
            //if( p[i].sale < p[j].sale ) //�����(��������)
            if (strcmp(p[i].title, p[j].title) > 0) { //������(��������)            
                //����ü ��ü �����͸� �ٲٱ�
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\n\n\t\t������ ���� �������� ���� �Ϸ�~!!\n");
}//end sort


void search(BOOK* p) {
    char str[30];
    int flag = 0; //�˻����� Ȯ�κ���
    system("cls");
    printf("\n\n�˻� ������ �Է� : ");
    scanf_s("%s", str, (int)sizeof(str));
    printf("\n\n\t\t\t*** ���� �˻� ���� ��� ***\n\n");
    printf("%5s %27s %20s %7s %5s %8s\n", "��ȣ", "������", "�۰�", "����", "����", "�����");
    printf(" ---------------------------------------------------------------------------- \n");
    for (int i = 0; i < MAX; i++) {
        if (strcmp(str, p[i].title) == 0) {//�������� ��ġ�Ѵٸ�        
            printf("  %03d %27s %20s %7d %5d %8d\n", p[i].no, p[i].title, p[i].author, p[i].price, p[i].cnt, p[i].sale);
            flag = 1; //�˻� �Ǿ��� �� flag���� 1�� ����
        }
    }//end for
    if (flag == 0) {
        printf("\n\n\t\t�˻� ������ �������� �ʽ��ϴ�.\n");
    }
}//end search
