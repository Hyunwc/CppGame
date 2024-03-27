#include "Character.h"

Character::Character() : m_maxHp(100), m_damage(20)
{
}

void Character::ShowDisplay()
{
	cout << "정보창입니다" << endl;
}

void Character::ShowInfo()
{
}

void Character::SetInfo()
{
}

void Character::Observer()
{
	/*MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.8);
	cout << "현재 턴 : " << ()*/
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


