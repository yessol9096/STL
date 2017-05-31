#include <iostream>
#include <random>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>


#define NUMBER 20000			// �÷��̾��
#define FIRSTRANDOM 15000000	// ���ӽ����� ȹ�� ���� ���� ����
#define ARENASCORE 25000000     // ���ӽ����� ȹ�� ���� ���� ����
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


int myRank(vector<Player>&, int);									// sort�� ������� ����, ���� ���� ��ȯ
void score(int arena, int pre, int now, vector<Player>&);			// ��ũȭ�� ���
void gamePlay(vector<Player>&, default_random_engine, uniform_int_distribution<>, int);
// �Ʒ��� ���� ���ӽ���� ��� �ְ������� �ٲ��ֱ�


void main()
{
	vector<Player> player;
	player.reserve(20000);				// �̸� ���Ҵ�
	int order = 0;
	vector<Player>::iterator iter = player.begin();
	default_random_engine dre;
	uniform_int_distribution<> ui(0, FIRSTRANDOM);
	uniform_int_distribution<> uiNum(1, NUMBER);
	uniform_int_distribution<> uiScore(0, ARENASCORE);

	dre.seed(time(NULL));

	ifstream inputFile("STLScore.txt");

	int name, firScore, secScore, thrScore, fourScore, fifScore;
	if (inputFile.is_open() == false)		// ������ ������ ���ο� ������ ����
	{
		player.push_back(Player(0, ui(dre), ui(dre), ui(dre), ui(dre), ui(dre)));
		for (int i = 1; i < NUMBER; ++i)
			player.push_back(Player(i, ui(dre), ui(dre), ui(dre), ui(dre), ui(dre)));
	}
	else
	{
		while (!inputFile.eof())		// ������ �ִٸ� �ҷ��ͼ� ����
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
		cout << "-------1. �Ʒ���--------" << endl;
		cout << "-------2. �Ʒ���--------" << endl;
		cout << "-------3. �Ʒ���--------" << endl;
		cout << "-------4. �Ʒ���--------" << endl;
		cout << "-------5. �Ʒ���--------" << endl;
		cout << "-------6. IDã��--------" << endl;
		cout << "-------7. ����----------" << endl;
		cout << "���ڸ� �Է��Ͻÿ�:";
		cin >> order;

		switch (order) {

		case 1:
		{
			int prerank = myRank(player, 0);		 // ���� ������ ���� ����
			gamePlay(player, dre, uiScore, 1);		 // ���� ���� <�ְ��� �ٲٱ�>
			int arenarank = myRank(player, 1);		 // �Ʒ��� ��ŷ ����
			int rank = myRank(player, 0);			 // ���� ������ ���� ����
			score(arenarank, prerank, rank, player); // ��ŷ ȭ�� ���
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
			cout << "ã���ô� id�� �Է��Ͻÿ�:";
			cin >> id;
			for (iter = player.begin(); iter != player.end(); ++iter) { // iterator�̿��Ͽ� vector�ݺ�
				if (iter->getName() == id)	
				{
					cout << iter->getName() << endl << iter->getFir() << endl << iter->getSec() <<
						endl << iter->getThr() << endl << iter->getFour() << endl << iter->getFif() << endl;
					break;
				}
			}

			break;
		case 7:
			remove("STLScore.txt");	// ���� �����͸� �����ϰ� �ٽ� ���� ����
			fstream out("STLScore.txt", ios::out);
			for (int i = 0; i < NUMBER; ++i)
			{
				out << player[i].getName() << " " << player[i].getFir() << " " << player[i].getSec() <<
					" " << player[i].getThr() << " " << player[i].getFour() << " " << player[i].getFif() << endl;
			}
			out.close();

			order = 8; // whie�� ������
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
	cout << "����� ARENA ����: " << arena*0.005 << "% " << endl;
	cout << "����� ���� ���� : " << now*0.005 << " % ||��� : " << now << "����:" << endl;
	cout << " ���÷��̾� id   : " << p[preplayer].getName() << "||����:" << preplayer << "����:" << p[preplayer].getSum()<< endl;
	cout << "�Ʒ� �÷��̾� id : " << p[nextplayer].getName() << "||����:" << nextplayer << "����:" << p[nextplayer].getSum() << endl;
	cout << "   ���� ����     : " << pre << "->" << now << endl;
};
void gamePlay(vector<Player>& p, default_random_engine dre, uniform_int_distribution<> uiScore, int num)
{
	set<int> s;			// set�� �̿��Ͽ� �ߺ����� �ʴ� ���� ����
	s.insert(0);		// ���� ������ ���� 
	while (true) {
		s.insert(rand()%NUMBER);	
		if (s.size() == (NUMBER/10)-1)		// �������� �÷��̾��� 10% �̱�
			break;
		}
	if (num == 1)
	{
		for (int d : s)
		{
			int v = uiScore(dre);
			if (p[d].getFir() < v)		// �÷��̾��� ���� ������ �� 
			{
				p[d].setFir(v);		// ũ�� ���� ��ũ�� �α�
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