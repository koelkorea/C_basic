// ����ü�� �����迭 (struct array)
//  : ����ü�� �����ǵ� �ڷ� Ÿ�� = ����ü ���� ���� �迭(array)�� ���·� ��� ����
//     -> ����ü�� �迭ȭ �Ͽ� ���� ������ ���� �����͸� �Ѳ����� ���� �� ����
//         (= OOP�� class ��ü�迭�� ��������, �߻��� ���)

//         ex) struct person per[20];          <- ����ü �迭���� ���� (= per1�� �迭���̴�, �� ��ü�� �����ͺ���)

//             per->name;                      <- 1. �����ͺ����� -> ��������� ��� (= per[0]�� name)
//             (*(per + 2)).name;              <- 2. (*�����ͺ�����).��������� ��� (= per[3]�� name)
//             per[10].name;                   <- 3. ����ü������.��������� ���		<- (�߿�!) []�� �ٴ� ���� per[10]�� �����ͺ������� 1�� ���谡 ���� �迭�� index�� ��ġ�ϴ� ���� �ǹ��ϰ� �� 


//   # (�߿�!) array������ ���߼��� �ٽ� ����ؾ� ��
//       - 1���� array���� �ڽ�
//          : �ش� 1���� �迭�� �����ּҰ��� �ǹ��ϴ� '�����ͺ���' 
//            ( 1�����迭���� = &1�����迭����[0] )
//      
//       - []�� �Բ��ϴ� ���
//          : �迭 �ȿ� ��ġ�ϴ� �ܼ� �ڷ��� ���� (= �����Ϳ� ���ü��� 1�� ����)


#include <stdio.h>
#include <stdlib.h> //system() : ȭ�� �����
#define MAX 3

// struct ����array ��� ���� - 3���� �л��� ������ �����ϴ� ���� �ڵ�
typedef struct student {
    int no;
    char name[20];
    char phone[20];
} STU;

int main() {

    // STU ����ü �迭 ����
    //  -> struct student[MAX]; �Ͱ���
    STU st[MAX];        

    for (int i = 0; i < MAX; i++) {

        system("cls");
        printf("\n\t\t*** �л����� �Է� ***\n");

        // �ڵ��Ϸù�ȣ
        st[i].no = i + 1; 
        printf("��    ȣ : %03d", st[i].no);

        printf("\n��    �� : ");
        scanf_s("%s", st[i].name, (int)sizeof(st[i].name));
        // �Է� ���� ����
        while (getchar() != '\n'); 

        printf("��ȭ��ȣ : ");
        scanf_s("%s", st[i].phone, (int)sizeof(st[i].phone));
        // �Է� ���� ����
        while (getchar() != '\n');
    }

    system("cls");
    printf("\n\t\t*** �� �� �� �� ***\n");

    for (int i = 0; i < MAX; i++) {
        printf("\t%d. ��    �� : %s\n\t   ��ȭ��ȣ : %s\n\n\n", st[i].no, st[i].name, st[i].phone);
    }

    return 0;
}
