#pragma once
#include <memory>

using std::unique_ptr;

class Character;
class Monster;

class BattleSystem {
public:
    static void StartBattle(Character* player);
    static unique_ptr<Monster> CreateRandomEnemy();
    static void GrantVictoryRewards(Character* player);

};
