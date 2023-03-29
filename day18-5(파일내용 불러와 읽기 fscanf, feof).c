// - file 안의 문자열 입력(읽기), 출력(쓰기) 함수
//    : fopen_s를 통해 파일 스트림 생성을 생성해 준 뒤, 해당 파일 스트림에 사용 가능한 입력(읽기), 출력(쓰기) 함수  
//      -> (중요) 모드 = r, 입력(읽기)함수만 사용가능 <-> 모드 = w, a, 출력(쓰기)함수만 사용가능


//    3. File에서 문자열 전체 저장, 해당 File에서 데이터를 순차적으로 가져오기, 해당 파일의 끝을 찾는 함수

//      # fscanf( file포인터, 문자열… );
//        :  외부 파일에서 서식화된 자료를 입력 받기 위해 사용되는 함수
// 
//          ex) int fscanf(FILE* _Stream, char const* string);
//              -> int fscanf(파일포인터, 문자열…);로 해석

//      # feof( file포인터 );
//        : (feof : File End Of Flag) 파일의 끝에서(EOF) 0이 아닌 값을 리턴 = 파일의 끝이 아니면 0리턴
// 
//          ex) int feof(FILE* _Stream)
//              -> int fscanf(파일포인터, 문자열…);로 해석


// fscanf, feof을 사용하여 day18-5에서 생성한 txt파일 읽기
#include <stdio.h>
#include <stdlib.h>
#define STU_SIZE 20

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
    int i = 0, j;

    printf("\n＊ 파일명 입력 (.txt 확장자 입력!) : ");

    //불러올 txt 파일명 입력해서 받음
    scanf_s("%s", file_name, sizeof(file_name) - 1);         // 문자열을 받는 것이기에 끝을 알리는 NULL문자(\0)이 들어갈 공간인 1만큼을 제외해야 하므로, 공간배분은 file_name의 크기보다 1 작게
    while (getchar() != '\n');

    // file 읽기 모드(r) :  fopen_s 성공 시 0 반환
    if (0 == fopen_s(&fp, file_name, "r")) {

        // feof(파일포인터);
        //  :  파일의 끝에서(EOF) 0이 아닌 값을 리턴 = 파일의 끝이 아니면 0리턴
        //      -> 외부 파일을 읽을 때, 어디가 끝인지를 인지하게하기 위해 사용
        while (!feof(fp)) {

            // fscanf(파일포인터, 문자열…);
            //  :  외부파일(scanf_s를 통해 파일포인터로 들어간 위치에 배정되었음)의 서식화된 자료를 이쪽에 입력 받기 위해 사용되는 함수
            //      -> 외부 파일의 내용을 이쪽 파일의 변수로 넘겨받기 위한 함수를 의미 (단! 외부파일의 내용의 순서는 정해져 있고, 순서를 바꿀수는 없음)
            fscanf_s(fp, "%d %s %d %d %d\n", &sp[i].no, sp[i].name, (int)sizeof(sp[i].name), &sp[i].kor, &sp[i].eng, &sp[i].mat);
            i++;
        }

        // fclose(file 포인터) : 파일 포인터 닫기
        fclose(fp);

    }else {
        printf("File Open Fail\n"); //파일 생성 실패
    }

    printf("\n\n%7s%10s%8s%8s%8s\n", "번호", "이름", "국어", "영어", "수학");
    printf("─────────────────────────────────────────────\n");

    for (j = 0; j < i; j++) {

        printf("%7d%10s%8d%8d%8d\n", sp[j].no, sp[j].name, sp[j].kor, sp[j].eng, sp[j].mat);
    }

    return 0;
}
