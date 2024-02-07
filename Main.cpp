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
	map.MapDraw(); 
	gmr.SetPosition(map.GetSize());
	gmr.MenuDraw();
	while (1)
	{
		/*MapDraw::gotoxy(55, 10);
		cout << "테스트용";*/
	
	}
	
	return 0;
}