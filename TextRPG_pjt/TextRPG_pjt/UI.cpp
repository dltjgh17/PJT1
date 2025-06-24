#include "UI.h"
#include <windows.h>
#include <memory>
/*���� �ν��Ͻ��� ����*/
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
	std::cout << "=======����â=======" << endl;
	std::cout << "|    �̸� : " << UIName << endl;
	std::cout << "|    ���� : " << UILevel << endl;
	std::cout << "|    ü�� : " << UIHP << "/" << MAXHP << endl;
	std::cout << "|  ���ݷ� : " << UIATK << endl;
	std::cout << "|    ��� : " << UIGold << endl;
	std::cout << "|  ����ġ : " << EXP << "/100" << endl;
	std::cout << "____________________" << endl;
}

///* �κ��丮 UI*/	
void UI::PrintInventory()
{
	Character* p = Character::getInstance();
	const vector<Item*>& Itemlsit = p->getInventory();
	 
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	std::cout << "===== �κ��丮 ======" << endl;

	// �κ��丮 ���� ������ ����ó��//
	if (Itemlsit.empty())
	{
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 1);
		std::cout << "| �κ��丮�� ����ֽ��ϴ�." << endl;
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 9);
		std::cout << "____________________" << endl;
		return;
	}

	// �κ��丮 �����ؼ� ��������
	for (size_t i = 0; i < Itemlsit.size(); ++i)
	{
		// ���� ó�� (ǥ�� ���� �� �κ��丮 ���� ���� �� ����ó��)
		if (i >= Itemlsit.size()) break;
		if (i >= 11 ) break;

		// nullptr�� �ƴ� ��� ���� ǥ��
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
	std::cout << "____________________" << endl;
}

/* �ൿ ���� ���� UI*/
void UI::PrintAction()
{
	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y);
	std::cout << "=======ACTION=======" << endl;
	std::cout << "|     ���� : 1 " << endl;
	std::cout << "|     ���� : 2 " << endl;
	std::cout << "|   ������ : 3 " << endl;
	std::cout << "|     ���� : 4"  << endl;
	std::cout << "____________________" << endl;

	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 8);
	std::cout << "� �ൿ�� �Ͻðڽ��ϱ�? : ";

	/*�Է� �׻� �ʱ�ȭ �� �Է� �ޱ�*/
	ChooseAction = 0;
	std::cin >> ChooseAction;
}

/* �������� UI*/
void UI::PrintStage()
{
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	std::cout << "- ���� �������� : " << StageCount << " -" << endl;
	PastStageCount = StageCount;
}


/*���� ���� �α� ����*/
void UI::DeletePastBattleLog()
{
	BattleLog.erase(BattleLog.begin(),BattleLog.end());
}


/*���� �α�*/
void UI::PrintBattleLog()
{
	SetCursorPosition(UI_XY::POS_BATTLE_LOG_X-8, UI_XY::POS_BATTLE_LOG_Y);
	std::cout << "======= ���� ��� ========" << endl;

	if (!BattleLog.empty()) // 0. �α� ���� �˻� 
	{
		while (BattleLog.size() > 10) // 1.���� ũ�� ���� �� 10�� �ʰ��� ������ �α� ����
		{
			BattleLog.erase(BattleLog.begin());
		}
		for (size_t i = 0; i < BattleLog.size(); ++i)  // 3. �ֽ�ȭ�� ���� ũ�� �������� ���
		{
			SetCursorPosition(UI_XY::POS_BATTLE_LOG_X-8, UI_XY::POS_BATTLE_LOG_Y + i + 1);
			std::cout << BattleLog[i] << endl;
			Sleep(10);
		}
	}
	
}

/*��� ��� �α�*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	std::cout << "     ======= ����� ���� =======" << endl;
 
	if (!FullLog.empty()) // 0. �α� ���� �˻� 
	{
		while (FullLog.size() > 22) // 1.���� ũ�� ���� �� 22�� �ʰ��� ������ �α� ����
		{
			FullLog.erase(FullLog.begin());
		}
		for (size_t i = 0; i < FullLog.size(); ++i) // 3. �ֽ�ȭ�� ���� ũ�� �������� ���
		{
			SetCursorPosition(UI_XY::POS_FULL_LOG_X+8, UI_XY::POS_FULL_LOG_Y + i + 1);
			std::cout << FullLog[i] << endl;
			Sleep(10);
		}
	}
}

/*Ǯ �α׿� ������ ��� �޾ƿ�����*/
void UI::AddFullLog(const std::string& log)
{
	FullLog.push_back(log);
}

/*���� �α׿� ������ ��� �޾ƿ����*/
void UI::AddBattleLog(const std::string& log)
{
	BattleLog.push_back(log);
}

/*ȭ�� ��¿� �Լ�*/
void UI::CheckVal()
{
	// UI ������Ʈ �� �Է��� ��ȯ �ʱ�ȭ
	system("cls");
	cin.clear();
	cin.ignore();

	// UI�� ������Ʈ�� �ֽ� ���� �ҷ�����
	PrintStatus();
	PrintInventory();
	PrintBattleLog();
	PrintFullLog();
	PrintStage();
	PrintAction();
}