#include <iostream>
#include <BattleSystem.h>


#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;



//�Լ� ���� ���� ����� �� ����

Character* BattleSystem::CreateRandomEnemy()            
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int r = rand() % 3;

	switch (r)
	{
	case 0: return new //ToDo:���� �߰� �ʿ�
	case 1: return new //ToDo:���� �߰� �ʿ�
	case 2: return new //ToDo:���� �߰� �ʿ�
	default: return new //ToDo:���� �߰� �ʿ�
	}

}

void BattleSystem::StartBattle(Player* Player)
{
	Character* enemy = CreateRandomEnemy();  //ToDo:���� ���� Ŭ���������� ���� �ʿ�

	cout << "\n Battle Start!" << Player->GetName() << "vs" << enemy->GetName() << endl;  // ToDo:���� ���� �޽��� ��� �÷��̾�, ���ʹ� �̸��� �����޾ƾ���.
	
	while (Player->GetHp() > 0 && enemy->GetHp() > 0)
	{
		enemy->takeDamage(Player->GetAttack());    //ToDo:�÷��̾� Ŭ������ �°� ���� �ʿ�

		cout << Player->GetName() << " attacks " << enemy->GetHp() << " Hp left." << endl;
		if (enemy->GetHp() <= 0)
		{
			cout << enemy->GetName() << " is defeated!" << endl;
			if (!enemy->IsAlive()) break;
			Player->takeDamage(enemy->GetAttack());
			cout << enemy->GetName() << " attacks " << Player->GetName() << " for " << enemy->GetAttack() << " damage " << endl;
			this_thread::sleep_for(chrono::milliseconds(500)); // 0.5�� ���

		}
		else (Player)
	}

	if (Player->IsAlive())
	{
		cout << "\nVictory!" << endl;
		GrantVictoryRewards(Player);
	}

}

void BattleSystem::GrantVictoryRewards(Player* Player)
{
	const int expReward = 50;
	int goldReward = 10 + (rand() % 10);
	cout << "Reward :" << expReward << ". Gold " << goldReward << endl;
	Player->addExp(expReward);
	Player->addGold(goldReward);
}










int main()
{

}