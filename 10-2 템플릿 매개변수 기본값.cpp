#include<iostream>
using namespace std;
/*
	C++의 함수는 기본값으로 동작하도록 만들 수 있다.
	즉, 매개변수의 기본값을 정의해 놓으면 함수를 호출할 때 값을 전달하지 않아도 된다.

	템플릿 매개변수도 기본값을 설정해서 사용할 수 있다.
	다만, 템플릿 매개변수는 데이터 형식을 나타내므로, 기본 데이터 형식을 의미한다.
*/

template<typename T = int>
class data_package {
public:
	data_package(T first) : first(first){}
	void print_out_element() {
		cout << "템플릿 매개변수 값 : " << first << endl;
	}
private:
	T first;
};

int main()
{
	data_package<> template_inst1(5);
	data_package<string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

	template_inst1.print_out_element();
	template_inst2.print_out_element();
	return 0;
}