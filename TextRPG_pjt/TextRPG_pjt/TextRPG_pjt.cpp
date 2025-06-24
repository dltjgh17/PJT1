// TextRPG_pjt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "UI.h"
//#include "Monster.h"
//#include "MonsterData.h"
#include "Title.h"
#include "Shop.h"
#include "BattleSystem.h"

int main()
{
	/*인스턴스 및 필요 변수 생성*/
	string Name;
	Title* MainTitle= Title::getInstance();
	UI* InterFace = UI::getInstance();
	Character Player();
	Shop MyShop;
	BattleSystem MyBattle;

	//테스트용 생성한 몬스터, 아이템입니다.//
	//unique_ptr<Monster> goblin = CreateMonster(1);
	//InterFace->SetMonster(goblin.get());;
	
	/*캐릭터 이름 짓기*/
	Character* player = Character::getInstance(MainTitle->GameStart());

	/*실제 작동 부분*/
	while (true)
	{
		const vector<Item*>& Itemlsit = player->getInventory();
		int Choice = -1;

		//플레이어 체력 0인지 체크
		int PH = player->getHealth();
		if (0>=PH)
		{
			MainTitle->GameOver();
			goto END;
		}

		int ChooseAction = 0;
		InterFace->CheckVal();
		cin >> ChooseAction;
		UI * ui = UI::getInstance();
		// 케이스 테스트 중 //
		switch (ChooseAction)
		{
		case 1:
			//로그 테스트
			/*UI*/
			
			ui->AddFullLog("[전투 : " + std::to_string(InterFace->StageCount +1) + "]");
			system("cls");
			InterFace->Stage(); // 스테이트 올라가는 거 표시
			InterFace->DeletePastBattleLog(); //이전 전투 기록 삭제
			MyBattle.StartBattle(player);

			//player->addGold(100); // 골드 획득 (정상작동)
			//player->takeDamage(10); // 체력 감소 (정상작동)
			//player->heal(5); //체력 회복 (정상작동)

			//goblin->TakeDamage(10); // 체력 감소 (정상작동) 죽고 나서 삭제는 아직 X
			//player->addExp(10); // 경험치 획득 (정상작동)
			//player->levelUp(); //  레벨업 (정상 작동)

			cin.clear();
			cin.ignore();
			system("Pause");
			ui->AddFullLog("---------------------------------------");
			break;

		case 2: //상점
			ui->AddFullLog("[상점]");
			MyShop.displayItems(player);
			
			cin.clear();
			cin.ignore();
			ui->AddFullLog("---------------------------------------");
			break;

		case 3:
			ui->AddFullLog("[인벤토리]");
			// 아이템 사용
				cout << "Choose item : ";
				cin >> Choice;
				--Choice;
				if (Choice >= 0 && Choice < Itemlsit.size())
				{
					ui->AddFullLog("아이템 사용");
					player->useItem(Choice+1); // 아이템 사용 
				}
				else
				{
					cout << "wrong!!" << endl;
					Sleep(50);
				}
				break;
				ui->AddFullLog("---------------------------------------");
		case 4:
			//게임 오버
			MainTitle->GameOver();
			goto END;

		case 5:
			//게임 최종 승리
			MainTitle->EndVictory();
			goto END;

		default:
			cin.clear();
			cin.ignore();
		}
	}

END:
	player->destroyInstance();

	return 0;
}

