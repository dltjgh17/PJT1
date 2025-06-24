//MonsterData.cpp


#include "MonsterData.h"


//몬스터 id를 입력해서 몬스터 객체 생성 ex) std::unique_ptr<Monster> goblin = createMonster(1);
//생성 후 Monster의 SetHealth 함수를 실행하여, 플레이어 레벨에 따라 적용해주세요.
std::unique_ptr<Monster> CreateMonster(int monsterId)
{
	static const std::map<int, MonsterStats> monsterTamplates =
	{
		{0, {"Rat", 16, 4}},
		{1, {"Slime", 20, 5}},
		{2, {"Goblin", 15, 7}},
		{3, {"Golem", 30, 10}},
		{4, {"Dragon", 45, 15}}		//보스몬스터로 활용하면 좋을 것 같습니다.
	};


	auto it = monsterTamplates.find(monsterId);
	if (it != monsterTamplates.end())
	{
		const MonsterStats& stats = it->second;
		return std::make_unique<Monster>(stats.name, stats.health, stats.attack);
	}
	else
	{
		//못찾은 경우 이름만 다른 슬라임을 반환합니다.

		return std::make_unique<Monster>("FakeSlime", 20, 5);
	}
}


Monster* CreathMonsterP(int monsterId)
{
	static const std::map<int, MonsterStats> monsterTamplates =
	{
		{0, {"Rat", 16, 4}},
		{1, {"Slime", 20, 5}},
		{2, {"Goblin", 15, 7}},
		{3, {"Golem", 30, 10}},
		{4, {"Dragon", 45, 15}}		//보스몬스터로 활용하면 좋을 것 같습니다.
	};

	auto it = monsterTamplates.find(monsterId);
	if (it != monsterTamplates.end())
	{
		const MonsterStats& stats = it->second;
		return new Monster(stats.name, stats.health, stats.attack);
	}
	else
	{
		//못찾은 경우 이름만 다른 슬라임을 반환합니다.

		return new Monster("FakeSlime", 20, 5);
	}
}





