#include<iostream>
using namespace std;

/*
 ** 오버라이딩 : 어떤 규칙이나 권력에 앞서거나 무시한다 **
즉, 부모 클래스의 함수를 오버라이딩한다는 것은 부모의 정의를 무시하거나 그에 앞서
자식 클래스에 정의된 함수를 우선시하겠다는 뜻이다.

 ** 오버로딩 : 과부화 또는 과적 즉, 짐을 계속해서 쌓는다는 의미**
이미 정의된 함수와 같은 이름을 사용하지만, 매개변수 구성을 변경해 가면서 새로운 정의를
계속 쌓는 의미로 이해할 수 있다.

	함수의 이름 변경 -> 새로운 함수
	이름과 매개변수 구성은 그대로인데 반환 형식만 바꾼 함수 -> 오버로딩 X 오류 발생
*/

class character {
public:
	character() : location{0, 0} {}

	void move(int x, int y) {
		location[0] = x;
		location[1] = y;
		cout << location[0] << ", " << location[1] << "로 이동" << endl;
	}

	void move(int x[], int y[], int spot_count) {
		for (int i = 0;i < spot_count;i++) {
			location[0] = x[i];
			location[1] = y[i];
			cout << i + 1 << "번째: " << location[0] << ", " << location[1] << "로 이동" << endl;
		}
	}

protected:
	int location[2];
};

int main()
{
	character character_obj;
	int x_list[3] = { 10,15,20 };
	int y_list[3] = { 10,15,20 };

	character_obj.move(10, 10);
	cout << endl;
	character_obj.move(x_list, y_list, 3);
	return 0;
	return 0;
}