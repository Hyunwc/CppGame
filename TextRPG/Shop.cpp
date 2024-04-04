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
    cout << "�١ڹ���ڡ�";
    
    for (const auto& el : weaponVec)
    {
        MapDraw::gotoxy(WIDTH * 0.5, height);
        cout << "�̸� : " << el.m_strName << " ���ݷ� : " << el.m_damage << " ���� : " << el.m_gold;
        height += 3;
    }
    // 6 9 12 15 ..
    MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.6);
    cout << "HP �ִ�� ȸ��  ���� : 200";
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
        player->BuyShop(&weaponVec[Select - 1]);
        break;
    }
    case 5:
    {
        if (player->GetGold() >= 200)
            player->MaxHp();
        else
        {
            MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.9);
            cout << "��尡 �����մϴ�";
            
            _getch();
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
