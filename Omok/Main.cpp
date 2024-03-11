#include "Mecro.h"
#include "GameManager.h"

int main()
{
	GameManager gmr; //게임매니저 인스턴스
	system("mode con cols=40 lines=32");

	while (1)
	{
		gmr.GameSetting();
	}

	return 0;
}