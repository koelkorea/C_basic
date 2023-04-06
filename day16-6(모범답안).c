// 1�г� �л��� ���������� ���� ���α׷� �ۼ��ϱ�
//  -> ���� �� ����� �Է¹ް�
//  -> �ش� ���� �л��� ������� �Է¹ް�
//  -> �� ���� �� �л��� ������ �Է�

// (Ư���� 1) ���, �л꿡 �ش��ϴ� �迭 ���� �����Ҵ����� ���� ����
// (Ư���� 2) �޸� ��ü�� print_result�� �������� ��
// (Ư���� 3) �������� ��� + 2���� �迭 ���


#include <stdio.h>
#include <stdlib.h> //malloc(), free(), srand(), rand()
#include <time.h> //time()

void read_score(); // �� ����
void compute_stat(); // ���
void print_result(); // ���
void error(char*); // ����ó��
void release_memory(); //���� �Ҵ� ����

int no_class; // �й� �� ����
int* no_student; // �й� �� �л����� ����Ű�� ������
float* ave, * var; // �й� �� ��հ�, �л갪 ����Ű�� ������
int** score; // �й� �� ������ ����Ű�� ������ �迭
float tot_ave, tot_var; // ��ü ��� ��ġ

int main() {
    read_score(); // ���� �Է�
    compute_stat(); // ��հ�, �л갪 ���
    print_result(); // ���
    return 0;
}
void read_score() {

    srand((unsigned)time(NULL));
    printf("�й� ���� �Է��ϼ���.:");
    scanf_s("%d", &no_class);

    //int no_student[no_class]; �й� �� �л� �� �� �迭
    no_student = (int*)malloc(no_class * sizeof(int));
    
    //float ave[no_class];  �й� �� ��� �� �迭
    ave = (float*)malloc(no_class * sizeof(float));
    
    //float var[no_class];  �й� �� �л� �� �迭
    var = (float*)malloc(no_class * sizeof(float));
    
    //int * score[no_class]; �й� �� ������ ����Ű�� ������ �迭
    score = (int**)malloc(no_class * sizeof(int*));
    
    if (no_student == NULL || ave == NULL || var == NULL || score == NULL)
    {
        error("�޸� ����");
    }

    for (int i = 0; i < no_class; i++) {
        printf(" %d ���� �л� ���� �Է��ϼ���.", i + 1);
        scanf_s(" %d", &no_student[i]);

        score[i] = (int*)malloc(no_student[i] * sizeof(int));

        //int score[i][no_student] �й� �� �л� �ο����� ���� �迭
        if (score[i] == NULL) { error("�޸� ����"); }

        printf(" %d �� %d�� �л��� ������ �Է��ϼ���.\n", i + 1, no_student[i]);

        for (int j = 0; j < no_student[i]; j++) {

            score[i][j] = rand() % 100 + 1;
            printf("%4d\n", score[i][j]);
        }
    }
}

void compute_stat() {

    int i, j;
    float sum, total_ave = 0.0, total_var = 0.0;

    for (i = 0; i < no_class; i++) {

        for (sum = 0.0, j = 0; j < no_student[i]; j++) {
            sum += score[i][j];
        }

        ave[i] = sum / no_student[i];
        total_ave += ave[i];

        for (sum = 0.0, j = 0; j < no_student[i]; j++) {
            sum += (score[i][j] - ave[i]) * (score[i][j] - ave[i]);
        }

        var[i] = sum / no_student[i];
        total_var += var[i];
    }
    tot_ave = total_ave / no_class;
    tot_var = total_var / no_class;
}

void print_result() {

    printf("%3s %7s %9s %9s\n", "�й�", "�л���", "���", "�л�");

    for (int i = 0; i < no_class; i++) {
        printf("%3d %7d %11.2f %11.2f\n", i + 1, no_student[i], ave[i], var[i]);
    }

    printf("%11s %8.2f %11.2f\n", "��ü ��� ��ġ", tot_ave, tot_var);

    release_memory();
}

void release_memory() {

    for (int i = 0; i < no_class; i++) {
        free(score[i]);
    }

    free(score);
    free(no_student);
    free(ave);
    free(var);
}

void error(char* message) {

    printf("ERR : %s \n", message);
    exit(1);
}
