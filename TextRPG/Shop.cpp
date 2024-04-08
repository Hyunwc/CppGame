#include "Shop.h"

Shop::Shop()
{
}

void Shop::WeaponDisplay(Player* player)
{
  
    system("cls");
    int Select = 0;
    int height = HEIGHT * 0.2;
    MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT - 3);
    MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
    cout << "☆★무기★☆";
    
    for (const auto& el : weaponVec)
    {
        MapDraw::gotoxy(WIDTH * 0.5, height);
        cout << "이름 : " << el.m_strName << " 공격력 : " << el.m_damage << " 가격 : " << el.m_gold;
        height += 3;
    }
    // 6 9 12 15 ..
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.6);
    cout << "HP 최대로 회복  가격 : 200";
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
    cout << "Exit";
    Select = MapDraw::MenuSelectCursor(6, 3, WIDTH * 0.4, HEIGHT * 0.2);
    switch (Select)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    {
        //플레이어의 골드가 선택한 무기의 가격 이상일떄만
        if(player->GetGold() >= weaponVec[Select - 1].GetGold())
            player->BuyShop(&weaponVec[Select - 1]);
        else
        {
            system("cls");
            MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.5);
            cout << weaponVec[Select - 1].GetGold() - player->GetGold() << " 골드가 부족합니다";
            _getch();
            //WeaponDisplay(player);
        }
        
        break;
    }
    case 5:
    {
        //플레이어의 골드가 200 이상일때만 HP를 충전 가능하게
        if (player->GetGold() >= 200)
            player->MaxHp();
        else
        {
            system("cls");
            MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.5);
            cout << 200 - player->GetGold() << " 골드가 부족합니다";
            _getch();
            //WeaponDisplay(player);
        }
 
        break;
    }
    case 6:
    {
        return;
    }
    default:
        break;
    }

}

void Shop::WeaponLoad()
{
    ifstream load;
    load.open("WeaponList.txt");
    if (load.is_open())
    {
        string str;
        while (!load.eof())
        {
            //string type;
            string name;
            int power, price;
            Weapon weapon;

            load >> name >> power >> price;
          
            weapon.m_strName = name;
            weapon.m_damage = power;
            weapon.m_gold = price;

            weaponVec.push_back(weapon);
        }
        load.close();
    }
}

Shop::~Shop()
{
}
