// TextRPG_pjt.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include "UI.h"
#include "Title.h"
#include "Shop.h"
#include "BattleSystem.h"
#include <iostream>
#include <limits>

int main()
{
	/*인스턴스 및 필요 변수 생성*/
	Title* MainTitle= Title::getInstance(); // 화면 타이틀 및 승리, 게임 오버 표시
	UI* InterFace = UI::getInstance(); // 인 게임 화면 및 UI 표시
	Shop MyShop; // 상점 시스템
	BattleSystem MyBattle; // 배틀 시스템
	string Name; // 플레이엄 이름을 받아올 변수
	
	/*캐릭터 생성, 이름 짓기, 초기 화면*/
	Character* player = Character::getInstance(MainTitle->GameStart());
    
	/*인 게임 루프 */
	while (true)
	{

		const vector<Item*>& Itemlsit = player->getInventory();
		InterFace->CheckVal();

		int Choice = -1;

		/*플레이어 행동 처리*/
		switch (InterFace->GetChooseAction())
		{
		case 1: //전투
			system("cls");
			InterFace->AddFullLog("[전투 : " + std::to_string(InterFace->GetStageCount() + 1) + "]-----------------------------");
			InterFace->Stage(); // 스테이트 올라가는 거 표시 for UI 업데이트
			InterFace->DeletePastBattleLog(); //이전 전투 기록 삭제 for UI업데이트
			MyBattle.StartBattle(player); // 배틀 시스템(=전투로) 진입
			InterFace->AddFullLog("                                       ");
			system("Pause");
			break;

		case 2: //상점
			InterFace->AddFullLog("[상점]---------------------------------");
			MyShop.displayItems(player);
			InterFace->AddFullLog("                                       ");
			break;

		case 3:
			InterFace->AddFullLog("[인벤토리]-----------------------------");
			// 아이템 사용
				cout << "Choose item : ";
				cin >> Choice;
				--Choice;
				if (Choice >= 0 && Choice < Itemlsit.size())
				{
					player->useItem(Choice+1); // 아이템 사용 
				}
				else
				{
				}
				break;
				InterFace->AddFullLog("                                       ");
		case 4:
			//게임 종료
			MainTitle->GameEnd();
			goto END;

		default:
			break;
		}
	}

END: //게임 종료시 메모리 해제
	player->destroyInstance();
	return 0;
}

