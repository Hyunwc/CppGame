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
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.25);
	cout << "�١�TEXT RPG�ڡ�";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "1. New Game";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.55);
	cout << "2. Load Game";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.65);
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
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.3);
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
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT - 3);
	MapDraw::gotoxy(WIDTH * 0.75, HEIGHT * 0.25);
	cout << "�١ڸ޴��ڡ�";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "Colosseum";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.55);
	cout << "Shop";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.65);
	cout << "Save";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.78);
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
	//MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
	//cout << "�١��ݷμ���ڡ�";
	//m_player.ShowDisplay();
	//m_player.ShowInfo();
	GamePlay();
}

void GameManager::GamePlay()
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
		m_monster.ShowDisplay();
		
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
				m_monster.takeDamage(m_player.GetDamage());
				MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
				cout << m_monster.GetName() << "���� " << m_player.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
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
			m_player.takeDamage(m_monster.GetDamage());
			MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
			cout << m_player.GetName() << "���� " << m_monster.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
		}

		if (m_player.DeadCheck() || m_monster.DeadCheck())
		{
			//���Ͱ� �׾��ٸ� �÷��̾��� ����Ÿ���� �ƴϸ� ���ͷ�
			ResultBord(m_player.DeadCheck() ? MONSTER : PLAYER, m_monster.GetLevel());
		}


		heroTurn = !heroTurn;

		_getch();
	}
}

void GameManager::ResultBord(int winner, int level)
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
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "ȹ�� ����ġ : " << 50 * level;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "ȹ�� ��� : " << 300 * level;


	_getch();
	Menu();
}

GameManager::~GameManager()
{
}
