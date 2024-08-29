/*
	auto는 변수 선언과 초기화에 주로 사용되지만,
	decltype은 변수 선언뿐만 아니라 함수 템플릿이나 
	클래스 템플릿에서 반환값의 형식을 연역하는 데도 사용한다.

	후행 반환 형식 : 함수에서 반환값의 형식을 연역할 때는 선언문 앞쪽이 아니라 뒤쪽에 표기하는 형식
	
	반환값의 형식을 나타내는 자리에 auto 키워드만 사용하면 형식을 연역할 수 없어 오류가 발생한다.
	따라서 반드시 후행 반환 형식으로 decltype를 지정해야한다.

	decltype 반환값 형식 영역
		template<typename T, typename TT>
		auto mix_template(T t, TT tt) -> decltype(t + u) {
			return t * tt;
		}

	* 모던 C++에서 많이 사용하므로 깊게 공부하는게 좋음.
*/