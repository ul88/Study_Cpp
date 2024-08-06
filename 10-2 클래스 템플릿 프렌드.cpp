#include<iostream>
using namespace std;
/*
	클래스 템플릿도 프렌드 클래스와 함수를 가질 수 있다.

	클래스 템플릿의 프렌드는 인스턴스화 순서와 프렌드 규칙을 준수해야하므로 주의해야할 것이 있다.
*/

template<typename U>
class caller {
public:
	caller() : object(nullptr) {}
	void set_object(U* obj_pointer) { object = obj_pointer; }
	void print_out_frined_object() {
		cout << "(friend 클래스 템플릿 호출) 템플릿 매개변수 값 : "
			<< object->first << endl;
	}
private:
	U* object;
};

template<typename T = int>
class data_package {
public:
	data_package(T first) : first(first) {}
	friend caller<data_package>;
private:
	T first;
};

int main()
{
	caller<data_package<>> caller_int_obj;
	caller<data_package<string>> caller_string_obj;

	data_package<> template_inst1(5);
	data_package<string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

	caller_int_obj.set_object(&template_inst1);
	caller_string_obj.set_object(&template_inst2);
	caller_int_obj.print_out_frined_object();
	caller_string_obj.print_out_frined_object();
	return 0;
}