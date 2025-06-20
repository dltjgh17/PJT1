#include <iostream>
#include <BattleSystem.h>


#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;



//함수 명은 추후 변경될 수 있음

Character* BattleSystem::CreateRandomEnemy()            
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int r = rand() % 3;

	switch (r)
	{
	case 0: return new //ToDo:몬스터 추가 필요
	case 1: return new //ToDo:몬스터 추가 필요
	case 2: return new //ToDo:몬스터 추가 필요
	default: return new //ToDo:몬스터 추가 필요
	}

}

void BattleSystem::StartBattle(Player* Player)
{
	Character* enemy = CreateRandomEnemy();  //ToDo:추후 몬스터 클래스명으로 변경 필요

	cout << "\n Battle Start!" << Player->GetName() << "vs" << enemy->GetName() << endl;  // ToDo:전투 시작 메시지 출력 플레이어, 에너미 이름을 참조받아야함.
	
	while (Player->GetHp() > 0 && enemy->GetHp() > 0)
	{
		enemy->takeDamage(Player->GetAttack());    //ToDo:플레이어 클래스에 맞게 수정 필요

		cout << Player->GetName() << " attacks " << enemy->GetHp() << " Hp left." << endl;
		if (enemy->GetHp() <= 0)
		{
			cout << enemy->GetName() << " is defeated!" << endl;
			if (!enemy->IsAlive()) break;
			Player->takeDamage(enemy->GetAttack());
			cout << enemy->GetName() << " attacks " << Player->GetName() << " for " << enemy->GetAttack() << " damage " << endl;
			this_thread::sleep_for(chrono::milliseconds(500)); // 0.5초 대기

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