#include<iostream>
using namespace std;
/*
얕은 복사 : 동적으로 할당된 멤버 변수는 메모리를 할당하지 않고 대입한 객체의 멤버 변수를 포인터로 참조한다.
깊은 복사 : 메모리의 주소가 아닌 메모리에 저장된 값을 복사하는 것.
*/

class character {
public:
	character() {};
};
class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {};
};

class monster_b : public monster, character {
public:
	monster_b(player& attack_target)
		: monster_type("일반"),
		location{ 0,0 },
		unique_id(++total_count),
		target(attack_target) {
		difficult_level = 10;
		quiz = new char[1024];
	};
	~monster_b() {
		delete[]quiz;
		total_count--;
	};

	monster_b(const monster_b& ref);

	void set_quiz(const char* new_quiz) { strcpy_s(quiz, 1024, new_quiz); };
	void set_type(string type) { monster_type = type; };
	void set_difficult_level(int level) { difficult_level = level; };
	void set_location(int x, int y) { location[0] = x; location[1] = y; };
	char* get_quiz() { return quiz; };
	string get_type() { return monster_type; };
	int get_difficult_level() { return difficult_level; };
	int get_x_location() { return location[0]; };
	int get_y_location() { return location[1]; };
private:
	string monster_type;
	int location[2];
	static int total_count;
	const int unique_id;
	player& target;
	int difficult_level;
	char* quiz;
};

int monster_b::total_count = 0;

monster_b::monster_b(const monster_b& ref) : unique_id(++total_count), target(ref.target) {
	quiz = new char[1024];
	strcpy_s(quiz, strlen(ref.quiz) + 1, ref.quiz);
	monster_type = ref.monster_type;
	difficult_level = ref.difficult_level;
	location[0] = ref.location[0];
	location[1] = ref.location[1];
}

int main()
{
	player first_player;
	monster_b first_mon(first_player);
	first_mon.set_quiz("아침에 네 발, 점심에는 두 발, 저녁에는 두 발인 것은?");
	first_mon.set_difficult_level(100);
	first_mon.set_type("수수께끼 몬스터");
	first_mon.set_location(30, 30);

	monster_b second_mon = first_mon;
	second_mon.set_quiz("문이 두집어 지면 무엇이 될까?");
	second_mon.set_location(45, 50);

	cout << "[" << first_mon.get_x_location() << ", " << first_mon.get_y_location() << "] 첫 번째 몬스터("
		<< first_mon.get_type() << " - " << first_mon.get_difficult_level()
		<< ")가 내는 수수께끼: " << first_mon.get_quiz() << endl;
	cout << "[" << second_mon.get_x_location() << ", " << second_mon.get_y_location() << "] 첫 번째 몬스터("
		<< second_mon.get_type() << " - " << second_mon.get_difficult_level()
		<< ")가 내는 수수께끼: " << second_mon.get_quiz() << endl;
	return 0;
}