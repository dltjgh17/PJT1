#pragma once


class Player;
class Character;

class BattleSystem {
public:
    static void StartBattle(Player* Player);

private:
    static Character* CreateRandomEnemy();
    static void GrantVictoryRewards(Player* Player);

};
