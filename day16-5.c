#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() �Լ� ��� �����ϰ� ��

typedef struct score {
    char* name;     // ���ڿ��� �ּҸ� ����
    int kor, eng, math, total;
    float avg;
}score;

// str_len(���ڿ� �ּ�) : �ش� ���ڿ��� ���� ��ȯ
int str_len(char* p) {

    int n = 0;              // ���� ���ڿ� ������ ��Ÿ��
    while (*p++)n++;        // ���� �����ϴ� ���ڿ� �ּ� ��ġ�� ���� �������� ���� null�� �ƴϸ�? ���ڸ� 1���� �ø���.    -> �̰� ���ڿ��� null�� ���� ���������� ����ϸ�, ���ڿ� ���� üũ ����
    return n;
}

void input(score* pS, int number);
void output(score* pS, int number);
void freeMemory(score* pS, int number);

// [ N���� �л� ���� & �̸� ���� ] �ڵ� �ۼ�
int main(void) {
    srand((unsigned int)time(NULL));

    // ���� n : �л��� ��, start_address : ���� �Է��� �ּҰ� ���� �༮
    int n = 0;
    long long size = 0;
    score* start_address = 0;

    printf("������ �Է��� �л��� �� ���ΰ�? : ");
    scanf_s("%d", &n);

    start_address = (score*)calloc(n, sizeof(score));
    size = _msize(start_address);

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    printf("�Ҵ�� �޸� : %lld \n", size);

    for (int i = 0; i < n; i++) {

        char input[1000] = {0};

        (start_address + i)->kor = rand() % 101;
        (start_address + i)->math = rand() % 101;
        (start_address + i)->eng = rand() % 101;
        (start_address + i)->total = (start_address + i)->kor + (start_address + i)->math + (start_address + i)->eng;
        (start_address + i)->avg = (start_address + i)->total / 3;

        printf("[�л� %d ���� �Է�]\n", i + 1);
        printf("���� : %d\n", (start_address + i)->kor);
        printf("���� : %d\n", (start_address + i)->math);
        printf("���� : %d\n", (start_address + i)->eng);
        printf("�̸� : ");
        scanf_s("%s", input, sizeof(input) );

        // ���� �Ҵ��... ���ڿ��� ������ �� �Ҷ��� �׳��� �˸��� null ���ڱ��� �����������
        (start_address + i)->name = (char*)calloc(str_len(input)+1, (sizeof(char)));

        if ((start_address + i)->name != NULL) {

            for (int j = 0; j <= str_len(input); j++) {
                *(((start_address + i)->name) + j) = input[j];
            }
        }
        printf("�ű� �̸� Ȯ�� : %s\n\n", (start_address + i)->name);
        //free(input);          <- ���������� free�� ����� �ƴ�
    }

    for (int i = 0; i < n; i++) {
        printf("�л� %d��. �̸� : %s, ���� : %d��, ��� : %4.2f�� \n", i+1, (start_address + i)->name, (start_address + i)->total, (start_address + i)->avg);
        free(((start_address + i)->name));
    }

    free(start_address);

    return 0;
}

void input(score* pS, int number) {

}
void output(score* pS, int number) {

}
void freeMemory(score* pS, int number) {


}
