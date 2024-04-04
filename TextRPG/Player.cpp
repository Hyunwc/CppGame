#include "Player.h"

Player::Player() 
{
	m_level = 1;
	m_curExp = 0;
	m_curHp = m_maxHp;
	m_gold = 500;
	m_weaponpower = 0;
	m_mana = 0;
}

//Player::Player()
//{
//}

void Player::SetName(string name)
{
	m_name = name;
}

void Player::SetItem(int exp, int gold)
{
	m_curExp += exp;
	m_gold += gold;
}

void Player::LevelUp()
{
	//�� ����ġ�� maxExp�� �ʰ����� ��� ������
	if (m_curExp >= m_maxExp)
	{
		//������ ����ġ�� ������ �����صΰ�
		//������, �ִ����ġ ����, ���� ����ġ�� ������ ����ġ��
		int remain_Exp = m_curExp - m_maxExp;
		m_level++;
		m_maxExp += 100; 
		m_curExp = remain_Exp;
	}
	//����ġ�� �ѹ��� ���� �������� ������ ��� �����Ǿ���ϴ� ���߿� while������ �����غ����� ����
}

void Player::PowerUp()
{
	//weapon�� nullptr�� �ƴ� ��� �⺻���ݷ� + ������ ���ݷ� �߰�
	if(weapon != nullptr)
		m_damage += weapon->m_damage;
}

void Player::MaxHp()
{
	m_curHp = m_maxHp;
}

void Player::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.3);
	cout << "Player : " << m_name << " Attack : " << m_damage << " Hp : " << m_curHp << " Mana : " << m_mana;

	/*cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_exp << endl;
	cout << "Hp : " << m_curHp << " Gold : " << m_gold;*/
}

void Player::ShowInfo()
{
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT - 3);
	cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_curExp << endl;
	cout << "  Hp : " << m_curHp << " Gold : " << m_gold << " Power : (" << m_defaultpower << "+" << m_weaponpower << ")" << endl;

	if (weapon != nullptr)
	{
		cout << "  ���� ���� : " << weapon->m_strName << " ���ݷ� : " << weapon->m_damage;
	}
}

void Player::DataSave(int slot)
{
	ofstream save;
	save.open("SavePlayer" + to_string(slot) + ".txt");
	if (save.is_open())
	{
		save << m_name << " ";
		save << m_level << " ";
		save << m_curExp << " ";
		save << m_curHp << " ";
		save << m_defaultpower << " ";
		save << m_gold << " ";
		//���Ⱑ ������ ��쿡��
		if(weapon != nullptr)
			save << weapon->m_Type << endl;
		save.close();
	}
}

void Player::BuyShop(Weapon* weapon)
{
	this->weapon = weapon;
	m_weaponpower = weapon->m_damage;
	m_gold -= weapon->m_gold;

	PowerUp();
}

void Player::Reset()
{
	m_level = 1;
	m_curHp = m_maxHp;
	m_curExp = 0;
	m_defaultpower = 20;
	m_gold = 500;
	m_weaponpower = 0;
	if (weapon != nullptr)
	{
		delete weapon;
		weapon = nullptr;
	}
}

