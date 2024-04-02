#include "Shop.h"

void Shop::WeaponDisplay()
{
    ifstream load;
    load.open("WeaponList.txt");
    if (!load.is_open())
    {
        string str;
        while (!load.eof())
        {
            WEAPON TYPE;
            string name;
            int power, price;

            load >> TYPE >> name >> power >> price;
            
        }
        load.close();
    }
}

bool Shop::BuyWeapon(Player* player, WEAPON TYPE)
{
    return false;
}

Shop::Shop()
{
}

Shop::~Shop()
{
}
