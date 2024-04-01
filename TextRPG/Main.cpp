#include "GameManager.h"


int main()
{
	GameManager gmr;
	system("mode con cols=50 lines=25");

	//gmr.GameSetting();
	
	Character* test1 = new Player;
	Weapon wea{ WEAPON_AXE, "금도끼", 50, 500 };
	test1->ShowDisplay();
	test1->PowerUp(&wea);

	test1->ShowDisplay();
	delete test1;


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

