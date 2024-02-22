#include "GameManager.h"

void GameManager::GameSetting()
{
	MenuDraw();
}

void GameManager::MenuDraw()
{
	//처음에 화면 지운다.
	system("cls"); 
	int Select; //선택하기 위한 변수
	MapDraw::FieldDraw(width, height); //오목판 그리는 함수
	MapDraw::gotoxy(width * 0.8, height * 0.3);
	cout << "★ 오 목 ★";
	MapDraw::gotoxy(width * 0.8, height * 0.4);
	cout << "1. 게임 시작";
	MapDraw::gotoxy(width * 0.8, height * 0.5);
	cout << "2. 게임 종료";
	MapDraw::gotoxy(width * 0.8, height * 0.7);
	cout << "입력 : ";
	cin >> Select;
	switch (Select)
	{
	case 1:
		GameStart();
		break;
	case 2:
		return;
	}
}

void GameManager::GameStart()
{
}

void GameManager::MenualDraw()
{
}
