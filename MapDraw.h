#pragma once
#include "Mecro.h"

class MapDraw
{
public:
	MapDraw();
	void DrawPoint(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void ErasePoint(int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};