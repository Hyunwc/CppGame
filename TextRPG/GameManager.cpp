#include "GameManager.h"

GameManager::GameManager()
{
	srand(static_cast<unsigned int>(time(0)));
}
//필요없으면 삭제할 예정
void GameManager::GameSetting()
{
	//MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	LoadMonster();
	m_shop.WeaponLoad();
	GameTitle();
}

void GameManager::LoadMonster()
{
	ifstream load;
	load.open("defaultMonster.txt");
	if (load.is_open())
	{
		while (!load.eof())
		{
			string name;
			int level, hp, power;

			load >> name >> level >> hp >> power;
			Monster monster(name, level, hp, power);
			monsterVec.push_back(monster);
		}
		load.close();
	}
}

void GameManager::GameTitle()
{
	system("cls");
	int Select = 0;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.2);
	cout << "☆★TEXT RPG★☆";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "1. New Game";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "2. Load Game";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "3. Exit";
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
	Select = MapDraw::MenuSelectCursor(3, 3, WIDTH * 0.7, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		NewGame();
		break;
	}
	case 2:
	{
		Load();
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
	MapDraw::gotoxy(WIDTH / 2, HEIGHT / 2);
	cout << "이름을 입력해주세요 : ";
	cin >> name;
	//이 곳에 플레이어에게 이름을 넘겨주는 코드 추가할 예정
	m_player.SetName(name);
	Menu();
}

void GameManager::Menu()
{
	//화면 지우고 맵 다시 그림
	system("cls");
	int Select = 0;
	m_player.LevelUp();
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT - 3);
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.3);
	cout << "☆★메뉴★☆";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "Colosseum";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "Shop";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "Save";
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.7);
	cout << "Exit";
	m_player.ShowInfo();
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
	Select = MapDraw::MenuSelectCursor(4, 3, WIDTH * 0.7, HEIGHT * 0.4);
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
		m_shop.WeaponDisplay(&m_player);
		Menu();
	}
	case 3:
	{
		//저장 아직 개발 안됨
		Save();
		Menu();
	}
	case 4:
	{
		m_player.Reset();
		GameTitle();
		break;
	}
	default:
		break;
	}
}

void GameManager::Colosseum()
{
	system("cls");
	//선택 변수와 높이를 지정할 변수
	int Select = 0;
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
	cout << "☆★콜로세움★☆";
	//몬스터벡터 사이즈만큼 루프를 돌아서 출력!
	for (int i = 0; i < monsterVec.size(); i++)
	{
		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << "레벨" << monsterVec[i].GetLevel() << " : [" << monsterVec[i].GetName() << "]" << endl;
		height += 3;
	}
	MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.8);
	cout << "돌아가기";
	Select = MapDraw::MenuSelectCursor(monsterVec.size() + 1, 3, WIDTH * 0.2, HEIGHT * 0.2);
	//3 6 9 12 15 18 21
	//선택한것이 돌아가기라면 메뉴로 돌아간다.
	if (Select == monsterVec.size() + 1) Menu();
	//Select는 대전할 몬스터의 레벨이기도함. 플레이어의 레벨이 몬스터레벨 이상일떄만
	if(m_player.GetLevel() >= Select)
		GamePlay(Select);
	else
	{
		system("cls");
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.1, HEIGHT * 0.5);
		cout << "당신의 레벨은 " << monsterVec[Select - 1].GetName() << "과 대전하기에 적합하지 않습니다." << endl;
		_getch();
		Colosseum();
	}
	
}

void GameManager::GamePlay(int count)
{
	int Select;
	//획득 경험치와 골드
	int sum_exp = 0, sum_gold = 0;
	//누가 먼저 공격할건지 결정
	bool heroTurn = rand() % 2;
	
	while (1)
	{
		system("cls");

		//변수에 히어로턴이면 플레이어의 이름 아니면 몬스터의 이름
		string name = heroTurn ? m_player.GetName() : m_monster.GetName();
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
		cout << "☆★콜로세움★☆";
		MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.2);
		cout << "현재 턴 : " << name;
		m_player.ShowDisplay();
		MapDraw::gotoxy(WIDTH, HEIGHT * 0.4);
		cout << "vs";
		monsterVec[count - 1].ShowDisplay();
		
		//MapDraw::BoxDraw(2, 20, WIDTH - 2, HEIGHT - 2);
		
		if (heroTurn)
		{
			MapDraw::gotoxy(WIDTH * 0.1, HEIGHT * 0.8);
			cout << "1. 기본 공격 2. 필살기(50 마나 필요) 입력 : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
			{
				//몬스터에게 플레이어의 공격력만큼의 데미지를 준다
				monsterVec[count - 1].takeDamage(m_player.GetDamage());
				MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
				cout << monsterVec[count - 1].GetName() << "에게 " << m_player.GetDamage() << "만큼의 데미지를 주었습니다!";
				break;
			}
			case 2:
			{
				//필살기 로직 나중에 구현할 예정
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
			m_player.takeDamage(monsterVec[count - 1].GetDamage());
			MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
			cout << m_player.GetName() << "에게 " << monsterVec[count - 1].GetDamage() << "만큼의 데미지를 주었습니다!";
		}

		if (m_player.DeadCheck() || monsterVec[count - 1].DeadCheck())
		{
			//몬스터가 죽었다면 플레이어의 열거타입을 아니면 몬스터로
			ResultBord(m_player.DeadCheck() ? MONSTER : PLAYER, monsterVec[count - 1].GetLevel());
		}


		heroTurn = !heroTurn;

		_getch();
	}
}

bool GameManager::FileCheck(int count)
{
	ifstream load;
	load.open("SavePlayer" + to_string(count) + ".txt");
	return load.is_open();
}

void GameManager::Save()
{
	system("cls");
	int Select;
	string ox;
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.1);
	cout << "☆★Save★☆" << endl;
	//MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.3);
	
	for (int i = 1; i <= 5; i++)
	{
		if (FileCheck(i))
			ox = "O";
		else
			ox = "X";

		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << i << "번 슬롯 : (파일여부 : " << ox << ")" << endl;
		height += 3;
	}
	//6 9 12 15 18 21
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
	cout << "돌아가기";
	Select = MapDraw::MenuSelectCursor(6, 3, WIDTH * 0.2, HEIGHT * 0.2);
	if (Select == 6) return;
	
	m_player.DataSave(Select);
	
	system("cls");
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "Save가 완료되었습니다!" << endl;

	_getch();
}

void GameManager::Load()
{
	system("cls");
	int Select;
	string ox;
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.1);
	cout << "☆★Load★☆" << endl;
	for (int i = 1; i <= 5; i++)
	{
		if (FileCheck(i))
			ox = "O";
		else
			ox = "X";

		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << i << "번 슬롯 : (파일여부 : " << ox << ")" << endl;
		height += 3;
	}
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
	cout << "돌아가기";

	Select = MapDraw::MenuSelectCursor(6, 3, WIDTH * 0.2, HEIGHT * 0.2);

	if (Select == 6) GameTitle();
	
	if (FileCheck(Select))
		m_player.DataLoad(Select);
	else
	{
		system("cls");
		MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
		cout << "파일이 존재하지 않습니다";
		_getch();
		Load();
	}
	
	system("cls");
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "Load가 완료되었습니다!" << endl;

	_getch();
	Menu();
}



void GameManager::testfunc()
{
	for (int i = 0; i < monsterVec.size(); i++)
	{
		cout << monsterVec[i].GetLevel() << "," << monsterVec[i].GetName() << endl;
	}
	system("pause");
}



//몬스터 정보창
void GameManager::MonsterInfo()
{
	system("cls");
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	ifstream load;
	load.open("defaultMonster.text");
	if (load.is_open())
	{
		string str;
		while (!load.eof())
		{

		}
	}
}

//결과판 출력 후 플레이어에게 경험치와 골드 전달
void GameManager::ResultBord(int winner, int level)
{
	system("cls");
	int exp = 0, gold = 0;
	//레벨만큼 경험치와 골드를 부여할 예정 졌다면 반만
	if (winner == PLAYER)
	{
		exp = 50 * level;
		gold = 300 * level;
	}
	else
	{
		exp = 25 * level;
		gold = 150 * level;
		m_player.Respone();
	}
	
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	//승자가 플레이어면 플레이어 이름 저장 아니면 몬스터 이름 저장
	string winner_name = (winner == PLAYER) ? m_player.GetName() : monsterVec[level - 1].GetName();
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.3);
	cout << "☆★결과★☆" << endl;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.4);
	cout << "승자 : " << winner_name; 
	//추후에 경험치랑 획득 골드 넣을 예정
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.5);
	cout << "획득 경험치 : " << 50 * level;
	MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.6);
	cout << "획득 골드 : " << 300 * level;

	m_player.SetItem(exp, gold);
	
	//끝나고 전투를 치루었던 몬스터의 hp를 최대로
	monsterVec[level - 1].MaxHp();
	
	_getch();
	Menu();
}

GameManager::~GameManager()
{
}
