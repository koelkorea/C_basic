// 도서관리 프로그램 작성
#include <stdio.h>
#include<windows.h>  // exit(),  sysyem()
#include "day17-12.h"
int main() {

    BOOK books[Max] = {
        {1, "asdasd", "adsads", 12, 12 , 12 * 12},
        {2, "dsadsa", "sdfsdf", 12, 12 , 12 * 12},
        {3, "dfgdfg", "gfdgfd", 12, 12 , 12 * 12},
    };
    int n = 0;

    while (1) {
        system("cls");

        printf("\n *** 도서관리 메뉴 ***\n\n");
        printf("  1. 입력\n");
        printf("  2. 출력\n");
        printf("  3. 정렬\n");
        printf("  4. 검색\n");
        printf("  5. 종료\n\n");
        printf("  선택 : [ ]\b\b");

        scanf_s("%d", &n);
        while (getchar() != '\n');

        switch (n){
            case Input: 
                input(books); 
                break;
            case Output :
                output(books);
                break;
            case Sort:
                sort(books);
                break;
            case Search:
                search(books);
                break;
            case Exit:
                exit(0);         // 강제종료
                break;
            default:; 
        }

        system("pause");
    }
    return 0;
}