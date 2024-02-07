#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class GameManager
{
private:
	Size m_mapSize;
	//int heartCount = 0; //��Ʈ ����
	int score = 0;  //���ھ�
public:
	GameManager(); //������
	void SetPosition(Size _mapSize);
	void MenuDraw(); //���Ӽ��ø޴� 
	void GameStart();
	void TextScore(); //���ھ� ����
	~GameManager();
};