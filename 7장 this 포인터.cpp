#include<iostream>
using namespace std;
/*
this : 객체 내부에서 객체 자신을 가리키는 키워드
*/

class bank {
private:
	int safe;
	string bank_name;
public:
	bank(string name) : bank_name(name) { safe = 0; }
	~bank() {}
	int get_safe() { return safe; };
	void use_counter(int _in, int _out);
	void transfer_account(int safe);
	void reset_account();
};

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;
	cout << bank_name << " 처리 - 입금: " << _in << ", 출금: " << _out << endl;
}

/* 위 함수가 컴파일을 하면 아래와 같은 코드로 바뀐다.
void bank::use_counter(bank *const this, int _in, int _out){
	this->safe += _in;
	this->safe -= _out;
}
*/

void bank::transfer_account(int safe) {
	this->safe = safe;
	cout << bank_name << "로 계좌 이동: " << safe << endl;
}

void bank::reset_account() {
	safe = 0;
	cout << bank_name << " 계좌가 초기화 되었습니다.";
}

int main()
{
	bank rich_bank("부유한 은행"), global_bank("세계적 은행");
	rich_bank.use_counter(50, 10);
	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();
	return 0;
}