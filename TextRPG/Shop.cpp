#include "Shop.h"

Shop::Shop()
{
}

void Shop::WeaponDisplay(Player* player)
{
    ifstream load;
    load.open("WeaponList.txt");
    if (load.is_open())
    {
        string str;
        while (!load.eof())
        {
            string type;
            string name;
            int power, price;
            Weapon weapon;

            load >> type >> name >> power >> price;
            weapon.m_strName = name;
            weapon.m_damage = power;
            weapon.m_gold = price;

            weaponVec.push_back(weapon);
        }
        load.close();
    }
    system("cls");
    int Select = 0;
    MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT - 3);
    MapDraw::gotoxy(WIDTH * 0.75, HEIGHT * 0.25);
    cout << "�١ڹ���ڡ�";
    MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
    cout << "�̸� : " << weaponVec[0].m_strName << " ���ݷ� : " << weaponVec[0].m_damage << " ���� : " << weaponVec[0].m_gold;
    MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.55);
    cout << "�̸� : " << weaponVec[1].m_strName << " ���ݷ� : " << weaponVec[1].m_damage << " ���� : " << weaponVec[1].m_gold;
    MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.65);
    cout << "�̸� : " << weaponVec[2].m_strName << " ���ݷ� : " << weaponVec[2].m_damage << " ���� : " << weaponVec[2].m_gold;
    MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.78);
    cout << "�̸� : " << weaponVec[3].m_strName << " ���ݷ� : " << weaponVec[3].m_damage << " ���� : " << weaponVec[3].m_gold;
    MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.9);
    cout << "Exit";
    Select = MapDraw::MenuSelectCursor(5, 3, WIDTH * 0.7, HEIGHT * 0.4);
    switch (Select)
    {
    case 1:
    {
        BuyWeapon(player, WEAPON_GONE);
        break;
    }
    case 2:
    {
        BuyWeapon(player, WEAPON_SWORD);
        break;
    }
    case 3:
    {
        BuyWeapon(player, WEAPON_AXE);
        break;
    }
    case 4:
    {
        BuyWeapon(player, WEAPON_HAMMER);
        break;
    }
    case 5:
    {
        return;

    }
    default:
        break;
    }

}

void Shop::BuyWeapon(Player* player, WEAPON TYPE)
{
    player->BuyShop(weaponVec[TYPE].m_gold);
    //�÷��̾��� �Ŀ��� �Լ� ȣ��
    player->PowerUp(&weaponVec[TYPE]);

    WeaponDisplay(player);
}



Shop::~Shop()
{
}
