// struct, typedef, union, enum

// ����ü(union) ����
//  : ���� ���� �ڷ����� �����͸� �ϳ��� ��� ��ҿ��� �����ϸ� ����
//     -> �ش� ����ü�� ��� ��, ���� ū �ڷ��� 1���� ������ �Ҵ� ( <-> struct�� ��� ��������� �޸𸮸� �Ҵ�)
//         -> (�߿�) ��Ȯ���� ��� �������� �޸𸮸� �����ϴµ�, �� ū ���� ������ �̸� ����� �����̴�..
// 
//             ex) int �� double�� ���� ���, double�� �Էµǵ� ������ �ִ� int������ ������ �����ϳ�.. �� ���� �־��� 8byte�� ������� double �� 4byte�� int�� ���� ���� �Ұ���
   
   
//   # ����ü union ���� �� ���� : 
// 
//       union ����ü�� {
//           �ڷ��� ��� 1;
//           �ڷ��� ��� 2;
//           ��;
//       };
         
//       ex) union int_or_float {
//              int a;
//              float b;
//           };
   
//   # ����ü(struct) vs ����ü(union)
//      - ������ : ���������� ��ü����
//      - ������ : ����ü�� ��� ��������� �޸𸮸� ���� �Ҵ�    
//                                  <->     
//                 ����ü�� ������� �� ���� ū �޸𸮸� ���� �ڷ����� ���� 1������ �Ҵ� (������ �����ϳ�, ��ǻ� �������� �������� �ʴ� ����ȸ��� ��������)


// ����ü(struct) vs ����ü(union)�� ���� ����
#include <stdio.h>

// typedef�� ���� ����ü���� Unum�� �̸� ������ -> Unum to Union
typedef union Unum {
    double d;
    int i;
} Union;

// typedef�� ���� ����ü���� Snum�� �̸� ������ -> Snum to Struct
typedef struct Snum {
    double d;
    int i;
} Struct;

int main() {

    // ������ �� ����ü, ����ü ����
    Union u_num;
    Struct s_num;

    printf("Union ����  �Է� :");
    scanf_s("%d", &u_num.i);

    printf("Union ����       : %10d \t \t union  whole size : %3d\n\n", u_num.i, (int)sizeof(u_num));

    printf("Union �Ǽ�  �Է� :");
    scanf_s("%lf", &u_num.d);

    // (�߿�) int �� double�� ���� ���, double�� �Էµǵ� ������ �ִ� int������ ������ �����ϳ�.. �� ���� �־��� 8byte�� ������� double �� 4byte�� int�� ���� ���� �Ұ���
    printf("Union ���� (�ս�): %10d \t \t union    int size : %3d\n", u_num.i, (int)sizeof(u_num.i));
    printf("Union �Ǽ�       : %10.2lf \t \t union double size : %3d\n\n", u_num.d, (int)sizeof(u_num.d));

    printf("---------------------------------------------------------------------\n\n");

    printf("Struct ���� �Է� :");
    scanf_s("%d", &s_num.i);

    printf("Struct ����      : %10d \t \t struct  whole size : %3d\n\n", s_num.i, (int)sizeof(s_num));

    printf("Struct �Ǽ� �Է� :");
    scanf_s("%lf", &s_num.d);

    printf("Struct ����      : %10d \t \t struct    int size : %3d\n", s_num.i, (int)sizeof(s_num.i));
    printf("Struct �Ǽ�      : %10.2lf \t \t struct double size : %3d\n\n", s_num.d, (int)sizeof(s_num.d));
    return 0;
}
