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

class Player
{
private:
	string stone; //�ٵϵ� ���
	Position curPos; //���� x, y ��ǥ
	Position blackSavePos;
	Position whiteSavePos; //�ٵϵ��� ��ǥ�� ������ ����
	vector<Position> BlackStoneVec; //�浹�� ��ǥ�� ���� �����̳�
	vector<Position> WhiteStoneVec; //�鵹�� ��ǥ�� ���� �����̳�
	bool isBlackTurn; //��,ȭ��Ʈ �� ������ ���� true�Ͻ� �� ��
	
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void StoneErase(Position prevPos);
	void KeyInput(); //Ű���� �Է¿� ���� ������, ������, ������, ���� ����
	void CursorUpdate();
	void Cancel(); //������ 
	bool WinCheck();

	string playerName;
	int turn;
	//void Move(char input);
};