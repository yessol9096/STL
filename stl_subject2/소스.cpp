#include <iostream>
#include <fstream>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#include<conio.h>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;

class Key
{
protected:
	char key;
	int time;
public:
	Key(char key, int time) : key{ key }, time{time} {}

	char getKey() const { return key; }
	int getTime() const { return time; }

};

void PlayingThePiano(const char&);

int main() {
	int order = 0;
	vector<Key> v;
	char str;
	cout << "1. ���Ϻҷ�����" << endl;
	cout << "2. ���ο����ϱ�" << endl;
	cout << "3. �����ϱ�" << endl;
	cout << "4. ������" << endl;
	cin >> order;
	ifstream inputFile("STLsubject2.txt");
	switch (order) {
	case 1:
		char input1;
		int time1;
		while (!inputFile.eof())		// ������ �ִٸ� �ҷ��ͼ� ����
		{
			inputFile >> input1 >> time1;
			v.push_back(Key(input1, time1));
		}
		inputFile.close();
		for (auto i = 0; i < v.size(); ++i)
		{
			PlayingThePiano(v[i].getKey());
			Sleep(v[i].getTime());
		}
			break;
	case 2:
		char input;
		cout << "a:�� s:�� d:�� f:�� h:�� j:�� k:�� l:��   q:�޴���" << endl;
		while (input != 'q') {
			std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
			input = _getch();
			PlayingThePiano(input);
			std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
			std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime);
			v.push_back(Key(input, mill.count()));
		}
		fstream out("STLsubject2.txt", ios::out);
		{
			for (auto i = 0; i < v.size(); ++i)
				out << v[i].getKey() << v[i].getTime() << endl;
		}
		out.close();
		break;
		}

		return 0;
}
	

void PlayingThePiano(const char& input)
{
	switch (input) {
	case 'a': PlaySound(L"do.wav", NULL, SND_ASYNC); break;
	case 's': PlaySound(L"re.wav", NULL, SND_ASYNC); break;
	case 'd': PlaySound(L"mi.wav", NULL, SND_ASYNC); break;
	case 'f': PlaySound(L"fa.wav", NULL, SND_ASYNC); break;
	case 'h': PlaySound(L"sol.wav", NULL, SND_ASYNC); break;
	case 'j': PlaySound(L"ra.wav", NULL, SND_ASYNC); break;
	case 'k': PlaySound(L"si.wav", NULL, SND_ASYNC); break;
	case 'l': PlaySound(L"highdo.wav", NULL, SND_ASYNC); break;
	}
};