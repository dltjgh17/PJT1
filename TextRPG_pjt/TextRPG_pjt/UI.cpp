#include "UI.h"

/* UI ��ġ �� �Լ�*/
void UI::SetCursorPosition(int X, int Y) 
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* ����â UI*/
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


/* �κ��丮 UI*/
void UI::PrintInventory()
{
	// ������ ��� ����Ǵ� ��Ȯ�� �ľǵǱ� ������ ���� ����//
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	cout << "=====INVENTORY======" << endl;
	cout << "| item A : AAAAAAA" << endl;
	cout << "| item B : BBBBBBB" << endl;
	cout << "| item C : CCCCCCC" << endl;
	cout << "| item D : CCCCCCC" << endl;
	cout << "____________________" << endl;

}

/* ���� UI (�湮 �� ���� ��)*/
void UI::PrintIsShop()
{
	SetCursorPosition(UI_XY::POS_SHOP_X, UI_XY::POS_SHOP_Y);
	cout << "========SHOP========" << endl;
	cout << "|      NOT NOW " << endl;
	cout << "____________________" << endl;
}

/* �ൿ ���� ���� UI*/
void UI::PrintAction()
{
	//�ý��� ���� �ϼ����� ���� ����//
	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y);
	cout << "=======ACTION=======" << endl;
	cout << "|   BATTLE : 1 " << endl;
	cout << "|     SHOP : 2 " << endl;
	cout << "|      ESC : 3 " << endl;
	cout << "____________________" << endl;
}


/* �������� UI*/
void UI::PrintStage()
{
	static int StageCount = 0;
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	cout << "- STAGE : " << ++StageCount << " -" << endl;
}



/*�÷��̾� ���� ����â*/
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


/*���� ��������*/
void UI::SetMonster(Monster* m)
{
	currentMonster = m;
}

/*���� ���� ����â*/
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


/*���� �α�*/
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


/*��� ��� �α�*/
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
