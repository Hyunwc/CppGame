#include "GameManager.h"

int main()
{
	GameManager gmr;
	system("mode con cols=60 lines=40");
	while (1)
	{
		gmr.GameSetting();
	}
	
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