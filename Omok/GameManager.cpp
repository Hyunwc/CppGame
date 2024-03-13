#include "GameManager.h"

GameManager::GameManager() 
{
	m_mapSize.m_iWidth = 20;
	m_mapSize.m_iHeight = 20;
}

void GameManager::GameSetting()
{
	player.SetPosition(m_mapSize); //플레이어 좌표설정(오목판 가운데)
	MenuDraw(); 
}

void GameManager::MenuDraw()
{
	//처음에 화면 지운다.
	system("cls"); 
	int Select; //선택하기 위한 변수
	MapDraw::FieldDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight); //오목판 그리는 함수
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.3);
	cout << "★ 오 목 ★";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.4);
	cout << "1. 게임 시작";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.5);
	cout << "2. 게임 종료";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.7);
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
	player.Reset(); //모든 정보 초기화
	//MapDraw::FieldDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight); //오목판 그리기.
	//MenualDraw(); //조작법 출력
	player.StoneDraw();
	player.MenualUpdate();
	GamePlay();
}

void GameManager::GamePlay()
{
	while (1)
	{
		player.KeyInput();			
		if (player.WinStone() == true)
		{
			//system("pause");
			_getch();

			MenuDraw();
		}
	}
}



