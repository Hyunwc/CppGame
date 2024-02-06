#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"
#include "Snake.h"
#include "GameManager.h"
#include <vector>
#include <time.h>

int main()
{
	Map map;
	GameManager gmr;
	map.MapDraw(); //º®
	gmr.SetPosition(map.GetSize());
	gmr.MenuDraw();
	return 0;
}