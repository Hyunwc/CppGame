#include "Mecro.h"
#include "MapDraw.h"
#include "Map.h"
#include "Snake.h"
#include "GameManager.h"
#include <vector>
#include <time.h>

int main()
{
	GameManager gmr;
	system("mode con cols=100 lines=35");
	while (1)
	{
		gmr.GameSetting();
	}
	
	return 0;
}