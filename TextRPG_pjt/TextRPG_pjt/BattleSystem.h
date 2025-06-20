#pragma once


class Character;
class Monster;

class BattleSystem {
public:
    static void StartBattle(Character* player);
    static Monster* CreateRandomEnemy();
    static void GrantVictoryRewards(Character* player);

};
