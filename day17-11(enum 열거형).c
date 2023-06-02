// struct, typedef, union, enum

// ������(enum) 
//  : ���ڿ��� ���ȭ ���� �����ϸ� �����ϴ� �ڷ��� (���α׷��� ������ ��)
//     -> �� ���ڿ��� �ƹ� ���ڵ� �������� ������, 0 ~ n-1 ���� ���������� �־���

//   # ������ enum ���� �� ����
//      : enum �������� { ���ڿ����1, ���ڿ����2, ... }; 

//         ex) enum week { SUN, MON, TUE, WED, THU, FRI, SAT };

//   # ������ enum ���� �� �迭 ����
//      : �� ������ ���� ������ ������ '��������'�� �����͸� ä�� �� ����
//         -> �׸��� �� ���ΰ��� �����ϸ�, '��������'���� ���ص� int���̳� �ڵ����� ������ �־��� int������ ������
// 
//      1. enum ����
//        : enum �������� ������������ = ����� ���ڿ�������� �ϳ�; 

//         ex) enum week { SUN, MON, TUE, WED, THU, FRI, SAT };     <- ������(enum) week ��� ����
//             enum week week1 = WED;                               <- ������(enum) week�� ���� week1����
//              -> (�߿�) week1 = 4; 

//      2. enum �迭
//        : enum �������� �������迭��[int] = { ����� ���ڿ������, ...}; 

//         ex) enum week { SUN, MON, TUE, WED, THU, FRI, SAT };     <- ������(enum) week ��� ����
//             enum week week1[3] = {FRI, TUE, SAT};                <- ������(enum) week�� �迭 week1����
//              -> (�߿�) �ش� week1�迭�� ���� {5, 2, 6}�� ����

//   # (�߿�!) ������ enum�� �Ӽ�
//      1. {}���� �� ���ڿ����� �ƹ��� ���� ���Ե��� ������, 1��° ��ġ�� ���ڿ��� ��Ÿ���� ������� 0�� ����      ex) SUN = 0���� ����
//      2. {}���� ���ڿ��� 1��° ��ġ�� �ƴ϶��, �� ���ڿ��� ��Ÿ���� ������� '���� ���ڿ��� ����� + 1' �� ��
//      3. {}�ȿ� ���ڿ� ��, ���� ���Ƿ� ������ ���ڿ��� 1,2�� ������ �߱�� ���Ե� ���� ������
//      4. (�߿�) ���� enum �ڷ������κ��� ������ ���� ���� �ڷ���(int, long)�� ����

#include <stdio.h>

// enum ���
typedef enum week1 { SUN, MON, TUE, WED, THU, FRI, SAT } WEEK;      // <SUN = 0���� ����>
enum week2 { SU = 2, MO = 9, TU, WE = 10, TH, FR, SA };
enum week3 { S = 9, M , T, W = 5, U, F = 10, A };

int main() {

    WEEK day1[7] = { SUN, MON, TUE, WED, THU, FRI, SAT };           
    enum week2 day2[7] = { SU, MO, TU, WE, TH, FR, SA };
    enum week3 day3[7] = { S, M, T, W, U, F, A };

    for (int i = 0; i < 7; i++) {
        printf("week1 : %d \tweek2 : %d \tweek3 : %d \n", day1[i], day2[i], day3[i]);
    }

    //  week1: 0        week2 : 2       week3 : 9
    //  week1 : 1       week2 : 9       week3 : 10
    //  week1 : 2       week2 : 10      week3 : 11
    //  week1 : 3       week2 : 10      week3 : 5
    //  week1 : 4       week2 : 11      week3 : 6
    //  week1 : 5       week2 : 12      week3 : 10
    //  week1 : 6       week2 : 13      week3 : 11

    return 0;
}
