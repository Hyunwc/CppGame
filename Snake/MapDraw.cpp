#include "MapDraw.h"


void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDraw::ErasePoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void MapDraw::TextErase(string str, int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
}


void MapDraw::WallDraw(set<Position> WallSet)
{
	for (const auto& wall : WallSet)
	{
		gotoxy(wall.m_ix * 2, wall.m_iy);
		cout << "¢Ë";
	}
}

void MapDraw::ObstacleDraw(set<Position> ObsSet)
{
	for (const auto& obs : ObsSet)
	{
		gotoxy(obs.m_ix * 2, obs.m_iy);
		cout << "¢Ë";
	}
}

void MapDraw::HeartDraw(set<Position> HeartSet)
{
	//int CurClock, CountClock;
	//CountClock = clock();
	/*for (const auto& heart : HeartSet)
	{
		gotoxy(heart.m_ix * 2, heart.m_iy);
		cout << "¢¾";
	}*/
	for (auto itr = HeartSet.begin(); itr != HeartSet.end(); itr++)
	{
		gotoxy(itr->m_ix * 2, itr->m_iy);
		cout << "¢¾";
	}
}

