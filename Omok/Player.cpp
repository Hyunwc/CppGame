#include "Player.h"

Player::Player() : stone("��"), isBlackTurn(true), playerName("Black"), map{ {CHECK_EMPTY} }
{
	turn = 1;
	b_CancelCount = 5;
	w_CancelCount = 5;
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
	//������ ���� �ش� ��ǥ�� �´� ��ȣ�� �׸�
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (map[y][x])
			{
			case CHECK_BLACK: //��
			{
				MapDraw::DrawPoint("��", x, y);
				break;
			}
			case CHECK_WHITE: //��
			{
				MapDraw::DrawPoint("��", x, y);
				break;
			}
			case CHECK_NOT: //������
			{
				MapDraw::DrawPoint("��", x, y);
				break;
			}
			default:
				break;
			}
		}
	}

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
		//StoneErase(prevPos);  //���� ���� ��ǥ�� ������.
		switch (_getch())
		{
		case KEY_LEFT:
		{
			//x�� ������ǥ�� 0 �̻��϶��� (0������)
			if (curPos.m_ix - 1 >= 0)
				curPos.m_ix--;
			break;
		}
		case KEY_RIGHT:
		{
			//x�� ������ǥ�� 20 �̸� �� 19
			if (curPos.m_ix + 1 < width)
				curPos.m_ix++;
			break;
		}
		case KEY_UP:
		{
			if (curPos.m_iy - 1 >= 0)
				curPos.m_iy--;
			break;
		}
		case KEY_DOWN:
		{
			if (curPos.m_iy + 1 < height)
				curPos.m_iy++;
			break;
		}
		//���� �Է½�
		case KEY_ENTER:
		{
			//������
			turn++;
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					if (map[y][x] == CHECK_NOT)
					{
						map[y][x] = CHECK_EMPTY;
						Position temp = { x, y };
						StoneErase(temp);
					}
				}
			}
			//CursorUpdate();
			//�����̸鼭 �����ΰ���
			if ((isBlackTurn && map[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY) && !(map[curPos.m_iy][curPos.m_ix] == CHECK_NOT))
			{
				//�浹�� ���� ��ǥ�� Black�� ����
				map[curPos.m_iy][curPos.m_ix] = CHECK_BLACK;
				//�� ��ǥ�� ����(���� ���� ���� �� �� ��ǥ���� �����ϱ� ����)
				blackSavePos = curPos;
				playerName = "White";
				isBlackTurn = false;
				//������ ȭ��Ʈ������ �ٲ������ Ŀ�� ������Ʈ �Լ����� ȭ��Ʈ�� ������ Ÿ 
				//�鵹�� ������ ��ǥ�� Ŀ���� ������Ʈ��
			}
			else if(!(isBlackTurn && map[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY) && !(map[curPos.m_iy][curPos.m_ix] == CHECK_NOT))
			{
				map[curPos.m_iy][curPos.m_ix] = CHECK_WHITE;
				whiteSavePos = curPos;
				playerName = "Black";
				isBlackTurn = true;
			}

			WinStone(); //�¸�üũ
			CursorUpdate(); //������ Ŀ���� ��ġ ������Ʈ
			MenualUpdate(); //���� �ֽ�ȭ(� �÷��̾��� ��, �� ��, ������ ��)
			break;
		}
		//������
		case KEY_CANCEL:
		{
			turn--;
			////�����⸦ �����Ѱ� ������ ��� �� ü����
			if (isBlackTurn)
			{
				playerName = "White";
				isBlackTurn = false;
			}
			else
			{
				playerName = "Black";
				isBlackTurn = true;
			}
			//ü���� �Ŀ� �������Լ� ȣ��
			Cancel(); 
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

void Player::Cancel()
{
	
	if (isBlackTurn)
		map[blackSavePos.m_iy][blackSavePos.m_ix] = CHECK_NOT;
	else
		map[whiteSavePos.m_iy][whiteSavePos.m_ix] = CHECK_NOT;

	CursorUpdate();
}

void Player::MenualUpdate()
{
	MapDraw::gotoxy(width * 0.8, height + 2);
	cout << "====����Ű====" << endl;
	cout << "�̵� : A, S, W, D  ������ : ENTER" << endl;
	cout << "������ : N ���� : ESC" << endl;
	cout << "Player Name : " << playerName << " ������ : 5" << endl;
	cout << "Turn : " << turn;
}

void Player::WinStone()
{
	int Count = 0;
	
	if (isBlackTurn)
	{
		Count = WinCheck(CHECK_BLACK);
		if (Count == 5)
		{
			MapDraw::gotoxy(width * 0.8, height - 15);
			cout << "�� �¸�";
		}
	}
	else
	{

	}
}

//������ int�� �ۼ��Ͽ��µ� ���� �����Ǹ� bool�� �ٲ� ����
int Player::WinCheck(int stone)
{
	int Count = 0;

	//���� �¸� ���� {0, 0} ����Ž��
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			
		}
	}
	
	return Count;
}


