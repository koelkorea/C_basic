// - file 안의 문자열 입력(읽기), 출력(쓰기) 함수
//    : fopen_s를 통해 파일 스트림 생성을 생성해 준 뒤, 해당 파일 스트림에 사용 가능한 입력(읽기), 출력(쓰기) 함수  
//       -> (중요) 모드 = r, 입력(읽기)함수만 사용가능 <-> 모드 = w, a, 출력(쓰기)함수만 사용가능

//    3. File에서 [문자열 전체] 저장, 해당 File에서 데이터를 순차적으로 가져오기, 해당 파일의 끝을 찾는 함수

//       # fprintf( file포인터, 문자열… );
//          : 파일에 서식화된 자료를 기록(save)하기 위해 사용되는 함수 
//            (지정한 file 포인터의 주소값에 해당하는 부분에 문자열을 저장)
//          
//            ex) int fprintf(FILE* _Stream, char const* string);
//                -> int fprintf(파일포인터, 문자열…);로 해석

//       # fscanf( file포인터, 문자열… );
//          : 외부 파일에서 서식화된 자료를 입력 받기 위해 사용되는 함수
//          
//            ex) int fscanf(FILE* _Stream, char const* string);
//                -> int fscanf(파일포인터, 문자열char포인터변수)로 해석

//       # feof( file포인터 );
//          : (feof : File End Of Flag) 파일의 끝에서(EOF) 0이 아닌 값을 리턴 = 파일의 끝이 아니면 0리턴
//          
//            ex) int feof(FILE* _Stream)
//                -> int fscanf(파일포인터, 문자열…);로 해석


// fprintf를 통한 성적입력과 해당 내용을 txt로 저장
#include <stdio.h>
#include <stdlib.h>
#define STU_SIZE 3

typedef struct student {
    int no;
    char name[20];
    int kor, eng, mat;
}STU;

int main() {

    //파일 포인터 선언 & 초기화
    FILE* fp = NULL;

    STU sp[STU_SIZE];

    // 파일명을 받기 위한 char 배열
    char file_name[80];
    int i;

    printf("\n＊ 파일명 입력 (.txt 확장자 입력!) : ");

    // 파일명 입력
    scanf_s("%s", file_name, sizeof(file_name) - 1);        // 문자열을 받는 것이기에 끝을 알리는 NULL문자(\0)이 들어갈 공간인 1만큼을 제외해야 하므로, 공간배분은 file_name의 크기보다 1 작게
    while (getchar() != '\n');

    // 구조체 입력(STU_SIZE 만큼 반복)
    for (i = 0; i < STU_SIZE; i++) {

        sp[i].no = i + 1;    //일련변호
        printf("\n번호 : [%03d]\n", sp[i].no);

        printf("이름 : ");
        scanf_s("%s", sp[i].name, sizeof(sp[i].name) - 1);   // 문자열을 받는 것이기에 끝을 알리는 NULL문자(\0)이 들어갈 공간인 1만큼을 제외해야 하므로, 공간배분은 file_name의 크기보다 1 작게
        while (getchar() != '\n');

        printf("국어 : ");
        scanf_s("%d", &sp[i].kor);

        printf("영어 : ");
        scanf_s("%d", &sp[i].eng);

        printf("수학 : ");
        scanf_s("%d", &sp[i].mat);
        while (getchar() != '\n');
    }

    // file_name의 이름으로 file 생성모드 : fopen_s 성공 시 0 반환
    if (fopen_s(&fp, file_name, "w") == 0) {


        for (i = 0; i < STU_SIZE; i++) {
            // fprintf(파일포인터, 문자열…);
            //  : 파일에 서식화된 자료를 기록(save)하기 위해 사용되는 함수(지정한 file 포인터의 주소위치에 문자열 저장)
            fprintf(fp, "%d %s %d %d %d\n", sp[i].no, sp[i].name, sp[i].kor, sp[i].eng, sp[i].mat);
        }

        printf("\n\n\t\t %s 파일에 입력완료되었습니다...\n", file_name);

        // fclose(file 포인터) : 파일 포인터 닫기
        fclose(fp);

    }else {
        printf("File Open Fail\n"); //파일 생성 실패
    }

    return 0;
}
