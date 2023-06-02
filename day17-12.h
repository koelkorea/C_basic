#pragma once
#include <stdio.h>
#include<windows.h>  // exit(),  sysyem()
#define Max 10
typedef struct _book
{
    int no;          // 책 일련번호
    char title[30];  // 도서명
    char author[20]; // 작가
    int price;       // 가격
    int cnt;         // 수량
    int sale;        // 매출액(가격 * 수량)
}BOOK;

enum input { Input = 1, Output, Sort, Search, Exit };

// strchr() : 두 개의 문자열을 아스키 코드 값으로 비교 (2문자열의 각 자리수를 비교하다가 판정이 나오면 리턴값 주기)
//  - str1 < str2 인 경우 - 1 반환
//  - str1 > str2 인 경우 1 반환
//  - str1 == str2 인 경우 0 반환 <- 최종
int str_cmp(char* str1, char* str2) {

    int n1 = 0;
    int n2 = 0;
    int n = 0;
    int result = 0;

    char* sx1 = str1;
    char* sx2 = str2;

    // 문자열1의 길이 구하기
    while (*str1) {
        n1++;
        str1 = str1 + 1;
    }

    // 문자열1의 길이 구하기
    while (*str2) {
        n2++;
        str2 = str2 + 1;
    }

    str1 = sx1;
    str2 = sx2;

    if (n1 != n2) {

        if (n1 > n2) {
            n = n1;
        }
        else if (n1 < n2) {
            n = n2;
        }
    }
    else {

        n = n1;
    }

    // printf("%d\n", n);

    for (int i = 0; i < n; i++) {

        if (*(str1 + i) > *(str2 + i)) {
            result = 1;
            break;

        }
        else if (*(str1 + i) < *(str2 + i)) {
            result = -1;
            break;
        }

    }

    return result;
}

// str_len(문자열 주소) : 해당 문자열의 길이 반환
int str_len(char* p) {

    int n = 0;           // 현재 문자열 길이을 나타냄
    while (*p++)n++;     // 현재 참고하는 문자열 주소 위치의 값을 역참조한 값이 null이 아니면? 숫자를 1개씩 올린다.    -> 이걸 문자열이 null이 나와 끝날때까지 계속하면, 문자열 길이 체크 가능
    return n;
}

//1. 구조체 데이터 입력함수
void input(BOOK* p) {

    int num = 0;

    printf("도서를 몇 권 등록하시겠습니까?  : ");
    scanf_s("%d", &num);

    for (int n = 0; n < num; n++) {

        p[n].no = n + 1;
        printf("일련번호  : %d\n", p[n].no);

        printf("도서명을 입력해주세요  : ");
        scanf_s("%s", p[n].title, (int)sizeof(p[n].title));
        while (getchar() != '\n');

        printf("작가명을 입력해주세요  : ");
        scanf_s("%s", p[n].author, (int)sizeof(p[n].author));
        while (getchar() != '\n');

        printf("가격을 입력해주세요  : ");
        scanf_s("%d", &p[n].price);
        while (getchar() != '\n');

        printf("수량을 입력해주세요  : ");
        scanf_s("%d", &p[n].cnt);
        while (getchar() != '\n');

        p[n].sale = p[n].price * p[n].cnt;
        printf("매출액  : %d\n\n", p[n].sale);
    }

}

//2. 출력함수
void output(BOOK* p) {

    int n = 0;

    while (p[n].no != 0) {

        printf("일련번호  : %d \n", p[n].no);
        printf("도서명  : %s \n", p[n].title);
        printf("작가명  : %s \n", p[n].author);
        printf("가격  : %d \n", p[n].price);
        printf("수량  : %d \n", p[n].cnt);
        printf("매출액  : %d \n\n", p[n].sale);

        n++;
    }

}

//3. 작가명 a ~ z 정렬함수
void sort(BOOK* p) {

    int book_array_length = 0;

    int n = 0;

    while (p[n].no != 0) {
        book_array_length++;
        n++;
    }

    printf("현재 데이터 수  : %d \n\n", book_array_length);


    // 순차정렬 사용 (1~9 순차적 비교후 가장 작거나 큰 값을 가져오고, 2~9 이런식으로 같은 방식)
    for (int i = 0; i < book_array_length; i++) {

        for (int j = i + 1; j < book_array_length; j++) {

            BOOK temp;

            if (str_cmp(p[i].title, p[j].title) == 1) {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

            }
        }
    }

}

//4. 책이름 검색함수
void search(BOOK* p) {

    char search_word[30];         // 도서명 검색

    printf("검색어를 입력해주세요  : ");
    scanf_s("%s", search_word, (int)sizeof(search_word));
    while (getchar() != '\n');

    int search_length = str_len(search_word);
    printf("검색어 길이  : %d\n\n", search_length);

    printf("---------------------------------[검색 결과]--------------------------------------------------\n\n");

    int n = 0;

    while (p[n].no != 0) {

        int title_length = str_len(p[n].title);
        //printf("일련번호 %d번 검색어 길이  : %d\n\n", p[n].no, title_length);

        for (int i = 0; i < title_length - search_length; i++) {

            int flag = 0;

            for (int j = 0; j < search_length; j++) {

                if (p[n].title[i + j] == search_word[j]) {
                    flag++;
                }
            }

            if (flag == search_length) {

                printf("일련번호  : %d \n", p[n].no);
                printf("도서명  : %s \n", p[n].title);
                printf("작가명  : %s \n", p[n].author);
                printf("가격  : %d \n", p[n].price);
                printf("수량  : %d \n", p[n].cnt);
                printf("매출액  : %d \n\n", p[n].sale);
                break;
            }
        }

        n++;
    }

}