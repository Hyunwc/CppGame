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

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << " ";
	gotoxy(-1, -1);
	return;
}

void MapDraw::WallDraw(int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		gotoxy(0, 0 + y);
		if (y == 0)
		{
			cout << "��";
			//y 0�̸鼭 x��ǥ���� ���α��̸�ŭ Ư����ȣ��
			for (int x = 1; x < width; x++)
			{
				cout << "��";
			}
		}
		else if (y == height - 1)
		{
			cout << "��";
			for (int x = 1; x < width; x++)
				cout << "��";
		}
		//������ ��ǥ �� x��ǥ���� ��������
		else
		{
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "��";
		}
	}
}

void MapDraw::ObstacleDraw(int x, int y)
{
	gotoxy(x, y);
	cout << "��";
}
