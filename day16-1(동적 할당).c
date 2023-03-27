// 동적 할당
//		: 메모리 영역 할당 후, 필요가 없을 시 이를 그 영역 부여를 해제하는 것

// # 동적할당의 필요성
//		: 한정된 자원 메모리를 효율적으로 사용하기 위한 방법 (필요할 때만 배분, 끝나면 회수)
//			-> 필요없는 메모리가 회수되지 않는다면? 이건 메모리 누수의 원인이 됨

// # 동적 할당 관련 함수
// 1.  (void*)malloc(size_t s)
//		: s byte에 해당하는 만큼의 메모리 영역을 할당하는 함수  (성공 : 메모리 시작주소 반환 , 실패 : NULL 반환)
//			-> 보통 사용할 때는 대상이 될 포인터변수의 자료형과 일치시키는 형변화를 하는게 좋음
 
// 2. (void) free(void* p); 
//		: 포인터 변수 p가 가리키는 메모리 영역을 해제하는 함수
//			-> 메모리 누수 대비

// ex) 배열의 포인터	(  (int*)malloc(sizeof(int) * n)  =  int score1[n] )		<- 이런 의미지 같다는 말은 아님..
//			 int* score1;
//			 score1 = (int*)malloc(sizeof(int) * n);			<-		시작 주소(void *)를 정수형 포인터(int *)로 형변환 후 score 대입	
//																								(sizeof(int) * n byte의 메모리를 할당, 메모리의 시작 주소(void *)를 반환)
//			free(score1);				<- score1이 가리키는 메모리 해제

//	ex) 포인터 배열의 포인터 ( (int**)malloc(sizeof(int*) * n) =  int* score2[n])
//			int** score2;
//			score2 = (int**)malloc(sizeof(int*) * n);
//			free(score2);				<- score2가 가리키는 메모리 해제
