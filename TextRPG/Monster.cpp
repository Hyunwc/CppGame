#include "Monster.h"


Monster::Monster()
{
	m_name = "ø¿≈©";
	m_curHp = m_maxHp;
	m_power = 10;
	m_level = 1;
}

void Monster::ShowInfo()
{

}

void Monster::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.5);
	cout << "Monster : " << m_name << " Attack : " << m_power << " Hp : " << m_curHp;
}

void Monster::MaxHp()
{
	m_curHp = m_maxHp;
}
