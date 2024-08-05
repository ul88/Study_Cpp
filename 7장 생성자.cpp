#include<iostream>
using namespace std;

/*
생성자 : 객체가 생성된 직후에 자동으로 호출되는 함수
		클래스_이름() 으로 선언한다.
*/

class character {
public:
	character() {
		cout << "character 클래스 생성자" << endl;
	};
};

class monster {
public:
	monster() {
		cout << "monster 클래스 생성자" << endl;
	};
};

class monster_a : public monster, character {
public:
	monster_a() : monster_a(10,10) { // 다음과 같이 초기화 목록에 다른 생성자 호출이 가능하다. (C++11부터)
		cout << "monster_a 클래스 생성자" << endl;
	};

	monster_a(int x, int y) : location{ x,y } { 
		// : 뒤는 초기화 목록이라고 하며, 매개변수로 전달받은 값으로 변수를 초기화한다.
		cout << "monster_a 클래스 생성자 (매개변수 추가)" << endl;
	};

	void show_location() {
		cout << "위치(" << location[0] << ", " << location[1] << ")" << endl;
	};
private:
	int location[2];
};

int main() {
	character player;

	//상속 클래스의 생성자 호출 순서는
	//상속받은 순서대로 monster -> character 순으로 호출되고
	//마지막으로 자식의 생성자가 호출된다.
	//즉, monster -> character -> monster_a 순이다.
	monster_a forest_monster;
	forest_monster.show_location();

	monster_a wood_monster(10, 25);
	wood_monster.show_location();
	return 0;
}