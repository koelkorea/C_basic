// - file 안의 문자열 입력(읽기), 출력(쓰기) 함수
//    : fopen_s를 통해 파일 스트림 생성을 생성해 준 뒤, 해당 파일 스트림에 사용 가능한 입력(읽기), 출력(쓰기) 함수  
//      -> (중요) 모드 = r, 입력(읽기)함수만 사용가능 <-> 모드 = w, a, 출력(쓰기)함수만 사용가능

//  1. File에서 '단일문자' 입력(읽기), 출력(쓰기) 함수

//      # (단일문자 출력(쓰기) 함수)
//        fputc(정수변수, 파일포인터 (=파일스트림) )
//			    : 대상 File에 단일 문자를 출력(쓰기)하여 반환 (= 모드가 r에서만 사용가능) 
//			      (쓰기 에러 발생시 EOF(-1) 반환)
//			        ex) int fputc(int c, FILE* stream);
//                    -> fputc(정수변수, 파일스트림);로 해석

//      # (단일문자 입력(읽기) 함수)
//        fgetc(정수변수, 파일포인터 (=파일스트림) )
//			     : 대상 File에서 단일 문자를 순차적으로 읽고, 그 문자를 반환 (= 모드가 w, a에서만 사용가능) 
//			       (파일의 끝을 만나거나, 읽기 에러 발생시 EOF(-1) 반환)
//			         ex) int fputc(int c, FILE* stream);


// 단일문자 입력(fgetc) 출력(fputc) 함수를 사용, 내가 입력한 텍스트들을 txt 파일로 생성 + 읽기
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>      //_getch()
int main() {

    //file 포인터 선언 & 초기화 (file은 이미 애초부터 struct 형식인데, typedef로 FILE이라는 재정의가 되어 있음)
    FILE* fp = NULL;

    int ch;

    // 1. file 생성모드 : fopen_s 성공 시 0 반환
    if (fopen_s(&fp, "out.txt", "w") == 0) {            // "out.txt" 이라는 파일을 생성해라

        printf("문자 입력(종료:0)\n");

        // 0을 입력하기 직전까지 단일문자 입력하라는 do ~ while
        do {

            ch = _getch();

            printf("입력된 문자 : %c\n", ch);

            // fputc : 스트림에 문자 출력
            fputc(ch, fp);

        } while (ch != '0');

        printf("\n \t 프로그램 종료\n");

        // fclose(file 포인터) : 파일 포인터 닫기
        fclose(fp);


    }
    else {     // 파일 생성 실패 (fopen_s의 결과로 0을 반환하지 못할 시)

        printf("File Open Fail\n");

    }


    // 2. 1에서 생성한 file 읽기 모드 :  fopen_s 성공 시 0 반환
    if (fopen_s(&fp, "out.txt", "r") == 0) {

        printf("파일 내용\n");

        // 텍스트 파일의 끝을 만나면 EOF 값을 받기까지 ch를 출력하는 while문
        while ((ch = fgetc(fp)) != EOF) {

            //  \r : 캐리지 리턴 (해당행의 첫째줄로 이동)
            if (ch != '\r') {
                printf("%c", ch);
            }
            else {
                printf("\n");
            }
        }

        // fclose(file 포인터) : 파일 포인터 닫기
        fclose(fp);

    }
    else {      // 파일 생성 실패 (fopen_s의 결과로 0을 반환하지 못할 시)

        printf("File Open Fail\n");
    }

    return 0;

}
