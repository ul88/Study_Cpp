#include<iostream>
#include<string>
using namespace std;
/*
	템플릿 특수화 : 특수한 상황일 때만 별도의 함수 템플릿으로 만들어 처리하는 방법
		명시적 특수화 : 모든 템플릿 매개변수를 특정 데이터 형식으로 지정하는 방법
		부분 특수화 : 일부 템플릿 매개변수만 특정 데이터 형식으로 지정하는 방법
		함수 템플릿에서는 명시적 특수화만 사용 가능
*/

template <typename T>
T data_sum(T operand1, T operand2) {
	return operand1 + operand2;
}

template<>
double data_sum(double operand1, double operand2) {
	return (int)operand1 + (int)operand2;
}

int main() {
	int data1 = 3, data2 = 5;
	double data3 = 4.5, data4 = 8.9;

	cout << "정수형 데이터 합 : " << data_sum(data1, data2) << endl;
	cout << "실수형 데이터 합 : " << data_sum(data3, data4) << endl;
	return 0;
}