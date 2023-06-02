// - file 안의 문자열 입력(읽기), 출력(쓰기) 함수
//    : fopen_s를 통해 파일 스트림 생성을 생성해 준 뒤, 해당 파일 스트림에 사용 가능한 입력(읽기), 출력(쓰기) 함수  
//       -> (중요) 모드 = r, 입력(읽기)함수만 사용가능 <-> 모드 = w, a, 출력(쓰기)함수만 사용가능

//    2. File에서 [문자열(1줄)] 입력(읽기), 출력(쓰기) 함수 
//       (= 행 단위로 읽는 경우 주로 사용)

//       # fputs(문자열, 파일포인터 (= 파일스트림) )
//          : 파일로 문자열을 NULL문자(‘\0‘) 이전까지 출력 = 반드시 NULL문자로 finish (= 모드가 r에서만 사용가능) 
//             -> 출력된 마지막 문자 리턴 및 에러 발생시 EOF(-1) 리턴
//             -> 줄바꿈을 위한 개행 문자('\n')도 포함하여 출력
//             
//                ex) int fputs(char const* string, FILE* _Stream);
//                     -> int fputs(문자열, 파일포인터);로 해석

//       # fgets(문자열 변수, 입력 최대 문자수, 파일포인터 (=파일스트림) )
//          : 파일로 문자열을 읽어와 char형 배열에 저장하는 함수 = 개행문자('\n')나 배열의 길이만큼 문자읽음 (= 모드가 w, a에서만 사용가능) 
//             -> 문자열이 저장된 포인터를 리턴, 문자열이 없는 빈 파일은 NULL 리턴
//             -> 문자열보다 배열의 길이가 더 길면 개행문자('\n')까지 배열에 저장
//             
//                ex) char* fgets(char* _Buffer, int _MaxCount, FILE* _Stream);
//                    -> char* fgets(문자열char포인터변수, 입력 최대 문자수, 파일포인터); 로 해석

// 단일문자 입력(fgetc) 출력(fputc) 함수를 사용, 내가 입력한 텍스트들을 txt 파일로 생성 + 읽기
#include <stdio.h>
#include <stdlib.h>
int main() {

    //file 포인터 선언 & 초기화 (file은 이미 애초부터 struct 형식인데, typedef로 FILE이라는 재정의가 되어 있음)
    FILE* fp = NULL;
    
    char str[1024];
    int ch;
    int i = 0;

    // 1. file 생성모드(w) : fopen_s 성공 시 0 반환
    if (fopen_s(&fp, "out2.txt", "w") == 0) {         // "out2.txt" 이라는 파일을 생성해라

        printf("문자열 입력 (종료 : Enter + Ctrl + Z + Enter)\n");

        // 입력된 문자들이 EOF영역이 아닌 한, 계속 진행 while문 진행해서, 문자열 char배열 str에 문자 하나씩 넣고 진행
        while ((ch = getchar()) != EOF) {

            //입력 버퍼의 문자열에서 문자 1개씩 ch에 저장 EOF(Ctrl+Z) 비교 후 루프 실행
            //앞에 다른 문자가 없이 Ctrl + z 키를 누르면 EOF 값 발생
            str[i++] = ch;      // int getchar(void) unsigned char로 받은 문자 ->  int로 변환해서 리턴 (에러시 EOF 리턴)

        }

        //  while 끝난 직후 다음의 str 배열의 주소에는 NULL이 들어감
        str[i] = '\0';

        // (문자열 출력 함수)
        // fputs(문자열, 파일포인터)
        //  : 파일로 문자열을 NULL문자(‘\0‘) 이전까지 출력 = 반드시 NULL문자로 finish or 출력된 마지막 문자 리턴 및 에러 발생시 EOF(-1) 리턴
        fputs(str, fp);

        printf("out2.txt 파일에 저장완료\n");

        // fclose(file 포인터) : 파일 포인터 닫기
        fclose(fp);

        // (결과) out2.txt 파일 출력

    }else {     // 파일 생성 실패 (fopen_s의 결과로 0을 반환하지 못할 시)

        printf("File Open Fail\n");

    } 

    // 2. 1에서 생성한 file 읽기 모드(r) :  fopen_s 성공 시 0 반환
    if (fopen_s(&fp, "out2.txt", "r") == 0) {

        // (문자열 입력 함수) 
        // fgets(문자열 변수, 입력 최대 문자수, 파일포인터)
        //   : 파일로 문자열을 읽어와 char형 배열에 저장하는 함수 = 개행문자('\n')나 배열의 길이만큼 문자읽음 

        // 1행 단위로 str 배열에 문자열에 저장하는 while문 (문자열이 없는 마지막은 NULL 리턴해서  while문 마무리)
        while (fgets(str, 1024, fp) != NULL) {

            printf("%s", str);
        }

        // fclose(file 포인터) : 파일 포인터 닫기
        fclose(fp);

        //(결과) out2.txt 문자열 입력

    }else {      // 파일 생성 실패 (fopen_s의 결과로 0을 반환하지 못할 시)

        printf("File Open Fail\n");
    }

    return 0;
}
