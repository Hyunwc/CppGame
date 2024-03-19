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
	cout << "2. 리플레이";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.6);
	cout << "3. 게임 종료";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.7);
	cout << "입력 : ";
	cin >> Select;
	switch (Select)
	{
	case 1:
		GameStart();
		break;
	case 2:
		RePlay();
		break;
	case 3:
		exit(0);
	}
}

void GameManager::GameStart()
{
	system("cls"); //시작과 동시에 기존 화면 지운다.
	player.Reset(); //모든 정보 초기화
	player.StoneDraw();
	player.CursorDraw();
	player.MenualUpdate();
	GamePlay();
}

void GameManager::GamePlay()
{
	while (1)
	{
		
		//true 반환받으면 EndGame() 호출
		if (player.KeyInput())
		{
			//EndGame();
			//true 반환받으면 Save호출
			player.Save();
			EndGame();
		}
	}
}

//플레이어 클래스에서 저장된 정보를 읽어와야함
void GameManager::RePlay()
{
	system("cls");
	
	player.Load();
	if (player.LoadDraw())
	{
		EndGame();
	}
	//system("pause");
}

void GameManager::EndGame()
{
	_getch();
	MenuDraw();
}



