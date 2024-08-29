#include<iostream>
using namespace std;
/*
	constexpr : 변수나 함수를 상수 표현식으로 만들어 주는 키워드

	const와 달리 constexpr은 변수ㅏ 함수를 컴파일 시점에 상수 표현식으로 만들어준다.
	따라서 실행 시점에서 함수 호출이 이뤄지지 않고 상수로 대체된다.
*/

void sum_int(int operand1, int operand2) {
	const int var11 = 10;
	const int var12 = operand1 + 10;
	const int var13 = operand1 + operand2;
	constexpr int var14 = 20;
	// 컴파일 오류
	// constexpr 변수를 사용할 때는 초깃값이 리터럴이어야한다.
	//constexpr int var15 = operand1 + 15;
	//constexpr int var16 = operand1 + operadn2;
}

int main()
{
	const int var1 = 10;
	const int var2 = var1 + 10;
	const int var3 = var1 + var2;

	constexpr int var4 = 20;
	constexpr int var5 = var1 + 15;
	constexpr int var6 = var1 + var4;

	sum_int(var1, var4);
	return 0;
}