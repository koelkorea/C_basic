// FILE(구조체)
//  : 파일에 대한 여러 가지 정보를 가진 구조체(struct)
//     -> 입, 출력 함수들은 모두 이 구조체의 내용을 참조 및 수행

// - File 입력(read), 출력(write)이란?
//    : 보조기억장치에 파일(file) 자료를 입력(읽기)하거나, 출력(쓰기)하는 개념
//       -> 입력이라는 말이 ㅈㄴ게 모호할 수 있는데, 그냥 [입력 = 읽기 =  read], [출력 = 저장 = write]라고 받아들이자... 

//     # (주의) 
//        1. 반드시 file 포인터를 선언 후 입력(읽기), 출력(쓰기) 실행(입, 출력 전에 해당 입,출력 함수에게 포인터를 전달)
//        2. 가급적 [출력, 입력] : [쓰기, 읽기] : [저장, 열기] 같은 개념으로 개념에 접근해야 함
//             -> 파일과 연관해서 입력이라는 단어는 굉장히 중의성이 짙음
//                 - write : 데이터를 저장(write)하는 '출력' 개념에서도 '입력'이라는 말이 쓰일 수 있고.. 사람 입장에서는 저장이 데이터를 입력하는 행위라고 하는게 이해가 빠름
//                 - read  : 파일에서 데이터를 읽어들이는 것을 '입력'이라고 함..


// - File 입,출력 모드
//    1. 텍스트 모드
//        : 텍스트 기반의 데이터 처리용도
//           -> 프로그램상에서 파일로 읽고 쓰는 경우, 데이터 변환 이후 입력(읽기), 출력(쓰기)

//    2. 2진 모드
//        : 영상, 사진…등 손실 or 변환이 없어야 하는 경우
//           -> 이 경우 데이터 변환 없이 데이터 입, 출력


// - File Stream (= FILE* = 파일 포인터변수)
//    : 파일을 읽고, 쓰기 위해 '주기억장치 <-> 보조기억장치' 간의 데이터의 흐름이 이어질 수 있는 기능 및 매개체를 추상화한 개념 
//      (= 해당 파일의 내용이 존재하는 주기억장치의 주소값의 영역과 실제 파일이 저장된 보조기억장치의 파일위치를 연결하는 일종의 통로를 의미함) 
//          -> 그리고 파일 입력(read), 출력(write)을 하는 함수 기능을 구현하는데 해당 개념이 사용됨
//             (= 정확히는 읽고 쓸 대상이 되는 파일의 주소값인 파일스트림이 File 입력(read), 출력(write) 함수를 선언할 때 파라미터로 전달됨)


// - file 스트림 생성 및 열기, 닫기
  
//  1. (파일 스트림 생성) fopen_s(file stream 포인터변수 주소값이 존재하는 위치가 저장된 주소값(2중 포인터), 파일명 , 파일모드)
//      : 파일 스트림이 위치하는 '주소값(정확히는 2중포인터를 통한 간접전달)'에 '모드(r,w,a)'에 맞게 스트림을 생성하고 '파일명'에 따른 이름을 붙여줌

//         ex) fopen_s(FILE** str, const char* _filename , const char* _mode);
//              -> fopen_s(file stream 포인터변수 주소값(포인터), 파일명 , 파일모드); 로 해석	
        
//       # File stream 포인터변수 (= FILE** = File pointer의 포인터)
//         : 주기억장치(RAM)에서 해당 파일의 내용이 위치하는 주소값인 File stream의 값이 저장된 메모리 위치의 주소값..
//             -> 포인터 변수인 File stream은 크기를 알 수 없는 파일을 메모리에 할당하기 위해, 파일의 크기에 따른 동적할당의 결과로 그 주소값이 변할수도 있음
//                 -> 따라서 해당 파일의 포인터변수인 File stream 또한 그 주소값을 저장할 File stream의 포인터 변수가 필요하게 되고..
//                     -> 동적할당이 끝나면 File stream의 주소값은 File stream 포인터의 역참조로 file의 주소을 알 수 있게 됨
         
//       # fopen_s(file stream이 위치한 주소값이 저장된 주소값(file stream 포인터), 파일명 , 파일모드) 로직 이해
//          1. 먼저 파일스트림(어떤 파일 내용이 저장될 위치 주소값)이 위치한 주소값을 저장할 수 있는 'file stream 포인터 변수'를 생성함
//             -> '파일명'에 해당하는 파일을 열기 위해서는 먼저 그 내용을 주기억장치(RAM)에 저장해야 하지만..
//                 -> 파일의 크기를 사전에 알지 못함 = 메모리 크기는 동적할당을 하게 됨 = 파일 내용이 저장할 위치가 어딘지는 작업이 끝나봐야 알기 때문
//          2. '파일모드'에 따라 '파일명'에 해당하는 파일을 보조기억장치에서 찾거나 생성한다
//          3. 2번 과정의 결과로 나온 읽거나 생성한 파일을 앞서 생성한 파일스트림의 포인터를 참고하여, 주기억장치에서 파일 내용을 저장하기 위해 할당한 주소값을 역참조하여 찾음
//          4. 3번 과정의 결과로 찾은 File stream의 위치값(해당 file이 저장된 주소값)에 해당 파일 내용을 쓴다
//          5. 모든 과정이 성공적으로 끝나서, 주기억장치(RAM)에 파일스트림이 생성되고, 그 위치에 파일명의 내용이 올라왔으면 0을 반환함
//          6. 이후 모드의 값에 따라 입력(읽기), 출력(쓰기) 함수를 사용할 수 있음
         
//       # 파일모드 일람 : (중요) fopen_s에서 파라미터로 준 모드가 r이면 입력(읽기)함수만 사용가능 <->  fopen_s에서 파라미터로 준 모드가 w, a이면 출력(쓰기)함수만 사용가능
//            r (읽기 전용)       : 파일 불러오기(읽기), 해당 파일 필요
//            w (쓰기 전용)       : 새로 생성, 이름이 같으면 덮어쓰기
//            a (추가 전용)       : 새로 생성, 이름이 같으면 내용 뒤에 추가
//            r+ (갱신용)         : 읽고 쓰기용, 새로 생성, 이름이 같으면 덮어쓰기
//            w+ (갱신용)         : 읽고 쓰기용, 새로 생성, 이름이 같으면 덮어쓰기
//            a+ (갱신용)         : 파일 맨 끝부터 작업이 필요할 경우 사용 새로 생성, 이름이 같으면 데이터 끝부터 추가
         
//       # EOF(End Of File)
//          : C언어에서 운영체제와 상관없이 파일의 끝을 알리는 반환값(-1)을 의미 
//            (키보드를 통한 입력을 받을 때에도 입력의 끝을 알려주는 방법이 필요하기에 존재)
//              -> (중요!) 대부분의 유닉스(UNIX) 시스템에서는 라인의 시작 위치에서 Enter키를 통해 EOF가 발생함(즉 ! 어떠한 문자도 없는 상태에서 EOF발생)
//          
//                  ex) Ctrl + D, Ctrl + Z(console)   =>   ENTER
    
//  2. (파일 스트림 닫기) fclose
//      : 해당하는 FILE 스트림의 주소값의 메모리를 해제 (동시에 버퍼에 남아있는 데이터를 파일로 완전히 출력)
//        ex) fclose(FILE*);
//            -> fopen_s(file stream 주소값(포인터)); 로 해석	
    
//    ex) 파일스트림 생성 + 해제까지 예시
//  
//        FILE* fp = NULL;                                      <- File stream의 포인터 변수가 임시적으로 담을 File의 주소값이 해당 코드의 목적 
//                                                                 (= 어차피 해당 파일의 크기에 따라 메모리 위치도 동적으로 바뀌는 동적할당이 이뤄짐)
//  
//        if (fopen_s(&fp, "out.txt", "w") == 0) {				<- fopen_s 성공하여 out.txt 파일이 주기억장치에 성공적으로 올라오면 0을 반환
//          fclose(fp); 
//        }


// - file 안의 문자열 입력(읽기), 출력(쓰기) 함수
//    : fopen_s를 통해 파일 스트림 생성을 생성해 준 뒤, 해당 파일 스트림에 사용 가능한 입력(읽기), 출력(쓰기) 함수  
//       -> (중요) 모드 = r, 입력(읽기)함수만 사용가능 <-> 모드 = w, a, 출력(쓰기)함수만 사용가능

//    1. File에서 [단일문자] 입력(읽기), 출력(쓰기) 함수
      
//       # fputc(정수변수, 파일포인터 (= 파일스트림) )
//          : 대상 File에 단일 문자를 출력(쓰기)하여 반환 (= 모드가 r에서만 사용가능) 
//             -> 쓰기 에러 발생시 EOF(-1) 반환
         
//                ex) int fputc(int c, FILE* stream);
//                     -> fputc(정수변수, 파일스트림);로 해석
         
//       # fgetc(정수변수, 파일포인터 (= 파일스트림) )
//          : 대상 File에서 단일 문자를 순차적으로 읽고, 그 문자를 반환 (= 모드가 w, a에서만 사용가능) 
//             -> 파일의 끝을 만나거나, 읽기 에러 발생시 EOF(-1) 반환
         
//                ex) int fputc(int c, FILE* stream);
      
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
