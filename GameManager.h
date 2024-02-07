#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"

class GameManager
{
private:
	Size m_mapSize;
	Map map;
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