#include "GameManager.h"


int main()
{
	GameManager gmr;
	system("mode con cols=50 lines=25");

	//gmr.GameSetting();
	
	Character* test1 = new Player;
	Weapon wea{ WEAPON_AXE, "�ݵ���", 50, 500 };
	test1->ShowDisplay();
	test1->PowerUp(&wea);

	test1->ShowDisplay();
	delete test1;


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

