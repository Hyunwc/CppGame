#include "GameManager.h"

void GameManager::GameSetting()
{
	MenuDraw();
}

void GameManager::MenuDraw()
{
	//ó���� ȭ�� �����.
	system("cls"); 
	int Select; //�����ϱ� ���� ����
	MapDraw::FieldDraw(width, height); //������ �׸��� �Լ�
	MapDraw::gotoxy(width * 0.8, height * 0.3);
	cout << "�� �� �� ��";
	MapDraw::gotoxy(width * 0.8, height * 0.4);
	cout << "1. ���� ����";
	MapDraw::gotoxy(width * 0.8, height * 0.5);
	cout << "2. ���� ����";
	MapDraw::gotoxy(width * 0.8, height * 0.7);
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
	MapDraw::FieldDraw(width, height); //������ �׸���.
	MenualDraw(); //���۹� ���
}

void GameManager::MenualDraw()
{
	MapDraw::gotoxy(width * 0.8, height + 2);
	cout << "====����Ű====" << endl;
	cout << "�̵� : A, S, W, D  ������ : ENTER" << endl;
	cout << "������ : N ���� : ESC" << endl;
	cout << "Player Name : " << "������ : 5" << endl;
	cout << "Turn : ";
}
