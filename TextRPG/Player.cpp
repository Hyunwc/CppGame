#include "Player.h"

Player::Player() 
{
	m_level = 1;
	m_curExp = 0;
	m_curHp = m_maxHp;
	m_gold = 500;
	m_damage = m_defaultpower;
	m_weaponpower = 0;
	m_mana = 0;
}

//Player::Player()
//{
//}

void Player::SetName(string name)
{
	m_name = name;
}

void Player::SetItem(int exp, int gold)
{
	m_curExp += exp;
	m_gold += gold;
}

void Player::LevelUp()
{
	//�� ����ġ�� maxExp�� �ʰ����� ��� ������
	if (m_curExp >= m_maxExp)
	{
		//������ ����ġ�� ������ �����صΰ�
		//������, �ִ����ġ ����, ���� ����ġ�� ������ ����ġ��
		int remain_Exp = m_curExp - m_maxExp;
		m_level++;
		m_maxExp += 100; 
		m_curExp = remain_Exp;
		m_maxHp += 100;
		m_curHp = m_maxHp;
		m_defaultpower += 20;
		m_damage += 20;
	}
	//����ġ�� �ѹ��� ���� �������� ������ ��� �����Ǿ���ϴ� ���߿� while������ �����غ����� ����
}

void Player::PowerUp()
{
	//weapon�� nullptr�� �ƴ� ��� �⺻���ݷ� + ������ ���ݷ� �߰�
	if(weapon != nullptr)
		m_damage += weapon->m_damage;
}

void Player::MaxHp()
{
	//shop���� ���� ��尡 200�̻��� ��� ȣ���. 200��� ��� hp�� �ִ�� ȸ��������
	m_gold -= 200;
	m_curHp = m_maxHp;
}

void Player::ShowDisplay()
{
	//���� �÷����ϴ� ���� ������ִ� �Լ�
	//������ ���� �⺻+���� ���ݷ��� ��ģ ��ġ.
	MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.3);
	cout << "Player : " << m_name << " Attack : " << m_damage << " Hp : " << m_curHp << " Mana : " << m_mana;
}

void Player::ShowInfo()
{
	//���� �������� ������, �Ŀ��� �⺻ ���ݷ� + ���� ���ݷ��� ���
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT - 3);
	cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_curExp << endl;
	cout << "  Hp : " << m_curHp << " Gold : " << m_gold << " Power : (" << m_defaultpower << "+" << m_weaponpower << ")" << endl;

	//������ �����Ұ�� ���
	if (weapon != nullptr)
	{
		cout << "  ���� ���� : " << weapon->m_strName << " ���ݷ� : " << weapon->m_damage;
	}
}

void Player::Respone()
{
	m_curHp = m_maxHp / 2;
}

void Player::DataSave(int slot)
{
	ofstream save;
	save.open("SavePlayer" + to_string(slot) + ".txt");
	if (save.is_open())
	{
		save << m_name << " ";
		save << m_level << " ";
		save << m_curExp << " ";
		save << m_curHp << " ";
		save << m_defaultpower << " ";
		save << m_gold << " ";
		//���Ⱑ ������ ��쿡��
		if (weapon != nullptr)
		{
			//save << weapon->m_Type << " ";
			save << weapon->m_strName << " ";
			save << weapon->m_damage << " ";
			save << weapon->m_gold << endl;
		}
			
		save.close();
	}
}

void Player::DataLoad(int slot)
{
	ifstream load;
	load.open("SavePlayer" + to_string(slot) + ".txt");
	if (load.is_open())
	{
		string name, weaponname;
		int level, exp, hp, power, gold, weaponpower, weaponprice;
		Weapon* loadweapon = new Weapon();
		load >> name >> level >> exp >> hp >> power >> gold >> weaponname >> weaponpower >> weaponprice;
		m_name = name;
		m_level = level;
		m_curExp = exp;
		m_curHp = hp;
		m_gold = gold;
		m_defaultpower = power;
		loadweapon->m_strName = weaponname;
		loadweapon->m_damage = weaponpower;
		loadweapon->m_gold = weaponprice;

		if (weapon != nullptr)
			delete weapon;
		weapon = loadweapon;

		load.close();	
	}

	PowerUpdate();
}

void Player::PowerUpdate()
{
	//������ �������� �������� �⺻������ ����Ʈ �Ŀ�
	m_damage = m_defaultpower;
	//���� ���� ���Ⱑ �����Ұ�� ������ �������� �߰�
	if (weapon != nullptr)
	{
		m_damage = m_defaultpower + weapon->GetDamage();
		m_weaponpower = weapon->GetDamage();
	}
		
	
}

void Player::BuyShop(Weapon* new_weapon)
{
	if (weapon != nullptr) {
		delete weapon;
	}

	weapon = new_weapon;
	m_weaponpower = new_weapon->m_damage;
	m_gold -= new_weapon->m_gold;

	PowerUpdate();
}


void Player::Reset()
{
	m_level = 1;
	m_curHp = m_maxHp;
	m_curExp = 0;
	m_defaultpower = 20;
	m_gold = 500;
	m_weaponpower = 0;
	if (weapon != nullptr)
	{
		delete weapon;
		weapon = nullptr;
	}
}

