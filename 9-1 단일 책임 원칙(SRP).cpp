/*
	단일 책임 원칙(SRP) : 클래스는 한 가지 기능만 수행해야 하고, 한 가지 이유로만 변경해야한다.

	즉, 어떤 클래스가 A라는 기능을 수정할 때도 변경되고, B라는 기능을 수정할 때도 변경되는 현상을
	지양해야한다는 것이다.

	산탄총 수술(Shotgun surgery) : 한 가지 기능을 수정할 때, 클래스를 여러 개 수정해야 한다면
	유지보수성이 떨어저기 마련인데, 이런 현상들을 가리키는 단어이다.

	기능을 수정할 때,
	여러 클래스가 변경되지 않아야하며, 변경된 클래스가 다른 클래스에 영향을 주지도 않아야한다.

	즉, SRP의 핵심은
		1. 변경 사항이 한 클래스에 국한되는 것
		2. 변경된 클래스가 다른 클래스에 영향을 주지 않는 것
	이다.

	설계 측면에서는 상속 관계보다 컴포지션이나 어그리게이션을 적극 활용하는 방법이 존재한다.
	리펙토링 측면에서는 클래스를 추출해 거대 클래스를 작은 단위로 나누는 방법이 존재한다.
	이때, 거대 클래스를 작은 단위로 나누더라도 논리적인 관계는 유지돼야한다.
	기존 거대 클래스는 여러가지 기능을 묶는 역할만 하고, 단일 책임으로 추출한 하위 클래스는
	컴포지션이나 어그리게이션을 이용해 has-a 관계로 구현한다.
	* 이렇게 리펙토링하는 작업에는 정답이 없다.
	* 리펙토링 : 프로그램의 실행 결과는 유지한 채 유지보수가 쉽도록 코드를 정리하는 것
	* 다중 상속은 필요할 때 한정해서만 사용하는 것이 좋다.
*/