#include "GameManager.h"


int main()
{
	GameManager gmr;
	system("mode con cols=60 lines=30");

	gmr.GameSetting();
	
	//Player player;
	//Monster monster;

	//int Select;
	////���� ���� �����Ұ��� ����
	//bool heroTurn = rand() % 2;
	//player.SetInfo("����");

	//while (1)
	//{
	//	system("cls");
	//	player.ShowDisplay();
	//	MapDraw::gotoxy(WIDTH, HEIGHT * 0.3);
	//	cout << "vs";
	//	monster.ShowDisplay();
	//	string name = heroTurn ? player.GetName() : monster.GetName();
	//	MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.8);
	//	cout << "���� �� : " << name;
	//	if (heroTurn)
	//	{
	//		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.6);
	//		cout << "1. �⺻ ���� 2. �ʻ��(50 ���� �ʿ�) �Է� : ";
	//		cin >> Select;
	//		switch (Select)
	//		{
	//		case 1:
	//		{
	//			monster.takeDamage(player.GetDamage());
	//			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
	//			cout << monster.GetName() << "���� " << player.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
	//			//cout << "�⺻ ���� ����!";
	//			break;
	//		}
	//		case 2:
	//		{
	//			
	//			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
	//			cout << "�ʻ��!";
	//			break;
	//		}
	//		default:
	//			break;
	//		}
	//	}
	//	else
	//	{
	//		Sleep(2000);
	//		player.takeDamage(monster.GetDamage());
	//		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
	//		cout << player.GetName() << "���� " << monster.GetDamage() << "��ŭ�� �������� �־����ϴ�!";
	//	}

	//	if (player.DeadCheck() || monster.DeadCheck())
	//	{
	//		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.5);
	//		cout << "���� ���� !";
	//		system("pause");
	//	}
	//		

	//	heroTurn = !heroTurn;

	//	system("pause");
	//}

	
	//���⼭ �÷��̾�� �ٸ� Ŭ������ �۵� �ߵǴ��� �׽�Ʈ
	//�������� ��Ÿ���� 
	/*Character* m_cha = new Player("test");
	m_cha->ShowDisplay();
	delete m_cha;

	m_cha = new Monster();
	m_cha->ShowDisplay();
	delete m_cha;*/
	return 0;
}

