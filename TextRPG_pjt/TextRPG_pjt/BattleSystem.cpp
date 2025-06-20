#include "BattleSystem.h"
#include "Character.h"
<<<<<<< HEAD


#include <iostream>
=======
#include "MonsterData.h"
#include "Monster.h"

>>>>>>> 57e491f46ad5467c820e2fd0eba0210f317522fa
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;




Monster* BattleSystem::CreateRandomEnemy()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = rand() % 4;

    switch (r)
    {
    case 0: return new Monster("Slime", 20, 5);
	case 1: return new Monster("Goblin", 15, 7);
	case 2: return new Monster("Golem", 30, 10);
	case 3: return new Monster("Dragon", 45, 15);
    }

}

<<<<<<< HEAD
void BattleSystem::StartBattle(Character* Player)
=======
void BattleSystem::StartBattle(Character* player)
>>>>>>> 57e491f46ad5467c820e2fd0eba0210f317522fa
{
    Monster* monster = CreateRandomEnemy();  //ToDo:

<<<<<<< HEAD
    cout << "\n Battle Start!" << Player->getName() << "vs" << enemy->GetName() << endl;  // ToDo:

    while (Player->getHp() > 0 && enemy->getHp() > 0)
=======
    cout << "\n Battle Start!" << player->getName() << "vs" << monster->GetName() << endl;  // ToDo:

    while (player->getHealth() > 0 && monster->GetHealth() > 0)
>>>>>>> 57e491f46ad5467c820e2fd0eba0210f317522fa
    {
        monster->TakeDamage(player->getAttack());    //ToDo:

        cout << player->getName() << " attacks " << monster->GetHealth() << " HP left.\n" << endl;

        if (monster->GetHealth() <= 0)
        {
            cout << monster->GetName() << " is defeated!" << endl;
  
            this_thread::sleep_for(chrono::milliseconds(500)); // 0.5ÃÊ µô·¹ÀÌ
            break;

        }
        player->takeDamage(monster->GetAttack());
        cout << monster->GetName() << " attacks " << player->getName() << " has " << monster->GetAttack() << " HP left. \n " << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // 0.5ÃÊ µô·¹ÀÌ
   
    }

    if (player->getHealth() > 0) 
    {
        cout << "\nVictory!\n" << endl;
        GrantVictoryRewards(player);
    }
    else
    {
        cout << "\n You were defeated!\n" << endl;
    }

    delete monster;
}

void BattleSystem::GrantVictoryRewards(Character* player)
{
    const int expReward = 50;
    int goldReward = 10 + (rand() % 10);
    cout << "Reward :" << expReward << "EXP," << ". Gold\n " << goldReward << endl;
    player->addExp(expReward);
    player->addGold(goldReward);
}










int main()
{

}