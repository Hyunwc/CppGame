#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Map
{
private:
	Position m_position; //���� ��ǥ
	Size m_mapSize; //���� ũ��
public:
	Map(); //������
	void MapDraw(); //�ܼ� �� �׸���
	Position GetPosition(); //���� ������ǥ ��ȯ
	Size GetSize(); // �� ���� ���� ��ȯ
	~Map(); //�Ҹ���
};