#include<iostream>
#include<set>
#include<map>
using namespace std;
/*
	연관 컨테이너들은 검색 작업의 시간복잡도가 O(logN) 또는 O(1)에 가깝다.
*/

int main() {
	//멀티 셋
	multiset<int> myMultiset;

	myMultiset.insert(5);
	myMultiset.insert(2);
	myMultiset.insert(5);

	int count = myMultiset.count(5);
	cout << "저장되어 있는 5의 개수: " << count << endl;

	for (auto iter : myMultiset) {
		cout << iter << " ";
	}
	cout << endl;

	//멀티맵
	multimap<string, int> scores;
	scores.insert({ "Bob", 85 });
	scores.insert({ "Jane", 90 });
	scores.insert({ "Tom", 70 });
	scores.insert({ "Bob", 100 });

	cout << "multimap 크기 : " << scores.size() << endl;

	count = scores.count("Bob");
	cout << "저장되어 있는 Bob 점수의 개수: " << count << endl;

	auto range = scores.equal_range("Bob");
	if (range.first != scores.end()) {
		cout << "Bob의 모든 점수: ";
		for (auto iter = range.first; iter != range.second; iter++) {
			cout << iter->second << " ";
		}
		cout << endl;
	}
	else {
		cout << "Bob의 점수는 저장 X" << endl;
	}

	scores.erase("Bob");

	cout << "멀티맵 원소 출력" << endl;
	for (auto iter : scores) {
		cout << iter.first << " " << iter.second << "\n";
	}
}