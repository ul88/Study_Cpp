#include<iostream>
using namespace std;
/*
	�Լ� ȣ�⹮�� ��� ǥ�������� ġȯ�Ǹ� ������ �ð��� �� �� �ɷ��� 
	�Լ� ȣ�⿡ �ʿ��� ������ ���µǹǷ� ���� �ð��� ��������.

	constexpr �Լ��� ���� ����
		1. �Լ��� ���ڿ� ��ȯ�� ��� ���ͷ� �����̾���Ѵ�.
		2. ��� �Լ��� ������ �� �ִ�. ���� �Լ����� ������ �� ����.
		3. try-catch, goto ������ ����� �� ����.
		4. if�� switch, ���� ��� for���� ��� �ݺ� ������ ����� �� �ִ�.
		5. ���� ������ �ݵ�� �ʱ�ȭ�ϰų� ���ͷ� �����̾���Ѵ�. ���� ������ ������� �ʴ´�.

	#define�� ���ǵ� ���� �ǹ��ִ� �̸����� �������� ���̱� ���� ���̰�,
	const�� ������ ���� ���� Ȱ���ϰų� ������ �� ���� �ϴ� ������ �Ѵ�.
	�ٸ�, constexpr�� ���� �����Ѵٴ� �ͺ��� ������ ������ �ҽ� �ڵ忡 �´�
	������ ���� �����Ͽ� �Լ� ȣ���̳� �������� ��� �ð��� �ٿ��ִ� �����̴�.

	��, #define�� const�� ������ �Ǵ� �������� ���ؼ�
	constexpr�� ���� �ð� ������ ���ؼ� ����Ѵ�.
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
		������� �ڵ�
		> mov edx, 5
		> mov ecx, 4
		> call sum_int (07FF~~)
		> mov dword ptr [var1],eax
	*/

	int var2 = sum_int(var1, 10);
	int var3 = sum_int(var1, var2);

	constexpr int var11 = sum_int_constexpr(4, 5);
	/*
		������� �ڵ�
		> mov dword ptr [var11],9
	*/
	constexpr int var12 = sum_int_constexpr(var11, 10);
	constexpr int var13 = sum_int_constexpr(var11, var12);
	return 0;
}