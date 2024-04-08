#include "GameManager.h"

GameManager::GameManager()
{
	srand(static_cast<unsigned int>(time(0)));
}
void GameManager::GameSetting()
{
	//몬스터와 무기를 외부에서 읽어온뒤 GameTitle 실행
	LoadMonster();
	m_shop.WeaponLoad();
	GameTitle();
}

void GameManager::LoadMonster()
{
	//defaultMonster.txt에서 읽어와 이름, 레벨, hp, 전투력이 담긴 인스턴스를 벡터에 삽입
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
		NewGame(); //새게임
		break;
	}
	case 2:
	{
		Load(); //저장되었던 정보 불러오기
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
	//플레이어에게 이름을 넘겨주고 메뉴 출력
	m_player.SetName(name);
	Menu();
}

void GameManager::Menu()
{
	//화면 지우고 맵 다시 그림
	system("cls");
	int Select = 0;
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
	//현재 플레이어의 저보를 출력해줌
	m_player.ShowInfo();
	//메뉴 갯수, 커서 y좌표를 얼마만큼 내릴지 , 초기 x,y 좌표값
	Select = MapDraw::MenuSelectCursor(4, 3, WIDTH * 0.7, HEIGHT * 0.4);
	switch (Select)
	{
	case 1:
	{
		Colosseum(); //콜로세움 입장
		break;
	}
	case 2:
	{
		//보유 골드로 무기를 구매할 수 있는 상점 
		m_shop.WeaponDisplay(&m_player);
		Menu();
		break;
	}
	case 3:
	{
		//현 플레이어의 정보 저장
		Save();
		Menu();
		break;
	}
	case 4:
	{
		//현 플레이어 정보 초기화하고 GameTitle로 
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
	//선택한것이 돌아가기라면 메뉴로 돌아간다.
	if (Select == monsterVec.size() + 1) Menu();
	//Select는 대전할 몬스터의 레벨이기도함. 플레이어의 레벨이 몬스터레벨 이상일떄만 GamePlay
	if(m_player.GetLevel() >= Select)
		GamePlay(Select);
	else
	{
		system("cls");
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.1, HEIGHT * 0.5);
		//플레이어 레벨이 몬스터보다 낮다면 다시 콜로세움으로
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
		string name = heroTurn ? m_player.GetName() : monsterVec[count - 1].GetName();
		MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
		MapDraw::gotoxy(WIDTH * 0.7, HEIGHT * 0.1);
		cout << "☆★콜로세움★☆";
		MapDraw::gotoxy(WIDTH * 0.8, HEIGHT * 0.2);
		cout << "현재 턴 : " << name;
		m_player.ShowDisplay();
		MapDraw::gotoxy(WIDTH, HEIGHT * 0.4);
		cout << "vs";
		monsterVec[count - 1].ShowDisplay();
		
		//히어로턴
		if (heroTurn)
		{
			monsterVec[count - 1].takeDamage(m_player.GetDamage());
			MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
			cout << monsterVec[count - 1].GetName() << "에게 " << m_player.GetDamage() << "만큼의 데미지를 주었습니다!";
		}
		else
		{
			//몬스터 턴일땐 플레이어에게 몬스터의 전투력만큼 데미지를 줌
			m_player.takeDamage(monsterVec[count - 1].GetDamage());
			MapDraw::gotoxy(WIDTH * 0.2, HEIGHT * 0.7);
			cout << m_player.GetName() << "에게 " << monsterVec[count - 1].GetDamage() << "만큼의 데미지를 주었습니다!";
		}

		//둘중 하나의 hp가 0이 되었을때
		if (m_player.DeadCheck() || monsterVec[count - 1].DeadCheck())
		{
			//결과전송
			ResultBord(m_player.DeadCheck() ? MONSTER : PLAYER, monsterVec[count - 1].GetLevel());
		}

		//턴체인지
		heroTurn = !heroTurn;

		_getch();
	}
}

//파일이 존재하는지 체크하는 함수
bool GameManager::FileCheck(int count)
{
	ifstream load;
	load.open("SavePlayer" + to_string(count) + ".txt");
	bool isOpen = load.is_open();
	load.close(); 
	return isOpen;
}

void GameManager::Save()
{
	system("cls");
	int Select;
	string ox; // 파일 존재 여부를 작성하기 위한 변수
	int height = HEIGHT * 0.2;
	MapDraw::BoxDraw(0, 0, WIDTH, HEIGHT);
	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.1);
	cout << "☆★Save★☆" << endl;
	//MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.3);
	
	for (int i = 1; i <= 5; i++)
	{
		//파일이 존재한다면 o표시 아니면 x표시
		if (FileCheck(i))
			ox = "O";
		else
			ox = "X";

		MapDraw::gotoxy(WIDTH * 0.5, height);
		cout << i << "번 슬롯 : (파일여부 : " << ox << ")" << endl;
		height += 3; //높이조절
	}

	MapDraw::gotoxy(WIDTH * 0.5, HEIGHT * 0.7);
	cout << "돌아가기";
	Select = MapDraw::MenuSelectCursor(6, 3, WIDTH * 0.2, HEIGHT * 0.2);
	if (Select == 6) return; //돌아가기
	
	//플레이어에게 데이터 저장할 위치 보냄
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
	
	//파일이 존재할때만 DataLoad 아니면 다시 Load함수 실행
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
	//플레이어가 패배했을시 보상은 절반. hp가 0이니 리스폰함수 호출해서 hp충전
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

	//플레이어에게 획득 exp와 gold를 보내줌
	m_player.SetItem(exp, gold);
	
	//끝나고 전투를 치루었던 몬스터의 hp를 최대로
	monsterVec[level - 1].MaxHp();
	
	_getch();
	m_player.LevelUp();
	Menu();
}

GameManager::~GameManager()
{
}
