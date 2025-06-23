#include "UI.h"

std::unique_ptr<UI> UI::instance = nullptr;
UI* UI::getInstance()
{
	static UI instance;
	return &instance;
}

/* UI 위치 값 함수*/
void UI::SetCursorPosition(int X, int Y) 
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* 상태창 UI*/
void UI::PrintStatus() 
{
	Character* p = Character::getInstance();
	string UIName = p->getName();
	int UILevel = p->getLevel();
	int UIHP = p->getHealth();
	int MAXHP = p->getMaxHealth();
	int UIATK = p->getAttack();
	int UIGold = p->getGold();
	int EXP = p->getExp();

	SetCursorPosition(UI_XY::POS_STATUS_X, UI_XY::POS_STATUS_Y);
	cout << "=======STATUS=======" << endl;
	cout << "|  Name : " << UIName << endl;
	cout << "|  Level : " << UILevel << endl;
	cout << "|     HP : " << UIHP << "/" << MAXHP << endl;
	cout << "|    ATK : " << UIATK << endl;
	cout << "|   Gold : " << UIGold << endl;
	cout << "|   EXP : " << EXP << "/100" << endl;
	cout << "____________________" << endl;
}

///* 인벤토리 UI*/	
void UI::PrintInventory()
{
	Character* p = Character::getInstance();
	const vector<Item*>& Itemlsit = p->getInventory();
	 
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	cout << "=====INVENTORY======" << endl;

	if (Itemlsit.empty())
	{
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 1);
		cout << "| 인벤토리가 비어있습니다." << endl;
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 9);
		cout << "____________________" << endl;
		return;
	}

	// 인벤토리 접근
	for (size_t i = 0; i < Itemlsit.size(); ++i)
	{
		if (i >= Itemlsit.size()) break;
		if (i >= 11 ) break;

		if (Itemlsit[i] != nullptr)
		{
			SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + (int)i + 1);
			std::cout << "| " << (i + 1) << ". " << Itemlsit[i]->getName() << endl;
		}
		else
		{
			// nullptr인 경우 해당 슬롯은 건너뛰거나 빈 슬롯으로 표시
			SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + (int)i + 1);
			std::cout << "| " << (i + 1) << ". [빈 슬롯]" << endl;
		}
	}

	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 12);
	cout << "____________________" << endl;
}

/* 행동 유형 선택 UI*/
void UI::PrintAction()
{
	//시스템 전부 완성까지 참조 보류//
	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y);
	cout << "=======ACTION=======" << endl;
	cout << "|   BATTLE : 1 " << endl;
	cout << "|     SHOP : 2 " << endl;
	cout << "|     ITEM : 3 " << endl;
	cout << "| **TEST GAMOVER: 4"  << endl;
	cout << "| **TEST VICTORY : 5" << endl;
	cout << "____________________" << endl;

	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 8);
	cout << "Action? : ";

}

/* 스테이지 UI*/
void UI::PrintStage()
{
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	cout << "- STAGE : " << StageCount << " -" << endl;
}


/*플레이어 전투 상태창*/
void UI::PrintPlayerSummry()
{

	Character* p = Character::getInstance();
	string UIName = p->getName();
	int UIHP = p->getHealth();
	int UIATK = p->getAttack();

	SetCursorPosition(UI_XY::POS_PLAYER_SUMMARY_X, UI_XY::POS_PLAYER_SUMMARY_Y);
	cout << "=   PLAYER   =" << endl;
	SetCursorPosition(UI_XY::POS_PLAYER_SUMMARY_X, UI_XY::POS_PLAYER_SUMMARY_Y + 1);
	cout << "=  HP : " << UIHP << " =" << endl;
	SetCursorPosition(UI_XY::POS_PLAYER_SUMMARY_X, UI_XY::POS_PLAYER_SUMMARY_Y + 2);
	cout << "= ATK " << UIATK << " =" << endl;
}


/*몬스터 가져오기*/
void UI::SetMonster(Monster* m)
{
	currentMonster = m;
}

/*몬스터 전투 상태창*/
void UI::PrintMonsterSummary()
{
	if (currentMonster == nullptr)
	{
		SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y);
		cout << "=  " " =" << endl;
		SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 1);
		cout << "=  HP : "  << "=" << endl;
		SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 2);
		cout << "= ATK : " << " =" << endl;
	}

	SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y);
	cout << "=  " << currentMonster->GetName() << " =" << endl;
	SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 1);
	cout << "=  HP : " << currentMonster->GetHealth() << " =" << endl;
	SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 2);
	cout << "= ATK : " << currentMonster->GetAttack() << " =" << endl;
}


/*전투 로그*/
void UI::PrintBattleLog()
{
	SetCursorPosition(UI_XY::POS_BATTLE_TITLE_X, UI_XY::POS_BATTLE_TITLE_Y);
	cout << "======= BATTLE ========" << endl;

	if (!BattleLog.empty())
	{
		// 벡터 크기 제한 (20개 초과시 오래된 로그 삭제)
		while (BattleLog.size() > 10)
		{
			BattleLog.erase(BattleLog.begin());
		}

		// 현재 벡터 크기 기준으로 반복
		for (size_t i = 0; i < BattleLog.size(); ++i)
		{
			SetCursorPosition(UI_XY::POS_BATTLE_LOG_X-8, UI_XY::POS_BATTLE_LOG_Y + i + 1);
			cout << BattleLog[i] << endl;
			Sleep(10);
		}
	}
	
	// 전투 끝나면 모든 로그 삭제해버리는 게 좋을 것 같은데... 
}

/*모든 기록 로그*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	cout << "======= FULL LOG =======" << endl;

	if (!FullLog.empty())
	{
		// 벡터 크기 제한 (10개 초과시 오래된 로그 삭제)
		while (FullLog.size() > 22) {
			FullLog.erase(FullLog.begin());
		}

		// 안전한 반복문 - 현재 벡터 크기 기준으로 반복
		for (size_t i = 0; i < FullLog.size(); ++i)
		{
			SetCursorPosition(UI_XY::POS_FULL_LOG_X+8, UI_XY::POS_FULL_LOG_Y + i + 1);
			cout << FullLog[i] << endl;
			Sleep(10);
		}
	}
}
void UI::AddFullLog(const std::string& log)
{
	FullLog.push_back(log);
}

void UI::AddBattleLog(const std::string& log)
{
	BattleLog.push_back(log);
}

void UI::CheckVal()
{
	system("cls");
	PrintStatus();
	PrintInventory();

	PrintBattleLog();
	PrintMonsterSummary();
	PrintPlayerSummry();

	PrintFullLog();
	PrintStage();
	PrintAction();
}