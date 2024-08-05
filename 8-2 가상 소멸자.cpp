#include<iostream>
using namespace std;
/*
	생성자는 부모 -> 자식 순으로 호출되고
	소멸자는 자식 -> 부모 순으로 호출된다.

	그러나 부모클래스로 업캐스팅한 후 보면,
	생성자는 제대로 부모 -> 자식 순으로 호출되지만,
	자식 클래스의 소멸자는 호출되지 않는다.
	이렇게 되면 자식 클래스에 있는 소멸자가 실행되지 않으므로, 코드에 따라서
	메모리 누수가 발생할 수 있다.

	가상 소멸자 : 소멸자르 가상 함수로 정의하는 것

	가상 소멸자를 사용하면 업캐스팅된 monster_a의 소멸자가 호출된 후에 상속 구조에 따라
	부모 클래스로 올라가면서 호출된다.
*/

class monster {
public:
	monster() {
		cout << "monster() 생성자 호출" << endl;
		dummy = new int;
	}
	virtual ~monster() {
		cout << "~monster() 소멸자 호출" << endl;
		delete dummy;
	}
private:
	int* dummy;
};

class monster_a : public monster {
public:
	monster_a() {
		cout << "monster_a() 생성자 호출" << endl;
		dummy_a = new int;
	}
	~monster_a() {
		cout << "~monster_a() 소멸자 호출" << endl;
		delete dummy_a;
	}
private:
	int* dummy_a;
};

int main()
{
	monster* mon = new monster_a();
	delete mon;
	return 0;
}