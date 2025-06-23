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

using namespace std;
using std::unique_ptr;




unique_ptr<Monster> BattleSystem::CreateRandomEnemy() 
{
	static bool seeded = false; // ���� �õ� �ʱ�ȭ ���θ� Ȯ���ϴ� ����
	if (!seeded) // �õ尡 �ʱ�ȭ���� �ʾҴٸ�
    {
		srand(static_cast<unsigned int> (time(nullptr))); // ���� �õ� �ʱ�ȭ
		seeded = true; // �õ尡 �ʱ�ȭ�Ǿ����� ǥ��
    }
	int r = rand() % 4;  // 0���� 3������ ���� ���� ���� (���� ���� ����)

	return CreateMonster(r);  // ���� ���� �Լ� ȣ��

}

unique_ptr<Monster> BattleSystem::CreateBossMonster(int playerLevel)
{
    unique_ptr<Monster> boss = make_unique<Monster>("Dragon", 50, 15); // Todo: ���� ���� ���� ���� �߰�

	int randomPerHp = rand() % 2 + 2; 
	int randomPerAtk = rand() % 2 + 2; 
    boss->SetHealth(playerLevel, randomPerHp, randomPerAtk);

	return boss; // ������ ���� ���͸� ��ȯ
}


void BattleSystem::StartBattle(Character* player)
{
    unique_ptr<Monster> monster;

	bool isBossBattle = false; // ���� ��Ʋ ���� �ʱ�ȭ
    if (player->getLevel() >= 10) // �÷��̾� ������ 10 �̻��̸� ���� ��Ʋ�� ����
    {
        monster = CreateBossMonster(player->getLevel()); // ���� ���� ����
        isBossBattle = true; // ���� ��Ʋ�� ����

        cout << "\n=========���� ��Ʋ=========\n"; // ���� ��Ʋ ���� �޽��� ���
        cout << player->getName() << " VS " << monster->GetName() << endl; // �÷��̾�� ���� �̸� ���
    }
    else
    {
		monster = CreateRandomEnemy(); // �Ϲ� ���� ����
		monster->SetHealth(player->getLevel()); // ������ ü���� �÷��̾� ������ �°� ����

        cout << "\n=========�Ϲ� ����=========\n";
		cout << player->getName() << " VS " << monster->GetName() << endl; // �÷��̾�� ���� �̸� ���
    }


	cout << "\n Battle Start! \n" << player->getName() << "\nvs\n" << monster->GetName() << endl;  // ���� ���� �޽��� ���
	while (player->getHealth() > 0 && monster->GetHealth() > 0) // �÷��̾�� ���Ͱ� ��� ����ִ� ���� ���� ����
    {
		monster->TakeDamage(player->getAttack());     // �÷��̾ ���͸� ����
        if (isBossBattle) // ���� ��Ʋ�� ���
        {
            cout << player->getName() << " attacks " << monster->GetName() << " HP left: " << monster->GetHealth() << endl; // �÷��̾��� ���� �� ������ ���� ü���� ���
        }
        else // �Ϲ� ���� ��Ʋ�� ���
        {
			cout << player->getName() << " attacks " << monster->GetHealth() << " HP left.\n" << endl; // �÷��̾��� ���� �� ������ ���� ü���� ���
            this_thread::sleep_for(chrono::seconds(3));    //3�� ���
            if (monster->GetHealth() <= 0) break;
        }


		player->takeDamage(monster->GetAttack()); // �÷��̾ ������ ������ ����
        if (isBossBattle) // ���� ��Ʋ�� ���
        {
			cout << monster->GetName() << " attacks " << player->getName() << " HP left: " << player->getHealth() << endl; // ������ ���� �� �÷��̾��� ���� ü���� ���
        }
        else
        {
        cout << monster->GetName() << " attacks!" << player->getName() << " HP left: " << player->getHealth() << endl; // ������ ���� �� �÷��̾��� ���� ü���� ���
		this_thread::sleep_for(chrono::seconds(3)); //3�� ���
		if (player->getHealth() <= 0) break; // �÷��̾ �׾����� Ȯ��
        }



    }
	bool playerWon = player->getHealth() > 0 && monster->GetHealth() <= 0; // �÷��̾ �¸��ߴ��� Ȯ��

	cout << "\n=====================\n"; // ���� ��� ���
    if (playerWon) // 6.24 ���� ���� ��Ʋ �¸� ���� ������ ���,
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

}

Item* CreateRandomItemDrop()
{
	int r = rand() % 100;
    
    if (r < 30) return new HealthPotion(); // 50% Ȯ���� HealthPotion ���
    else if (r < 10) return new AttackBoost(); // 10% Ȯ���� AttackBoost ��� 
    else return nullptr; // ������ ��� ����
    
		
}

void BattleSystem::GrantVictoryRewards(Character* player) // �÷��̾�� ���� ����
{
	const int expReward = 50; // ���� ����ġ ����
	int goldReward = 10 + (rand() % 10); // 10���� 20 ������ ���� ��� ����
    cout << "Reward :" << expReward << "EXP , " << "Gold " << goldReward << endl;
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

