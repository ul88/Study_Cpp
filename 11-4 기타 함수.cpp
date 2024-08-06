#include<iostream>
#include<random> // 난수 생성
#include<chrono> // 시드값 설정
using namespace std;
int main()
{
	//시드값 사용
	auto curTime = chrono::system_clock::now();
	auto duration = curTime.time_since_epoch();
	auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();

	//mt19937 : 32bit 버전
	//mt19937_64 : 64bit 버전
	//rand, srand 함수에 비해 꺼내올 수 있는 값의 크기가 더 큼
	mt19937_64 mt_rand(millis);

	for (int i = 0;i < 10;i++) {
		cout << mt_rand() << endl;
	}

	/*
		복사함수
		얕은 복사 : 주솟값을 복사
		깊은 복사 : 실제 값을 새로운 메모리 공간에 복사
	*/
	return 0;
}