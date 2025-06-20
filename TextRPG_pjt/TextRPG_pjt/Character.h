#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Item; //실제 정의는 Character.cpp에서 함

class Character
{
private:
	Character(const string& name);
	static Character* instance;
	string name; //캐릭터 이름
	int level; //캐릭터 레벨
	int health; //캐릭터 현재 체력
	int maxHealth; //캐릭터 최대 체력
	int attack; //캐릭터 공격력
	int experience; //현재 경험치
	int gold; //소지 골드
	vector<Item*> inventory; //아이템 인벤토리

public:
	static Character* getInstance(const string& name = "");
	void displayStatus();
	void levelUp(); //레벨업 함수
	void addItem(Item* item); //아이템 획득 함수
	void useItem(int index); //아이템 사용 함수
	void addExp(int amount); //경험치 획득 함수
	void addGold(int amount); //골드 획득 함수
	void heal(int amount); //체력 회복 함수
	void takeDamage(int amount); //체력 감소 함수
	bool isDead(); //캐릭터 사망 여부 체크 함수


	//getter함수들
	//사용하실 cpp에서 Character* p(사용할 이름) = Character::getInstance(); 하시고
	//int HP = p->getHealth(); 이런식으로 화살표 연산자 사용하셔서 값 가져오시면 됩니다
	string getName() const { return name; } //캐릭터 이름 반환
	int getLevel() const { return level; } //레벨 반환
	int getHealth() const { return health; } //현재 체력 반환
	int getMaxHealth() const { return maxHealth; } //최대 체력 반환
	int getAttack() const { return attack; } //캐릭터 공격력 반환
	int getExp() const { return experience; } //현재 경험치 반환
	int getGold() const { return gold; } //소지 골드 반환
};