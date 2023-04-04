// - ���� �Ҵ� ���� �Լ�
//  3. (void*) calloc (size_t _Count, size_t _size) 
//      : _count ���� * _size �޸� ũ�� �� ������ �� �ִ� �޸� ������ �Ҵ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

//      # (�߿�) malloc���� ������
//        1. �Ҵ�� �޸� �� ��� 0���� �ʱ�ȭ
//        2. ������ �Ķ���ͷ� ����, �������� �ø�

//  4. (void*) realloc (void* _Block, size_t size)
//      : �̹� �Ҵ��� ������ ������ �ּҰ��� _block�ϰ�, ���Ҵ� �� ������ ũ�⸦ size�� �Է� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

#include <stdio.h>
#include <stdlib.h>
int main() {

    long* buffer, * oldbuffer;

    // size_t : c��� �ȿ��� unsigned long long�� ������ �� �̸�
    size_t size;

    // (void*) calloc (size_t ����, size_t �޸�ũ��)
    //  : _count ���� * _size �޸� ũ�� �� ������ �� �ִ� �޸� ������ �Ҵ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)
    buffer = (long*)calloc(40, sizeof(long));   // long�� �ش��ϴ� ��ŭ�� �޸𸮸� 40�� �����ؼ� �Ҵ��� ��, �� ���� �ּҰ��� ��ȯ + �޸𸮰��� ��θ� 0���� �ʱ�ȭ

    // calloc�� ��� ��
    if (buffer != NULL) {
        printf("sizeof(long) * 40 �޸� �Ҵ� ����!\n");
    }
    else {
        printf("�޸� �Ҵ� ����...\n");
    }

    free(buffer); // �Ҵ���� �޸� �Ҹ�

    // (void*)malloc(size_t s)
    //  : s byte�� �ش��ϴ� ��ŭ�� �޸� ������ �Ҵ��ϴ� �Լ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)
    if ( (buffer = (long*) malloc ( sizeof(long) * 1000) ) == NULL) { // long�� �ش��ϴ� ��ŭ�� �޸𸮸� 1000�� �����ؼ� �Ҵ��� ��, �� �Ҵ翡 ���������� ����
        exit(1);
    }

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    size = _msize(buffer);  // �Ҵ翡 ����������, �� �޸� ũ�⸦ size��� ������ ����

    printf(" (long x 1000) �޸� malloc ���� �Ҵ� : %lld\n", size);

    oldbuffer = buffer;     // �޸� �ּ� �� �ӽ� ����, ( ���Ҵ� ������ ��� NULL�� ����� �� )

    // (void*) realloc (void* _Block, size_t size)
    //  : �̹� �Ҵ��� ������ ������ �ּҰ��� _block�ϰ�, ���Ҵ� �� ������ ũ�⸦ size�� �Է� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)
    if ( (buffer = realloc(buffer, (sizeof(long) * 2000) ) ) == NULL) { // buffer�� �Ҵ��� �޸𸮸� block�ϰ�, long�� �ش��ϴ� ��ŭ�� �޸𸮸� 2000�� �����ؼ� ���Ҵ��� ��, �� �Ҵ翡 ���������� ����
        free(oldbuffer);    // �Ҵ� ���� : ������ �Ҵ���� �޸� �Ҹ�
        exit(1);            // ���� ����
    }

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    size = _msize(buffer);  // �Ҵ翡 ����������, �� �޸� ũ�⸦ size��� ������ ����

    printf(" (long x 2000) �޸� ralloc ���� �Ҵ� : %lld\n", size);

    free(buffer);

    return 0;
}
