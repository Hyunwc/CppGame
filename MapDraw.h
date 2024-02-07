#pragma once
#include "Mecro.h"

//���� Ŭ������ ���� ������ ���ʿ��� �ν��Ͻ� ���� ����
static class MapDraw
{
public:
	static void DrawPoint(string str, int x, int y);
	static void TextDraw(string str, int x, int y);
	static void DrawMidText(string str, int x, int y);
	static void ErasePoint(int x, int y);
	static void WallDraw(int width, int height);
	static void ObstacleDraw(vector<Position> Obsvec);
	static void HeartDraw(vector<Position> Heartvec);
	static inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};