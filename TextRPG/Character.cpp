#include "Character.h"

Character::Character() : m_maxHp(100), m_power(20), m_maxExp(100)
{
}

void Character::ShowDisplay()
{
	cout << "정보창입니다" << endl;
}

void Character::ShowInfo()
{
}

//void Character::SetInfo()
//{
//}



void Character::SetItem(int exp, int gold)
{
}

void Character::LevelUp()
{
}

void Character::MaxHp()
{

}

void Character::Observer()
{
	/*MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.8);
	cout << "현재 턴 : " << ()*/
}

void Character::PowerUp(Weapon* weapon)
{
}

void Character::takeDamage(int damage)
{
	m_curHp -= damage;
}

bool Character::DeadCheck()
{
	return m_curHp <= 0;
}

Character::~Character()
{
}


