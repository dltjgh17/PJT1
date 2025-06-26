#include "UI.h"
#include <windows.h>
#include <memory>
/*단일 인스턴스로 생성*/
std::unique_ptr<UI> UI::instance = nullptr;
UI* UI::getInstance()
{
	static UI localInstance; // Renamed the local variable to 'localInstance'
	return &localInstance;
}

GameState UI::currentState = GameState::Running;

/* UI 위치 값 함수*/
void UI::SetCursorPosition(int X, int Y) 
{
	COORD coord = { 0, 0 };
	coord.X = static_cast<SHORT>(X); // Explicitly cast int to SHORT
	coord.Y = static_cast<SHORT>(Y); // Explicitly cast int to SHORT
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
	std::cout << "=======상태창=======" << endl;
	std::cout << "|    이름 : " << UIName << endl;
	std::cout << "|    레벨 : " << UILevel << endl;
	std::cout << "|    체력 : " << UIHP << "/" << MAXHP << endl;
	std::cout << "|  공격력 : " << UIATK << endl;
	std::cout << "|    골드 : " << UIGold << endl;
	std::cout << "|  경험치 : " << EXP << "/100" << endl;
	std::cout << "____________________" << endl;
}

///* 인벤토리 UI*/	
void UI::PrintInventory()
{
	Character* p = Character::getInstance();
	const vector<Item*>& Itemlsit = p->getInventory();
	 
	SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y);
	std::cout << "===== 인벤토리 ======" << endl;

	// 인벤토리 접근 오류시 예외처리//
	if (Itemlsit.empty())
	{
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 1);
		std::cout << "| 인벤토리가 비어있습니다." << endl;
		SetCursorPosition(UI_XY::POS_INVENTORY_X, UI_XY::POS_INVENTORY_Y + 9);
		std::cout << "____________________" << endl;
		return;
	}

	// 인벤토리 접근해서 가져오기
	for (size_t i = 0; i < Itemlsit.size(); ++i)
	{
		// 예외 처리 (표시 갯수 및 인벤토리 오버 접근 시 예외처리)
		if (i >= Itemlsit.size()) break;
		if (i >= 11 ) break;

		// nullptr인 아닌 경우 슬롯 표시
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
	std::cout << "____________________" << endl;
}

/* 행동 유형 선택 UI*/
void UI::PrintAction()
{
	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y);
	std::cout << "=======행동 선택=======" << endl;
	std::cout << "|      전투 : 1 " << endl;
	std::cout << "|      상점 : 2 " << endl;
	std::cout << "|    아이템 : 3 " << endl;
	std::cout << "|      종료 : 4" << endl;
	std::cout << "____________________" << endl;

	SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 8);
	std::cout << "어떤 행동을 하시겠습니까? : ";

	/*입력 항상 초기화 후 입력 받기*/
	/*입력 받기 - getline 사용*/
	ChooseAction = 0;
	std::string input;

	std::getline(std::cin, input);

	// 입력이 비어있는지 확인
	if (input.empty())
	{
		SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 9);
		std::cout << "올바른 숫자를 입력해주세요! : ";
		return;
	}

	// 입력이 숫자로만 이루어져 있는지 확인
	for (char c : input) {
		if (!isdigit(c)) { // 문자가 숫자가 아니라면
			SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 9);
			std::cout << "올바른 숫자를 입력해주세요! : ";
			return; // 함수를 즉시 종료하고 재입력 요구
		}
	}

	// 문자열을 숫자로 변환 시도
	try
	{
		ChooseAction = std::stoi(input); // 문자열을 정수로 변환
		if (ChooseAction >= 1 && ChooseAction <= 4)
		{
			return; // 올바른 입력이면 함수 종료
		}
		else
		{
			SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 9);
			std::cout << "1~4 사이의 숫자를 입력해주세요! : ";
		}
	}
	catch (const std::out_of_range&) // 입력된 숫자가 너무 큰 경우
	{
		SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 9);
		std::cout << "입력된 숫자가 너무 큽니다. 다시 입력해주세요! : ";
	}
	catch (const std::exception&) // 기타 예외 처리 (이 경우는 위에서 대부분 걸러짐)
	{
		SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 9);
		std::cout << "올바른 숫자를 입력해주세요! : ";
	}
}


/* 스테이지 UI*/
void UI::PrintStage()
{
	SetCursorPosition(UI_XY::POS_STAGE_X, UI_XY::POS_STAGE_Y);
	std::cout << "- 현재 스테이지 : " << StageCount << " -" << endl;
	PastStageCount = StageCount;
}


/*이전 전투 로그 삭제*/
void UI::DeletePastBattleLog()
{
	BattleLog.erase(BattleLog.begin(),BattleLog.end());
}


/*전투 로그*/
void UI::PrintBattleLog()
{
	SetCursorPosition(UI_XY::POS_BATTLE_LOG_X-8, UI_XY::POS_BATTLE_LOG_Y);
	std::cout << "======= 전투 기록 ========" << endl;

	if (!BattleLog.empty()) // 0. 로그 접근 검사 
	{
		while (BattleLog.size() > 10) // 1.벡터 크기 제한 시 10개 초과시 오래된 로그 삭제
		{
			BattleLog.erase(BattleLog.begin());
		}
		for (size_t i = 0; i < BattleLog.size(); ++i)  // 3. 최신화한 벡터 크기 기준으로 출력
		{
			SetCursorPosition(UI_XY::POS_BATTLE_LOG_X - 8, UI_XY::POS_BATTLE_LOG_Y + static_cast<int>(i) + 1);
			std::cout << BattleLog[i] << endl;
		}
	}
	
}

/*모든 기록 로그*/
void UI::PrintFullLog()
{
	SetCursorPosition(UI_XY::POS_FULL_LOG_X, UI_XY::POS_FULL_LOG_Y);
	std::cout << "     ======= 당신의 여정 =======" << endl;
 
	if (!FullLog.empty()) // 0. 로그 접근 검사 
	{
		while (FullLog.size() > 22) // 1.벡터 크기 제한 시 22개 초과시 오래된 로그 삭제
		{
			FullLog.erase(FullLog.begin());
		}
		for (size_t i = 0; i < FullLog.size(); ++i) // 3. 최신화한 벡터 크기 기준으로 출력
		{
			SetCursorPosition(UI_XY::POS_FULL_LOG_X+8, UI_XY::POS_FULL_LOG_Y + static_cast<int>(i) + 1);
			std::cout << FullLog[i] << endl;
		}
	}
}

/*풀 로그에 저장할 기록 받아오기요용*/
void UI::AddFullLog(const std::string& log)
{
	FullLog.push_back(log);
}

/*전투 로그에 저장할 기록 받아오기용*/
void UI::AddBattleLog(const std::string& log)
{
	BattleLog.push_back(log);
}

/*화면 출력용 함수*/
void UI::CheckVal()
{
	// UI 업데이트 및 입력을 위환 초기화
	system("cls");

	// UI에 업데이트할 최신 상태 불러오기
	PrintStatus();
	PrintInventory();
	PrintBattleLog();
	PrintFullLog();
	PrintStage();
	PrintAction();
}

/*예비용 입력 함수*/
// 사용법
// UI 헤더 추가하고 
// UI* InterFace = UI::getInstance(); 사용할 스코프, 함수의 내부에 선언
// 아래 함수를 InterFace->Input(); 이렇게 가져오면 됩니다.
void UI::Input()
{
/*입력 항상 초기화 후 입력 받기*/
/*입력 받기 - getline 사용*/
ChooseAction = 0;
std::string input;


std::getline(std::cin, input);

// 입력이 비어있는지 확인
if (input.empty())
{
	std::cout << "올바른 숫자를 입력해주세요! : ";
	return;
}

// 문자열을 숫자로 변환 시도
try
{
	ChooseAction = std::stoi(input);
	if (ChooseAction >= 1 && ChooseAction <= 4)
	{
		return; // 올바른 입력이면 루프 종료
	}
	else
	{
		std::cout << "1~4 사이의 숫자를 입력해주세요! : ";
	}
}
catch (const std::exception&)
{
	std::cout << "올바른 숫자를 입력해주세요! : ";
}
}