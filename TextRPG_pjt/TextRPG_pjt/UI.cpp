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
	cout << "=======����â=======" << endl;
	cout << "|    �̸� : " << UIName << endl;
	cout << "|    ���� : " << UILevel << endl;
	cout << "|    ü�� : " << UIHP << "/" << MAXHP << endl;
	cout << "|  ���ݷ� : " << UIATK << endl;
	cout << "|    ��� : " << UIGold << endl;
	cout << "|  ����ġ : " << EXP << "/100" << endl;
	cout << "____________________" << endl;
}

///* �κ��丮 UI*/	
void UI::PrintInventory()
{
	Character* p = Character::getInstance();
	const vector<Item*>& Itemlsit = p->getInventory();
	 
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	cout << "===== �κ��丮 ======" << endl;

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
	cout << "|     ���� : 1 " << endl;
	cout << "|     ���� : 2 " << endl;
	cout << "|   ������ : 3 " << endl;
	cout << "| **TEST GAMOVER: 4"  << endl;
	cout << "| **TEST VICTORY : 5" << endl;
	cout << "____________________" << endl;

	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 8);
	cout << "� �ൿ�� �Ͻðڽ��ϱ�? : ";

}

/* �������� UI*/
void UI::PrintStage()
{
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	cout << "- ���� �������� : " << StageCount << " -" << endl;
	PastStageCount = StageCount;
}


/*�÷��̾� ���� ����â*/
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


///*���� ��������*/
//void UI::SetMonster(Monster* m)
//{
//	currentMonster = m;
//}
//
///*���� ���� ����â*/
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


/*���� ���� �α� ����*/
void UI::DeletePastBattleLog()
{
	BattleLog.erase(BattleLog.begin(),BattleLog.end());
}


/*���� �α�*/
void UI::PrintBattleLog()
{
	SetCursorPosition(UI_XY::POS_BATTLE_TITLE_X-8, UI_XY::POS_BATTLE_LOG_Y);
	cout << "======= ���� ��� ========" << endl;

	if (!BattleLog.empty())
	{
		// ���� ũ�� ���� (10�� �ʰ��� ������ �α� ����)
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
	
}

/*��� ��� �α�*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	cout << "     ======= ����� ���� =======" << endl;

	if (!FullLog.empty())
	{
		// ���� ũ�� ���� (22�� �ʰ��� ������ �α� ����)
		while (FullLog.size() > 22)
		{
			FullLog.erase(FullLog.begin());
		}

		// ���� ���� ũ�� �������� �ݺ�
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