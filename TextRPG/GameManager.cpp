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
		GamePlay();
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

void GameManager::GamePlay()
{
	cout << "이름을 입력해주세요 : ";
	
}

GameManager::~GameManager()
{
}
