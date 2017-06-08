#include <iostream>

using namespace std;

//main()���� �ڵ带 �ݵ�� �ܰ躰�� ������� ���鼭 ����� ���캸��, ����Ǵ� ���� ������
// �����䱸�ϴ� ���븸�� �������.
// �Լ��� �ذ� �� �� �ִ� ���� �ݺ����� ����Ͽ� �ذ��� ����� ������ �� ����.
// ȭ�� ��°���� ������ ��

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
	virtual void move() { cout << "���� �ڴ� - " << age << endl; };
};

class Bird : public Animal
{
public:
	Bird(int n) : Animal(n) { age = n; };
	virtual void move() { cout << "���� ���� - " << age << endl; }
};

int main()
{
	// �� �ڵ� ���� �������� ������ �������� c++ code�̴�.
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
		cout << "������ ���� Ȯ�� ���" << endl;
		cout << "------------------" << endl;

		for (Animal* p : animals)
			p->move();      // �������� �������� Ȯ���Ҽ��ִ�.

							// [����1] �� �ڵ� �� ��ü�� �������� �����϶�.
							// ������ �Ʒ��θ� �ȴ�. �Ʒ����� ���� �������� ��ĳ��Ʈ�� �Ͽ��� �Ѵ�.����ƽĳ��Ʈ��, ���̳��� ĳ��Ʈ. 
							// [����2] �������� �ذ��ϱ� ���Ͽ� �̺����� �ʿ��� �ڵ带 �����.
							// [����3] ���� 2 �� ����� �ذ��ϱ� ���Ͽ� class �ȿ��� �߰��ؾ��� �ڵ带 ����
							// ������ �����϶�

	}
}