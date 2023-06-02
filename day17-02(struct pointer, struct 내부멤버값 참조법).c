// (�߿�!) 
// ����ü(struct)�� �����͸� ��밡��
//	-> ����ü�� �ּҰ� �� ������(���� ����)�� ������

//   # ����ü ������ ����� �� ���� 
//      : struct ����ü��* ������ ������;
//         -> (�߿�!) struct�� ���κ����μ� ��밡��

//   # �����͸� ���� ����ü(struct)�� ������� ���� �����ϴ� 3���� ���
//      1. struct�����ͺ����� -> ���������       <- ����ü������ ��밡���� ������ ������ ��ȣ
//      2. struct������.���������
//      3. (*struct�����ͺ�����).���������       <- ������(���� ��� ���� ������)�� �̿�

//      ex) struct person {
//             int no;
//             char name[20];
//             int score;
//             int rank;
//          };

//          struct person per1;                   <- ����ü ���� ����
//          struct person* pt;                    <- ����ü �����ͺ��� ����
//          pt = &per1;                           <- ����ü �����ͺ��� pt�� per1�� �ּ� �Ҵ�

//          pt->name;                             <- 1. �����ͺ����� -> ��������� ��� ����
//          (*pt).name;                           <- 2. (*�����ͺ�����).��������� ��� ����
//          per1.name;                            <- 3. ����ü������.��������� ��� ����

//          (���!) pt -> name; == (*pt).name == per1.name		<- 1,2,3�� ������� �����ϸ� �Ȱ��� ������� name�� ���� ���� ����

#include <stdio.h>
typedef struct score {
	int kor, eng, mat, sum;
}SCO;

// ����ü�� ��������� �������ϱ� ����
int main() {

	// {��1, ��2 ...} : ����ü ���� ��, �� �Ҵ��ϴ� ���
	SCO st = { 100, 100, 100 };		
	SCO* p;

	// ����ü �����ͺ��� pt�� per1�� �ּ� �Ҵ�
	p = &st;			

	printf("%d %d %d %d\n", st.kor, st.eng, st.mat, st.sum);
	printf("%d %d %d %d\n", st.kor, st.eng, st.mat, st.kor + st.eng + st.mat);                  // sum == 0
	printf("%d %d %d %d\n", p->kor, p->eng, p->mat, p->kor + p->eng + p->mat);                  // sum == 0
	printf("%d %d %d %d\n", (*p).kor, (*p).eng, (*p).mat, (*p).kor + (*p).eng + (*p).mat);      // sum == 0
	printf("%d %d %d %d\n", st.kor, st.eng, st.mat, st.sum);

	p->sum = p->kor + p->eng + p->mat;                                                          // sum == 300

	printf("1. sum = %d\n", st.sum);
	printf("2. sum = %d\n", p->sum);
	printf("3. sum = %d\n", (*p).sum);

	return 0;
}
