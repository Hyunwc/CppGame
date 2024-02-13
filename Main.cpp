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
	Snake snake;
	map.MapDraw(); 
	gmr.SetPosition(map.GetSize());
	snake.SetPosition(map.GetSize());
	gmr.MenuDraw();
	snake.SnakeDraw();
	while (1)
	{
		snake.SelectDirection();
		snake.Move();
		/*MapDraw::gotoxy(55, 10);
		cout << "테스트용";*/
	
	}
	
	return 0;
}