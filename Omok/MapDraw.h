#pragma once
#include "Mecro.h"

static class MapDraw
{
public:
	static void FieldDraw(int width, int height);
	static void DrawPoint(string str, int x, int y);
	static void TextDraw(string str, int x, int y);
	static void TextErase(string str, int x, int y);
	static void DrawMidText(string str, int x, int y);
	static void ErasePoint(string str, int x, int y);
	static void StoneDraw(vector<Position> vec);
	static void testDraw(vector<Position> vec, string str, int width, int height, int x, int y);
	static inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};