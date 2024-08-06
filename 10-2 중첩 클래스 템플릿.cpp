#include<iostream>
using namespace std;
/*
	클래스 내에 중첩된 클래스를 만들 수 있는 것처럼
	클래스 템플릿도 중첩할 수 있다.
		1. 안쪽 클래스를 멤버 변수처럼 사용하는 방법
			멤버 변수이므로 바깥쪽 클래스에서 안쪽 클래스의 멤버 변수를 선언하고
			필요하면 초기화도 진행한다.
		2. 안쪽 클래스를 독립된 객체로 선언해서 사용하는 방법
			주의 : 템플릿으 중첩된 형태이므로 바깥쪽 클래스의 템플릿 매개변수도 모두 입력해야함.
*/

template<typename Type1, typename Type2>
class data_package { // 바깥쪽 클래스
public:
	template <typename Type3>
	class nested_class_data_package { // 안쪽 클래스
	public:
		nested_class_data_package(Type3 data) : nested_class_data(data) {}
		Type3 get_element() { return nested_class_data; }
		Type3 nested_class_data;
	};

	template<typename Type4>
	class nested_class {
	public:
		nested_class(Type4 data) : nested_class_data(data) {}
		void print_out_element() {
			cout << "중첩 클래스 데이터: " << nested_class_data << endl;
		}
	private:
		Type4 nested_class_data;
	};

	data_package(Type1 first, Type2 second) : first(first), second(second),
		internal_data(second) {}

	void print_out_element() {
		cout << "첫 번째 요소: " << first << ", 두 번째 요소: " << second << endl;
		cout << "중첩 클래스 요소: " << internal_data.get_element() << endl;
	}

private:
	Type1 first;
	Type2 second;
	nested_class_data_package<Type2> internal_data;
};

int main()
{
	data_package<string, int> template_inst1("문자열", 10);
	data_package<string, int>::nested_class<int> template_inst2(500);

	cout << "중첩 클래스 첫 번째 범례" << endl;
	template_inst1.print_out_element();

	// 두 번째 범례로 사용한 방식이 일반적인 클래스 템플릿의 활용이다.
	cout << endl << "중첩 클래스 두 번째 범례" << endl;
	template_inst2.print_out_element();
	return 0;
}