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
	int m_power; //���ݷ�
	int m_mana;
public:
	Character();
	//���� ������ ���
	virtual void ShowDisplay();
	virtual void ShowInfo();
	//������ ���� �޴� �Լ�
	virtual void SetInfo();
	void Observer();
	//�׾����� üũ (���� hp�� 0���ϸ� ���� true)
	void takeDamage(int damage);
	bool DeadCheck();
	string GetName() { return m_name; }
	int GetCurHP() { return m_curHp; }
	int GetDamage() { return m_power; }
	int GetLevel() { return m_level; }

	~Character();
};


