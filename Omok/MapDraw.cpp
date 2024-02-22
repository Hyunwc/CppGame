#include "MapDraw.h"

void MapDraw::FieldDraw(int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			gotoxy(x * 2, y);
			if (x == 0 && y == 0)
				cout << "¦£";
			else if(x == width - 1 && y == 0)
				cout << "¦¤";
			else if (x == 0 && y == height - 1)
				cout << "¦¦";
			else if (x == width - 1 && y == height - 1)
				cout << "¦¥";
			else if (x == 0)
				cout << "¦§";
			else if (x == width - 1)
				cout << "¦©";
			else if (y == 0)
				cout << "¦¨";
			else if (y == height - 1)
				cout << "¦ª";
			else
				cout << "¦«";
		}
	}
}

void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDraw::ErawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
