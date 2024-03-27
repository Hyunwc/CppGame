#include "GameManager.h"

GameManager::GameManager()
{
	srand(static_cast<unsigned int>(time(0)));
}
//�ʿ������ ������ ����
void GameManager::GameSetting()
{
	//MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	GameTitle();
}

void GameManager::GameTitle()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "�١�TEXT RPG�ڡ�";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.4);
	cout << "1. New Game";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.5);
	cout << "2. Load Game";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.6);
	cout << "3. Exit";
	//�޴� ����, Ŀ�� y��ǥ�� �󸶸�ŭ ������ , �ʱ� x,y ��ǥ��
	Select = MapDraw::MenuSelectCursor(3, 3, WIDTH * 0.8, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		NewGame();
		break;
	}
	case 2:
	{
		break;
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
	MapDraw::gotoxy(WIDTH * 0.6, HEIGHT * 0.3);
	cout << "�̸��� �Է����ּ��� : ";
	cin >> name;
	//�� ���� �÷��̾�� �̸��� �Ѱ��ִ� �ڵ� �߰��� ����
	m_player.SetInfo(name);
	Menu();
}

void GameManager::Menu()
{
	//ȭ�� ����� �� �ٽ� �׸�
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "�١ڸ޴��ڡ�";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.4);
	cout << "Colosseum";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.5);
	cout << "Shop";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.6);
	cout << "Save";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.7);
	cout << "Exit";
	m_player.ShowInfo();
	//�޴� ����, Ŀ�� y��ǥ�� �󸶸�ŭ ������ , �ʱ� x,y ��ǥ��
	Select = MapDraw::MenuSelectCursor(4, 3, WIDTH * 0.8, HEIGHT * 0.4);
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
		break;
	}
	case 3:
	{
		//���� ���� ���� �ȵ�
		break;
	}
	case 4:
	{
		return;
	}
	default:
		break;
	}
}

void GameManager::Colosseum()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.1);
	cout << "�١��ݷμ���ڡ�";
	m_player.ShowDisplay();
	m_player.ShowInfo();
	GamePlay();
}

void GameManager::GamePlay()
{
	int Select;
	//���� ���� �����Ұ��� ����
	bool heroTurn = rand() % 2;

	while (1)
	{
		system("cls");
		m_player.ShowDisplay();
		MapDraw::gotoxy(WIDTH, HEIGHT * 0.3);
		cout << "vs";
		m_monster.ShowDisplay();
		string name = heroTurn ? m_player.GetName() : m_monster.GetName();
		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.8);
		cout << "���� �� : " << name;
		if (heroTurn)
		{
			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.6);
			cout << "1. �⺻ ���� 2. �ʻ��(50 ���� �ʿ�) �Է� : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
			{
				m_monster.takeDamage(m_player.GetDamage());
				MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
				cout << m_monster.GetName() << "���� " << m_player.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
				//cout << "�⺻ ���� ����!";
				break;
			}
			case 2:
			{

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
			Sleep(2000);
			m_player.takeDamage(m_monster.GetDamage());
			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
			cout << m_player.GetName() << "���� " << m_monster.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
		}

		if (m_player.DeadCheck() || m_monster.DeadCheck())
		{
			//���Ͱ� �׾��ٸ� �÷��̾��� ����Ÿ���� �ƴϸ� ���ͷ�
			ResultBord(m_player.DeadCheck() ? MONSTER : PLAYER);
		}


		heroTurn = !heroTurn;

		system("pause");
	}
}

void GameManager::ResultBord(int winner)
{
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	//���ڰ� �÷��̾�� �÷��̾� �̸� ���� �ƴϸ� ���� �̸� ����
	string winner_name = (winner == PLAYER) ? m_player.GetName() : m_monster.GetName();
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "�١ڰ���ڡ�" << endl;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "���� : " << winner_name; 
	//���Ŀ� ����ġ�� ȹ�� ��� ���� ����

	_getch();
	Menu();
}

GameManager::~GameManager()
{
}
