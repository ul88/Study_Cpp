#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1("Hello"); // 생성자 호출로 초기화
	string str2 = "Hello"; // 대입 연산으로 초기화
	
	cout << endl << "length, size" << endl;

	cout << str1.length() << endl; // 문자열의 길이 반환
	cout << str1.size() << endl; // 객체의 메모리 크기 반환
	// 따라서 문자열의 길이가 필요할 땐 length를 사용해야함

	cout << endl << "empty" << endl;

	cout << std::boolalpha; // bool을 출력할 때, true 또는 false로 뜨게 함
	cout << str1.empty() << endl;
	cout << std::noboolalpha; // bool을 출력할 때, 1 또는 0으로 뜨게 함
	cout << str1.empty() << endl;

	/*
		문자열.append("추가할_문자열", 문자열_시작_인덱스, 문자_개수);
	*/
	cout << endl << "append" << endl;

	str1.append(" World!"); // 기존 문자열의 끝에 추가로 붙임
	cout << str1 << endl;

	str2.append(" World!", 6, 1); // 추가할 문자열에서 6번째 인덱스인 !부터 1개를 추가로 붙임
	cout << str2 << endl;

	/*
		문자열.find(찾을_문자열);
		문자열.find(찾을_문자);
		문자열.find(찾을_문자열, 시작_위치);
		시작 위치를 비웠다면 무조건 처음 시작 위치부터 탐색을 진행한다.

		문자열을 찾는데 성공하면 해당 문자열의 시작 위치를 반환한다.
		만약 찾지 못하면 정수 타입의 string::npos를 반환한다.

		string::npos 정의
			static const size_t npos = -1;
	*/

	cout << endl << "find" << endl;

	cout << str1.find("Hello") << endl;
	cout << str1.find("World") << endl;
	cout << (str1.find("NO FIND") == string::npos ? "false" : "true") << endl;

	/*
		대상_문자열.compare(비교할_문자열);

		0 : 두 문자열이 같음
		양수 : 대상 문자열이 더 길거나 일치하지 않는 첫 번째 문자가 더 큼
		음수 : 대상 문자열이 더 짧거나 일치하지 않는 첫 번째 문자가 더 작음
	*/

	cout << endl << "compare" << endl;

	cout << str1.compare("Hello World!") << endl;
	cout << str1.compare("Hello") << endl;
	cout << str1.compare("Hello World! not compare") << endl;
	cout << str1.compare("Hella World!") << endl;
	cout << str1.compare("Hellz World!") << endl;

	// compare보다 가볍게 사용하려면 관계 연산자를 사용하면 된다.
	cout << endl << "compare 대신 관게연산자로 비교" << endl;
	cout << (str1 == "Hello World!" ? "true" : "false") << endl;
	cout << (str1 != "Hello World!" ? "true" : "false") << endl;

	/*
		replace 생략
	*/

	/*
		wstring : 와이드 문자열 -> 유니코드 문자열을 처리할 때 사용
	*/
	cout << endl << "wstring" << endl;

	setlocale(LC_ALL, ""); // 프로그램의 지역 설정

	wstring korString = L"안녕하세요"; // L은 문자열 리터럴이 와이드 문자열임을 나타냄

	wcout << korString << endl; // 와이드 출력 스트림 wcout 사용

	return 0;
}