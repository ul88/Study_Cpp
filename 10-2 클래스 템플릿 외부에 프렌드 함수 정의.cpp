#include<iostream>
using namespace std;

template<typename T = int>
class data_package {
public:
	data_package(T first) : first(first) {}
	template<typename C>
	friend void print_out_friend_element(C& data_object);
private:
	T first;
};

template<typename C>
void print_out_friend_element(C& data_object) {
	cout << "(friend 클래스 템플릿 호출) 템플릿 매개변수 값 : "
		<< data_object.first << endl;
}

int main()
{
	data_package<> template_inst1(5);
	data_package<string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

	print_out_friend_element(template_inst1);
	print_out_friend_element(template_inst2);
	return 0;
}