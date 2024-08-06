#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	cout << binary_search(v.begin(), v.end(), 3)<<endl; // true
	cout << binary_search(v.begin(), v.end(), 11); // false
	return 0;
}