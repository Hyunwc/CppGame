#include "Character.h"

Character::Character() : m_maxHp(100)
{
}

void Character::ShowDisplay()
{
	cout << "정보창입니다" << endl;
}

bool Character::DeadCheck()
{
	return m_curHp <= 0;
}

Character::~Character()
{
}

Player::Player(string name)
{
	m_name = name;
	m_level = 1;
	m_exp = 0;
	m_curHp = m_maxHp;
	m_gold = 100;
	m_mana = 0;
}

void Player::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT + 1);
	cout << "Player : " << m_name << " Hp : " << m_curHp << " Mana : " << m_mana;
	
	/*cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_exp << endl;
	cout << "Hp : " << m_curHp << " Gold : " << m_gold;*/
}

Monster::Monster()
{
	m_name = "오크";
	m_curHp = m_maxHp;
}

void Monster::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT + 1);
	cout << "Monster : " << m_name << " Hp : " << m_curHp;
}
