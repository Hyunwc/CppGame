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
	//현 경험치가 maxExp를 초과했을 경우 레벨업
	if (m_curExp >= m_maxExp)
	{
		//나머지 경험치를 변수에 저장해두고
		//레벨업, 최대경험치 증가, 현재 경험치를 나머지 경험치로
		int remain_Exp = m_curExp - m_maxExp;
		m_level++;
		m_maxExp += 100; 
		m_curExp = remain_Exp;
		m_maxHp += 100;
		m_curHp = m_maxHp;
		m_defaultpower += 20;
		m_damage += 20;
	}
	//경험치가 한번에 많이 들어왔을때 레벨이 계속 증가되어야하니 나중에 while문으로 수정해보도록 하자
}

void Player::PowerUp()
{
	//weapon이 nullptr이 아닐 경우 기본공격력 + 웨폰의 공격력 추가
	if(weapon != nullptr)
		m_damage += weapon->m_damage;
}

void Player::MaxHp()
{
	//shop에서 보유 골드가 200이상일 경우 호출됨. 200골드 깎고 hp를 최대로 회복시켜줌
	m_gold -= 200;
	m_curHp = m_maxHp;
}

void Player::ShowDisplay()
{
	//게임 플레이하는 동안 출력해주는 함수
	//어택은 현재 기본+무기 공격력을 합친 수치.
	MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.3);
	cout << "Player : " << m_name << " Attack : " << m_damage << " Hp : " << m_curHp << " Mana : " << m_mana;
}

void Player::ShowInfo()
{
	//현재 정보들을 보여줌, 파워는 기본 공격력 + 무기 공격력을 출력
	MapDraw::gotoxy(WIDTH * 0.1, HEIGHT - 3);
	cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_curExp << endl;
	cout << "  Hp : " << m_curHp << " Gold : " << m_gold << " Power : (" << m_defaultpower << "+" << m_weaponpower << ")" << endl;

	//웨폰이 존재할경우 출력
	if (weapon != nullptr)
	{
		cout << "  장착 무기 : " << weapon->m_strName << " 공격력 : " << weapon->m_damage;
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
		//무기가 존재할 경우에만
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
	//적에게 가해지는 데미지는 기본적으로 디폴트 파워
	m_damage = m_defaultpower;
	//만약 장착 무기가 존재할경우 무기의 데미지도 추가
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

