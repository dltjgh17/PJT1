#include "UI.h"

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
	int UIATK = p->getAttack();
	int UIGold = p->getGold();

	SetCursorPosition(UI_XY::POS_STATUS_X, UI_XY::POS_STATUS_Y);

	cout << "=======STATUS=======" << endl;
	cout << "|  Name : " << UIName << endl;
	cout << "|  Level : " << UILevel << endl;
	cout << "|     HP : " << UIHP << endl;
	cout << "|    ATK : " << UIATK << endl;
	cout << "|   Gold : " << UIGold << endl;
	cout << "____________________" << endl;
}


/* 인벤토리 UI*/
void UI::PrintInventory()
{
	// 아이템 어디에 저장되는 정확히 파악되기 전까지 참조 보류//
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	cout << "=====INVENTORY======" << endl;
	cout << "| item A : AAAAAAA" << endl;
	cout << "| item B : BBBBBBB" << endl;
	cout << "| item C : CCCCCCC" << endl;
	cout << "| item D : CCCCCCC" << endl;
	cout << "____________________" << endl;

}

/* 상점 UI (방문 안 했을 때)*/
void UI::PrintIsShop()
{
	SetCursorPosition(UI_XY::POS_SHOP_X, UI_XY::POS_SHOP_Y);
	cout << "========SHOP========" << endl;
	cout << "|      NOT NOW " << endl;
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
	cout << "|      ESC : 3 " << endl;
	cout << "____________________" << endl;
}


/* 스테이지 UI*/
void UI::PrintStage()
{
	static int StageCount = 0;
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	cout << "- STAGE : " << ++StageCount << " -" << endl;
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
		return;
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
	cout << "======= BATTLE =======" << endl;

	if (!BattleLog.empty())
	{

		for (int i = 0; i < BattleLog.size(); ++i)
		{
			if (BattleLog.size() > 15)
			{
				BattleLog.erase(BattleLog.begin());
			}

			SetCursorPosition(UI_XY::POS_BATTLE_LOG_X, UI_XY::POS_BATTLE_LOG_Y + i + 1);
			cout << BattleLog[i] << endl;
		}
	}
}


/*모든 기록 로그*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	cout << "======= FULL LOG =======" << endl;

	if (!FullLog.empty())
	{
		for (int i = 0; i < FullLog.size(); ++i)
		{
			if (FullLog.size() > 20)
			{
				FullLog.erase(FullLog.begin());
			}

			SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y + i + 1);
			cout << FullLog[i] << endl;
		}
	}
}
void UI::AddFullLog(const std::string& log)
{
	FullLog.push_back(log);
}

std::vector<std::string>* UI::GetFullLogPtr()
{
	return &FullLog;
}


void UI::AddBattleLog(const std::string& log)
{
	BattleLog.push_back(log);
}

std::vector<std::string>* UI::GetBattleLogPtr()
{
	return &BattleLog;
}

void UI::CheckVal()
{
	PrintStatus();
	PrintInventory();
	PrintAction();
	PrintBattleLog();
	PrintFullLog();
	PrintMonsterSummary();
	PrintPlayerSummry();
}
