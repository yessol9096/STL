#include <iostream>
#include <random>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>


#define NUMBER 20000			// 플레이어수
#define FIRSTRANDOM 15000000	// 게임실행전 획득 가능 점수 범위
#define ARENASCORE 25000000     // 게임실행후 획득 가능 점수 범위
using namespace std;


class Player
{
protected:
	int name;
	int firScore, secScore, thrScore, fourScore, fifScore;
	bool flag = false;
public:
	Player(int n, int fir, int sec, int thr, int four, int fif) { name = n, firScore = fir, secScore = sec, thrScore = thr, fourScore = four, fifScore = fif; }
	int getFir() { return firScore; }
	int getSec() { return secScore; }
	int getThr() { return thrScore; }
	int getFour() { return fourScore; }
	int getFif() { return fifScore; }
	int getName() { return name; }
	int getSum() { return firScore + secScore + thrScore + fourScore + fifScore; }

	void setName(int n) { name = n; }
	void setFir(int n) { firScore = n; }
	void setSec(int n) { secScore = n; }
	void setThr(int n) { thrScore = n; }
	void setFour(int n) { fourScore = n; }
	void setFif(int n) { fifScore = n; }
};


int myRank(vector<Player>&, int);									// sort로 순서대로 정리, 나의 순위 반환
void score(int arena, int pre, int now, vector<Player>&);			// 랭크화면 출력
void gamePlay(vector<Player>&, default_random_engine, uniform_int_distribution<>, int);
// 아레나 들어가서 게임실행시 얻는 최고점으로 바꿔주기


void main()
{
	vector<Player> player;
	player.reserve(20000);				// 미리 재할당
	int order = 0;
	vector<Player>::iterator iter = player.begin();
	default_random_engine dre;
	uniform_int_distribution<> ui(0, FIRSTRANDOM);
	uniform_int_distribution<> uiNum(1, NUMBER);
	uniform_int_distribution<> uiScore(0, ARENASCORE);

	dre.seed(time(NULL));

	ifstream inputFile("STLScore.txt");

	int name, firScore, secScore, thrScore, fourScore, fifScore;
	if (inputFile.is_open() == false)		// 파일이 없으면 새로운 값으로 생성
	{
		player.push_back(Player(0, ui(dre), ui(dre), ui(dre), ui(dre), ui(dre)));
		for (int i = 1; i < NUMBER; ++i)
			player.push_back(Player(i, ui(dre), ui(dre), ui(dre), ui(dre), ui(dre)));
	}
	else
	{
		while (!inputFile.eof())		// 파일이 있다면 불러와서 생성
		{
			{
				inputFile >> name >> firScore >> secScore >> thrScore >> fourScore >> fifScore;
				player.push_back(Player(name, firScore, secScore, thrScore, fourScore, fifScore));
			}
		}
		inputFile.close();
	}



	while (order != 8)
	{
		cout << "-------1. 아레나--------" << endl;
		cout << "-------2. 아레나--------" << endl;
		cout << "-------3. 아레나--------" << endl;
		cout << "-------4. 아레나--------" << endl;
		cout << "-------5. 아레나--------" << endl;
		cout << "-------6. ID찾기--------" << endl;
		cout << "-------7. 종료----------" << endl;
		cout << "숫자를 입력하시오:";
		cin >> order;

		switch (order) {

		case 1:
		{
			int prerank = myRank(player, 0);		 // 게임 실행전 총점 순위
			gamePlay(player, dre, uiScore, 1);		 // 게임 실행 <최고점 바꾸기>
			int arenarank = myRank(player, 1);		 // 아레나 랭킹 순위
			int rank = myRank(player, 0);			 // 게임 실행후 총점 순위
			score(arenarank, prerank, rank, player); // 랭킹 화면 출력
		}
		break;
		case 2:
		{
			int prerank = myRank(player, 0);
			gamePlay(player, dre, uiScore, 2);
			int arenarank = myRank(player, 2);
			int rank = myRank(player, 0);
			score(arenarank, prerank, rank, player);
		}
		break;
		case 3:
		{
			int prerank = myRank(player, 0);
			gamePlay(player, dre, uiScore, 3);
			int arenarank = myRank(player, 3);
			int rank = myRank(player, 0);
			score(arenarank, prerank, rank, player);
		}
		break;
		case 4:
		{
			int prerank = myRank(player, 0);
			gamePlay(player, dre, uiScore, 4);
			int arenarank = myRank(player, 4);
			int rank = myRank(player, 0);
			score(arenarank, prerank, rank, player);
		}
		break;
		case 5:
		{
			int prerank = myRank(player, 0);
			gamePlay(player, dre, uiScore, 5);
			int arenarank = myRank(player, 5);
			int rank = myRank(player, 0);
			score(arenarank, prerank, rank, player);
		}
		break;
		case 6:
			int id;
			cout << "찾으시는 id를 입력하시오:";
			cin >> id;
			for (iter = player.begin(); iter != player.end(); ++iter) { // iterator이용하여 vector반복
				if (iter->getName() == id)	
				{
					cout << iter->getName() << endl << iter->getFir() << endl << iter->getSec() <<
						endl << iter->getThr() << endl << iter->getFour() << endl << iter->getFif() << endl;
					break;
				}
			}

			break;
		case 7:
			remove("STLScore.txt");	// 기존 데이터를 삭제하고 다시 파일 생성
			fstream out("STLScore.txt", ios::out);
			for (int i = 0; i < NUMBER; ++i)
			{
				out << player[i].getName() << " " << player[i].getFir() << " " << player[i].getSec() <<
					" " << player[i].getThr() << " " << player[i].getFour() << " " << player[i].getFif() << endl;
			}
			out.close();

			order = 8; // whie문 나가기
			break;
		}

	}
}


int myRank(vector<Player>& p, int num)
{
	if (num == 0)
	{
		sort(p.begin(), p.end(), [](Player a, Player b) {
			return a.getSum() > b.getSum();
		});
	}
	else if (num == 1)
	{
		sort(p.begin(), p.end(), [](Player a, Player b) {
			return a.getFir() > b.getFir();
		});
	}
	else if (num == 2)
	{
		sort(p.begin(), p.end(), [](Player a, Player b) {
			return a.getSec() > b.getSec();
		});
	}
	else if (num == 3)
	{
		sort(p.begin(), p.end(), [](Player a, Player b) {
			return a.getThr() > b.getThr();
		});
	}
	else if (num == 4)
	{
		sort(p.begin(), p.end(), [](Player a, Player b) {
			return a.getFour() > b.getFour();
		});
	}
	else if (num == 5)
	{
		sort(p.begin(), p.end(), [](Player a, Player b) {
			return a.getFif() > b.getFif();
		});
	}

	int rank = 0;

	while (0 != p[rank].getName())
	{
		++rank;
	}
	return rank;
};

void score(int arena, int pre, int now, vector<Player>& p)
{
	int preplayer = now - 1;
	int nextplayer = now + 1;
	cout << "당신의 ARENA 순위: " << arena*0.005 << "% " << endl;
	cout << "당신의 총점 순위 : " << now*0.005 << " % ||등수 : " << now << "총점:" << endl;
	cout << " 위플레이어 id   : " << p[preplayer].getName() << "||순위:" << preplayer << "총점:" << p[preplayer].getSum()<< endl;
	cout << "아래 플레이어 id : " << p[nextplayer].getName() << "||순위:" << nextplayer << "총점:" << p[nextplayer].getSum() << endl;
	cout << "   순위 변동     : " << pre << "->" << now << endl;
};
void gamePlay(vector<Player>& p, default_random_engine dre, uniform_int_distribution<> uiScore, int num)
{
	set<int> s;			// set을 이용하여 중복되지 않는 난수 생성
	s.insert(0);		// 나는 무조건 포함 
	while (true) {
		s.insert(rand()%NUMBER);	
		if (s.size() == (NUMBER/10)-1)		// 무작위로 플레이어의 10% 뽑기
			break;
		}
	if (num == 1)
	{
		for (int d : s)
		{
			int v = uiScore(dre);
			if (p[d].getFir() < v)		// 플레이어의 기존 점수와 비교 
			{
				p[d].setFir(v);		// 크면 변경 안크면 두기
			}
		}
	}
	else if (num == 2)
	{
		for (int d : s)
		{
			int v = uiScore(dre);
			if (p[d].getSec() < v)
			{
				p[d].setSec(v);
			}
		}
	}
	else if (num == 3)
	{
		for (int d : s)
		{
			int v = uiScore(dre);
			if (p[d].getThr() < v)
			{
				p[d].setThr(v);
			}
		}
	}
	else if (num == 4)
	{
		for (int d : s)
		{
			int v = uiScore(dre);
			if (p[d].getFour() < v)
			{
				p[d].setFour(v);
			}
		}
	}
	else if (num == 5)
	{
		for (int d : s)
		{
			int v =  uiScore(dre);
			if (p[d].getFif() < v)
			{ 
				p[d].setFif(v);
			}
		}
	}
}