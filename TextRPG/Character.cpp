#include "Character.h"

Character::Character() : m_maxHp(100)
{
}

void Character::ShowDisplay()
{
	cout << "����â�Դϴ�" << endl;
}

void Character::ShowInfo()
{
}

void Character::SetInfo()
{
}

bool Character::DeadCheck()
{
	return m_curHp <= 0;
}

Character::~Character()
{
}


