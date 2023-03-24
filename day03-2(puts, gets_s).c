#include <stdio.h>		
#include <conio.h>

int main() {

	char GetName[20], Sname[20];

	// puts("내용") : 표준 출력 스트림인 키보드로부터 문자열을 출력받음
	//		-> printf("내용") 과 비슷하지만, 문자열만 출력 (printf()가 상위호환)

	// gets("내용") :  
	//		-> scanf("내용") 과 비슷하지만, enter키( \n )가 나오기 전까지의 모든 값을 입력받음
	//			ex) Lee Seung Ho 입력시... 
	//					- gets("Lee Seung Ho") : Lee Seung Ho
	//					- scanf("Lee Seung Ho") : Lee
	puts("영문 이름을 입력하세요.");		
	puts("gets_s : ");
	gets_s(GetName, sizeof(GetName));
	printf("이름은 : %s 입니다. \n", GetName);
	puts(GetName);

	puts("scanf_s : ");
	scanf_s("%s", Sname, (int)sizeof(Sname));
	printf("이름은 : %s 입니다. \n", Sname);
	puts(Sname);

	return 0; 

}