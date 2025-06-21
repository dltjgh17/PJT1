#include "UI.h"

std::unique_ptr<UI> UI::instance = nullptr;
UI* UI::getInstance()
{
	static UI instance;
	return &instance;
}

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

///* �κ��丮 UI*/	
void UI::PrintInventory()
{
	Character* p = Character::getInstance();
	const vector<Item*>& Itemlsit = p->getInventory();
	 
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	cout << "=====INVENTORY======" << endl;

	if (Itemlsit.empty())
	{
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 1);
		cout << "| �κ��丮�� ����ֽ��ϴ�." << endl;
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 9);
		cout << "____________________" << endl;
		return;
	}

	// �κ��丮 ����
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
			// nullptr�� ��� �ش� ������ �ǳʶٰų� �� �������� ǥ��
			SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + (int)i + 1);
			std::cout << "| " << (i + 1) << ". [�� ����]" << endl;
		}
	}

	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 12);
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
	cout << "|     ITEM : 3 " << endl;
	cout << "| **TEST GAMOVER: 4"  << endl;
	cout << "| **TEST VICTORY : 5" << endl;
	cout << "____________________" << endl;

	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 8);
	cout << "Action? : ";

}

/* �������� UI*/
void UI::PrintStage()
{
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	cout << "- STAGE : " << StageCount << " -" << endl;
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


/*���� �α�*/
void UI::PrintBattleLog()
{
	SetCursorPosition(UI_XY::POS_BATTLE_TITLE_X, UI_XY::POS_BATTLE_TITLE_Y);
	cout << "======= BATTLE ========" << endl;

	if (!BattleLog.empty())
	{
		// ���� ũ�� ���� (20�� �ʰ��� ������ �α� ����)
		while (BattleLog.size() > 10)
		{
			BattleLog.erase(BattleLog.begin());
		}

		// ���� ���� ũ�� �������� �ݺ�
		for (size_t i = 0; i < BattleLog.size(); ++i)
		{
			SetCursorPosition(UI_XY::POS_BATTLE_LOG_X-8, UI_XY::POS_BATTLE_LOG_Y + i + 1);
			cout << BattleLog[i] << endl;
			Sleep(10);
		}
	}
	
	// ���� ������ ��� �α� �����ع����� �� ���� �� ������... 
}

/*��� ��� �α�*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	cout << "======= FULL LOG =======" << endl;

	if (!FullLog.empty())
	{
		// ���� ũ�� ���� (10�� �ʰ��� ������ �α� ����)
		while (FullLog.size() > 22) {
			FullLog.erase(FullLog.begin());
		}

		// ������ �ݺ��� - ���� ���� ũ�� �������� �ݺ�
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