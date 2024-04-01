#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Weapon.h"

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
	int m_curExp;
	int m_maxExp;
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
	//virtual void SetInfo();
	//����ġ�� ��带 �����ϱ�����
	virtual void SetItem(int exp, int gold);
	virtual void LevelUp();
	//�� �ν��Ͻ��� hp�� �ִ�ġ��. ���߿� �÷��̾� ���� �����Ҷ� �ᵵ �ɵ�
	virtual void MaxHp();

	void Observer();
	virtual void PowerUp(Weapon* weapon);
	void takeDamage(int damage);
	//�׾����� üũ (���� hp�� 0���ϸ� ���� true)
	bool DeadCheck();
	string GetName() { return m_name; }
	int GetCurHP() { return m_curHp; }
	int GetDamage() { return m_power; }
	int GetLevel() { return m_level; }

	~Character();
};


