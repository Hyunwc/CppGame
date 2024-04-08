#include "Player.h"
#include "Shop.h"

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
	
	//경험치가 한번에 많이 들어왔을때 레벨이 계속 증가되어야하니 나중에 while문으로 수정해보도록 하자
	while (m_curExp > m_maxExp)
	{
		int remain_Exp = m_curExp - m_maxExp;
		m_level++;
		m_maxExp += 100;
		m_curExp = remain_Exp;
		m_maxHp += 100;
		m_curHp = m_maxHp;
		m_defaultpower += 20;
		m_damage += 20;
	}
	
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
	cout << "Player : " << m_name << " Level : " << m_level << " Exp : " << m_curExp << " / " << m_maxExp << endl;
	cout << "  Hp : " << m_curHp << " Gold : " << m_gold << " Power : (" << m_defaultpower << "+" << m_weaponpower << ")" << endl;

	//웨폰이 존재할경우 출력
	if (weapon != nullptr)
	{
		cout << "  장착 무기 : " << weapon->m_strName << " 공격력 : " << weapon->m_damage;
	}
}

void Player::Respone()
{
	//절반의 HP로 부활
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
			save << weapon->m_strName << " ";
			/*save << weapon->m_damage << " ";
			save << weapon->m_gold << endl;*/
		}
			
		save.close();
	}
}

void Player::DataLoad(int slot, class Shop* shop)
{
	ifstream load;
	load.open("SavePlayer" + to_string(slot) + ".txt");
	if (load.is_open())
	{
		string name, weaponname;
		int level, exp, hp, power, gold;
	
		load >> name >> level >> exp >> hp >> power >> gold >> weaponname;
		m_name = name;
		m_level = level;
		m_curExp = exp;
		m_curHp = hp;
		m_gold = gold;
		m_defaultpower = power;

		//어차피 리셋호출되면 weapon이 null이 되니 null체크할 필요x
		SetWeapon(shop->GetWeapon(weaponname));

		load.close();	
	}

	PowerUpdate();
}

//공격력 갱신
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
	//무기가 존재하고 현재 무기와 구매하려는 무기의 이름이 같다면
	if (weapon != nullptr && weapon->m_strName == new_weapon->m_strName)
	{
		system("cls");
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT / 2);
		cout << "이미 착용하고 계신 무기입니다." << endl;
		_getch();
		return;
	}

	if (SetWeapon(new_weapon)) {
		//구매한 무기 가격만큼 차감
		m_gold -= new_weapon->m_gold;
	}

	//공격력 갱신
	PowerUpdate();
}

bool Player::SetWeapon(Weapon* weapon)
{
	// 현재 무기가 존재하는 경우 삭제
	if (weapon == nullptr)
		return false;

	//새로운 무기로 장착
	this->weapon = weapon;
	//무기 공격력 업데이트
	m_weaponpower = weapon->m_damage;
	return true;
}

//초기상태로
void Player::Reset()
{
	m_level = 1;
	m_maxExp = 100;
	m_maxHp = 100;
	m_curHp = m_maxHp;
	m_curExp = 0;
	m_defaultpower = 20;
	m_gold = 500;
	m_weaponpower = 0;
	weapon = nullptr;
	/*if (weapon != nullptr)
	{
		
	}*/
}

