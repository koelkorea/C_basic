#include <stdio.h>		

// sizeof(parameter)
//  : 파라미터로 들어온 자료형의 메모리의 크기를 구한다 (byte 단위)
int main() {

	char str[10];

	printf("char = %lu \n", sizeof(("asdfgㅁㄴㅇ")));       // 문자열로 인식 (a라는 문자 뒤에는 null값인 \0가 포함되어 있음  : 12 (11+1)
	printf("char = %lu \n", sizeof(('a')));                 // 숫자로 인식 (여기서는 int에 해당하는게 나오나 운영체제와 환경에 따라 컴퓨터가 인식하는 값이 다를수 있음.. 호환성 생각하면 낮게 생각해봐야함) : 4
	printf("char[10] = %lu \n", sizeof((str)));             // 크기 10인 문자배열의 크기(아직 각 배열주소에 들어간 값이 없음) : 10
	printf("int = %lu \n", sizeof(int));                    // 4
	printf("long = %lu \n", sizeof(long));                  // 4 (운영체제와 환경에 따라 컴퓨터가 인식하는 값이 다를수 있음.. 호환성 생각하면 낮게 생각해봐야함)
	printf("float = %lu \n", sizeof(float));
	printf("double = %lu \n", sizeof(double));
	printf("long double = %lu \n", sizeof(long double));

	return 0;
}