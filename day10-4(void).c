#include <stdio.h>

//   # void 지료형
//     : return이 존재하지 않는 자료형 (코드까보면 존재는 하지만, 보이지 않게 조치했을거라 생각함)
//        -> 보통 return 값이 필요없이 필요한 작업을 반복수행하게 하거나, parameter의 값을 call by reference 형식으로 가져와 직접연산 과정을 순차적으로 수행할 필요가 있을때 사용하기에..
//            -> void 자료형 함수는 해당 함수의 용도를 암시한다고 볼 수 있음

//   # 함수 선언부 ()안의 void
//     : parameter가 없음을 의미 (참고 : 파라미터 void는 생략이 가능하다)
//        -> void voidFunction(void); = void voidFunction();

// void 자료형과 선언부의 void
void display_menu(void) {

	printf("[단위변환 프로그램]\n");
	printf("1. inch <-> cm\n");
	printf("2. cm <-> inch\n");
	printf("3. °F <-> °C\n");
	printf("4. °C <-> °F\n");
	printf("5. 끝내기 \n");
	printf("메뉴를 선택해주세요\n");
}

int main() {

	display_menu();
	return 0;
}