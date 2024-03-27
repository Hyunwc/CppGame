#include "GameManager.h"

GameManager::GameManager()
{
	srand(static_cast<unsigned int>(time(0)));
}
//필요없으면 삭제할 예정
void GameManager::GameSetting()
{
	//MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	GameTitle();
}

void GameManager::GameTitle()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "☆★TEXT RPG★☆";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.4);
	cout << "1. New Game";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.5);
	cout << "2. Load Game";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.6);
	cout << "3. Exit";
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
	Select = MapDraw::MenuSelectCursor(3, 3, WIDTH * 0.8, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		NewGame();
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		exit(0);
	}
	default:
		break;
	}
}

void GameManager::NewGame()
{
	//화면 지우고 맵 다시 그림
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	string name;
	MapDraw::gotoxy(WIDTH * 0.6, HEIGHT * 0.3);
	cout << "이름을 입력해주세요 : ";
	cin >> name;
	//이 곳에 플레이어에게 이름을 넘겨주는 코드 추가할 예정
	m_player.SetInfo(name);
	Menu();
}

void GameManager::Menu()
{
	//화면 지우고 맵 다시 그림
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "☆★메뉴★☆";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.4);
	cout << "Colosseum";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.5);
	cout << "Shop";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.6);
	cout << "Save";
	MapDraw::gotoxy(WIDTH * 0.9, HEIGHT * 0.7);
	cout << "Exit";
	m_player.ShowInfo();
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
	Select = MapDraw::MenuSelectCursor(4, 3, WIDTH * 0.8, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		Colosseum();
		break;
	}
	case 2:
	{
		//상점 아직 개발 안됨
		break;
	}
	case 3:
	{
		//저장 아직 개발 안됨
		break;
	}
	case 4:
	{
		return;
	}
	default:
		break;
	}
}

void GameManager::Colosseum()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.1);
	cout << "☆★콜로세움★☆";
	m_player.ShowDisplay();
	m_player.ShowInfo();
	GamePlay();
}

void GameManager::GamePlay()
{
	int Select;
	//누가 먼저 공격할건지 결정
	bool heroTurn = rand() % 2;

	while (1)
	{
		system("cls");
		m_player.ShowDisplay();
		MapDraw::gotoxy(WIDTH, HEIGHT * 0.3);
		cout << "vs";
		m_monster.ShowDisplay();
		string name = heroTurn ? m_player.GetName() : m_monster.GetName();
		MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.8);
		cout << "현재 턴 : " << name;
		if (heroTurn)
		{
			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.6);
			cout << "1. 기본 공격 2. 필살기(50 마나 필요) 입력 : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
			{
				m_monster.takeDamage(m_player.GetDamage());
				MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
				cout << m_monster.GetName() << "에게 " << m_player.GetDamage() << "만큼의 데미지를 주었습니다!";
				//cout << "기본 공격 성공!";
				break;
			}
			case 2:
			{

				MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
				cout << "필살기!";
				break;
			}
			default:
				break;
			}
		}
		else
		{
			Sleep(2000);
			m_player.takeDamage(m_monster.GetDamage());
			MapDraw::gotoxy(WIDTH * 0.3, HEIGHT * 0.9);
			cout << m_player.GetName() << "에게 " << m_monster.GetDamage() << "만큼의 데미지를 주었습니다!";
		}

		if (m_player.DeadCheck() || m_monster.DeadCheck())
		{
			//몬스터가 죽었다면 플레이어의 열거타입을 아니면 몬스터로
			ResultBord(m_player.DeadCheck() ? MONSTER : PLAYER);
		}


		heroTurn = !heroTurn;

		system("pause");
	}
}

void GameManager::ResultBord(int winner)
{
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	//승자가 플레이어면 플레이어 이름 저장 아니면 몬스터 이름 저장
	string winner_name = (winner == PLAYER) ? m_player.GetName() : m_monster.GetName();
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "☆★결과★☆" << endl;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "승자 : " << winner_name; 
	//추후에 경험치랑 획득 골드 넣을 예정

	_getch();
	Menu();
}

GameManager::~GameManager()
{
}
