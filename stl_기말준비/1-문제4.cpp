#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <set>
using namespace std;

//main()안의 코드를 반드시 단계별로 실행시켜 가면서 결과를 살펴보며, 실행되는 답을 적을것
// 답은요구하는 내용만을 적으면됨.
// 함수로 해결 할 수 있는 것은 반복문을 사용하여 해결한 답안은 감점할 수 있음.
// 화면 출력결과를 참고할 것

class Animal
{
protected:
	int age;
	int kind;
public:
	virtual void move() = 0;
	int getAge() const { return age; }
	int getKind() const { return kind; }
};

class Dog :public Animal
{
public:
	Dog(int n) {
		age = n; kind = 0;
	};
	virtual void move() { cout << "개가 뛴다 - " << age << endl; };
};

class Bird : public Animal
{
public:
	Bird(int n) { age = n; kind = 1; };
	virtual void move() { cout << "새가 난다 - " << age << endl; }
};

template <class T>
void DeleteItem(T* item)
{
	delete item;
}

class Comp {		// Comp는 function object이다.
public:
	Comp() {}

	bool operator()(int a, int b) {
			return a < b;
	}
};

bool twenty(Animal*const value)
{
	return (value->getAge() == 20);
}
int main()
{
	vector<Animal*> v;

	// [문제4] for 반복문을 사용하여 v에 100 마리의 동물을 넣어라.
	for (int i = 0; i < 100; ++i)
	{
		if(rand() & 1)
			v.push_back(new Dog(rand()%30));
		else
			v.push_back(new Bird(rand() % 30));
	}
	// rand()를 사용하여 값이 홀수이면 Dog, 짝수이면 Bird를 v에 push_back한다.
	// 나이는 rand()를 사용하여 1부터 30까지 사이의 정수값으로 설정하라.

	// 이부분을 코딩할 것
	cout << endl;
	cout << "-----------------" << endl;
	cout << "문제 4 결과 출력"  << endl;
	cout << "-----------------" << endl;

	for (Animal* p : v)
		p->move();

	// [문제 5] main()이 여기에서 끝난다고 가정하고 실행시 문제점을 지적하라.
	// 메모리누수문제가 발생한다.
	// [문제 6] 문제 5의 문제점을 해결하는 코드를 적어라.
	//vector<Animal*> vclear;
	//v.swap(vclear);

	//vclear.clear();
	//v.clear();

	// 이부분을 코딩할 것

	// [문제 7] 문제 6과 같은 코딩을 하지 않고 문제 5의 문제점을 해결할 수 있는 방법을
	// 설명하고 고쳐야할 부분을 적어라.
	// 함수를 사용하여서 지울 수도 있다.
	//for_each(v.begin(), v.end(), DeleteItem<Animal>);

	// [문제 8] v를 multiset s에 복사하여 나이 오름차순으로 정렬하라.???
	// [주의] 문제 6을 해결하였다면 주석처리하여 문제없도록 하자.

	//이부분을 코딩할것
	multiset<Animal*> s ;
	for (int i = 0; i < 100; ++i)
	{
		if (v[i]->getKind() == 0)
			s.insert(new Dog(v[i]->getAge()));
		else
			s.insert(new Bird(v[i]->getAge()));
	}
	cout << endl;
	cout << "-----------------" << endl;
	cout << "문제 8 결과 출력" << endl;
	cout << "-----------------" << endl;
	cout << "s의 원소 갯수-" << s.size() << endl;
	for (Animal* p : s)
		p->move();

	// [문제 9] 나이가 20인 동물의 수를 출력하라.


	// 이부분을 코딩할것
	int n20 = count_if(s.begin(), s.end(), twenty);
	cout << "20살인 동물은" << n20 << "마리" << endl;

	// [문제10] s에서 모든 Dog를 삭제하라.
	 s.erase(remove_if(s.begin(), s.end(), [](Animal* p) {
		return p->getKind() == 0;
	}),s.end());
	//s.erase(p, s.end());
	// 이부분을 코딩할것

	cout << endl;
	cout << "-----------------" << endl;
	cout << "문제 10 결과 출력" << endl;
	cout << "-----------------" << endl;
	cout << "삭제후 동물의 수" << s.size() << endl;
}