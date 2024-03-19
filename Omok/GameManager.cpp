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
	cout << "2. ���÷���";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.6);
	cout << "3. ���� ����";
	MapDraw::gotoxy(m_mapSize.m_iWidth * 0.8, m_mapSize.m_iHeight * 0.7);
	cout << "�Է� : ";
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
	system("cls"); //���۰� ���ÿ� ���� ȭ�� �����.
	player.Reset(); //��� ���� �ʱ�ȭ
	player.StoneDraw();
	player.CursorDraw();
	player.MenualUpdate();
	GamePlay();
}

void GameManager::GamePlay()
{
	while (1)
	{
		
		//true ��ȯ������ EndGame() ȣ��
		if (player.KeyInput())
		{
			//EndGame();
			//true ��ȯ������ Saveȣ��
			player.Save();
			EndGame();
		}
	}
}

//�÷��̾� Ŭ�������� ����� ������ �о�;���
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



