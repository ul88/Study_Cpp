#include<iostream>
using namespace std;
/*
소멸자 : 생성자와 반대 역할을 하며, 소멸자는 객체가 소멸할 때 실행된다.
소멸자에서는 객체가 소멸할 때 필요한 메모리 해제나 외부 환경을 객체 생성 이전 상태로
변경하는 등의 일을 진행한다.
*/

class character {
public:
	character() {
		cout << "character 클래스 생성자" << endl;
	}
	virtual ~character() {
		cout << "charactor 클래스 소멸자" << endl;
	}
};

class monster {
public:
	monster() {
		cout << "monster 클래스 생성자" << endl;
	}
	virtual ~monster() {
		cout << "monster 클래스 소멸자" << endl;
	}
};

class monster_a : public monster, character {
public:
	monster_a() {
		cout << "monster_a 클래스 생성자" << endl;
	}
	virtual ~monster_a() {
		cout << "monster_a 클래스 소멸자" << endl;
	}
};

int main()
{
	// 소멸자의 호출 순서는 생성자의 역순이다.
	//monster_a forest_monster;

	//리스코프 치환 원칙 적용
	monster* forest_monster = new monster_a();
	/*
	소멸자에 virtual을 붙이지 않을 시, monster 클래스에 해당하는 소멸자만 실행된다.
	소멸자에 virtual을 붙일 시, monster_a forest_monster을 실행했을 때와 똑같이, 모든 소멸자가 실행된다.
	*/
	delete forest_monster;
	return 0;
}