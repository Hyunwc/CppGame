#include "Mecro.h"
#include "GameManager.h"

int main()
{
	GameManager gmr; //���ӸŴ��� �ν��Ͻ�
	system("mode con cols=40 lines=32");

	while (1)
	{
		gmr.GameSetting();
	}

	return 0;
}