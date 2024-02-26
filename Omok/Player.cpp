#include "Player.h"

Player::Player() : stone("��")
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
	MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);
}

void Player::StoneErase()
{
	MapDraw::ErasePoint(stone, stonePos.m_ix, stonePos.m_iy);
}


void Player::KeyInput()
{
	Position nextPos = stonePos;
	//Ű���� �Է°��� ����
	if (_kbhit())
	{
		//�켱 ���� �׷��� �ٵϵ��� �����
		//MapDraw::TextErase(stone, stonePos.m_ix * 2, stonePos.m_iy);
		
		switch (_getch())
		{
		case KEY_LEFT:
		{
			//x = 0 �̻��϶������� //���߿� ������ ����
			if (nextPos.m_ix > 0)
			{
				nextPos.m_ix--;
				break;
			}
		}	
		case KEY_RIGHT:
		{
			//x = 20 ���� 
			if (nextPos.m_ix <= 19)
			{
				nextPos.m_ix++;
				break;
			}
		}	
		case KEY_UP:
		{
			if (nextPos.m_iy >= 0)
			{
				nextPos.m_iy--;
				break;
			}
		}
		case KEY_DOWN:
		{
			if (nextPos.m_iy < 19)
			{
				nextPos.m_iy++;
				break;
			}
		}
		}

		StoneErase();  //���� ������ �ִ� �ٵϵ��� �����
		stonePos = nextPos; //�ٵϵ��� ��ǥ�� nextPos�� ������Ʈ
		StoneDraw(); //������Ʈ�� ��ǥ�� �ٵϵ��� �׸���.
	}
}
