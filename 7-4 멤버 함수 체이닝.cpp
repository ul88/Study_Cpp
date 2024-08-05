#include<iostream>
#include<string>
using namespace std;

/*
함수 체이닝 : 여러 함수를 연이어 호출하는 방식
 이러한 스타일은 코드를 간결하게 만들고, 호출 순서를 직관적으로 표현한다.

멤버 함수 체이닝을 구현할 때에는 반환 형식을 레퍼런스로 지정하고
return문에 this포인터를 활용하여 만들 수 있다.

만약 레퍼런스가 아니라 포인터로 지정하면
func1().func2().func3()이 아니라 func1()->func2()->func3()으로 작성해야한다.
*/

class bank {
public:
	bank(string bank_name) : bank_name(bank_name) { safe = 0; }

	string get_bank_name() { return bank_name; }
	int get_safe() { return safe; }

	void use_counter(int _in, int _out);
	void transfer_account(int safe);
	void reset_account();
	bank& deposit_interest(int interest);
	bank& withdraw_utility(int utility);
	bank& withdraw_tax(int tax);
private:
	string bank_name;
	int safe;
};

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;
	cout << bank_name << "처리 - 입금: " << _in << ", 출금: " << _out<<endl;
}

void bank::transfer_account(int safe) {
	this->safe = safe;
	cout << bank_name << "으로 계좌 이동: " << this->safe << endl;
}

void bank::reset_account() {
	safe = 0;
	cout << bank_name << " 계좌가 초기화 되었습니다." << endl;
}

bank& bank::deposit_interest(int interest) {
	safe += interest;
	cout << bank_name << " 이자 지급: " << interest << endl;
	return *this;
}

bank& bank::withdraw_utility(int utility) {
	safe -= utility;
	cout << bank_name << " 공과금 납부: " << utility << endl;
	return *this;
}

bank& bank::withdraw_tax(int tax) {
	safe -= tax;
	cout << bank_name << " 세금 납부: " << tax << endl;
	return *this;
}

int main() {
	bank rich_bank("부유한 은행"), global_bank("세계적 은행");
	rich_bank.use_counter(50, 10);
	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();

	global_bank.deposit_interest(10).withdraw_utility(1).withdraw_tax(2);
	cout << endl;
	cout << global_bank.get_bank_name() << "잔액: " << global_bank.get_safe() << endl;
}