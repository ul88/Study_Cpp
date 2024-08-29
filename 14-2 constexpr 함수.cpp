#include<iostream>
using namespace std;
/*
	함수 호출문이 상수 표현식으로 치환되면 컴파일 시간은 좀 더 걸려도 
	함수 호출에 필요한 절차가 생력되므로 실행 시간이 빨라진다.

	constexpr 함수의 제약 조건
		1. 함수의 인자와 반환값 모두 리터럴 형식이어야한다.
		2. 재귀 함수에 적용할 수 있다. 가상 함수에는 적용할 수 없다.
		3. try-catch, goto 구문을 사용할 수 없다.
		4. if와 switch, 범위 기반 for문등 모든 반복 구문을 사용할 수 있다.
		5. 지역 변수는 반드시 초기화하거나 리터럴 형식이어야한다. 정적 변수는 허용하지 않는다.

	#define은 정의된 값을 의미있는 이름으로 가독성을 높이기 위한 것이고,
	const는 고정된 값을 쉽게 활용하거나 변경할 수 없게 하는 역할을 한다.
	다만, constexpr은 값을 고정한다는 것보다 컴파일 시점에 소스 코드에 맞는
	고정된 값을 정의하여 함수 호출이나 변숫값의 계산 시간을 줄여주는 문법이다.

	즉, #define과 const는 가독성 또는 안정성을 위해서
	constexpr은 실행 시간 단축을 위해서 사용한다.
*/
int sum_int(int operand1, int operand2) {
	return operand1 + operand2;
}

constexpr int sum_int_constexpr(int operand1, int operand2) {
	return operand1 + operand2;
}

int main() {
	int var1 = sum_int(4, 5);
	/*
		어셈블리어 코드
		> mov edx, 5
		> mov ecx, 4
		> call sum_int (07FF~~)
		> mov dword ptr [var1],eax
	*/

	int var2 = sum_int(var1, 10);
	int var3 = sum_int(var1, var2);

	constexpr int var11 = sum_int_constexpr(4, 5);
	/*
		어셈블리어 코드
		> mov dword ptr [var11],9
	*/
	constexpr int var12 = sum_int_constexpr(var11, 10);
	constexpr int var13 = sum_int_constexpr(var11, var12);
	return 0;
}