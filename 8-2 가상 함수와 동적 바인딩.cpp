#include<iostream>
using namespace std;
/*
	C++에서 다형성을 구현할 때 멤버 함수 가운데 자식 클래스에서 오버라이딩해야 하는 함수는
	가상함수로 선언해야한다.

	일반 멤버 변수는 업캐스팅된 부모 클래스에 구현된 함수가 호출되지만,
	가상 함수는 자식 클래스에서 오버라이딩한 함수가 호출된다.

	*가상 함수 사용 이유 : 다형성 구현

	리스코프 치환 원칙에 따라 자식 클래스가 부모 클래스를 대체하더라도(업캐스팅) 부모 클래스의
	멤버 함수가 아닌 자식 크래스에 오버라이딩한 함수가 호출돼야 다형성이 구현된다.

	바인딩 : 프로그램을 실행하면 함수 호출이나 변수 참조가 해당 코드와 연결되는 것

	정적 바인딩 : 컴파일할 때 결정되어 프로그램이 실행되는 동안 그대로 유지된다.
		auto 변수 외에는 형식 추론을 하지 않으므로, 일반 변수와 함수, 클래스, 정적 멤버 함수,
		템플릿 등 대부분을 정적으로 바인딩한다.
	동적 바인딩 : 대상이 실행 시점에 결정되며 변경될 수 있다.

	가상 함수 테이블 : 메모리에 _vfptr 이라는 가상 함수 테이블을 가리키는 포인터가 자동으로 생기고,
	객체가 가상 함수를 호출 할 때 _vfptr을 사용한다.

	가상함수 테이블은 클래스의 계층 구조에서 최상위 클래스에만 존재한다.
		자식 클래스는 부모 클래스의 가상 함수 테이블을 상속받으며, 가상 함수를 오버라이딩 할 때
		해당 함수의 주소를 가상 함수 테이블에 등록한다.



*/

class character {
public:
	character() : hp(100), power(100) {}
protected:
	int hp;
	int power;
};

class player : public character {
public:
	player() {}
};

class monster {
public:
	monster() {}
	void get_damage(int _damage) {}
	void attack(player target_player) {}
	virtual void attack_special(player target_player);
};

void monster::attack_special(player target_plater) {
	cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

class monster_a : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "인텡클 공격 : 데미지 - 15 hp" << endl;
	}
};

int main() {
	player player_1;

	monster mother_monster;
	monster_a forest_monster;

	mother_monster.attack_special(player_1);

	monster* mon = &forest_monster;
	cout << endl << "부모 클래스로 업캐스팅 후 공격" << endl;
	mon->attack_special(player_1);

	mon = &mother_monster;
	cout << endl << "부모 클래스로 공격" << endl;
		mon->attack_special(player_1);
}
