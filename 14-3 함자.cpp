#include<iostream>
using namespace std;
/*
	���� : �Լ� ��ü
	�Լ� ��ü : �Լ�ó�� ȣ���� �� �ִ� ��ü

	����ü���� ���ڸ� �����Ϸ��� �Լ� ȣ�� ������ operator()�� �����ε��Ѵ�.
	�׷��� ����ü ��ü�� ������ �� ��ü ��ü�� �Լ�ó�� ����� �� �ִ�.
	���ڴ� ������ �����ε����� �����ϹǷ� ����ü�� �ƴ϶� Ŭ���������� ����� �� �ִ�.
*/

struct bomb {
	void operator()() {
		cout << "��!" << endl;
	}
	void operator()(int range) {
		cout << "�ݰ� " << range << "m �� �÷��̾� ����!" << endl;
	}
};
int main()
{
	bomb mine;
	mine();
	mine(30);
	return 0;
}