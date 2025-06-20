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
	Title* T= Title::getInstance();
	UI* InterFace = UI::getInstance();
	Character Player();
	Shop MyShop;
	
	//테스트용 생성한 몬스터, 아이템입니다.//
	std::unique_ptr<Monster> goblin = CreateMonster(1);
	Item* Healposition1 = nullptr;
	Item* Healposition2 = nullptr;
	Item* Healposition3 = nullptr;
	Item* Healposition4 = nullptr;

	/*이름 짓기*/
	T->GameStart();
	cout << "Name : ";
	while (true)
	{
		cin >> Name;

		if (Name.length() < 5)
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			system("cls");
			T->GameStart();
			cout << " less 3 word in english" << endl;
			cout << "Name : ";
		}

	}
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

		system("cls");
		InterFace->CheckVal();

		InterFace->SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 7);
		cout << "Action? : ";

		cin >> ChooseAction;

		switch (ChooseAction)
		{
		case 1:
			//로그 테스트
			player->addExp(1); //  레벨업
			player->addItem(Healposition1); // 아이템 획득
			player->removeItem(0); // 아이템 삭제
			player->addItem(Healposition2); // 아이템 획득
			player->useItem(0); // 아이템 사용
			player->heal(10); //체력 회복
			player->addExp(10); // 경험치 획득
			player->addGold(10); // 골드 획득
			player->addItem(Healposition3); // 아이템 획득
			player->addItem(Healposition4); // 아이템 획득

			system("cls");
			InterFace->CheckVal();
			InterFace->SetMonster(goblin.get());;
			InterFace->SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 7);
			cout << "                        ";
			InterFace->Stage();
			break;

		case 2: //쇼핑 예상 로그 출력
			system("cls");
			InterFace->CheckVal();
			MyShop.displayItems(player);
			system("cls");
			InterFace->CheckVal();
			InterFace->SetCursorPosition(UI_XY::POS_ACTION_X, UI_XY::POS_ACTION_Y + 7);
			cout << "                        ";
			break;

		case 3:
			//게임 오버
			system("cls");
			T->GameOver();
			player->destroyInstance();
			InterFace->~UI();
			T->~Title();
			exit(0);

		default:
			cin.clear();
			cin.ignore();
			system("cls");
			InterFace->CheckVal();
		}

	}

	player->destroyInstance();
	InterFace->~UI();
	T->~Title();
	
	return 0;
}

