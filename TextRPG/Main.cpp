#include "GameManager.h"

int main()
{
	/*GameManager gmr;
	system("mode con cols=60 lines=40");
	while (1)
	{
		gmr.GameSetting();
	}*/
	
	//���⼭ �÷��̾�� �ٸ� Ŭ������ �۵� �ߵǴ��� �׽�Ʈ
	/*string name;
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;*/
	Character* m_cha = new Player("test");
	m_cha->ShowDisplay();
	delete m_cha;

	m_cha = new Monster();
	m_cha->ShowDisplay();

	return 0;
}