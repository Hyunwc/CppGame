#include "GameManager.h"

GameManager::GameManager()
{
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
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	string name;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "�̸��� �Է����ּ��� : ";
	cin >> name;
	//�� ���� �÷��̾�� �̸��� �Ѱ��ִ� �ڵ� �߰��� ����
	m_player.SetInfo(name);
	Menu();
}

void GameManager::Menu()
{
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
	cout << "�١ھ����� �ݷμ���ڡ�";
	m_player.ShowDisplay();
	m_player.ShowInfo();
}

GameManager::~GameManager()
{
}
