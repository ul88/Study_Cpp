#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void pinrt_vector_all(vector<T>& v) {
	cout << "벡터 내 원소 개수 : " << v.size() << endl;
	for (auto iter : v) {
		cout << iter << " ";
	}
	cout << endl << "-----------" << endl;
}
int main()
{
	vector<int> v = { 0,10,20,30,40 };

	cout << "원본" << endl;
	pinrt_vector_all(v);

	v.insert(v.begin() + 3, 25);
	cout << "insert 결과" << endl;
	pinrt_vector_all(v);

	v.erase(v.begin() + 3);
	cout << "erase 결과" << endl;
	pinrt_vector_all(v);


	//vector<int>::const_iterator : 정적 반복자로 반복자가 가리키는 원솟값을 변경할 수 없다.

	vector<int>::const_iterator const_it = v.cbegin();
	cout << *const_it << endl;

	++const_it;
	cout << *const_it << endl;
	
	const_it = v.cend();
	--const_it;
	cout << *const_it << endl;


	cout << "리버스 반복자 사용" << endl;
	for (auto it = v.rbegin();it != v.rend();it++) {
		cout << *it << endl;
	}
	return 0;
}