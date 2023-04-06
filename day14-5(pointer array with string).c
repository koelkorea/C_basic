//  - (중요 !!!) c언어에서의 문자열은 그 자체가 char 배열 !!!! 

//   # (주의!) char[] 형식의 문자열(string)은 반드시 그 끝을 알리는 NULL문자(\0)까지 포함해줘야 출력시 정상적으로 인식함

//   # 문자열이 char 배열에 따른 특성들
//      1. char c[] = { C, l,a,n,g,u,a,g,e,!,\0, s,e,c,re,t, s,p,a,c,e } 로 쓰지 않아도 됨 ->  char c[] = "C language!\0 secret space"; 로 OK           <-  \0은 NULL을 의미하는 문자로 문자열 이스케이프 문자

//      2. (제일 중요) 문자열은 배열이라  char c[] = "C language!\0 secret space"; 가 성립
//            -> char * p = c가 성립
//            -> char * p = "C language!\0 secret space" 라고 써도 성립한다는 충격과 공포가 성립

//      3. 2번의 문자열의 배열로서의 성질과 pointer array를 결함하면 다음도 성립 
//            ->	char* q[3] = { "Computer","Programing","Enjoy" }            <- 문자열은 배열이기에 저렇게 적어도 주소를 적은거로 성립이 가능하다

//                  - q[0] =  "Computer\0"          <- 포인터 변수도 배열형식대로 쓰면, *없이도 역참조 모드임 
//                  - q[1] =  "Programing\0"
//                  - q[2] =  "Enjoy\0"

//      (정리)
//      -------------------------------------------------------------------------------------------
//                     메모리 주소	             배열 순서	                    예제 값
//      -------------------------------------------------------------------------------------------
//                         q                     char* q[0]                  "Computer\0"
//                         q + 1                 char* q[1]                  "Programing\0"
//                         q + 2                 char* q[2]                  "Enjoy\0"

#include <stdio.h>
#include <string.h> // strlen() : 문자열 길이 확인 함수
int main()
{
    
    char c[] = "C language!\0 secret space";
    
    // char 포인터변수 p는 문자열 배열 c의 첫번째 문자 주소 저장
    char* p = c;
    
    // char 포인터변수 a는 문자열 배열 "array and pointer"의 첫번째 문자 주소 저장
    char* a = "array and pointer";    
    
    // char 포인터 배열 q는 3만큼의 크기를 가지고, char 포인터변수인 "Computer", "Programing", "Enjoy"의 각 시작점 위치를 저장
    char* q[3] = { "Computer", "Programing", "Enjoy" };
    
    // char 포인터 배열 d는 20만큼을 크기를 가짐
    char* d[20];
    
    int i = 0, k = 0;

    // "C language! 까지만 하나하나 입력 (\0인 NULL이전까지)
    while (*(p + i) != '\0') {
        printf("%c", *(p + i));
        i++;
    }

    printf("\n\n");

    // secret space까지만 하나하나 입력 (포인터변수 p의 값을 직접 조작)
    while (*p != '\0') {
        printf("%s\n", p);
        p++;
    }

    printf("\n\n");

    printf("%c %c \n", *(a + 4), a[4]);
    printf("pointer : %s \n", a);
    printf("  array : ");

    // a의 문자열 array and pointer을 한글자씩 써줌
    for (int i = 0; i < strlen(a); i++) {           // strlen() : 문자열 길이 확인 함수
        printf("%c", a[i]);
    }

    printf("\n\n");

    // "Computer", "Programing", "Enjoy" 출력
    for (int i = 0; i < 3; i++) {
        printf("%s\n", *(q + i) );          // 
    }

    printf("\n\n");

    printf("[문자열 입력 20개]\n");
    
    // scanf_s : scanf의 c++개선 버전으로 문자열 string자료형 구현에 필요한 메모리 동적할당을 위해 반드시 파라미터로 메모리 크기를 할당해줘야 함
    //  -> 앞서 언급한 char 배열 d의 크기인 20만큼에 해당하는 문자열을 입력해서 d에 문자열을 입력해라
    scanf_s("%s", d, (int)sizeof(d));       

    p = d;

    printf("입력된 문자열 %s\n\n", p);
    return 0;
}
