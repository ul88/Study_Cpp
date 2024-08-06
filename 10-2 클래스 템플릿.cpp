#include<iostream>
using namespace std;
/*
	보통 클래스 템플릿을 직접 선언하기보다는 라이브러리에서 
	이미 선언된 크래스 템플릿을 이용할 때가 더 많다.

	템플릿 선언과 클래스 정의
		template <typename Type1, typename Type2>
		class data_package {
		public:
			data_package(Type1 first, Type2 second) : first(first), second(second) {}
		private:
			Type1 first;
			Type2 second;
		};

	기본적으로 클래스 템플릿에서는 데이터 형식을 명시적으로 지정해줘야하지만
	C++17 이후 컴파일러에서는 클래스 템플릿에서도 형식 추론을 사용할 수 있다.
*/

template <typename Type1, typename Type2>
class data_package {
public:
	data_package(Type1 first, Type2 second) : first(first), second(second) {}
	void print_out_element() {
		cout << "첫 번째 요소: " << first << ", 두 번째 요소: " << second << endl;
	}
private:
	Type1 first;
	Type2 second;
};

int main()
{
	/*data_package<int, double> template_inst1(5, 10.5);
	data_package<string, int> template_inst2("문자열", 10);*/

	data_package template_inst1(5, 10.5);
	data_package template_inst2("문자열", 10);

	template_inst1.print_out_element();
	template_inst2.print_out_element();
	return 0;
}