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
	//현 경험치가 maxExp를 초과했을 경우 레벨업
	if (m_curExp >= m_maxExp)
	{
		//나머지 경험치를 변수에 저장해두고
		//레벨업, 최대경험치 증가, 현재 경험치를 나머지 경험치로
		int remain_Exp = m_curExp - m_maxExp;
		m_level++;
		m_maxExp += 100; 
		m_curExp = remain_Exp;
	}
	//경험치가 한번에 많이 들어왔을때 레벨이 계속 증가되어야하니 나중에 while문으로 수정해보도록 하자
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
		cout << "  장착 무기 : " << weapon->m_strName << " 공격력 : " << weapon->m_damage;
	}
}

void Player::BuyShop(Weapon* weapon)
{
	
	this->weapon = weapon;
	m_gold -= weapon->m_gold;
}

