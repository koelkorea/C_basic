// 중첩 구조체
//  : 구조체 자료형을 포함하는 구조체의 재정의 (= 이를 통해 자료관리가 더 쉬워진다.)
//     -> OOP의 클래스 내 타 클래스를 변수로 두는 그런거...


// 서적 관리 시스템의 자료 구조를 통한 중첩 구조의 예시

// 책 정보 구조체
struct book {
	int code;
	struct b_data b_info;		// 서적 구조체 형식을 가짐
	struct p_data p_info;		// 출판 구조체 형식을 가짐
};

//서적
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

//출판
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


// 원시적인 방법... 
//  -> 책 구조체 항목에 모든 정보를 때려넣어버리는 것이다!
//     -> 이렇게 하면, 각 변수의 용도를 햇갈림 + 세부적 변수명 짓기도 곤란 + 책마다 중복되는 내용이 많은 항목의 노가다성 타자... 등등이 문제
//         -> OOP가 등장한 이유
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