#include<iostream>
#include<memory>
using namespace std;
/*
	RAII 디자인 패턴 : Resource Acquisition Is Initialization의 앞 글자를 따서 만든 단어로,
	리소스 할당은 초기화다 라는 의미를 가진다.
	 * 주요 특징 : 동적으로 할당된 메모리가 생성된 범위를 벗어나면 자동으로 해제된다.
	
	unique_ptr : 메모리 관리 객체 또는 래퍼라고 불리며, 참조를 허용하지 않고 하나의 
	포인터 변수만을 허용하는 스마트 포인터이다.

*/

//메모리 누수 코드
//class class_object {
//public:
//	class_object() {
//		cout << "메모리가 할당되었습니다." << endl;
//	};
//	~class_object() {
//		cout << "메모리가 해제되었습니다." << endl;
//	}
//};
//int main()
//{
//	class_object* unique_pointer = new class_object();
//	return 0;
//}

//스마트 포인터 사용
class class_object {
public:
	class_object() {
		cout << "메모리가 할당되었습니다." << endl;
	}
	~class_object() {
		cout << "메모리가 해제되었습니다." << endl;
	}
	void print_out() {
		cout << "객체의 함수를 호출합니다." << endl;
	}
};
int main()
{

	/* unique_ptr<class_object> unique_pointer(new class_object());
		보다 auto와 make_unique를 사용하면 복잡함을 줄일 수 있다.
	*/
	auto unique_pointer = make_unique<class_object>();
	unique_pointer->print_out();
	return 0;
}