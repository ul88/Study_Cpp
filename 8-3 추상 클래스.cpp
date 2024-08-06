#include<iostream>
#include<list>
using namespace std;
/*
	추상 클래스 : 클래스에 순수 가상 함수가 있는 클래스
		추상 클래스와 대비되는 일반 클래스는 구상 클래스라고 한다.

	C++에서 추상 클래스는 일반 클래스와 달리 객체를 직접 생성할 수 없으며,
	추상 클래스를 상속받은 자식 클래스에서 객체를 선언한다.

	자식 클래스에서는 순수 가상 함수를 반드시 오버라이딩해야한다.

	추상 클래스는 객체지향 원칙의 다형성을 구현할 때 사용한다.
	추상 클래스에는 특정 역할을 담당할 함수를 선언만 해놓고, 여러 자식 클래스에서
	각기 다른 알고리즘으로 동작하도록 정의할 수 있다.
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
	monster() {
		cout << "Monster 부모 클래스 생성자"<<endl;
	}
	virtual ~monster() {
		cout << "Monster 부모 클래스 소멸자" << endl;
	}
	virtual void find_route() = 0;
	virtual void attack_special(player target_plater) = 0;
};

class monster_a : public monster {
public:
	virtual void attack_special(player target_player) override {
		cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
	}
	virtual void find_route() override {
		cout << "깊이 우선 탐색(DFS)" << endl;
	}
};

class monster_b : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "가상 공격 : 데미지 - 0 hp" << endl;
	}
	virtual void find_route() override {
		cout << "너비 우선 탐색(BFS)" << endl;
	}
};

class monster_c : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
	}
	virtual void find_route() override {
		cout << "다익스트라 최단 경로 알고리즘" << endl;
	}
};

void monster_routine(monster* mon, player target_plater) {
	mon->find_route();
	mon->attack_special(target_plater);
}

int main() {
	list<monster*> mon_list;
	player target_player;
	monster_a first_monster;
	mon_list.push_back(&first_monster);

	monster_b second_monster;
	mon_list.push_back(&second_monster);

	monster_c third_monster;
	mon_list.push_back(&third_monster);

	for (auto item : mon_list) {
		monster_routine(item, target_player);
	}
	return 0;
}