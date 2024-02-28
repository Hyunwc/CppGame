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
	Position stonePos; //�ٵϵ��� x, y ��ǥ
	Position savePos; //�ٵϵ��� ��ǥ�� ������ ����
	vector<Position> stoneVec; //�ٵϵ��� ��ǥ�� ���� �����̳�
	bool isBlackTurn; //��,ȭ��Ʈ �� ������ ���� true�Ͻ� �� ��
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void StoneErase();
	void KeyInput(); //Ű���� �Է¿� ���� ������, ������, ������, ���� ����
	void Move(char input);
};