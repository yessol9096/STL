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
	virtual void move() = 0;
	int getAge() const { return age; }
};

class Dog :public Animal
{
public:
	Dog(int n) {
		age = n;
	};
	virtual void move() { cout << "개가 뛴다 - " << age << endl; };
};

class Bird : public Animal
{
public:
	Bird(int n) { age = n; };
	virtual void move() { cout << "새가 난다 - " << age << endl; }
};

int main()
{
	// 이 코드 블럭은 다형성을 구현한 전통적인 c++ code이다.
	{
		Dog* d1 = new Dog(1);
		Dog* d2 = new Dog(2);
		Bird* b1 = new Bird(3);
		Bird* b2 = new Bird(4);

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
							// [문제2] 문제점을 해결하기 위하여 이블럭내에 필요한 코드를 적어라.
							// [문제3] 문제 2 를 제대로 해결하기 위하여 class 안에서 추가해야할 코드를 적고
							// 내용을 설명하라

	}
	// 위의 전통적인 []대신 stl 컨테이너를 이용하여 다형성을 구현할 수 있다.
	// 다수의 동물이 출려갛는 프로그램을 구현하려고 한다.

	vector<Animal*> v;

	// [문제4] for 반복문을 사용하여 v에 100 마리의 동물을 넣어라.
	// rnad()를 사용하여 값이 홀수이면 Dog, 짝수이면 Bird를 v에 push_back한다.
	// 나이는 rand()를 사용하여 1부터 30까지 사이의 정수값으로 설정하라.

	// 이부분을 코딩할 것
	cout << endl;
	cout << "-----------------" << endl;
	cout << "문제 4 결과 출력" << endl;
	cout << "-----------------" << endl;

	for (Animal* p : v)
		p->move();

	// [문제 5] main()이 여기에서 끝난다고 가정하고 실행시 문제점을 지적하라.
	// [문제 6] 문제 5의 문제점을 해결하는 코드를 적어라.

	// 이부분을 코딩할 것

	// [문제 7] 문제 6과 같은 코딩을 하지 않고 문제 5의 문제점을 해결할 수 있는 방법을
	// 설명하고 고쳐야할 부분을 적어라.

	// 이부분을 코딩할 것

	// [문제 8] v를 multiset s에 복사하여 나이 오름차순으로 정렬하라.
	// [주의] 문제 6을 해결하였다면 주석처리하여 문제없도록 하자.

	//이부분을 코딩할것

	cout << endl;
	cout << "-----------------" << endl;
	cout << "문제 8 결과 출력" << endl;
	cout << "-----------------" << endl;
	cout << "s의 원소 갯수-" << s.size() << endl;
	for (Animal* p : s)
		p->move();

	// [문제 9] 나이가 20인 동물의 수를 출력하라.

	int n20;

	// 이부분을 코딩할것

	cout << "20살인 동물은" << n20 << "마리" << endl;

	// [문제10] s에서 모든 Dog를 삭제하라.

	// 이부분을 코딩할것

	cout << endl;
	cout << "-----------------" << endl;
	cout << "문제 10 결과 출력" << endl;
	cout << "-----------------" << endl;
	cout << "삭제후 동물의 수" << s.size() << endl;
}