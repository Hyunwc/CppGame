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
	system("cls"); //시작과 동시에 기존 화면 지운다.
	MapDraw::FieldDraw(width, height); //오목판 그리기.
	MenualDraw(); //조작법 출력
}

void GameManager::MenualDraw()
{
	MapDraw::gotoxy(width * 0.8, height + 2);
	cout << "====조작키====" << endl;
	cout << "이동 : A, S, W, D  돌놓기 : ENTER" << endl;
	cout << "무르기 : N 종료 : ESC" << endl;
	cout << "Player Name : " << "무르기 : 5" << endl;
	cout << "Turn : ";
}
