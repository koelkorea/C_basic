// 자기 참조 구조체
//  : 포인터를 활용해 자기 자신을 가리키는 구조체 (= C언어에서 구조체가 자신의 주소값을 통해 자신의 내부멤버변수에 접근할 수 있는 방법)
//      -> 어찌보면 재귀함수랑 유사한 부분이 존재
   
//   # (주의!) C언어에서는 타언어에서와 다르게, 자기 자신을 멤버변수로 일반적으로는 가질 수 없지만!
//      -> 자기 참조 구조체라는 구조체 스스로의 포인터 변수 형식으로 멤버변수를 넣음으로서, 자신의 주소값을 넣고 이를 활용하는 것은 가능하다!


// 자기 참조 구조체를 통한 linked list의 구현 에시
#include <stdio.h>

//struct list {
//    int data;
//    struct list next;                    <- c언어에서는 구조체가 자기 자신을 내부에 정의 불가
//};

struct list {
  int data;
  struct list* next;                       // (중요!) 하지만 해당 구조체의 포인터변수를 통해, 내부에 자기 참조 구조체를 넣으면, 자기 자신의 중첩이 가능하다
};

int main() {
    struct list list1, list2, list3, list4;
    struct list* head = &list1;            // 구조체 list 변수 head는 구조체 list의 주소를 참조

    list1.data = 111111;  
    list2.data = 222222;
    list3.data = 333333;  
    list4.data = 444444;
    
    list1.next = &list2;  
    list2.next = &list3; 
    list3.next = &list4;  
    list4.next = &list1;

    // 포인터변수 head가 일단 존재하면, 계속 무한루프해라.. 
    while (head) {
        printf("%d\n", head->data);
        head = head->next;          // (중요) head에 대입된 list 포인터의 값이 초기값(list1의 주소값) -> list2의 주소값으로 변경    -> 다음 while에서 head는 list2의 값 역참조
    }

    return 0;
}
