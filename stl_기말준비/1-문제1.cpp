#include <iostream>

using namespace std;

//main()안의 코드를 반드시 단계별로 실행시켜 가면서 결과를 살펴보며, 실행되는 답을 적을것
// 답은요구하는 내용만을 적으면됨.
// 함수로 해결 할 수 있는 것은 반복문을 사용하여 해결한 답안은 감점할 수 있음.
// 화면 출력결과를 참고할 것

class Animal
{
protected:
	int age;
public:
	Animal(int n) : age(n) {}
	virtual void move() = 0;
	int getAge() const { return age; }
};

class Dog :public Animal
{
public:
	Dog(int n) : Animal(n){
		age = n;
	};
	virtual void move() { cout << "개가 뛴다 - " << age << endl; };
};

class Bird : public Animal
{
public:
	Bird(int n) : Animal(n) { age = n; };
	virtual void move() { cout << "새가 난다 - " << age << endl; }
};

int main()
{
	// 이 코드 블럭은 다형성을 구현한 전통적인 c++ code이다.
	{
		Animal* d1 = new Dog(1);
		Animal* d2 = new Dog(2);
		Animal* b1 = new Bird(3);
		Animal* b2 = new Bird(4);

		Animal* animals[4];

		animals[0] = d1;
		animals[1] = d2;
		animals[2] = b1;
		animals[3] = b2;

		cout << "------------------" << endl;
		cout << "다형성 구현 확인 출력" << endl;
		cout << "------------------" << endl;

		for (Animal* p : animals)
			p->move();      // 다형성이 구현됨을 확인할수있다.

							// [문제1] 이 코드 블럭 전체의 문제점을 지적하라.
							// 위에서 아래로만 된다. 아래에서 위로 가려면은 업캐스트를 하여야 한다.스태틱캐스트나, 다이내믹 캐스트. 
							// [문제2] 문제점을 해결하기 위하여 이블럭내에 필요한 코드를 적어라.
							// [문제3] 문제 2 를 제대로 해결하기 위하여 class 안에서 추가해야할 코드를 적고
							// 내용을 설명하라

	}
}