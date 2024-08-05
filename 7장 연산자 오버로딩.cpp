#include<iostream>
using namespace std;

/*
클래스에는 얇은 복사를 수행하는 대입 연산자가 기본으로 정의되어 있으며,
필요할 때 복사 생성자를 오버라이딩해서 사용해야한다.
복사 생성자는 매개변수 구성이 같으므로 이미 정의된 함수를 오버라이딩한다.

비슷한 개념으로 객체끼리 더하는 덧셈은 이미 정의된 더하기 연산에서
피연산자를 변경하는 것이다.
즉, int + int, string + string처럼 정의된 더하기 연산에서 int,string 대신에 객체를 사용하는 것이다.
이것이 바로 연산자 오버로딩이다.

	반환_형식 operator연산자_기호(매개변수)

로 사용한다.
*/

class character {
public:
	character() : hp(100), level(1) {};
protected:
	int hp;
	int level;
};

class player : public character {
public:
	player() {};
	int get_hp() { return hp; }
};

class monster {
public:
	monster() {};
};

class monster_c : public monster, public character {
public:
	void attack_special(player target_player);
	monster_c operator+(monster_c& operand);
	monster_c operator+(player& operand);
	void set_level(int level_value) { level = level_value; }
	void set_hp(int hp_value) { hp = hp_value; }
	int get_level() { return level; }
	int get_hp() { return hp; }
};

monster_c monster_c::operator+(monster_c& operand) {
	monster_c result_monster;
	result_monster.set_level(level + operand.get_level());
	return result_monster;
}

monster_c monster_c::operator+(player& operand) {
	monster_c result_monster;
	result_monster.set_hp(hp + operand.get_hp());
	return result_monster;
}

int main()
{
	monster_c monster_c_obj1, monster_c_obj2;
	monster_c_obj2.set_level(2);
	monster_c new_monster_c_obj = monster_c_obj1 + monster_c_obj2;
	cout << "합체 전 몬스터 C #1 Level[" << monster_c_obj1.get_level()
		<< "], 몬스터 C #2 Level[" << monster_c_obj2.get_level()
		<< "]" << endl;

	cout << "합체 후 몬스터 C Level[" << new_monster_c_obj.get_level()
		<< "]" << endl;

	monster_c monster_c_obj3, monster_c_obj4;
	monster_c_obj4.set_level(2);
	player player1;

	new_monster_c_obj = monster_c_obj1 + monster_c_obj2;

	cout << "Player 합체 전 몬스터 C HP[" << new_monster_c_obj.get_hp() << "]" << endl;

	new_monster_c_obj = new_monster_c_obj + player1;
	
	cout << "Player 합체 후 몬스터 C HP[" << new_monster_c_obj.get_hp() << "]" << endl;
	return 0;
}