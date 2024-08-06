#include<iostream>
#include<vector>
using namespace std;
/*
	컨테이너 : 같은 타입의 여러 객체를 저장할 수 있는 묶음 단위의 데이터 구조

	반복자 : 객체지향 프로그래밍에서 컨테이너의 내부 원소들을 순회하는 객체
*/

int main()
{
	//begin() : 시작 위치
	//end() : 마지막 요소 다음 위치
	vector<int> v {0,1,2,3,4};

	vector<int>::iterator it = v.begin();

	cout << *it << endl;
	cout << *(it + 1) << endl;
	cout << *(it + 2) << endl;
	cout << *(it + 3) << endl;
	cout << *(it + 4) << endl;

	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
		cout << *it << " ";
	}
	return 0;
}