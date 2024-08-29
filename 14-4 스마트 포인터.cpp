#include<iostream>
#include<memory>
using namespace std;
/*
	RAII ������ ���� : Resource Acquisition Is Initialization�� �� ���ڸ� ���� ���� �ܾ��,
	���ҽ� �Ҵ��� �ʱ�ȭ�� ��� �ǹ̸� ������.
	 * �ֿ� Ư¡ : �������� �Ҵ�� �޸𸮰� ������ ������ ����� �ڵ����� �����ȴ�.
	
	unique_ptr : �޸� ���� ��ü �Ǵ� ���۶�� �Ҹ���, ������ ������� �ʰ� �ϳ��� 
	������ �������� ����ϴ� ����Ʈ �������̴�.

*/

//�޸� ���� �ڵ�
//class class_object {
//public:
//	class_object() {
//		cout << "�޸𸮰� �Ҵ�Ǿ����ϴ�." << endl;
//	};
//	~class_object() {
//		cout << "�޸𸮰� �����Ǿ����ϴ�." << endl;
//	}
//};
//int main()
//{
//	class_object* unique_pointer = new class_object();
//	return 0;
//}

//����Ʈ ������ ���
class class_object {
public:
	class_object() {
		cout << "�޸𸮰� �Ҵ�Ǿ����ϴ�." << endl;
	}
	~class_object() {
		cout << "�޸𸮰� �����Ǿ����ϴ�." << endl;
	}
	void print_out() {
		cout << "��ü�� �Լ��� ȣ���մϴ�." << endl;
	}
};
int main()
{

	/* unique_ptr<class_object> unique_pointer(new class_object());
		���� auto�� make_unique�� ����ϸ� �������� ���� �� �ִ�.
	*/
	auto unique_pointer = make_unique<class_object>();
	unique_pointer->print_out();
	return 0;
}