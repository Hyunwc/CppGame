#include "Player.h"

Player::Player() : stone("��"), isBlackTurn(true), playerName("Black"), field{ {CHECK_EMPTY} }
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
			switch (field[y][x])
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


bool Player::KeyInput()
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
			//�����̸鼭 �����Ⱑ �ƴ� ����
			if (field[curPos.m_iy][curPos.m_ix] == CHECK_EMPTY && !(field[curPos.m_iy][curPos.m_ix] == CHECK_NOT))
			{
				//������
				turn++;
				//üũ���� ��ǥ �ٽ� �������� �ٲٰ� ������ �ٽ� �׸���
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						if (field[y][x] == CHECK_NOT)
						{
							field[y][x] = CHECK_EMPTY;
							Position temp = { x, y };
							StoneErase(temp);
						}
					}
				}
				
				if (isBlackTurn)
				{
					//�浹�� ���� ��ǥ�� Black�� ����
					field[curPos.m_iy][curPos.m_ix] = CHECK_BLACK;
					//�� ��ǥ�� ����(���� ���� ���� �� �� ��ǥ���� �����ϱ� ����)
					blackSavePos = curPos;
					playerName = "White";
				}
				else
				{
					field[curPos.m_iy][curPos.m_ix] = CHECK_WHITE;
					whiteSavePos = curPos;
					playerName = "Black";
				}

				if(WinStone())
					return true; //�¸�üũ 
				isBlackTurn = !isBlackTurn; //��ü����	
			}
			
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
				b_CancelCount--;
				playerName = "White";
				isBlackTurn = false;
			}
			else
			{
				w_CancelCount--;
				playerName = "Black";
				isBlackTurn = true;
			}
			//ü���� �Ŀ� �������Լ� ȣ��
			Cancel();
			MenualUpdate();
			break;
		}
		}

		StoneErase(prevPos);  //���� ���� ��ǥ�� ������.
		StoneDraw(); //������Ʈ�� ��ǥ�� �ٵϵ��� �׸���.
	}

	return false;
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
		field[blackSavePos.m_iy][blackSavePos.m_ix] = CHECK_NOT;
	else
		field[whiteSavePos.m_iy][whiteSavePos.m_ix] = CHECK_NOT;

	CursorUpdate();
}

void Player::MenualUpdate()
{
	MapDraw::gotoxy(width * 0.6, height + 2);
	cout << "====����Ű====" << endl;
	cout << "�̵� : A, S, W, D  ������ : ENTER" << endl;
	cout << "������ : N ���� : ESC" << endl;
	cout << "Player Name : " << playerName;
	if(isBlackTurn)
		cout << " ������ : " << b_CancelCount << endl;
	else
		cout << " ������ : " << w_CancelCount << endl;
	cout << "Turn : " << turn;
}

bool Player::WinStone()
{
	int Count = 0;
	//�����̸� �� �ƴϸ� ȭ��Ʈ�� ����
	Count = WinCheck(isBlackTurn ? CHECK_BLACK : CHECK_WHITE);

	if (Count == 5)
	{
		//�����̸� ���¸� �ƴϸ� ȭ��Ʈ �¸�
		MapDraw::gotoxy(width * 0.8, height / 4);
		cout << (isBlackTurn ? "�� �¸�" : "ȭ��Ʈ �¸�");
		return true;
	}

	return false;
}

void Player::Reset()
{
	//�ʵ� �ٽ� �׸���
	MapDraw::FieldDraw(width, height);
	//�迭 �ʱ�ȭ
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			field[y][x] = CHECK_EMPTY;
		}
	}
	//������ġ, ������ ������ġ, �� ���� �ʱ� ���·�
	curPos.m_ix = width / 2;
	curPos.m_iy = height / 2;
	blackSavePos = curPos;
	whiteSavePos = curPos;
	b_CancelCount = 5;
	w_CancelCount = 5;
	turn = 1;
	isBlackTurn = true;
	playerName = "Black";
}

//5�� üũ�ϴ� �Լ� �Ű����� stoneColor�� ������ ������ ���޹޴� ����
int Player::WinCheck(int stoneColor)
{
	int Count = 0;

	//���� �¸� ���� {0, 0} ����Ž��
	for (int y = 0; y < height; y++)
	{
		//�� �ึ�� ī��Ʈ �ʱ�ȭ
		//�̰� �ʱ�ȭ�� �� �̷������ y = 0 x = 17,18,19 , y = 1 x = 0,1 �� �������� �̷���� 
		Count = 0; 
		for (int x = 0; x < width; x++)
		{
			//���ӵǴ� ��ǥ�� �� ������ ��쿡�� ���� 
			if (field[y][x] == stoneColor)
			{
				Count++;
				//5�� ���ӵ��� üũ
				if (Count == 5)
					return Count;
			}
			// ������ �ƴ϶�� 0����
			else
				Count = 0;
		}
	}
	//���� ���� üũ
	for (int x = 0; x < width; x++)
	{
		Count = 0; //�� ������ ī��Ʈ �ʱ�ȭ
		for (int y = 0; y < height; y++)
		{
			if (field[y][x] == stoneColor)
			{
				Count++;

				//5�� ���ӵ��� üũ
				if (Count == 5)
					return Count;
			}
			else
				Count = 0;
		}
	}

	//���� �ϴ����� ���� �밢��
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Count = 0;
			for (int i = 0; i < 5; i++)
			{
				if (field[y + i][x + i] == stoneColor)
				{
					Count++;

					if (Count == 5)
						return Count;
				}
				else
					Count = 0;
			}
		}
	}
	//���� �ϴ����� ���� �밢��
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Count = 0;
			for (int i = 0; i < 5; i++)
			{
				if (field[y - i][x + i] == stoneColor)
				{
					Count++;

					if (Count == 5)
						return Count;
				}
				else
					Count = 0;
			}
		}
	}
	
	return Count;
}


