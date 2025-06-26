#include "BattleSystem.h"
#include "Character.h"
#include <iostream>
#include "MonsterData.h"
#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Title.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "Movie.h" // 무비 추가

using namespace std;
using std::unique_ptr;



unique_ptr<Monster> BattleSystem::CreateRandomEnemy() 
{
	static bool seeded = false; // 랜덤 시드 초기화 여부를 확인하는 변수
	if (!seeded) // 시드가 초기화되지 않았다면
    {
		srand(static_cast<unsigned int> (time(nullptr))); // 랜덤 시드 초기화
		seeded = true; // 시드가 초기화되었음을 표시
    }
	int r = rand() % 4;  // 0부터 3까지의 랜덤 숫자 생성 (몬스터 종류 선택)

	return CreateMonster(r);  // 몬스터 생성 함수 호출

}

unique_ptr<Monster> BattleSystem::CreateBossMonster(int playerLevel)  // 보스 몬스터 생성 함수
{
	Character* player = Character::getInstance("YourName"); // 플레이어 이름 설정 (예시로 "YourName" 사용)

    static const vector<MonsterStats> bossTemplates =   // 보스 몬스터 템플릿 정의
    {
        {"드래곤", 50, 10},
        {"데몬 로드", 50, 10},
        {"에이션트 골렘", 50, 10}
    };

	int bossIndex = rand() % bossTemplates.size(); // 랜덤으로 보스 몬스터 인덱스 선택
	const MonsterStats& selectedBoss = bossTemplates[bossIndex]; // 선택된 보스 몬스터 정보 가져오기


    unique_ptr<Monster> boss = make_unique<Monster>(selectedBoss.name, selectedBoss.health, selectedBoss.attack); // 보스 몬스터 생성

    // 플레이어 레벨에 따라 보스 몬스터의 체력과 공격력 조정
    float  randomPerHp = static_cast<float>(rand() % 51 + 100) / 100.0f;  // 1.00 ~ 1.50 랜덤 출력
    float  randomPerAtk = static_cast<float>(rand() % 51 + 100) / 100.0f;


	boss->SetHealth(playerLevel, randomPerHp, randomPerAtk); // 보스 몬스터의 체력 설정 (플레이어 레벨에 따라 조정)


	return boss; // 생성된 보스 몬스터를 반환
}


void BattleSystem::StartBattle(Character* player)
{
    int level = player->getLevel();
    unique_ptr<Monster> monster;

	bool isBossBattle = false; // 보스 배틀 여부 초기화
    if (level >= 10) // 플레이어 레벨이 10 이상이면 보스 배틀로 설정
    {
        monster = CreateBossMonster(player->getLevel()); // 보스 몬스터 생성
        isBossBattle = true; // 보스 배틀로 설정

        
        Movie MV;
        MV.MoviePlay();

        cout << "\n=========보스 배틀=========\n"; // 보스 배틀 시작 메시지 출력
        cout << player->getName() << " VS " << monster->GetName() << endl; // 플레이어와 몬스터 이름 출력
    }
    else
    {
		monster = CreateRandomEnemy(); // 일반 몬스터 생성
		monster->SetHealth(player->getLevel()); // 몬스터의 체력을 플레이어 레벨에 맞게 설정

        cout << "\n==========일반 전투=========\n";
		cout << player->getName() << " VS " << monster->GetName() << endl; // 플레이어와 몬스터 이름 출력
    }


	cout << "\n=========전투 시작!=========\n"  << endl;  // 전투 시작 메시지 출력
	while (player->getHealth() > 0 && monster->GetHealth() > 0) // 플레이어와 몬스터가 모두 살아있는 동안 전투 진행
    {
		monster->TakeDamage(player->getAttack());     // 플레이어가 몬스터를 공격
        if (isBossBattle) // 보스 배틀인 경우
        {
            cout << player->getName() << " 의 공격!\n" << monster->GetName() << " 남은 체력 : " << monster->GetHealth() << endl; // 플레이어의 공격 후 몬스터의 남은 체력을 출력
            this_thread::sleep_for(chrono::seconds(2)); //2초 대기
            if (monster->GetHealth() <= 0) break;
        }
        else // 일반 몬스터 배틀인 경우
        {
			cout << player->getName() << " 의 공격!\n" << monster->GetName() << " 남은 체력 : " << monster->GetHealth() << endl; // 플레이어의 공격 후 몬스터의 남은 체력을 출력
            this_thread::sleep_for(chrono::seconds(2));    //2초 대기
            if (monster->GetHealth() <= 0) break;
        }


		player->takeDamage(monster->GetAttack()); // 플레이어가 몬스터의 공격을 받음
        if (isBossBattle) // 보스 배틀인 경우
        {
			cout << monster->GetName() << " 의 공격!\n" << player->getName() << " 남은 체력 : " << player->getHealth() << endl; // 몬스터의 공격 후 플레이어의 남은 체력을 출력
            this_thread::sleep_for(chrono::seconds(2)); //2초 대기
            if (player->getHealth() <= 0) break; // 플레이어가 죽었는지 확인
        }
        else
        {
        cout << monster->GetName() << " 의 공격!\n" << player->getName() << " 남은 체력 : " << player->getHealth() << endl; // 몬스터의 공격 후 플레이어의 남은 체력을 출력
		this_thread::sleep_for(chrono::seconds(2)); //2초 대기
		if (player->getHealth() <= 0) break; // 플레이어가 죽었는지 확인
        }



    }
	bool playerWon = player->getHealth() > 0 && monster->GetHealth() <= 0; // 플레이어가 승리했는지 확인

	cout << "\n----------------------------\n\n"; // 전투 결과 출력
    if (playerWon) // 6.24 보스 몬스터 배틀 승리 조건 별도로 출력,
    {
        if (isBossBattle) // 보스 배틀에서 승리한 경우
        {
            cout << "=========축하드립니다! 보스";
            cout << monster->GetName() << "를 처치하셨습니다!=========\n" << endl;
			Title::getInstance()->EndVictory(); // 보스 배틀 승리 화면 출력

			cout << "=========축하합니다! 게임 엔딩을 보셨습니다!=========" << endl;
            for (int i = 5; i > 0; --i)
            {
                cout << "\r" << "=========게임이 " << i << "초 후 종료됩니다...========= " << flush;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << "\n";			exit(0); // 게임 종료
        }
        
        cout << "\n=========전투 승리!=========\n" << endl;
        this_thread::sleep_for(chrono::seconds(2)); //2초 대기
        Title::getInstance()->Victory();      // 승리 화면 출력
        GrantVictoryRewards(player);
        
    }
    else
    {
        cout << "=========" << player->getName() << " 가 " << monster->GetName() << "에게 패배했습니다!=========" << endl;
        this_thread::sleep_for(chrono::seconds(2)); //2초 대기
		Title::getInstance()->GameOver(); //패배 화면 출력
        for (int i = 5; i > 0; --i)
        {
            cout << "\r" << "=========게임이 " << i << "초 후 종료됩니다...========= " << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "\n";			exit(0); // 게임 종료
    }

}

static Item* CreateRandomItemDrop()
{
	int r = rand() % 100;
    
    if (r < 40) return new HealthPotion(); // 40% 확률로 체력 물약 드랍
    else if (r < 80) return new AttackBoost(); // 40% 확률로 공격력 증가 아이템 드랍
    else return nullptr; // 20% 확률로 아이템 드랍 없음
    	
}

void BattleSystem::GrantVictoryRewards(Character* player) // 플레이어에게 보상 지급
{
	const int expReward = 50; // 고정 경험치 보상
	int goldReward = 10 + (rand() % 10); // 10에서 20 사이의 랜덤 골드 보상
    cout << "보상 : " << expReward << "경험치 , " << "골드 " << goldReward << endl;
	player->addExp(expReward); // 플레이어에게 경험치 추가
	player->addGold(goldReward); // 플레이어에게 골드 추가

    Item* drop = CreateRandomItemDrop();// 아이템 드랍 생성
 
        if (drop)
        {
            player->addItem(drop); // 플레이어에게 아이템 추가
            cout << drop->getName() << "를 찾았습니다!\n" << endl; // 아이템 드랍 메시지 출력
        }
        else
        {
            cout << "아이템이 드랍되지 않았습니다.\n" << endl; // 아이템 드랍 없음 메시지 출력
        }

}

