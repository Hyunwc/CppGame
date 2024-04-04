#include "Monster.h"


Monster::Monster()
{
}

Monster::Monster(string name, int level, int hp, int power)
{
	m_name = name;
	m_level = level;
	m_curHp = hp;
	m_maxHp = hp;
	m_damage = power;
}


void Monster::SetData(string name, int level, int hp, int power)
{
	m_name = name;
	m_level = level;
	m_curHp = hp;
	m_defaultpower = power;
}

void Monster::ShowInfo()
{

}

void Monster::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.5);
	cout << "Monster : " << m_name << " Attack : " << m_damage << " Hp : " << m_curHp;
}

void Monster::MaxHp()
{
	m_curHp = m_maxHp;
}
