#include "Monster.h"


Monster::Monster()
{
	m_name = "ø¿≈©";
	m_curHp = m_maxHp;
	m_damage = 10;
}

void Monster::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.45);
	cout << "Monster : " << m_name << " Hp : " << m_curHp;
}

