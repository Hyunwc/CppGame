#include "GameManager.h"

GameManager::GameManager()
{
	srand(static_cast<unsigned int>(time(0)));
}
//�ʿ������ ������ ����
void GameManager::GameSetting()
{
	//MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	LoadMonster();
	m_shop.WeaponLoad();
	GameTitle();
}

void GameManager::LoadMonster()
{
	ifstream load;
	load.open("defaultMonster.txt");
	if (load.is_open())
	{
		while (!load.eof())
		{
			string name;
			int level, hp, power;

			load >> name >> level >> hp >> power;
			Monster monster(name, level, hp, power);
			monsterVec.push_back(monster);
		}
		load.close();
	}
}

void GameManager::GameTitle()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.2);
	cout << "�١�TEXT RPG�ڡ�";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "1. New Game";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "2. Load Game";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "3. Exit";
	//�޴� ����, Ŀ�� y��ǥ�� �󸶸�ŭ ������ , �ʱ� x,y ��ǥ��
	Select = MapDraw::MenuSelectCursor(3, 3, WIDTH * 0.7, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		NewGame();
		break;
	}
	case 2:
	{
		Load();
	}
	case 3:
	{
		exit(0);
	}
	default:
		break;
	}
}

void GameManager::NewGame()
{
	//ȭ�� ����� �� �ٽ� �׸�
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	string name;
	MapDraw::gotoxy(WIDTH / 2, HEIGHT / 2);
	cout << "�̸��� �Է����ּ��� : ";
	cin >> name;
	//�� ���� �÷��̾�� �̸��� �Ѱ��ִ� �ڵ� �߰��� ����
	m_player.SetName(name);
	Menu();
}

void GameManager::Menu()
{
	//ȭ�� ����� �� �ٽ� �׸�
	system("cls");
	int Select = 0;
	m_player.LevelUp();
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT - 3);
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.3);
	cout << "�١ڸ޴��ڡ�";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "Colosseum";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "Shop";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "Save";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.7);
	cout << "Exit";
	m_player.ShowInfo();
	//�޴� ����, Ŀ�� y��ǥ�� �󸶸�ŭ ������ , �ʱ� x,y ��ǥ��
	Select = MapDraw::MenuSelectCursor(4, 3, WIDTH * 0.7, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		Colosseum();
		break;
	}
	case 2:
	{
		//���� ���� ���� �ȵ�
		m_shop.WeaponDisplay(&m_player);
		Menu();
	}
	case 3:
	{
		//���� ���� ���� �ȵ�
		Save();
		Menu();
	}
	case 4:
	{
		m_player.Reset();
		GameTitle();
		break;
	}
	default:
		break;
	}
}

void GameManager::Colosseum()
{
	system("cls");
	//���� ������ ���̸� ������ ����
	int Select = 0;
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
	cout << "�١��ݷμ���ڡ�";
	//���ͺ��� �����ŭ ������ ���Ƽ� ���!
	for (int i = 0; i < monsterVec.size(); i++)
	{
		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << "����" << monsterVec[i].GetLevel() << " : [" << monsterVec[i].GetName() << "]" << endl;
		height += 3;
	}
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.8);
	cout << "���ư���";
	Select = MapDraw::MenuSelectCursor(monsterVec.size() + 1, 3, WIDTH * 0.2, HEIGHT * 0.2);
	//3 6 9 12 15 18 21
	//�����Ѱ��� ���ư����� �޴��� ���ư���.
	if (Select == monsterVec.size() + 1) Menu();
	//Select�� ������ ������ �����̱⵵��. �÷��̾��� ������ ���ͷ��� �̻��ϋ���
	if(m_player.GetLevel() >= Select)
		GamePlay(Select);
	else
	{
		system("cls");
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.1, HEIGHT * 0.5);
		cout << "����� ������ " << monsterVec[Select - 1].GetName() << "�� �����ϱ⿡ �������� �ʽ��ϴ�." << endl;
		_getch();
		Colosseum();
	}
	
}

void GameManager::GamePlay(int count)
{
	int Select;
	//ȹ�� ����ġ�� ���
	int sum_exp = 0, sum_gold = 0;
	//���� ���� �����Ұ��� ����
	bool heroTurn = rand() % 2;
	
	while (1)
	{
		system("cls");

		//������ ��������̸� �÷��̾��� �̸� �ƴϸ� ������ �̸�
		string name = heroTurn ? m_player.GetName() : m_monster.GetName();
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
		cout << "�١��ݷμ���ڡ�";
		MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.2);
		cout << "���� �� : " << name;
		m_player.ShowDisplay();
		MapDraw::gotoxy(WIDTH, HEIGHT * 0.4);
		cout << "vs";
		monsterVec[count - 1].ShowDisplay();
		
		//MapDraw::BoxDraw(2, 20, WIDTH - 2, HEIGHT - 2);
		
		if (heroTurn)
		{
			MapDraw::gotoxy(WIDTH * 0.1, HEIGHT * 0.8);
			cout << "1. �⺻ ���� 2. �ʻ��(50 ���� �ʿ�) �Է� : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
			{
				//���Ϳ��� �÷��̾��� ���ݷ¸�ŭ�� �������� �ش�
				monsterVec[count - 1].takeDamage(m_player.GetDamage());
				MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
				cout << monsterVec[count - 1].GetName() << "���� " << m_player.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
				break;
			}
			case 2:
			{
				//�ʻ�� ���� ���߿� ������ ����
				MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
				cout << "�ʻ��!";
				break;
			}
			default:
				break;
			}
		}
		else
		{
			m_player.takeDamage(monsterVec[count - 1].GetDamage());
			MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
			cout << m_player.GetName() << "���� " << monsterVec[count - 1].GetDamage() << "��ŭ�� �������� �־����ϴ�!";
		}

		if (m_player.DeadCheck() || monsterVec[count - 1].DeadCheck())
		{
			//���Ͱ� �׾��ٸ� �÷��̾��� ����Ÿ���� �ƴϸ� ���ͷ�
			ResultBord(m_player.DeadCheck() ? MONSTER : PLAYER, monsterVec[count - 1].GetLevel());
		}


		heroTurn = !heroTurn;

		_getch();
	}
}

bool GameManager::FileCheck(int count)
{
	ifstream load;
	load.open("SavePlayer" + to_string(count) + ".txt");
	return load.is_open();
}

void GameManager::Save()
{
	system("cls");
	int Select;
	string ox;
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.1);
	cout << "�١�Save�ڡ�" << endl;
	//MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.3);
	
	for (int i = 1; i <= 5; i++)
	{
		if (FileCheck(i))
			ox = "O";
		else
			ox = "X";

		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << i << "�� ���� : (���Ͽ��� : " << ox << ")" << endl;
		height += 3;
	}
	//6 9 12 15 18 21
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
	cout << "���ư���";
	Select = MapDraw::MenuSelectCursor(6, 3, WIDTH * 0.2, HEIGHT * 0.2);
	if (Select == 6) return;
	
	m_player.DataSave(Select);
	
	system("cls");
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "Save�� �Ϸ�Ǿ����ϴ�!" << endl;

	_getch();
}

void GameManager::Load()
{
	system("cls");
	int Select;
	string ox;
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.1);
	cout << "�١�Load�ڡ�" << endl;
	for (int i = 1; i <= 5; i++)
	{
		if (FileCheck(i))
			ox = "O";
		else
			ox = "X";

		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << i << "�� ���� : (���Ͽ��� : " << ox << ")" << endl;
		height += 3;
	}
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
	cout << "���ư���";

	Select = MapDraw::MenuSelectCursor(6, 3, WIDTH * 0.2, HEIGHT * 0.2);

	if (Select == 6) GameTitle();
	
	if (FileCheck(Select))
		m_player.DataLoad(Select);
	else
	{
		system("cls");
		MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
		cout << "������ �������� �ʽ��ϴ�";
		_getch();
		Load();
	}
	
	system("cls");
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "Load�� �Ϸ�Ǿ����ϴ�!" << endl;

	_getch();
	Menu();
}



void GameManager::testfunc()
{
	for (int i = 0; i < monsterVec.size(); i++)
	{
		cout << monsterVec[i].GetLevel() << "," << monsterVec[i].GetName() << endl;
	}
	system("pause");
}



//���� ����â
void GameManager::MonsterInfo()
{
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	ifstream load;
	load.open("defaultMonster.text");
	if (load.is_open())
	{
		string str;
		while (!load.eof())
		{

		}
	}
}

//����� ��� �� �÷��̾�� ����ġ�� ��� ����
void GameManager::ResultBord(int winner, int level)
{
	system("cls");
	int exp = 0, gold = 0;
	//������ŭ ����ġ�� ��带 �ο��� ���� ���ٸ� �ݸ�
	if (winner == PLAYER)
	{
		exp = 50 * level;
		gold = 300 * level;
	}
	else
	{
		exp = 25 * level;
		gold = 150 * level;
		m_player.Respone();
	}
	
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	//���ڰ� �÷��̾�� �÷��̾� �̸� ���� �ƴϸ� ���� �̸� ����
	string winner_name = (winner == PLAYER) ? m_player.GetName() : monsterVec[level - 1].GetName();
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "�١ڰ���ڡ�" << endl;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "���� : " << winner_name; 
	//���Ŀ� ����ġ�� ȹ�� ��� ���� ����
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "ȹ�� ����ġ : " << 50 * level;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "ȹ�� ��� : " << 300 * level;

	m_player.SetItem(exp, gold);
	
	//������ ������ ġ����� ������ hp�� �ִ��
	monsterVec[level - 1].MaxHp();
	
	_getch();
	Menu();
}

GameManager::~GameManager()
{
}
