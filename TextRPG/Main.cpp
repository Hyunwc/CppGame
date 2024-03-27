#include "GameManager.h"


int main()
{
	GameManager gmr;
	system("mode con cols=60 lines=30");

	gmr.GameSetting();
	
	//Player player;
	//Monster monster;

	//int Select;
	////누가 먼저 공격할건지 결정
	//bool heroTurn = rand() % 2;
	//player.SetInfo("태현");

	//while (1)
	//{
	//	system("cls");
	//	player.ShowDisplay();
	//	MapDraw::gotoxy(WIDTH, HEIGHT * 0.3);
	//	cout << "vs";
	//	monster.ShowDisplay();
	//	string name = heroTurn ? player.GetName() : monster.GetName();
	//	MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.8);
	//	cout << "현재 턴 : " << name;
	//	if (heroTurn)
	//	{
	//		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.6);
	//		cout << "1. 기본 공격 2. 필살기(50 마나 필요) 입력 : ";
	//		cin >> Select;
	//		switch (Select)
	//		{
	//		case 1:
	//		{
	//			monster.takeDamage(player.GetDamage());
	//			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
	//			cout << monster.GetName() << "에게 " << player.GetDamage() << "만큼의 데미지를 주었습니다!";
	//			//cout << "기본 공격 성공!";
	//			break;
	//		}
	//		case 2:
	//		{
	//			
	//			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
	//			cout << "필살기!";
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
	//		cout << player.GetName() << "에게 " << monster.GetDamage() << "만큼의 데미지를 주었습니다!";
	//	}

	//	if (player.DeadCheck() || monster.DeadCheck())
	//	{
	//		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.5);
	//		cout << "게임 종료 !";
	//		system("pause");
	//	}
	//		

	//	heroTurn = !heroTurn;

	//	system("pause");
	//}

	
	//여기서 플레이어랑 다른 클래스들 작동 잘되는지 테스트
	//다형성을 나타내는 
	/*Character* m_cha = new Player("test");
	m_cha->ShowDisplay();
	delete m_cha;

	m_cha = new Monster();
	m_cha->ShowDisplay();
	delete m_cha;*/
	return 0;
}

