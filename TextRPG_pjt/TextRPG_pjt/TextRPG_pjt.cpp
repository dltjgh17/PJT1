// TextRPG_pjt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "UI.h"
#include <string>
#include "Monster.h"
#include "MonsterData.h"
#include "Title.h"
#include "Shop.h"

int main()
{
	/*인스턴스 및 필요 변수 생성*/
	string Name;
	Title T;
	UI InterFace;
	Character Player();
	Shop MyShop;
	
	//테스트용 생성한 몬스터입니다.//
	std::unique_ptr<Monster> goblin = CreateMonster(1);

	/*이름 짓기*/
	T.GameStart();
	cout << "Name : ";
	cin >> Name;
	system("cls");
	Character* player = Character::getInstance(Name);

	/*실제 작동 부분*/
	while (true)
	{
		Character* p = Character::getInstance();
		string UIName = p->getName();
		int UIHP = p->getHealth();
		int UIATK = p->getAttack();

		int ChooseAction = 0;
		InterFace.CheckVal();
		InterFace.SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 7);
		cout << "Action? : ";
		cin >> ChooseAction;

		switch (ChooseAction)
		{
		case 1:
			//전투 예상 로그
			InterFace.AddFullLog("전투 시작!");
			InterFace.AddBattleLog("플레이어가 공격했다!");
			InterFace.AddBattleLog("몬스터가 반격했다!");
			InterFace.AddBattleLog("플레이어가 공격했다!");
			InterFace.AddBattleLog("몬스터가 반격했다!");
			InterFace.AddFullLog("전투 승리!");
			InterFace.AddFullLog("아이템을 획득했다");
			InterFace.AddFullLog("경험치를 획득했다");
			InterFace.AddFullLog("레벨업을 했다");
			InterFace.CheckVal();
			InterFace.SetMonster(goblin.get());;
			InterFace.SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 7);
			cout << "                        ";
			InterFace.PrintStage();
			break;

		case 2: //쇼핑 예상 로그 출력
			InterFace.AddFullLog("쇼핑이다!");
			InterFace.AddFullLog("물건을 샀다!");
			InterFace.AddFullLog("물건을 팔았다!");
			InterFace.CheckVal();
			system("cls");
			MyShop.displayItems(player);

			InterFace.SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 7);
			cout << "                        ";
			break;

		case 3:
			//게임 오버
			system("cls");
			T.GameOver();
			exit(0);

		default:
			cin.clear();
			cin.ignore();
			system("cls");
		}

	}

	return 0;
}

