#include<iostream>
using namespace std;

/*
상속받은 클래스 : 자식 클래스, 파생 클래스, 하위 클래스
상속해주는 클래스 : 부모 클래스, 기본 클래스, 슈퍼 클래스

함수 시그니처 : 함수의 이름, 매개변수 구성, 반환 형식을 아우르는 용어


자식 클래스는 부모 클래스를 대체할 수 있어야한다.
즉, 부모 클래스를 자식 클래스로 치환할 수 있어야한다.
따라서, 부모가 외부로 노출한 함수의 시그니처를 그대로 상속해야한다.

이 치환해야한다는 말은 부모 클래스의 모든 제약 사항과 동작 방식을 그대로 유지해야한다는 뜻이다.
이를 '리스코프 치환 원칙'이라고 한다.

다중 상속을 진행할 때, 
class monster_a : public monster, character {}; 와 같이 사용하면
monster은 public으로 상속받고, character은 private로 상속 받는다.
즉, 접근지정자를 생략하면 private이다.

*이는 클래스의 성격으로 구조체와 같은 경우는 기본값이 public이다.*

자식 클래스의 오버라이딩된 함수라도 네임스페이스를 이용해 부모 클래스의 함수를 사용할 수 있다.

부모 클래스의 레퍼런스에 사용하거나 자식 클래스의 레퍼런스에 사용하거나
기본적으로는 레퍼런스받는 클래스에 따라가지만, virtual을 붙여 가상 함수로 활용하면
항상 마지막으로 오버라이딩된 함수를 호출한다.

*/

class character {
public:
	character() : hp(100), power(100) {};
protected:
	int hp;
	int power;
};

class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	void attack(player target_player) {};
	virtual void attack_special(player target_player); // 가상 함수 선언
};

void monster::attack_special(player target_player) {
	cout << "기본 공격 : 데미지 - 10hp" << endl;
}

class monster_a : public monster, character {
public:
	void attack_special(player target_player);
};

void monster_a::attack_special(player target_player) {
	cout << "인텡글 공격 : 데미지 -15hp" << endl;
}

class monster_b : public monster, character {
public:
	void attack_special(player target_player);
};

void monster_b::attack_special(player target_player) {
	cout << "가상 공격 : 데미지 -0hp" << endl;
}

class monster_c : public monster, character {
public:
	void attack_special(player target_player);
};

void monster_c::attack_special(player target_player) {
	cout << "강력 뇌전 공격 : 데미지 -100hp" << endl;
}

class monster_d : public monster, character {

};

int main()
{
	player player_1;

	monster basic_monster;
	monster_a forest_monster;
	monster_b tutorial_monster;
	monster_c boss_monster;
	monster_d dummy_monster;

	cout << "몬스터 총 공격" << endl;
	basic_monster.attack_special(player_1);
	dummy_monster.attack_special(player_1);
	forest_monster.attack_special(player_1);
	tutorial_monster.attack_special(player_1);
	boss_monster.attack_special(player_1);

	cout << "기본(monster 클래스) 공격" << endl;
	forest_monster.monster::attack_special(player_1);
	tutorial_monster.monster::attack_special(player_1);
	boss_monster.monster::attack_special(player_1);

	monster& mon = forest_monster;
	monster_a& mon_a = forest_monster;

	cout << endl << "부모 클래스 레퍼런스로 공격" << endl;
	mon.attack_special(player_1);
	cout << endl << "자식 클래스 레퍼런스로 공격" << endl;
	mon_a.attack_special(player_1);
	return 0;
}