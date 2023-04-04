// - ���� �Ҵ� ���� �Լ�
//  3. (void*) calloc (size_t _Count, size_t _size) 
//      : _count ���� * _size �޸� ũ�� �� ������ �� �ִ� �޸� ������ �Ҵ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

//      # (�߿�) malloc���� ������
//        1. �Ҵ�� �޸� �� ��� 0���� �ʱ�ȭ
//        2. ������ �Ķ���ͷ� ����, �������� �ø�

//  4. (void*) realloc (void* _Block, size_t size)
//      : �̹� �Ҵ��� ������ ������ �ּҰ��� _block�ϰ�, ���Ҵ� �� ������ ũ�⸦ size�� �Է� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

#include<stdio.h>
#include<stdlib.h>              // malloc(), free()
#include<math.h>
#include<stdlib.h>				// srand(), rand() �Լ� ��� �����ϰ� ��

// N���� �л� ���� �Է� & ��� �ڵ带 �ۼ��ϴ� ���� (�����Ҵ��� ������!)
int main(void) {
    srand((unsigned int)time(NULL));

    // ���� n : �л��� ��, start_address : ���� �Է��� �ּҰ� ���� �༮
    int n = 0, size = 0;
    int* start_address = 0;

    float average = 0, deviation = 0, variance = 0, standard_deviation = 0;

    printf("������ �Է��� �л��� �� ���ΰ�? : ");
    scanf_s("%d", &n);

    start_address =  (int*) calloc(n, sizeof(int));

    size = _msize(start_address);

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    printf("�Ҵ�� �޸� : %d \n", size);

    for (int i = 0; i < n; i++) {
        *(start_address + i) = rand() % 101;
        printf("�л� %d : %d\n", i + 1, *(start_address + i));

        average += (float) *(start_address + i);
    }

    average /= n;

    for (int i = 0; i < n; i++) {

        deviation = (float)(*(start_address + i) - average);
        variance += (float)( *(start_address + i) - average) * (*(start_address + i) - average);
    }

    variance /= n;
    standard_deviation = sqrt(variance);

    printf("��� : %3.6f�� \n", average);
    printf("�л� : %3.6f�� \n", variance);
    printf("ǥ������ : %3.6f�� \n", standard_deviation);


    return 0;
}
