#include <iostream>
#include <fstream>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#include<conio.h>
#include <chrono>
#include <vector>
#include <string>
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

void DrawingPiano();
void PlayingThePiano(const char&);

template<class key>
void HowToPlaying(vector<key>);

int main() {
	int order = 0;
	string text;
	vector<Key> v;
	DrawingPiano();
	while (1)
	{
		cout << "1. 연주불러오기" << endl;
		cout << "2. 연주녹음하기" << endl;
		cout << "3. 연습하기" << endl;
		cout << "4. 나가기" << endl;

		cin >> order;
		switch (order)
		{
		case 1:
			char input1;
			int time1;
			cout << "파일명을 입력하시오:";
			cin >> text;
			{// 파일 읽어오기
				ifstream inputFile(text);
				while (!inputFile.eof())		
				{
					inputFile >> input1 >> time1;
					v.push_back(Key(input1, time1));
				}
				inputFile.close();
			}
			HowToPlaying(v);
			break;
		case 2:
			char input;
			cout << "그만 녹음하기 : q " << endl;
			while (input != 'q') {
				std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
				input = _getch();
				PlayingThePiano(input);
				std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
				std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime);
				v.push_back(Key(input, mill.count()));
			}
			{
				fstream out("STLsubject2.txt", ios::out);
				{
					for (auto i = 0; i < v.size(); ++i)
						out << v[i].getKey() << v[i].getTime() << endl;
				}
				out.close(); }
			break;
		case 3:
			char input3;
			while (input3 != 'q')
			{
				input3 = _getch();
				PlayingThePiano(input3);
			}
			break;

		}
	}
}
void DrawingPiano()
{
	cout << "　　　　　　┃ ┃┃┃┃ ┃ ┃┃┃┃┃┃ ┃ ┃┃┃┃ ┃ " << endl;
	cout << "　　　　　　┃ ┃┃┃┃ ┃ ┃┃┃┃┃┃ ┃ ┃┃┃┃ ┃ " << endl;
	cout << "　　　　　　┃ ┃┃┃┃ ┃ ┃┃┃┃┃┃ ┃ ┃┃┃┃ ┃ " << endl;
	cout << "　　　　　　┃ ┗┛┗┛ ┃ ┗┛┗┛┗┛ ┃ ┗┛┗┛ ┃ " << endl;
	cout << "　　　　　　┃  ┃  ┃  ┃  ┃  ┃  ┃  ┃  ┃  ┃  ┃ " << endl;
	cout << "　　　　　　┃도┃레┃미┃파┃솔┃라┃시┃도┃  ┃  ┃ " << endl;
	cout << "　　　　　　┃a ┃s ┃d ┃f ┃ h┃j ┃k ┃l ┃  ┃  ┃ " << endl;
	cout << "　　　　　　┗━┻━┻━┻━┻━┻━┻━┻━┻━┻━┛ " << endl;
	cout << "a:도 s:레 d:미 f:파 h:솔 j:라 k:시 l:도   q:메뉴로" << endl;
};

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

template<class key>
void HowToPlaying(vector<key> v)
{
	cout << "1.원본대로 연주하기 2.한음씩 연주하기 3.2배빠르게 연주하기" << endl;
	int playorder;
	int k = 0;
	cin >> playorder;
	switch (playorder) {
	case 1: 
		for (auto i = 0; i < v.size(); ++i)
		{
			PlayingThePiano(v[i].getKey());
			Sleep(v[i].getTime());
		}
		break;
	case 2:
		cout << "k : 한 음 연주 q: 그만하기" << endl;
		char onekey;
		while (onekey != 'q'|| key < v.size())
		{
			onekey = _getch();;

			if (onekey == 'k')
			{
				++k;
				if (k > v.size())
				{
					cout << "연주가 끝났습니다." << endl;
					break;
				}
				PlayingThePiano(v[k].getKey());
			}
		}
		break;
	case 3:
		for (auto j = 0; j < v.size(); ++j)
		{
			PlayingThePiano(v[j].getKey());
			Sleep(v[j].getTime()/2);
		}
		break;
	}
};