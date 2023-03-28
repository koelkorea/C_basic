#include <stdio.h>
#include <stdlib.h> //system(), exit()
#include <conio.h>  //_getch()
#include <string.h> //strcmp() : 두 문자열의 위상과 같은지 여부를 비교
#define MAX 3


// 도서 시스템 (모범답안)
//		- strcmp() 함수를 그냥 가져다 씀 
//		    -> 단, 이걸로 검색과 정렬을 둘 다 써서 경제적인 효과 노력
typedef struct _book
{
    int no;                       // 책 일련번호
    char title[30];          // 도서명
    char author[20];     // 작가
    int price;                   // 가격
    int cnt;                      // 수량
    int sale;                    // 매출액(가격 * 수량)
}BOOK;

void input(BOOK* p);  //입력함수
void output(BOOK* p); //출력함수
void sort(BOOK* p);   //정렬함수
void search(BOOK* p); //검색함수

int main() {
    int n;
    BOOK bo[MAX];
    while (1) {//무한루프    for(;;) 무한루프
        system("cls");//화면 지우기
        printf("\n *** 도서관리 메뉴 ***\n\n");
        printf("  1. 입력\n");
        printf("  2. 출력\n");
        printf("  3. 정렬\n");
        printf("  4. 검색\n");
        printf("  5. 종료\n\n");
        printf("  선택 : [ ]\b\b");
        scanf_s("%d", &n);

        switch (n) {
        case 1:
            input(bo);
            break;
        case 2:
            output(bo);
            break;
        case 3:
            sort(bo);
            break;
        case 4:
            search(bo);
            break;
        case 5:
            printf("\n\n\t\t프로그램을 종료합니다.\n");
            exit(0); //프로그램 강제종료
        }//end switch
        printf("\n\n\t\t아무키나 누르면 메뉴로 돌아갑니다.");
        _getch(); //입력함수(에코기능X, Enter필요없음) 대기 목적
    }//end while
    return 0;
}//end main


void input(BOOK* p) {
    for (int i = 0; i < MAX; i++) {
        system("cls");
        printf("\n\n*** 도서 정보 입력 ***\n\n");
        p[i].no = i + 1; //일련번호 자동할당
        printf("[%d번째 입력]\n", p[i].no);
        printf("도서명 : ");
        scanf_s("%s", p[i].title, (int)sizeof(p[i].title));
        printf("작  가 : ");
        scanf_s("%s", p[i].author, (int)sizeof(p[i].author));
        printf("가  격 : ");
        scanf_s("%d", &p[i].price);
        printf("수  량 : ");
        scanf_s("%d", &p[i].cnt);
        p[i].sale = p[i].price * p[i].cnt;   //매출액 = 가격 * 수량
    }
}//end input

void output(BOOK* p) {
    system("cls");
    printf("\n\n\t\t\t *** 도서 정보 출력 ***\n\n");
    printf("%5s %27s %20s %7s %5s %8s\n", "번호", "도서명", "작가", "가격", "수량", "매출액");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < MAX; i++) {
        printf("  %03d %27s %20s %7d %5d %8d\n", p[i].no, p[i].title, p[i].author, p[i].price, p[i].cnt, p[i].sale);
    }
}//end output

void sort(BOOK* p) {
    BOOK temp;
    for (int i = 0; i < MAX - 1; i++) { //순차정렬
        for (int j = i + 1; j < MAX; j++) {//최소값 찾기
            //if( p[i].sale < p[j].sale ) //매출액(내림차순)
            if (strcmp(p[i].title, p[j].title) > 0) { //도서명(오름차순)            
                //구조체 전체 데이터를 바꾸기
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\n\n\t\t도서명 기준 오름차순 정렬 완료~!!\n");
}//end sort


void search(BOOK* p) {
    char str[30];
    int flag = 0; //검색여부 확인변수
    system("cls");
    printf("\n\n검색 도서명 입력 : ");
    scanf_s("%s", str, (int)sizeof(str));
    printf("\n\n\t\t\t*** 도서 검색 정보 출력 ***\n\n");
    printf("%5s %27s %20s %7s %5s %8s\n", "번호", "도서명", "작가", "가격", "수량", "매출액");
    printf(" ---------------------------------------------------------------------------- \n");
    for (int i = 0; i < MAX; i++) {
        if (strcmp(str, p[i].title) == 0) {//도서명이 일치한다면        
            printf("  %03d %27s %20s %7d %5d %8d\n", p[i].no, p[i].title, p[i].author, p[i].price, p[i].cnt, p[i].sale);
            flag = 1; //검색 되었을 때 flag값을 1로 변경
        }
    }//end for
    if (flag == 0) {
        printf("\n\n\t\t검색 도서가 존재하지 않습니다.\n");
    }
}//end search
