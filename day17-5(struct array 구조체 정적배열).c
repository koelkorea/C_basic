//  ����ü�� �����迭 (struct array)
//      : ����ü�� �����ǵ� �ڷ� Ÿ�� = ����ü ���� ���� �迭(array)�� ���·� ��� ����
//          -> ����ü�� �迭ȭ �Ͽ� ���� ������ ���� �����͸� �Ѳ����� ���� �� ����
//              (= OOP�� Ŭ���� ��ü�� ��������, �߻��� ���)

#include <stdio.h>
#include <stdlib.h> //system() : ȭ�� �����
#define MAX 3

// struct ����array ��� ����
// ex) 3���� �л��� ������ �����ϴ� �ڵ�
typedef struct student {
    int no;
    char name[20];
    char phone[20];
} STU;

int main() {

    STU st[MAX];        //STU ����ü �迭 ����

    for (int i = 0; i < MAX; i++) {

        system("cls");
        printf("\n\t\t*** �л����� �Է� ***\n");

        st[i].no = i + 1; //�ڵ��Ϸù�ȣ
        printf("��    ȣ : %03d", st[i].no);

        printf("\n��    �� : ");
        scanf_s("%s", st[i].name, (int)sizeof(st[i].name));
        while (getchar() != '\n'); //�Է� ���� ����

        printf("��ȭ��ȣ : ");
        scanf_s("%s", st[i].phone, (int)sizeof(st[i].phone));
        while (getchar() != '\n');
    }

    system("cls");
    printf("\n\t\t*** �� �� �� �� ***\n");

    for (int i = 0; i < MAX; i++) {
        printf("\t%d. ��    �� : %s\n\t   ��ȭ��ȣ : %s\n\n\n", st[i].no, st[i].name, st[i].phone);
    }

    return 0;
}
