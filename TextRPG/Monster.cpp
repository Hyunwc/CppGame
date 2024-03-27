#include "Monster.h"


Monster::Monster()
{
	m_name = "ø¿≈©";
	m_curHp = m_maxHp;
}

void Monster::ShowDisplay()
{
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT + 1);
	cout << "Monster : " << m_name << " Hp : " << m_curHp;
}

