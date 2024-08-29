#include<iostream>
#include<functional>
#include<string>
using namespace std;
/*
	�Լ��� �����ϴ� function ��ü
		function<return_data,_type(param0, param1)> func_name = function;


	Ŭ����, ����ü ��� �Լ��� �����ϴ� function ��ü
		function<return_data_type(object&, param0, param1)> func_name =
		&class|struct::target_method;
*/

void function_pointer(int input) {
	cout << "�Լ� ������ ��� �Լ� : " << input << endl;
}

struct functor {
	void operator()(char functor_prefix){
		cout << "���� : " << functor_prefix << endl;
	}
};

class class_object {
public:
	class_object(string init_string) : class_object_name(init_string) {}

	void std_functoin_call_member(string contents) {
		cout << "Ŭ���� ��� �Լ� ��üȭ(" << class_object_name << ") : "
			<< contents << endl;
	}
private:
	string class_object_name;
};

int main()
{
	class_object class_obj("ȣ�� ��ü�� ������ �ִ� Ŭ����");
	functor functor_obj;

	function<void(int)> func_pointer = function_pointer;
	function<void(functor&, char)> functor_func = &functor::operator();
	function<void(double)> lambda_func =
		[](double input) { cout << "���� �Լ�: " << input << endl; };
	function<void(class_object&, string)> member_func =
		&class_object::std_functoin_call_member;

	func_pointer(10);
	functor_func(functor_obj, 'A');
	lambda_func(0xa8);
	member_func(class_obj, "���");
	return 0;
}