#include "Player.h"

Player::Player() 
{
	m_level = 1;
	m_curExp = 0;
	m_curHp = m_maxHp;
	m_gold = 500;
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
	if(weapon != nullptr)
		m_power += weapon->m_damage;
}

void Player::MaxHp()
{
	m_curHp = m_maxHp;
}

void Player::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.3);
	cout << "Player : " << m_name << " Attack : " << m_power << " Hp : " << m_curHp << " Mana : " << m_mana;

	/*cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_exp << endl;
	cout << "Hp : " << m_curHp << " Gold : " << m_gold;*/
}

void Player::ShowInfo()
{
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT - 3);
	cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_curExp << endl;
	cout << "  Hp : " << m_curHp << " Gold : " << m_gold << " Attack : " << m_power << endl;

	if (weapon != nullptr)
	{
		cout << "  ���� ���� : " << weapon->m_strName << " ���ݷ� : " << weapon->m_damage;
	}
}

void Player::BuyShop(Weapon* weapon)
{
	
	this->weapon = weapon;
	m_gold -= weapon->m_gold;
}

