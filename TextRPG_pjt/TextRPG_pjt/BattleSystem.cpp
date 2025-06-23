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
	case 2: return new Monster("Golem", 30, 10); // ���� �̸�, ü��, ���ݷ� ����
    }

}


void BattleSystem::StartBattle(Character* player)
{
	Monster* monster = CreateRandomEnemy();   // ���� ���� ����


	cout << "\n Battle Start!" << player->getName() << "vs" << monster->GetName() << endl;  // ���� ���� �޽��� ���

	while (player->getHealth() > 0 && monster->GetHealth() > 0) // �÷��̾�� ���Ͱ� ��� ����ִ� ���� ���� ����
    {
		monster->TakeDamage(player->getAttack());     // �÷��̾ ���͸� ����
		cout << player->getName() << " attacks " << monster->GetHealth() << " HP left.\n" << endl; // �÷��̾��� ���� �� ������ ���� ü���� ���
		this_thread::sleep_for(chrono::milliseconds(500));     //0.5�� ���
        if (monster->GetHealth() <= 0) break;

		player->takeDamage(monster->GetAttack()); // �÷��̾ ������ ������ ����
		cout << monster->GetName() << " attacks!" << player->getName() << " HP left: " << player->getHealth() << endl; // ������ ���� �� �÷��̾��� ���� ü���� ���
		this_thread::sleep_for(chrono::milliseconds(500)); //0.5�� ���

		if (player->getHealth() <= 0) break; // �÷��̾ �׾����� Ȯ��


    }
	bool playerWon = player->getHealth() > 0 && monster->GetHealth() <= 0; // �÷��̾ �¸��ߴ��� Ȯ��

	cout << "\n=====================\n"; // ���� ��� ���
    if (playerWon)
    {
        cout << player->getName() << " wins the battle!" << endl;
		Title::getInstance()->Victory();      // �¸� ȭ�� ���
        GrantVictoryRewards(player);
    }
    else
    {
        cout << player->getName() << " has been defeated by " << monster->GetName() << "!" << endl;
		Title::getInstance()->GameOver(); //�й� ȭ�� ���
    }
	delete monster; 

}

Item* CreateRandomItemDrop()
{
	int r = rand() % 100;
    
    if (r < 30) return new HealthPotion(); // 30% Ȯ���� HealthPotion ���
    else if (r < 70) return new AttackBoost(); // 40% Ȯ���� AttackBoost ���
    else return nullptr; //30% Ȯ���� ������ ��� ����
    
		
}

void BattleSystem::GrantVictoryRewards(Character* player) // �÷��̾�� ���� ����
{
	const int expReward = 50; // ���� ����ġ ����
	int goldReward = 10 + (rand() % 10); // 10���� 20 ������ ���� ��� ����
    cout << "Reward :" << expReward << "EXP," << ". Gold\n " << goldReward << endl;
	player->addExp(expReward); // �÷��̾�� ����ġ �߰�
	player->addGold(goldReward); // �÷��̾�� ��� �߰�

    Item* drop = CreateRandomItemDrop();// ������ ��� ����
 
        if (drop)
        {
            player->addItem(drop); // �÷��̾�� ������ �߰�
            cout << "You found a " << drop->getName() << "!\n" << endl; // ������ ��� �޽��� ���
        }
        else
        {
            cout << "No item dropped.\n" << endl; // ������ ��� ���� �޽��� ���
        }

}

