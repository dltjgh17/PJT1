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

using namespace std;




Monster* BattleSystem::CreateRandomEnemy()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = rand() % 3;

    switch (r)
    {
    case 0: return new Monster("Slime", 20, 5);
	case 1: return new Monster("Goblin", 15, 7);
	case 2: return new Monster("Golem", 30, 10); // 몬스터 이름, 체력, 공격력 설정
    }

}


void BattleSystem::StartBattle(Character* player)
{
	Monster* monster = CreateRandomEnemy();   // 랜덤 몬스터 생성


	cout << "\n Battle Start!" << player->getName() << "vs" << monster->GetName() << endl;  // 전투 시작 메시지 출력

	while (player->getHealth() > 0 && monster->GetHealth() > 0) // 플레이어와 몬스터가 모두 살아있는 동안 전투 진행
    {
		monster->TakeDamage(player->getAttack());     // 플레이어가 몬스터를 공격
		cout << player->getName() << " attacks " << monster->GetHealth() << " HP left.\n" << endl; // 플레이어의 공격 후 몬스터의 남은 체력을 출력
		this_thread::sleep_for(chrono::milliseconds(500));     //0.5초 대기
        if (monster->GetHealth() <= 0) break;

		player->takeDamage(monster->GetAttack()); // 플레이어가 몬스터의 공격을 받음
		cout << monster->GetName() << " attacks!" << player->getName() << " HP left: " << player->getHealth() << endl; // 몬스터의 공격 후 플레이어의 남은 체력을 출력
		this_thread::sleep_for(chrono::milliseconds(500)); //0.5초 대기

		if (player->getHealth() <= 0) break; // 플레이어가 죽었는지 확인


    }
	bool playerWon = player->getHealth() > 0 && monster->GetHealth() <= 0; // 플레이어가 승리했는지 확인

	cout << "\n=====================\n"; // 전투 결과 출력
    if (playerWon)
    {
        cout << player->getName() << " wins the battle!" << endl;
		Title::getInstance()->Victory();      // 승리 화면 출력
        GrantVictoryRewards(player);
    }
    else
    {
        cout << player->getName() << " has been defeated by " << monster->GetName() << "!" << endl;
		Title::getInstance()->GameOver(); //패배 화면 출력
    }
	delete monster; 

}

Item* CreateRandomItemDrop()
{
	int r = rand() % 100;
    
    if (r < 30) return new HealthPotion(); // 30% 확률로 HealthPotion 드랍
    else if (r < 70) return new AttackBoost(); // 40% 확률로 AttackBoost 드랍
    else return nullptr; //30% 확률로 아이템 드랍 없음
    
		
}

void BattleSystem::GrantVictoryRewards(Character* player) // 플레이어에게 보상 지급
{
	const int expReward = 50; // 고정 경험치 보상
	int goldReward = 10 + (rand() % 10); // 10에서 20 사이의 랜덤 골드 보상
    cout << "Reward :" << expReward << "EXP," << ". Gold\n " << goldReward << endl;
	player->addExp(expReward); // 플레이어에게 경험치 추가
	player->addGold(goldReward); // 플레이어에게 골드 추가

    Item* drop = CreateRandomItemDrop();// 아이템 드랍 생성
 
        if (drop)
        {
            player->addItem(drop); // 플레이어에게 아이템 추가
            cout << "You found a " << drop->getName() << "!\n" << endl; // 아이템 드랍 메시지 출력
        }
        else
        {
            cout << "No item dropped.\n" << endl; // 아이템 드랍 없음 메시지 출력
        }

}

