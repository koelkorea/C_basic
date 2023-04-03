// pointer array
//  : �� �״�� �����ͺ����� �̷���� �迭�� ��ǥ�����δ� ���ڿ��� ����
//      ex) int * a[3] = { &b, &c, &d};

//	- ������ �迭 ����� ( asterisk(*) ������ ���)
//		: �ڷ��� * �����ͺ�����[������ ��]	   <= �迭 ���ο� Ư�� �ڷ����� �����ͺ������� ���� �� �� �ִ� ������ �迭 ����
//			ex1) int * a[3];                  <- �ȿ� int �ڷ����� �ּҸ� �����ϴ� ũ�Ⱑ 3�� ������ �迭�� a�� ����
//               int b = 1, c = 2, d = 3      
//               int * a[3] = { &b, &c, &d};  <- �迭�ȿ� ��ҷ� int �����ͺ��� �Է� ���� 

//          ex2) int ary[5] = { 10 , 20 , 30 , 40 , 50 };
//               int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };  <- int�迭�� ��Ұ��� &�� ���� �ּҰ����� �޾Ƶ� ���� ����

//  - (�߿�!) ������ �迭�� ���� ����Ʈ �迭
//      : ������ �迭�� �� ������ ������ �ּҰ��� ������ �迭�� ���������� �����Ͽ� �ξ� �� �ս��� ���� ������
//        (������ �迭�� �޸� ������ [0][0]�� �������� �ڷ��� ũ�� ��ŭ �����̸� ���������� �޸𸮿� �Ҵ�ȴٴ� Ư������ ����, �� index�������� �迭���� ����)

//      # (���ǻ���!) x���� �迭�� ������ ���� ������ �迭�� ������ (x-1)�����̾�� ��


//      # �߸��� ���õ�

//			ex1) int score[5][5];
//               int* pScore = score;     <- 2���� �迭 score�� �޴� �����ͺ����� �ܼ� ������ ������ ���� ���, pScore�� ���� score�迭�� �������� &score[0][0]�� �����Ǹ�
//                                           ������ ������ �迭�� �ƴ϶�, pScore[3]�̷��� �Ұ�����

//			ex2) int score[5][5];
//               int* pScore[5] = score;   <- ������ ���� ����

//      # ������ ���õ�

//          ex1) int score[5][5];
//               int* pScore[5] = { score[0] , score[1] , score[2] , score[3] , score[4] }; [�ּҰ�]
//               int** ppScore = pScore;

//          ex2) int score[5][5];
//               int (*pScore)[5] = score;

#include<stdio.h>
int main() {

  int ary[5] = { 10 , 20 , 30 , 40 , 50 };
  int* pAry[5] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };

  int score[5][5];

  // 2���� �迭 score
  int* pScore = &score[0][0];
  int* pSarr[5] = { score[0] , score[1] , score[2] , score[3] , score[4] };
  int** ppScore = pSarr;

  int key = 0;

    for (int i = 0; i < 5; i++) {

        printf("%3d ", ary[i]);
    }

    printf("\n");
    
    for (int i = 0; i < 5; i++) {

        printf("%3d ", *pAry[i]);
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            score[i][j] = ++key;
            printf("%3d ", score[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        
        printf("%3d ", *(pScore + i));
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%3d ", *pSarr[i]);
        printf("\n");
    }

    printf("\n");


    printf("--------------------------------------------------------------\n\n");


    printf("[2���� �迭�� 2�� ������ ������ ������ �Ͽ� �迭 ����] \n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%3d ", (i + 1) * ( (**ppScore) + j ) );
        }
        printf("\n");
    }

    printf("\n");

    printf("[2���� �迭�� 1�� ������ ������ ������ �Ͽ� �迭 ����] \n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%3d ", *pScore++);
        }
        printf("\n");
    }

    printf("\n");

    printf("[2���� �迭�� 2�� ������ ������ ������ �� ������ �迭�� �����Ͽ� �迭 ����] \n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%3d ", *(pSarr[i] + j) );
        }
        printf("\n");
    }



    return 0;
}
