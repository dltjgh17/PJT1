//MonsterData.h

#ifndef MonsterData_h

#include <string>
#include <map>
#include <memory>
#include "Monster.h"


struct MonsterStats
{
	std::string name;
	int health;
	int attack;
};

//몬스터 id를 입력해서 몬스터 객체 생성 ex) std::unique_ptr<Monster> goblin = createMonster(1);
std::unique_ptr<Monster> CreateMonster(int monsterId)
{
	static const std::map<int, MonsterStats> monsterTamplates =
	{
		{1,{"Slime",50,5}},
		{2,{"Slime",50,5}},
		{3,{"Slime",50,5}}
	};


	auto it = monsterTamplates.find(monsterId);
	if (it != monsterTamplates.end())
	{
		const MonsterStats& stats = it->second;
		return std::make_unique<Monster>(stats.name, stats.health, stats.attack);
	}
	else
	{
		//못찾은 경우?
	}
}



#endif // !MonsterData_h
