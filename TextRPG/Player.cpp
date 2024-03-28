#include "Player.h"

Player::Player() 
{
	m_level = 1;
	m_exp = 0;
	m_curHp = m_maxHp;
	m_gold = 500;
	m_mana = 0;
}

//Player::Player()
//{
//}

void Player::SetInfo(string name)
{
	m_name = name;
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
	cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_exp << endl;
	cout << "  Hp : " << m_curHp << " Gold : " << m_gold;
}

