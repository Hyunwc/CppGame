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
	int turn;
	int field[20][20];
	vector<pair<int, int>> vec;
	int b_CancelCount; //���� ������ ���� Ƚ��
	int w_CancelCount; //ȭ��Ʈ�� ������ ���� Ƚ��
	string stone; //�ٵϵ� ���
	string playerName;
	Position curPos; //���� x, y ��ǥ
	Position blackSavePos; //�ٵϵ��� ��ǥ�� ������ ����
	Position whiteSavePos; 
	bool isBlackTurn; //��,ȭ��Ʈ �� ������ ���� true�Ͻ� �� ��
public:
	Player();
	void SetPosition(const Size& _mapSize);
	void StoneDraw();
	void CursorDraw();
	void StoneErase(Position prevPos);
	bool KeyInput(); //Ű���� �Է¿� ���� ������, ������, ������, ���� ����
	void CursorUpdate();
	void Cancel(); //������ 
	void MenualUpdate(); //�޴��� ������Ʈ : �� ������ �� ������
	void Reset();
	bool WinStone(); //���� �ٲ𶧸��� �¸� üũ�ϴ� �Լ� ȣ���ϴ� �Լ�
	void Save(); //����
	void Load(); //�ҷ�����
	bool LoadDraw();
	int WinCheck(int stoneColor); //���� ���鼭 5������ üũ�Ͽ� ��ȯ�ϴ� �Լ�
};