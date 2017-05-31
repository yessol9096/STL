#include <iostream>
#include <fstream>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#include<conio.h>
#include <chrono>
#include <vector>

using namespace std;

int main() {
	int order = 0;
	vector<char> v;
	char str;
	char input;
	input = 'a';
	char input1;
	ifstream inputFile("STLsubject2.txt");
	while (!inputFile.eof())		// 파일이 있다면 불러와서 생성
	{
		inputFile >> input1;
		v.push_back(input1);
	}
	inputFile.close();
	for (auto i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
		if (v[i] == 'a')
			PlaySound(L"do.wav", NULL, SND_ASYNC);
		if (v[i] == 's')
			PlaySound(L"re.wav", NULL, SND_ASYNC);
		if (v[i] == 'd')
			PlaySound(L"mi.wav", NULL, SND_ASYNC);
		if (v[i] == 'f')
			PlaySound(L"fa.wav", NULL, SND_ASYNC);
		if (v[i] == 'h')
			PlaySound(L"sol.wav", NULL, SND_ASYNC);
		if (v[i] == 'j')
			PlaySound(L"ra.wav", NULL, SND_ASYNC);
		if (v[i] == 'k')
			PlaySound(L"si.wav", NULL, SND_ASYNC);
		if (v[i] == 'l')
			PlaySound(L"highdo.wav", NULL, SND_ASYNC);
		Sleep(1000);
	}
}