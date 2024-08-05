#include<iostream>
#include<list>
using namespace std;
/*
	순수 가상 함수 : 부모 클래스에서는 가상 함수를 선언만 하고 자식 클래스에서 정의하도록
	강제하는 가상 함수
		부모 클래스에서는 동작하지 않지만, 자식 클래스의 기능을 미리 선언하고 싶을 때 사용

	순수 가상 함수 선언
		virtual void attack_special(player_target) = 0;
	
	순수 가상 함수로 선언한 후에는 이 클래스를 상속받는 자식 클래스에서 반드시 정의해야한다.
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
	virtual void attack_special(player target_player) {
		cout << "기본 공격 : 데미지 - 10 hp" << endl;
	}
	virtual void attack_at_dawn() = 0;
};

class monster_a : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
	}
	virtual void attack_at_dawn() override {
		cout << "동쪽에서 기습!" << endl;
	}
};

class monster_b : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "가상 공격 : 데미지 - 0 hp" << endl;
	}
	virtual void attack_at_dawn() override {
		cout << "적진에 조용히 침투하여 방화!" << endl;
	}
};

class monster_c : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
	}
	virtual void attack_at_dawn() override {
		cout << "남쪽에서 적진을 향해 대포 발사!" << endl;
	}
};

int main() {
	list<monster*> mon_list;

	monster_a first_monster;
	mon_list.push_back(&first_monster);

	monster_b second_monster;
	mon_list.push_back(&second_monster);

	monster_c third_monster;
	mon_list.push_back(&third_monster);

	for (auto item : mon_list) {
		item->attack_at_dawn();
	}
	return 0;
}