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
	cout << "=======상태창=======" << endl;
	cout << "|    이름 : " << UIName << endl;
	cout << "|    레벨 : " << UILevel << endl;
	cout << "|    체력 : " << UIHP << "/" << MAXHP << endl;
	cout << "|  공격력 : " << UIATK << endl;
	cout << "|    골드 : " << UIGold << endl;
	cout << "|  경험치 : " << EXP << "/100" << endl;
	cout << "____________________" << endl;
}

///* 인벤토리 UI*/	
void UI::PrintInventory()
{
	Character* p = Character::getInstance();
	const vector<Item*>& Itemlsit = p->getInventory();
	 
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	cout << "===== 인벤토리 ======" << endl;

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
	cout << "|     전투 : 1 " << endl;
	cout << "|     상점 : 2 " << endl;
	cout << "|   아이템 : 3 " << endl;
	cout << "| **TEST GAMOVER: 4"  << endl;
	cout << "| **TEST VICTORY : 5" << endl;
	cout << "____________________" << endl;

	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 8);
	cout << "어떤 행동을 하시겠습니까? : ";

}

/* 스테이지 UI*/
void UI::PrintStage()
{
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	cout << "- 현재 스테이지 : " << StageCount << " -" << endl;
	PastStageCount = StageCount;
}


/*플레이어 전투 상태창*/
//void UI::PrintPlayerSummry()
//{
//
//	Character* p = Character::getInstance();
//	string UIName = p->getName();
//	int UIHP = p->getHealth();
//	int UIATK = p->getAttack();
//
//	SetCursorPosition(UI_XY::POS_PLAYER_SUMMARY_X, UI_XY::POS_PLAYER_SUMMARY_Y);
//	cout << "=   PLAYER   =" << endl;
//	SetCursorPosition(UI_XY::POS_PLAYER_SUMMARY_X, UI_XY::POS_PLAYER_SUMMARY_Y + 1);
//	cout << "=  HP : " << UIHP << " =" << endl;
//	SetCursorPosition(UI_XY::POS_PLAYER_SUMMARY_X, UI_XY::POS_PLAYER_SUMMARY_Y + 2);
//	cout << "= ATK " << UIATK << " =" << endl;
//}


///*몬스터 가져오기*/
//void UI::SetMonster(Monster* m)
//{
//	currentMonster = m;
//}
//
///*몬스터 전투 상태창*/
//void UI::PrintMonsterSummary()
//{
//	if (currentMonster == nullptr)
//	{
//		SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y);
//		cout << "=  " " =" << endl;
//		SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 1);
//		cout << "=  HP : "  << "=" << endl;
//		SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 2);
//		cout << "= ATK : " << " =" << endl;
//	}
//
//	SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y);
//	cout << "=  " << currentMonster->GetName() << " =" << endl;
//	SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 1);
//	cout << "=  HP : " << currentMonster->GetHealth() << " =" << endl;
//	SetCursorPosition(UI_XY::POS_MONSTER_SUMMARY_X, UI_XY::POS_MONSTER_SUMMARY_Y + 2);
//	cout << "= ATK : " << currentMonster->GetAttack() << " =" << endl;
//}


/*이전 전투 로그 삭제*/
void UI::DeletePastBattleLog()
{
	BattleLog.erase(BattleLog.begin(),BattleLog.end());
}


/*전투 로그*/
void UI::PrintBattleLog()
{
	SetCursorPosition(UI_XY::POS_BATTLE_TITLE_X-8, UI_XY::POS_BATTLE_LOG_Y);
	cout << "======= 전투 기록 ========" << endl;

	if (!BattleLog.empty())
	{
		// 벡터 크기 제한 (10개 초과시 오래된 로그 삭제)
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
	
}

/*모든 기록 로그*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	cout << "     ======= 당신의 여정 =======" << endl;

	if (!FullLog.empty())
	{
		// 벡터 크기 제한 (22개 초과시 오래된 로그 삭제)
		while (FullLog.size() > 22)
		{
			FullLog.erase(FullLog.begin());
		}

		// 현재 벡터 크기 기준으로 반복
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
	//PrintMonsterSummary();
	//PrintPlayerSummry();

	PrintFullLog();
	PrintStage();
	PrintAction();
}