//MonsterData.h

#ifndef MonsterData_h
#define MonsterData_h

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
//생성 후 Monster의 SetHealth 함수를 실행하여, 플레이어 레벨에 따라 적용해주세요.
std::unique_ptr<Monster> CreateMonster(int monsterId);

Monster* CreathMonsterP(int monsterId);

#endif // !MonsterData_h
