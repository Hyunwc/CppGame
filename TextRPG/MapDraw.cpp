#include "MapDraw.h"


MapDraw::MapDraw()
{

}

void MapDraw::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;

	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == Height - 1)
		{
			cout << "��";
			for(int x = 1; x < Width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "��";
		}
	}
	return;
}

void MapDraw::BoxErase(int Width, int Height)
{
	for (int y = 1; y < Height - 1; y++)
	{
		gotoxy(2, y);
		for (int x = 1; x < Width - 1; x++)
			cout << "  ";
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


void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

int MapDraw::MenuSelectCursor(int MenuLen, double AddCol, int x, int y)
{
	int Select = 1;
	//�ʱ⿡ ȭ��ǥ �׸��� 1. NewGame �κп�
	DrawPoint("��", x / 2, y);
	while (1)
	{
		//�Է°��� ����
		switch (_getch())
		{
			//���� Ŭ���Ͽ����� 
		case UP:
			//1�̻��϶��� ����� ��ȯ�ϴ� ����Ʈ��-- 
			if (Select - 1 >= 1)
			{
				ErasePoint(x / 2, y);
				y -= AddCol;
				Select--;
			}
			break;
		case DOWN:
			if (Select + 1 <= MenuLen)
			{
				ErasePoint(x / 2, y);
				y += AddCol;
				Select++;
			}
			break;
		case ENTER:
			return Select;
		}
		DrawPoint("��", x / 2, y);
	}
	return 0;
}



MapDraw::~MapDraw()
{
}
