//  - ���� �Ҵ� ���� �Լ�
//     : ������� �޸� ������ �Ҵ�� void* '�ּҰ�'
//       (= ����ȯ�� ���� Ÿ�ڷ��� �����ͺ����� ������ ������)

//       3. (void*) calloc (sizeũ���ڷ���, size_t �޸�byte��) 
//           : _count ���� * _size �޸� ũ�� �� ������ �� �ִ� �޸� ������ �Ҵ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

//            # (�߿�) malloc���� ������
//              1. �Ҵ�� �޸� �� ��� 0���� �ʱ�ȭ
//              2. ������ �Ķ���ͷ� ����, �������� �ø�

//       4. (void) free (void* p); 
//           : void ������ ���� p�� ����Ű�� �ּҰ��� �޸� ���� �Ҵ��� �����ϰ� �����ϴ� �Լ�(�޸� ���� ���)

#include <stdio.h>
#include <stdlib.h>
int main() {

    long* buffer, * oldbuffer;

    // size_t
    //  : c��� �ȿ��� unsigned long long�� ������(= typedef) �� �̸�
    size_t size;

    // (void*) calloc (size_t ����, size_t �޸�ũ��)
    //   : _count ���� * _size �޸� ũ�� �� ������ �� �ִ� �޸� ������ �Ҵ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)
    //      -> long�� �ش��ϴ� ��ŭ�� �޸𸮸� 40�� �����ؼ� �Ҵ��� ��, �� ���� �ּҰ��� ��ȯ + �޸𸮰��� ��θ� 0���� �ʱ�ȭ
    buffer = (long*) calloc(40, sizeof(long));  

    // calloc�� ��� ��
    if (buffer != NULL) {
        printf("sizeof(long) * 40 �޸� �Ҵ� ����!\n");
    }
    else {
        printf("�޸� �Ҵ� ����...\n");
    }

    // �Ҵ���� �޸� �Ҹ�
    free(buffer); 

    // (void*)malloc(size_t s)
    //  : s byte�� �ش��ϴ� ��ŭ�� �޸� ������ �Ҵ��ϴ� �Լ� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

    // long�� �ش��ϴ� ��ŭ�� �޸𸮸� 1000�� �����ؼ� �Ҵ��� ��, �� �Ҵ翡 ���������� ����
    if ( (buffer = (long*) malloc ( sizeof(long) * 1000) ) == NULL) { 
        exit(1);
    }

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    //   -> �Ҵ翡 ����������, �� �޸� ũ�⸦ size��� ������ ����
    size = _msize(buffer);  

    printf(" (long x 1000) �޸� malloc ���� �Ҵ� : %lld\n", size);

    // �޸� �ּ� �� �ӽ� ����, ( ���Ҵ� ������ ��� NULL�� ����� �� )
    oldbuffer = buffer;     

    // (void*) realloc (void* _Block, size_t size)
    //  : �̹� �Ҵ��� ������ ������ �ּҰ��� _block�ϰ�, ���Ҵ� �� ������ ũ�⸦ size�� �Է� (���� : �޸� �����ּ� ��ȯ , ���� : NULL ��ȯ)

    // buffer�� �Ҵ��� �޸𸮸� block�ϰ�, long�� �ش��ϴ� ��ŭ�� �޸𸮸� 2000�� �����ؼ� ���Ҵ��� ��, �� �Ҵ翡 ���������� ����
    if ( (buffer = realloc(buffer, (sizeof(long) * 2000) ) ) == NULL) { 
        free(oldbuffer);    // �Ҵ� ���� : ������ �Ҵ���� �޸� �Ҹ�
        exit(1);            // ���� ����
    }

    // _msize() : �����Ͱ� ����Ű�� �޸� ũ�⸦ ��ȯ�ϴ� �Լ�
    //   -> �Ҵ翡 ����������, �� �޸� ũ�⸦ size��� ������ ����
    size = _msize(buffer);

    printf(" (long x 2000) �޸� ralloc ���� �Ҵ� : %lld\n", size);

    free(buffer);

    return 0;
}
