#include "GameManager.h"

GameManager::GameManager() 
{
	m_mapSize.m_iWidth = 20;
	m_mapSize.m_iHeight = 20;
}

void GameManager::GameSetting()
{
	player.SetPosition(m_mapSize); //�÷��̾� ��ǥ����(������ ���)
	MenuDraw(); 
}

void GameManager::MenuDraw()
{
	//ó���� ȭ�� �����.
	system("cls"); 
	int Select; //�����ϱ� ���� ����
	MapDraw::FieldDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight); //������ �׸��� �Լ�
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.3);
	cout << "�� �� �� ��";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.4);
	cout << "1. ���� ����";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.5);
	cout << "2. ���� ����";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.7);
	cout << "�Է� : ";
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
	system("cls"); //���۰� ���ÿ� ���� ȭ�� �����.
	MapDraw::FieldDraw(m_mapSize.m_iWidth, m_mapSize.m_iHeight); //������ �׸���.
	//MenualDraw(); //���۹� ���
	player.StoneDraw();
	GamePlay();
}

void GameManager::GamePlay()
{
	MenualDraw(); //���۹��� ������ִ� �Լ� ȣ��
	
	while (1)
	{
		player.KeyInput();
		//player.CursorUpdate();
		//MenualDraw();
		if (player.WinCheck())
		{
			MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight + 3);
			cout << "�¸�";
		}
			
	}
}



void GameManager::MenualDraw()
{
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight + 2);
	cout << "====����Ű====" << endl;
	cout << "�̵� : A, S, W, D  ������ : ENTER" << endl;
	cout << "������ : N ���� : ESC" << endl;
	cout << "Player Name : " << player.playerName << " ������ : 5" << endl;
	cout << "Turn : " << player.turn;
}


