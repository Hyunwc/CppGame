#include "Player.h"

Player::Player() : stone("��"), isBlackTurn(true)
{
}

void Player::SetPosition(const Size& _mapSize)
{
	//�� �߾ӿ� �ٵϵ��� �׸��� ����
	stonePos.m_ix = _mapSize.m_iWidth / 2;
	stonePos.m_iy = _mapSize.m_iHeight / 2;
	
}

void Player::StoneDraw()
{
	MapDraw::FieldDraw(20, 20); //������ ���� �ٽ� �׸��� ����
	MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);
}

void Player::StoneErase()
{
	MapDraw::ErasePoint(stone, stonePos.m_ix, stonePos.m_iy);
}


void Player::KeyInput()
{
	char ch;
	//Ű���� �Է°��� ����
	if (_kbhit())
	{
		ch = _getch();
	
		switch (ch)
		{
		case KEY_LEFT:
		case KEY_RIGHT:
		case KEY_UP:
		case KEY_DOWN:
		{
			Move(ch);
			break;
		}
		//�ٵϵ� ���� ��� �߰� ����
		case KEY_ENTER:
		{
			stoneVec.push_back(stonePos);
		}
		}
	}
}

void Player::Move(char input)
{
	switch (input)
	{
	case KEY_LEFT:
	{
		//x = 0 �̻��϶������� //���߿� ������ ����
		if (stonePos.m_ix - 1 >= 0)
		{
			stonePos.m_ix--;
			break;
		}
	}
	case KEY_RIGHT:
	{
		//x = 20 ���� 
		if (stonePos.m_ix + 1 < 20)
		{
			stonePos.m_ix++;
			break;
		}
	}
	case KEY_UP:
	{
		if (stonePos.m_iy - 1 >= 0)
		{
			stonePos.m_iy--;
			break;
		}
	}
	case KEY_DOWN:
	{
		if (stonePos.m_iy + 1 < 20)
		{
			stonePos.m_iy++;
			break;
		}
	}
	//�ٵϵ� ���� ��� �߰� ����
	case KEY_ENTER:
	{

	}
	}


	StoneErase();  //���� ������ �ִ� �ٵϵ��� �����
	//stonePos = nextPos; //�ٵϵ��� ��ǥ�� nextPos�� ������Ʈ
	MapDraw::testDraw(stoneVec, stone, 20, 20, stonePos.m_ix, stonePos.m_iy);
	//StoneDraw(); //������Ʈ�� ��ǥ�� �ٵϵ��� �׸���.
}
