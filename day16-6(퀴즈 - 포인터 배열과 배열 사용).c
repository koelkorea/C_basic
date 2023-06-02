#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() �Լ� ��� �����ϰ� ��

// 1�г� �л��� ���������� ���� ���α׷� �ۼ��ϱ�
//  -> ���� �� ����� �Է¹ް�
//  -> �ش� ���� �л��� ������� �Է¹ް�
//  -> �� ���� �� �л��� ������ �Է�

// (Ǯ��2) ������ �迭�� �迭 ���
int main(void) {
    srand((unsigned int)time(NULL));

    // ���� class_num : ���� �� ����, start_address : ���� �Է��� �ּҰ� ���� �༮
    int class_num = 0;
    long long size = 0;
    int** class_start_address = 0;

    printf("�ش� �г��� ���� �� ���ΰ�? : ");
    scanf_s("%d", &class_num);

    // �Է¹��� ���� ����ŭ int �����ͺ��� �ڷ����� �����Ҵ� ����迭 ����(�� ������ġ �ּҰ��� �޴°� int �����ͺ��� start_address)
    class_start_address = (int**)calloc(class_num, sizeof(int*));
    size = _msize(class_start_address);

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    printf("�Ҵ�� �޸� : %lld \n\n", size);

    // ���� �� ������ŭ �ݺ���
    for (int i = 0; i < class_num; i++) {

        int student_num = 0;
        float class_total = 0;

        // �� ���� �л��� �Է� -> student_num�� ����
        printf("\n%d�� �л����� �� ���ΰ�? : ", i + 1);
        scanf_s("%d", &student_num);

        // �Է¹��� ���� �л������� ����ŭ int �ڷ����� �����Ҵ� ����迭 ����
        // (�� �迭�� ������ġ �ּҰ��� int 2�� �����ͺ��� class_start_address�� ������ �޸� ��ġ�� ���������� ����Ǿ� ����)
        *(class_start_address + i) = (int*)calloc(student_num, sizeof(int));

        for (int j = 0; j < student_num; j++) {

            // �� �л��� ���� ���� ����
            *(*(class_start_address + i) + j) = rand() % 101;
            printf("%d�� �л��� ���� : %d \n", j + 1, *(*(class_start_address + i) + j));
        }
    }

    printf("\n[��� ���]\n");
    printf(" ��   �л���     ���      �л�\n");

    // ���, �л� ��� �� ����Ʈ
    for (int i = 0; i < class_num; i++) {

        float class_total = 0;
        float average = 0;
        float varience = 0;
        int student_num = 0;

        // �г� ������ ����
        while (*(*(class_start_address + i) + student_num) >= 0 && *(*(class_start_address + i) + student_num) <= 100) {
            class_total += *(*(class_start_address + i) + student_num);
            student_num++;
        }

        average = class_total / student_num;

        for (int j = 0; j < student_num; j++) {

            varience += ( ( *(*(class_start_address + i) + j) - average) * ( *(*(class_start_address + i) + j) - average) );
        }

        varience /= student_num;
       
        printf("%d��  %5d��  %5.2f��  %5.2f�� \n", i + 1, student_num, average, varience);
        free(*(class_start_address + i));
    }

    free(class_start_address);

    return 0;
}