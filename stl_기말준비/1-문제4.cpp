#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <set>
using namespace std;

//main()���� �ڵ带 �ݵ�� �ܰ躰�� ������� ���鼭 ����� ���캸��, ����Ǵ� ���� ������
// �����䱸�ϴ� ���븸�� �������.
// �Լ��� �ذ� �� �� �ִ� ���� �ݺ����� ����Ͽ� �ذ��� ����� ������ �� ����.
// ȭ�� ��°���� ������ ��

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
	virtual void move() { cout << "���� �ڴ� - " << age << endl; };
};

class Bird : public Animal
{
public:
	Bird(int n) { age = n; kind = 1; };
	virtual void move() { cout << "���� ���� - " << age << endl; }
};

template <class T>
void DeleteItem(T* item)
{
	delete item;
}

class Comp {		// Comp�� function object�̴�.
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

	// [����4] for �ݺ����� ����Ͽ� v�� 100 ������ ������ �־��.
	for (int i = 0; i < 100; ++i)
	{
		if(rand() & 1)
			v.push_back(new Dog(rand()%30));
		else
			v.push_back(new Bird(rand() % 30));
	}
	// rand()�� ����Ͽ� ���� Ȧ���̸� Dog, ¦���̸� Bird�� v�� push_back�Ѵ�.
	// ���̴� rand()�� ����Ͽ� 1���� 30���� ������ ���������� �����϶�.

	// �̺κ��� �ڵ��� ��
	cout << endl;
	cout << "-----------------" << endl;
	cout << "���� 4 ��� ���"  << endl;
	cout << "-----------------" << endl;

	for (Animal* p : v)
		p->move();

	// [���� 5] main()�� ���⿡�� �����ٰ� �����ϰ� ����� �������� �����϶�.
	// �޸𸮴��������� �߻��Ѵ�.
	// [���� 6] ���� 5�� �������� �ذ��ϴ� �ڵ带 �����.
	//vector<Animal*> vclear;
	//v.swap(vclear);

	//vclear.clear();
	//v.clear();

	// �̺κ��� �ڵ��� ��

	// [���� 7] ���� 6�� ���� �ڵ��� ���� �ʰ� ���� 5�� �������� �ذ��� �� �ִ� �����
	// �����ϰ� ���ľ��� �κ��� �����.
	// �Լ��� ����Ͽ��� ���� ���� �ִ�.
	//for_each(v.begin(), v.end(), DeleteItem<Animal>);

	// [���� 8] v�� multiset s�� �����Ͽ� ���� ������������ �����϶�.???
	// [����] ���� 6�� �ذ��Ͽ��ٸ� �ּ�ó���Ͽ� ���������� ����.

	//�̺κ��� �ڵ��Ұ�
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
	cout << "���� 8 ��� ���" << endl;
	cout << "-----------------" << endl;
	cout << "s�� ���� ����-" << s.size() << endl;
	for (Animal* p : s)
		p->move();

	// [���� 9] ���̰� 20�� ������ ���� ����϶�.


	// �̺κ��� �ڵ��Ұ�
	int n20 = count_if(s.begin(), s.end(), twenty);
	cout << "20���� ������" << n20 << "����" << endl;

	// [����10] s���� ��� Dog�� �����϶�.
	 s.erase(remove_if(s.begin(), s.end(), [](Animal* p) {
		return p->getKind() == 0;
	}),s.end());
	//s.erase(p, s.end());
	// �̺κ��� �ڵ��Ұ�

	cout << endl;
	cout << "-----------------" << endl;
	cout << "���� 10 ��� ���" << endl;
	cout << "-----------------" << endl;
	cout << "������ ������ ��" << s.size() << endl;
}