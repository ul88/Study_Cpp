#include<iostream>
using namespace std;

/*
-일반 멤버 변수 초기화-
직접 초기화 : 초기화 목록을 이용하여 초기화하는 것
복사 초기화 : 대입 연산을 이용해서 초기화하는 것
복사 초기화는 대입 연산을 이용하므로 데이터가 복사되어 들어간다.
따라서, 메모리 공간이 추가로 필요하므로 성능에 미세한 차이가 생긴다.
일반 변수는 큰 차이가 없지만, 클래스 변수는 직접 초기화와 복사 초기화 사이에 차이가 존재한다.

-레퍼런스 멤버 변수와 상수 멤버 변수 초기화-
레퍼런스 변수와 상수 변수는 선언과 동시에 값이 정해져야한다.
따라서, 클래스의 멤버로 선언한 레퍼런스 변수와 상수 변수는 생성자에서
초기화 목록이나 대입 연산을 통해 반든시 초기화 해야한다.
상수 멤버 변수는 선언과 동시에 값을 지정해도된다.

-정적 멤버 변수 초기화-
클래스 멤버 변수를 static으로 선언하면 해당 클래스로 생성하는 모든 객체에서 참조가 가능하다.
따라서, 클래스에 선언한 정적 변수는 전역 범위에서 초기화해야한다.
정적 멤버 변수는 전역 범위에서 초기화되므로 어떤 클래스에 속한 멤버인지 알 수 있도록
네임스페이스를 추가해야한다.
*/

class character {
public:
	character() {
		cout << "character 클래스 생성자" << endl;
	};
};

class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {
		cout << "monster 클래스 생성자" << endl;
	};
};

class monster_b : private monster, character {
public:
	//초기화 목록에서는 초깃값을 소괄호로 감싼다.
	monster_b(player& attack_target)
		: monster_type("일반"), // 직접 초기화 : 멤버 변수에 값을 직접 대입하는 방법.
		location{ 0,0 }, // 유니폼 초기화 : 배열 형태의 멤버 변수를 초기화하는 방법.
		unique_id(++total_count), // 상수 멤버 변수 초기화 : 상수 멤버 변수는 변경할 수 없으므로 생성자로 초기화해야한다.
		target(attack_target) { // 레퍼런스 멤버 변수 초기화 : 레퍼런스 멤버 변수는 변경할 수 없으므로 생성자에서 초기화해야한다.
		difficult_level = 10; // 복사 초기화 : 정의부에서 멤버 변수에 값을 직접 대입한다.
		quiz = new char[1024]; // 동적 메모리 할당 : 포인터 변수의 메모리는 필요에 따라 생성자에서 초기화 할 수 있다.
		
		cout << "monster_type : " << monster_type << endl;
		cout << "location : " << location[0] << " " << location[1] << endl;
		cout << "unique_id : " << unique_id << endl;
		cout << "difficult_level : " << difficult_level << endl;
		cout << "sizeof(quiz) : " << sizeof(quiz) << endl;
	};
	~monster_b() {
		cout << "소멸자 실행" << endl;

		delete[]quiz;
	};
private:
	string monster_type;
	int location[2];
	static int total_count;
	const int unique_id;
	player& target;
	int difficult_level;
	char* quiz;
};

int monster_b::total_count = 0; //정적 변수 초기화

int main() {

	player player_1;
	monster_b monster(player_1);
	return 0;
}