#include "GameManager.h"

GameManager::GameManager()
{
}
//필요없으면 삭제할 예정
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
	cout << "☆★TEXT RPG★☆";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.4);
	cout << "1. New Game";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.5);
	cout << "2. Load Game";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.6);
	cout << "3. Exit";
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
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
	cout << "이름을 입력해주세요 : ";
	cin >> name;
	//이 곳에 플레이어에게 이름을 넘겨주는 코드 추가할 예정
	m_player.SetInfo(name);
	Menu();
}

void GameManager::Menu()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "☆★메뉴★☆";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.4);
	cout << "Colosseum";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.5);
	cout << "Shop";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.6);
	cout << "Save";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.7);
	cout << "Exit";
	m_player.ShowInfo();
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
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
		//상점 아직 개발 안됨
		break;
	}
	case 3:
	{
		//저장 아직 개발 안됨
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
	cout << "☆★아텐츠 콜로세움★☆";
	m_player.ShowDisplay();
	m_player.ShowInfo();
}

GameManager::~GameManager()
{
}
