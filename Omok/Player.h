#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum KEY
{
	KEY_LEFT = 'a',
	KEY_RIGHT = 'd',
	KEY_UP = 'w',
	KEY_DOWN = 's',
	KEY_ESC = 27,  
	KEY_ENTER = 13,  //������
	KEY_CANCEL = 'n' //������
};

enum CHECK
{
	CHECK_EMPTY = 0, //����
	CHECK_BLACK,
	CHECK_WHITE,
	CHECK_NOT //���úҰ�
};

class Player
{
private:
	int height;  //����
	int width;   //����
	int map[20][20];
	int b_CancelCount; //���� ������ ���� Ƚ��
	int w_CancelCount; //ȭ��Ʈ�� ������ ���� Ƚ��
	string stone; //�ٵϵ� ���
	Position curPos; //���� x, y ��ǥ
	Position blackSavePos;
	Position whiteSavePos; //�ٵϵ��� ��ǥ�� ������ ����
	bool isBlackTurn; //��,ȭ��Ʈ �� ������ ���� true�Ͻ� �� ��
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void StoneErase(Position prevPos);
	void KeyInput(); //Ű���� �Է¿� ���� ������, ������, ������, ���� ����
	void CursorUpdate();
	void Cancel(); //������ 
	void MenualUpdate(); //�޴��� ������Ʈ : �� ������ �� ������
	void WinStone(); //���� �ٲ𶧸��� �¸� üũ�ϴ� �Լ� ȣ���ϴ� �Լ�
	int WinCheck(int stone); //���� ���鼭 5������ üũ�Ͽ� ��ȯ�ϴ� �Լ�

	string playerName;
	int turn;
	//void Move(char input);
};