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

unique_ptr<Monster> BattleSystem::CreateBossMonster(int playerLevel)  // ���� ���� ���� �Լ�
{
	Character* player = Character::getInstance("YourName"); // �÷��̾� �̸� ���� (���÷� "YourName" ���)

    static const vector<MonsterStats> bossTemplates =   // ���� ���� ���ø� ����
    {
        {"�巡��", 50, 10},
        {"���� �ε�", 50, 10},
        {"���̼�Ʈ ��", 50, 10}
    };

	int bossIndex = rand() % bossTemplates.size(); // �������� ���� ���� �ε��� ����
	const MonsterStats& selectedBoss = bossTemplates[bossIndex]; // ���õ� ���� ���� ���� ��������


    unique_ptr<Monster> boss = make_unique<Monster>(selectedBoss.name, selectedBoss.health, selectedBoss.attack); // ���� ���� ����

    // �÷��̾� ������ ���� ���� ������ ü�°� ���ݷ� ����
    float  randomPerHp = static_cast<float>(rand() % 51 + 100) / 100.0f;  // 1.00 ~ 1.50 ���� ���
    float  randomPerAtk = static_cast<float>(rand() % 51 + 100) / 100.0f;


	boss->SetHealth(playerLevel, randomPerHp, randomPerAtk); // ���� ������ ü�� ���� (�÷��̾� ������ ���� ����)


	return boss; // ������ ���� ���͸� ��ȯ
}


void BattleSystem::StartBattle(Character* player)
{
    int level = player->getLevel();
    unique_ptr<Monster> monster;

	bool isBossBattle = false; // ���� ��Ʋ ���� �ʱ�ȭ
    if (level >= 10) // �÷��̾� ������ 10 �̻��̸� ���� ��Ʋ�� ����
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

        cout << "\n==========�Ϲ� ����=========\n";
		cout << player->getName() << " VS " << monster->GetName() << endl; // �÷��̾�� ���� �̸� ���
    }


	cout << "\n=========���� ����!=========\n"  << endl;  // ���� ���� �޽��� ���
	while (player->getHealth() > 0 && monster->GetHealth() > 0) // �÷��̾�� ���Ͱ� ��� ����ִ� ���� ���� ����
    {
		monster->TakeDamage(player->getAttack());     // �÷��̾ ���͸� ����
        if (isBossBattle) // ���� ��Ʋ�� ���
        {
            cout << player->getName() << " �� ����!\n" << monster->GetName() << " ���� ü�� : " << monster->GetHealth() << endl; // �÷��̾��� ���� �� ������ ���� ü���� ���
            this_thread::sleep_for(chrono::seconds(2)); //2�� ���
            if (monster->GetHealth() <= 0) break;
        }
        else // �Ϲ� ���� ��Ʋ�� ���
        {
			cout << player->getName() << " �� ����!\n" << monster->GetName() << " ���� ü�� : " << monster->GetHealth() << endl; // �÷��̾��� ���� �� ������ ���� ü���� ���
            this_thread::sleep_for(chrono::seconds(2));    //2�� ���
            if (monster->GetHealth() <= 0) break;
        }


		player->takeDamage(monster->GetAttack()); // �÷��̾ ������ ������ ����
        if (isBossBattle) // ���� ��Ʋ�� ���
        {
			cout << monster->GetName() << " �� ����!\n" << player->getName() << " ���� ü�� : " << player->getHealth() << endl; // ������ ���� �� �÷��̾��� ���� ü���� ���
            this_thread::sleep_for(chrono::seconds(2)); //2�� ���
            if (player->getHealth() <= 0) break; // �÷��̾ �׾����� Ȯ��
        }
        else
        {
        cout << monster->GetName() << " �� ����!\n" << player->getName() << " ���� ü�� : " << player->getHealth() << endl; // ������ ���� �� �÷��̾��� ���� ü���� ���
		this_thread::sleep_for(chrono::seconds(2)); //2�� ���
		if (player->getHealth() <= 0) break; // �÷��̾ �׾����� Ȯ��
        }



    }
	bool playerWon = player->getHealth() > 0 && monster->GetHealth() <= 0; // �÷��̾ �¸��ߴ��� Ȯ��

	cout << "\n----------------------------\n\n"; // ���� ��� ���
    if (playerWon) // 6.24 ���� ���� ��Ʋ �¸� ���� ������ ���,
    {
        if (isBossBattle) // ���� ��Ʋ���� �¸��� ���
        {
            cout << "=========���ϵ帳�ϴ�! ����";
            cout << monster->GetName() << "�� óġ�ϼ̽��ϴ�!=========\n" << endl;
			Title::getInstance()->EndVictory(); // ���� ��Ʋ �¸� ȭ�� ���

			cout << "=========�����մϴ�! ���� ������ ���̽��ϴ�!=========" << endl;
            for (int i = 5; i > 0; --i)
            {
                cout << "\r" << "=========������ " << i << "�� �� ����˴ϴ�...========= " << flush;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << "\n";			exit(0); // ���� ����
        }
        
        cout << "\n=========���� �¸�!=========\n" << endl;
        this_thread::sleep_for(chrono::seconds(2)); //2�� ���
        Title::getInstance()->Victory();      // �¸� ȭ�� ���
        GrantVictoryRewards(player);
        
    }
    else
    {
        cout << "=========" << player->getName() << " �� " << monster->GetName() << "���� �й��߽��ϴ�!=========" << endl;
        this_thread::sleep_for(chrono::seconds(2)); //2�� ���
		Title::getInstance()->GameOver(); //�й� ȭ�� ���
    }

}

Item* CreateRandomItemDrop()
{
	int r = rand() % 100;
    
    if (r < 40) return new HealthPotion(); // 40% Ȯ���� ü�� ���� ���
    else if (r < 80) return new AttackBoost(); // 40% Ȯ���� ���ݷ� ���� ������ ���
    else return nullptr; // 20% Ȯ���� ������ ��� ����
    	
}

void BattleSystem::GrantVictoryRewards(Character* player) // �÷��̾�� ���� ����
{
	const int expReward = 50; // ���� ����ġ ����
	int goldReward = 10 + (rand() % 10); // 10���� 20 ������ ���� ��� ����
    cout << "���� : " << expReward << "����ġ , " << "��� " << goldReward << endl;
	player->addExp(expReward); // �÷��̾�� ����ġ �߰�
	player->addGold(goldReward); // �÷��̾�� ��� �߰�

    Item* drop = CreateRandomItemDrop();// ������ ��� ����
 
        if (drop)
        {
            player->addItem(drop); // �÷��̾�� ������ �߰�
            cout << drop->getName() << "�� ã�ҽ��ϴ�!\n" << endl; // ������ ��� �޽��� ���
        }
        else
        {
            cout << "�������� ������� �ʾҽ��ϴ�.\n" << endl; // ������ ��� ���� �޽��� ���
        }

}

