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
    MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.2);
    cout << "☆★무기★☆";
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.4);
  /*  for (const auto& el : weaponVec)
    {
        cout << "이름 : " << el.m_strName << " 공격력 : " << el.m_damage << " 가격 : " << el.m_gold << endl << endl;
    }*/
    cout << "이름 : " << weaponVec[0].m_strName << " 공격력 : " << weaponVec[0].m_damage << " 가격 : " << weaponVec[0].m_gold;
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.5);
    cout << "이름 : " << weaponVec[1].m_strName << " 공격력 : " << weaponVec[1].m_damage << " 가격 : " << weaponVec[1].m_gold;
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.6);
    cout << "이름 : " << weaponVec[2].m_strName << " 공격력 : " << weaponVec[2].m_damage << " 가격 : " << weaponVec[2].m_gold;
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
    cout << "이름 : " << weaponVec[3].m_strName << " 공격력 : " << weaponVec[3].m_damage << " 가격 : " << weaponVec[3].m_gold;
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.8);
    cout << "Exit";
    Select = MapDraw::MenuSelectCursor(5, 3, WIDTH * 0.4, HEIGHT * 0.4);
    switch (Select)
    {
    case 1:
    {
        player->BuyShop(&weaponVec[WEAPON_GONE]);
        //BuyWeapon(player, WEAPON_GONE);
        break;
    }
    case 2:
    {
        player->BuyShop(&weaponVec[WEAPON_SWORD]);
        break;
    }
    case 3:
    {
        player->BuyShop(&weaponVec[WEAPON_AXE]);
        break;
    }
    case 4:
    {
        player->BuyShop(&weaponVec[WEAPON_HAMMER]);
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

//void Shop::BuyWeapon(Player* player, WEAPON TYPE)
//{
//    player->BuyShop(weaponVec[TYPE].m_gold);
//    //플레이어의 파워업 함수 호출
//    player->PowerUp(&weaponVec[TYPE]);
//
//    WeaponDisplay(player);
//}



Shop::~Shop()
{
}
