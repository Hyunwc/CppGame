#include "Player.h"

Player::Player() : stone("��"), isBlackTurn(true), playerName("Black"), map{ {CHECK_EMPTY} }
{
	turn = 1;
}

void Player::SetPosition(const Size& _mapSize)
{
	//�� �߾ӿ� �ٵϵ��� �׸��� ����
	curPos.m_ix = _mapSize.m_iWidth / 2;
	curPos.m_iy = _mapSize.m_iHeight / 2;
	//����, ���� _mapSize�� �ʱ�ȭ
	height = _mapSize.m_iHeight;
	width = _mapSize.m_iWidth;
	blackSavePos = curPos;
	whiteSavePos = curPos;
}

void Player::StoneDraw()
{
	//�����̳ʿ� ����� �浹 Draw
	for (const auto& pos : BlackStoneVec)
		MapDraw::DrawPoint("��", pos.m_ix, pos.m_iy);
	//�����̳ʿ� ����� �鵹 Draw
	for (const auto& pos : WhiteStoneVec)
		MapDraw::DrawPoint("��", pos.m_ix, pos.m_iy);

	if (isBlackTurn)
		stone = "��";
	else
		stone = "��";

	MapDraw::DrawPoint(stone, curPos.m_ix, curPos.m_iy);
}

void Player::StoneErase(Position prevPos)
{
	//MapDraw::ErasePoint(stone, prevPos.m_ix, prevPos.m_iy);
	//���޹��� ������ǥ�� ���ǿ� �´� ��ȣ�� �׸���.
	MapDraw::gotoxy(prevPos.m_ix * 2, prevPos.m_iy);
	if (prevPos.m_ix == 0 && prevPos.m_iy == 0)
		cout << "��";
	else if (prevPos.m_ix == width - 1 && prevPos.m_iy == 0)
		cout << "��";
	else if (prevPos.m_ix == 0 && prevPos.m_iy == height - 1)
		cout << "��";
	else if (prevPos.m_ix == width - 1 && prevPos.m_iy == height - 1)
		cout << "��";
	else if (prevPos.m_ix == 0)
		cout << "��";
	else if (prevPos.m_ix == width - 1)
		cout << "��";
	else if (prevPos.m_iy == 0)
		cout << "��";
	else if (prevPos.m_iy == height - 1)
		cout << "��";
	else
		cout << "��";
}


void Player::KeyInput()
{
	//���� ���� ��ǥ ����
	Position prevPos = curPos;
	//Ű���� �Է°��� ����
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_LEFT:
		{
			//x = 0 �̻��϶������� //���߿� ������ ����
			if (curPos.m_ix - 1 >= 0)
			{
				curPos.m_ix--;
				break;
			}
		}
		case KEY_RIGHT:
		{
			//x = 20 ���� 
			if (curPos.m_ix + 1 < 20)
			{
				curPos.m_ix++;
				break;
			}
		}
		case KEY_UP:
		{
			if (curPos.m_iy - 1 >= 0)
			{
				curPos.m_iy--;
				break;
			}
		}
		case KEY_DOWN:
		{
			if (curPos.m_iy + 1 < 20)
			{
				curPos.m_iy++;
				break;
			}
		}
		//���� �Է½�
		case KEY_ENTER:
		{
			//������
			turn++;
			//CursorUpdate();
			//�����϶�
			if (isBlackTurn)
			{
				//��ǥ�� �浹���Ϳ� push 
				BlackStoneVec.push_back(curPos);
				//�浹�� ���� ��ǥ�� Black�� ����
				map[curPos.m_iy][curPos.m_ix] = CHECK_BLACK;
				//�� ��ǥ�� ����(���� ���� ���� �� �� ��ǥ���� �����ϱ� ����)
				blackSavePos = curPos;
				playerName = "White";
				isBlackTurn = false;
				//������ ȭ��Ʈ������ �ٲ������ Ŀ�� ������Ʈ �Լ����� ȭ��Ʈ�� ������ Ÿ 
				//�鵹�� ������ ��ǥ�� Ŀ���� ������Ʈ��
			}
			else
			{
				//�浹 ��ɰ� �ݴ� ����
				WhiteStoneVec.push_back(curPos);
				map[curPos.m_iy][curPos.m_ix] = CHECK_WHITE;
				whiteSavePos = curPos;
				playerName = "Black";
				isBlackTurn = true;
			}

			CursorUpdate();
			break;
		}
		//������
		case KEY_CANCEL:
		{
			//turn--;
			////cout << "������ ȣ��";
			////�����⸦ �����Ѱ� ������ ��� �� ü����
			//if (isBlackTurn)
			//{
			//	playerName = "White";
			//	isBlackTurn = false;
			//}
			//else
			//{
			//	playerName = "Black";
			//	isBlackTurn = true;
			//}
			////ü���� �Ŀ� �������Լ� ȣ��
			//Cancel(); 
			//break;
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
		//��ǥ�� �������� �浹 �ξ��� ��ǥ�� ������Ʈ
		curPos = blackSavePos;
	}
	else
	{
		curPos = whiteSavePos;
	}
	//������Ʈ�� ��ǥ�� �ٵϵ� �ٽ� �׸�
	StoneDraw();
}

//void Player::Cancel()
//{
//	//
//	if (isBlackTurn) {
//		//�ݺ��ڿ� �浹 �Ǹ����� ��ǥ ����
//		//�� ��ǥ ��ǥ�� ���⿡ �� ���� �ϱ� ���� (���߿� ����ó�� ���� ����)
//		//�Ǹ������� ���� ��ǥ ����
//		auto last = BlackStoneVec.end() - 1;
//		curPos.m_ix = last->m_ix;
//		curPos.m_iy = last->m_iy;
//		MapDraw::DrawPoint("��", last->m_ix, last->m_iy);
//
//	    BlackStoneVec.erase(BlackStoneVec.end() - 1);
//	}
//	else
//	{
//		auto last = WhiteStoneVec.end() - 1;
//		curPos.m_ix = last->m_ix;
//		curPos.m_iy = last->m_iy;
//		MapDraw::DrawPoint("��", last->m_ix, last->m_iy);
//		WhiteStoneVec.erase(WhiteStoneVec.end() - 1);
//		
//	}
//
//	//CursorUpdate();
//}

int Player::WinCheck()
{
	int blackCount = 0;
	int whiteCount = 0;

	//���� �¸� ���� {0, 0} ����Ž��
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//�ش���ǥ�� ���ϰ�� 
			//map 0,0 Ž���� ������ 0,1 = ��ǥ�� 1,0
			//���̸� ����ؼ� ī��Ʈ�� �����Ѵ�.
			//���� �Ǵ� �鵹�� ������ ī��Ʈ�� �ʱ�ȭ�ȴ�.
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//���� �¸� ���� 
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			//�ش���ǥ�� ���ϰ�� 
			//map 0,0 Ž���� ������ 1, 0 = ��ǥ�� 0,1
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//������ �밢�� �¸� ����
	for (int y =  -1; y < height; y++)
	{
		for (int x = -1; x < width; x++)
		{
			//+1�� �ϴ� ������ �밢���� �ƴ� �ٷ� ���� ��ȸ�Ѵٸ� count�� 0�� �Ǳ⶧��
			//y���� �����ִ� ���� : x�� ���θ�ŭ ��ȸ�ϱ� ������ y�� 1���� �Ǳ� ���� �ٷ� ���� Ž���ع����� count�� 0�� �Ǳ⋚��
			switch (map[y + 1][x + 1])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				y++;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				y++;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//���� �밢�� �¸�����
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//�浹 ��������� y+1 x-=2 , x�� 2���ִ� ������ ������ �����鼭 x�� 1�� �����Ǳ� ����
			//x�� -1�ϸ� �ٽ� ������� ���ƿ��� ������ ��������� �ٷ� �ؿ� ���� üũ�ϰԵ�
			switch (map[y][x])
			{
			case CHECK_BLACK:
			{
				blackCount++;
				whiteCount = 0;
				y++;
				x -= 2;
				break;
			}
			case CHECK_WHITE:
			{
				whiteCount++;
				blackCount = 0;
				y++;
				x -= 2;
				break;
			}
			case CHECK_EMPTY:
			{
				blackCount = 0;
				whiteCount = 0;
				break;
			}
			}
			if (blackCount == 5)
				return CHECK_BLACK;
			if (whiteCount == 5)
				return CHECK_WHITE;
		}
	}

	//count�� 5�� ��� true�� ��ȯ
	return CHECK_EMPTY;
}
