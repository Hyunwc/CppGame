#include "Player.h"

Player::Player() : stone("��"), isBlackTurn(true), playerName("Black")
{
	turn = 0;
}

void Player::SetPosition(const Size& _mapSize)
{
	//�� �߾ӿ� �ٵϵ��� �׸��� ����
	stonePos.m_ix = _mapSize.m_iWidth / 2;
	stonePos.m_iy = _mapSize.m_iHeight / 2;
	blackSavePos = stonePos;
	whiteSavePos = stonePos;
}

void Player::StoneDraw()
{
	//MapDraw::FieldDraw(20, 20); //������ ���� �ٽ� �׸��� ����
	//MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);
	for (const auto& pos : BlackStoneVec)
		MapDraw::DrawPoint("��", pos.m_ix, pos.m_iy);

	for (const auto& pos : WhiteStoneVec)
		MapDraw::DrawPoint("��", pos.m_ix, pos.m_iy);

	MapDraw::DrawPoint(stone, stonePos.m_ix, stonePos.m_iy);

	/*if(isBlackTurn)
		MapDraw::DrawPoint(stone, blackSavePos.m_ix, blackSavePos.m_iy);
	else
		MapDraw::DrawPoint(stone, whiteSavePos.m_ix, whiteSavePos.m_iy);*/
}

void Player::StoneErase(Position prevPos)
{
	//MapDraw::ErasePoint(stone, prevPos.m_ix, prevPos.m_iy);
	//���޹��� ������ǥ�� ���ǿ� �´� ��ȣ�� �׸���.
	MapDraw::gotoxy(prevPos.m_ix * 2, prevPos.m_iy);
	if (prevPos.m_ix == 0 && prevPos.m_iy == 0)
		cout << "��";
	else if (prevPos.m_ix == 19 && prevPos.m_iy == 0)
		cout << "��";
	else if (prevPos.m_ix == 0 && prevPos.m_iy == 19)
		cout << "��";
	else if (prevPos.m_ix == 19 && prevPos.m_iy == 19)
		cout << "��";
	else if (prevPos.m_ix == 0)
		cout << "��";
	else if (prevPos.m_ix == 19)
		cout << "��";
	else if (prevPos.m_iy == 0)
		cout << "��";
	else if (prevPos.m_iy == 19)
		cout << "��";
	else
		cout << "��";
}


void Player::KeyInput()
{
	//���� ���� ��ǥ ����
	Position prevPos = stonePos;
	//Ű���� �Է°��� ����
	if (_kbhit())
	{
		switch (_getch())
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
			turn++;

			if (isBlackTurn)
			{
				//MapDraw::gotoxy(blackSavePos.m_ix, blackSavePos.m_iy);
				BlackStoneVec.push_back(stonePos);
				blackSavePos = stonePos;
				stone = "��";
				playerName = "White";
				isBlackTurn = false;
			}
			else
			{
				//MapDraw::gotoxy(whiteSavePos.m_ix, whiteSavePos.m_iy);
				WhiteStoneVec.push_back(stonePos);
				whiteSavePos = stonePos;
				stone = "��";
				playerName = "Black";
				isBlackTurn = true;
			}
			break;
		}
		}

		StoneErase(prevPos);  //���� ���� ��ǥ�� ������.
		StoneDraw(); //������Ʈ�� ��ǥ�� �ٵϵ��� �׸���.
	}
}

void Player::CursorUpdate()
{
	//������ �Ǿ����� �ٷ� Ŀ�� ������Ʈ�ع�����
	if (isBlackTurn)
	{
		MapDraw::gotoxy(blackSavePos.m_ix * 2, blackSavePos.m_iy);
	}
	else
	{
		MapDraw::gotoxy(whiteSavePos.m_ix * 2, whiteSavePos.m_iy);
	}
}
