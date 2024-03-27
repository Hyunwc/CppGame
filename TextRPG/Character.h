#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum CHARACTER_TYPE
{
	PLAYER = 0,
	MONSTER
};

class Character
{
	//�÷��̾�� ���� Ŭ������ �� ������� ����ؾ� �ϱ� ������ protected
protected:
	CHARACTER_TYPE m_type;
	string m_name;
	int m_level;
	int m_exp;
	int m_curHp; //����hp
	int m_maxHp; //�ִ�hp
	int m_gold;
	int m_damager;
	int m_mana;
public:
	Character();
	//���� ������ ���
	virtual void ShowDisplay();
	virtual void ShowInfo();
	//������ ���� �޴� �Լ�
	virtual void SetInfo();
	//�׾����� üũ (���� hp�� 0���ϸ� ���� true)
	bool DeadCheck();
	~Character();
};


