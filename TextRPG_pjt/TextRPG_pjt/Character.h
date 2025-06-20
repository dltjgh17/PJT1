#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Item; //���� ���Ǵ� Character.cpp���� ��

class Character
{
private:
	Character(const string& name);
	static Character* instance;
	string name; //ĳ���� �̸�
	int level; //ĳ���� ����
	int health; //ĳ���� ���� ü��
	int maxHealth; //ĳ���� �ִ� ü��
	int attack; //ĳ���� ���ݷ�
	int experience; //���� ����ġ
	int gold; //���� ���
	vector<Item*> inventory; //������ �κ��丮

public:
	static Character* getInstance(const string& name = "");
	void displayStatus();
	void levelUp(); //������ �Լ�
	void addItem(Item* item); //������ ȹ�� �Լ�
	void useItem(int index); //������ ��� �Լ�
	void addExp(int amount); //����ġ ȹ�� �Լ�
	void addGold(int amount); //��� ȹ�� �Լ�
	void heal(int amount); //ü�� ȸ�� �Լ�
	void takeDamage(int amount); //ü�� ���� �Լ�
	bool isDead(); //ĳ���� ��� ���� üũ �Լ�


	//getter�Լ���
	//����Ͻ� cpp���� Character* p(����� �̸�) = Character::getInstance(); �Ͻð�
	//int HP = p->getHealth(); �̷������� ȭ��ǥ ������ ����ϼż� �� �������ø� �˴ϴ�
	string getName() const { return name; } //ĳ���� �̸� ��ȯ
	int getLevel() const { return level; } //���� ��ȯ
	int getHealth() const { return health; } //���� ü�� ��ȯ
	int getMaxHealth() const { return maxHealth; } //�ִ� ü�� ��ȯ
	int getAttack() const { return attack; } //ĳ���� ���ݷ� ��ȯ
	int getExp() const { return experience; } //���� ����ġ ��ȯ
	int getGold() const { return gold; } //���� ��� ��ȯ
};