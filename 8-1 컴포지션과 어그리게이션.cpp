#include<iostream>
using namespace std;
/*
	is-a 관계 : 몬스터가 가져야할 기본 속성과 동작을 상속받아서 
	새로운 몬스터를 만들고 해당 몬스터에만 특화된 내용을 정의하는 것과 같은 관계로,
	자식 클래스는 언제든 부모 클래스를 대체할 수 있다.
	
	다중 상속의 단점 : 
		1. 클래스가 커진다.
			*개발자가 지양해야할 문제
			클래스가 커지면 그만큼 속성과 기능이 많아지므로 사용이 어렵기 때문
			또한, 부모 클래스 중 일부가 변경되면 상속받은 모든 클래스를 
			다시 컴파일해야한다.
			상속이나 사용 관계로 서로 의존도가 높아지면 결합도가 높다고 말한다.
			소스 코드는 결합도가 낮을수록 유지보수에 수월하다.
			이런 거대 클래스는 결합도가 높아지므로 지양해야한다.

		2. 컴파일 시간 증가
			클래스 파일이 수십개라면 몇 분 안에 컴파일이 끝나지만,
			오픈소스처럼 클래스 파일이 수만 개라면 몇 시간이 걸릴 수도 있다.
			만약 변화의 범위가 적다면, 반복 컴파일을 하며 개발해도 문제가 없지만,
			상속 관계가 복잡하고 다중 상속이 복잡하게 엉켜있으면 
			컴파일에 많은 시간이 소요되어 개발에 부담이 될 수 있다.

	다중 상속의 대안점:
		재사용할 속성과 기능을 별도의 클래스로 분리하고
		이 클래스를 멤버 변수로 포함하는 것으로, 다중 상속을 피한다.

		클래스를 분리하여 포함하는 방식으로는
		'컴포지션'과 '어그리게이션'이 존재한다.

		컴포지셔은 분리한 클래스를 포함(part-of)하는 개념이고,
		어그리게이션은 사용(has-a)하는 개념이다.

	생명 주기 : 객체가 생성되어 소멸하는 과정을 의미
	생명 주기가 같다 : 다른 객체가 생성될 때 함께 생성되거나,
	다른 객체에 의해서 생성되거나,
	다른 객체에 의해서 소멸되는 경우를 말한다.

	*이 생명주기가 같은 것이 컴포지션과 어그리에이션을 구별하는 첫번째 기준이 된다.
	 
	
	컴포지션(part-of) : 클래스를 상속받는 것이 아니라 멤버 변수로 포함하는 개념
		생명주기가 동일하다.
		자식 클래스가 부모 클래스를 완전히 대체할 수 있는 다형성 구현에도
		상속보다 컴포지션이 유리

	어그리게이션(has-a) : 컴포지션과 비슷하지만, 
	어그리게이션은 객체를 포인터나 레퍼런스 변수로 포함한다.
		따라서 분리된 클래스와 이를 포함하는 클래스의 생명주기가 다르다.
			* 레퍼런스 변수로 사용한다면 반드시 생성자에서 초기화해야한다.
		컴포지션과 달리 분리된 클래스가 이를 사용하는 클래스와 유연한 관계를 가진다.
		리스코프 치환 원칙에 따라서 분리된 클래스를 직접 참조할 수도 있고,
		해당 클래스를 상속받은 자식 클래스를 차조할 수도 있다.


*/
class character {
public:
	character() : hp(100), power(100) {};
protected:
	int hp;
	int power;
};

class player {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	virtual void attack(player target_player) {
		cout << " 공격 : 데미지 - 10hp" << endl;
	}
};

class monster_2nd_gen : public monster {
public:
	virtual void attack(player target_plaer) override {
		cout << " 새로운 공격 : 데미지 - 30 hp" << endl;
	}
};

class monster_a { // 컴포지션
public:
	void attack(player target_player) {
		main_role.attack(target_player);
	}
private:
	character main_body;
	monster main_role;
};

class monster_b { // 어그리게이션
public:
	monster_b(character& ref_character, monster& ref_monster)
		: main_body(ref_character), main_role(ref_monster) {};
	void attack(player target_player) {
		main_role.attack(target_player);
	}
private:
	character& main_body;
	monster& main_role;
};

int main()
{
	player player_1;
	character character_obj;
	monster monster_obj;
	monster_2nd_gen monster_new_obj;

	monster_a forest_monster;

	monster_b tutorial_monster(character_obj, monster_obj);
	monster_b urban_monster(character_obj, monster_new_obj);

	cout << "몬스터 A 공격" << endl;
	forest_monster.attack(player_1);

	cout << endl << "몬스터 B 공격" << endl;
	tutorial_monster.attack(player_1);
	urban_monster.attack(player_1);

	return 0;
}