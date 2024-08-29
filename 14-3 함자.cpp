#include<iostream>
using namespace std;
/*
	함자 : 함수 객체
	함수 객체 : 함수처럼 호출할 수 있는 객체

	구조체에서 함자를 정의하려면 함수 호출 연산자 operator()를 오버로딩한다.
	그러면 구조체 객체를 선언한 후 객체 자체를 함수처럼 사용할 수 있다.
	함자는 연산자 오버로딩으로 정의하므로 구조체뿐 아니라 클래스에서도 사용할 수 있다.
*/

struct bomb {
	void operator()() {
		cout << "꽝!" << endl;
	}
	void operator()(int range) {
		cout << "반경 " << range << "m 내 플레이어 공격!" << endl;
	}
};
int main()
{
	bomb mine;
	mine();
	mine(30);
	return 0;
}