#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() �Լ� ��� �����ϰ� ��

// 1�г� �л��� ���������� ���� ���α׷� �ۼ��ϱ�
//  -> ���� �� ����� �Է¹ް�
//  -> �ش� ���� �л��� ������� �Է¹ް�
//  -> �� ���� �� �л��� ������ �Է�

// (Ǯ��1) ����ü�� �迭 ���
typedef struct class {
    int student_num;     // �л��� ��
    int* student_array;  // �л��� �����迭�� ������ġ ����
    float average;
    float varience;
}class;

void read_score(); // �� ����
void compute_average(); // ��հ��
void compute_varience(); // �л���
void print_result(); // ���
void error(char*); // ����ó��
void release_memory(); //���� �Ҵ� ����

int main(void) {

    srand((unsigned int)time(NULL));

    // ���� class_num : ���� �� ����, start_address : ���� �Է��� �ּҰ� ���� �༮
    int class_num = 0;
    long long size = 0;
    class* class_start_address = 0;

    printf("�ش� �г��� ���� �� ���ΰ�? : ");
    scanf_s("%d", &class_num);

    // �Է¹��� ���� ����ŭ class ����ü�� �����Ҵ� ����迭 ����(�� ������ġ �ּҰ��� �޴°� class����ü �����ͺ��� start_address)
    class_start_address = (class*)calloc(class_num, sizeof(class));
    size = _msize(class_start_address);

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    printf("�Ҵ�� �޸� : %lld \n\n", size);

    read_score(class_start_address, class_num);

    compute_average(class_start_address, class_num);
    compute_varience(class_start_address, class_num);

    print_result(class_start_address, class_num);
    release_memory(class_start_address, class_num);

    return 0;
}

// �� ����
void read_score(class* class_pointer, int class_num) {

    for (int i = 0; i < class_num; i++) {

        float class_total = 0;

        // �� ���� �л��� �Է� -> student_num�� ����
        printf("\n%d�� �л����� �� ���ΰ�? : ", i + 1);
        scanf_s("%d", &((class_pointer + i)->student_num));

        // �Է¹��� ���� �л������� ����ŭ int �ڷ����� �����Ҵ� ����迭 ����(�� �迭�� ������ġ �ּҰ��� �޴°� int �����ͺ��� student_start_address)
        (class_pointer + i)->student_array = (class*)calloc((class_pointer + i)->student_num, sizeof(int));

        for (int j = 0; j < (class_pointer + i)->student_num; j++) {

            // �� �л��� ���� ���� ����
            *((class_pointer + i)->student_array + j) = rand() % 101;
            printf("%d�� �л��� ���� : %d \n", j + 1, *((class_pointer + i)->student_array + j));
        }
    }
}

// ��հ��
void compute_average(class* class_pointer, int class_num) {

    for (int i = 0; i < class_num; i++) {

        (class_pointer + i)->average = 0;

        for (int j = 0; j < (class_pointer + i)->student_num; j++) {

            (class_pointer + i)->average +=  (*((class_pointer + i)->student_array + j) / (float) (class_pointer + i)->student_num );
        }
    }
}

// �л���
void compute_varience(class* class_pointer, int class_num) {

    for (int i = 0; i < class_num; i++) {

        (class_pointer + i)->varience = 0;

        for (int j = 0; j < (class_pointer + i)->student_num; j++) {

            (class_pointer + i)->varience
                += (float) (((*((class_pointer + i)->student_array + j) - (class_pointer + i)->average)
                    * (*((class_pointer + i)->student_array + j) - (class_pointer + i)->average)) / (float) (class_pointer + i)->student_num);
        }
    }
}

// ���
void print_result(class* class_pointer, int class_num) {

    printf("\n[��� ���]\n");
    printf("  ��  �л���      ���      �л�\n");

    for (int i = 0; i < class_num; i++) {

        printf("%d��  %5d��  %6.2f��  %6.2f�� \n", i + 1, (class_pointer + i)->student_num, (class_pointer + i)->average, (class_pointer + i)->varience);
    }
}

void error(char*); // ����ó��

//���� �Ҵ� ����
void release_memory(class* class_pointer, int class_num) {

    for (int i = 0; i < class_num; i++) {

        free((class_pointer + i)->student_array);
    }

    free(class_pointer);
} 