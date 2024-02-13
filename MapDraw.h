#pragma once
#include "Mecro.h"

//정적 클래스로 만든 이유는 불필요한 인스턴스 생성 방지
static class MapDraw
{
public:
	static void DrawPoint(string str, int x, int y);
	static void TextDraw(string str, int x, int y);
	static void DrawMidText(string str, int x, int y);
	static void ErasePoint(string str, int x, int y);
	static void TextErase(int x, int y);
	static void WallDraw(int width, int height);
	//static void WallDraw(vector<Position> WallSet);
	static void ObstacleDraw(set<Position> ObsSet);
	static void HeartDraw(set<Position> HeartSet);
	static inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};