#pragma once



//함수명은 추후 변경될 수 있음


class Player;
class Character;

class BattleSystem {
public:
	static void StartBattle(Player* Player);

private:
	static Character* CreateRandomEnemy();
	static void GrantVictoryRewards(Player* Player);

};


