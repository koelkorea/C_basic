// ��ø ����ü
//  : ����ü �ڷ����� �����ϴ� ����ü�� ������ (= �̸� ���� �ڷ������ �� ��������.)
//     -> OOP�� Ŭ���� �� Ÿ Ŭ������ ������ �δ� �׷���...


// ���� ���� �ý����� �ڷ� ������ ���� ��ø ������ ����

// å ���� ����ü
struct book {
	int code;
	struct b_data b_info;		// ���� ����ü ������ ����
	struct p_data p_info;		// ���� ����ü ������ ����
};

//����
struct b_data {
	char genre[20];
	char book_name[20];
	char original[20];
	char author[20];
	char translator[20];
	int price;
	int stock;
	float rank;
};

//����
struct p_data {
	char publisher_name[20];
	int edition;
	int date[3];
	int page;
	char address[20];
	char phone[20];
	char e_mail[20];
	char fax[20];
};


// �������� ���... 
//  -> å ����ü �׸� ��� ������ �����־������ ���̴�!
//     -> �̷��� �ϸ�, �� ������ �뵵�� �ް��� + ������ ������ ���⵵ ��� + å���� �ߺ��Ǵ� ������ ���� �׸��� �밡�ټ� Ÿ��... ����� ����
//         -> OOP�� ������ ����
struct book {
	int code;
	char genre[20];
	char book_name[20];
	char original[20];
	char author[20];
	char translator[20];
	int price;
	int stock;
	float rank;
	char publisher_name[20];
	int edition;
	int date[3];
	int page;
	char address[20];
	char phone[20];
	char e_mail[20];
	char fax[20];
];