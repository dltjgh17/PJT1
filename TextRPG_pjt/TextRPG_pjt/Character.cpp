#include "Character.h"
#include "Item.h"

//�ʱⰪ�� nullptr�� �ʱ�ȭ
Character* Character::instance = nullptr;
//Ŭ���� ������
Character::Character(const std::string& name)
    : name(name), level(1), health(200), maxHealth(200), attack(30), experience(0), gold(0) {} //�ʱ�ȭ ����Ʈ�� ���� �ʱ�ȭ

// �Ҹ���
Character::~Character()
{
    // �����Ҵ��� �κ��丮 �����۵� �޸� ����
    for (Item* i : inventory)
    {
        delete i;
    }
    // �κ��丮 ���� ���� (������� dangling pointer�� ��)
    inventory.clear();
}

//ĳ���ʹ� �� �ϳ��� �����ؾ���
Character* Character::getInstance(const std::string& name) 
{
    if (instance == nullptr) //ĳ���Ͱ� �������� ������
    {
        instance = new Character(name); //�ѹ��� ������
    }
    return instance; //�� ���ĺ��ʹ� ���� �ν��Ͻ� ��ȯ
}

void Character::displayStatus() 
{
    //UI�ʿ��� �̹� �����ѵ�
}

//������ �Լ�
void Character::levelUp() 
{
    if (level >= 10) return; //�ִ� ���� 10 ����

    while (experience >= 100 && level < 10) //������ �����ϴ� ��ŭ ������ ����
    {
        experience -= 100; //������ �ϴ� ��ŭ ����ġ ����
        level++; //���� +1
        maxHealth += 20; //�ִ�ü�� (���� * 20) ��ŭ ����
        health += maxHealth; //�ִ�ü�±��� ȸ��
        attack += 5; //���ݷ� (���� * 5) ��ŭ ����
    }
}
//����ġ ȹ�� �Լ�
void Character::addExp(int amount)
{
    experience += amount; //����ŭ ����ġ ȹ��
    levelUp(); //������ ����, ���⼭ �ؾ��ϳ�? ������ ���⼭ �ϴ°� ���ҵ�
}
//��� ȹ�� �Լ�
void Character::addGold(int amount)
{
    gold += amount; //����ŭ ��� ȹ��
}
//ü�� ȸ�� �Լ�
void Character::heal(int amount)
{
    health += amount; //����ŭ ü�� ȸ��
}
//ü�� ���� �Լ�
void Character::takeDamage(int amount)
{
    health -= amount; //����ŭ ü�� ����
}
//������ ȹ�� �Լ�
void Character::addItem(Item* item)
{
    inventory.push_back(item); //���Ϳ� ������ push
}

//������ ���� �Լ�
void Character::removeItem(int index)
{
    delete inventory[index];
    inventory.erase(inventory.begin() + index);
}

//������ ��� �Լ�
void Character::useItem(int index)
{
    if (index <= 0 || index >= inventory.size() + 1) return; //�Է¹��� index�� ��ȿ�� �˻�. ����� �����̱� ������ �κ��丮 ����� 1�� ����(1���� ����)

    //���湺��������������ϴ��ڵ�

    inventory.erase(inventory.begin() + index - 1); //�ش� ��ġ�� ������ ����
}
//ĳ���� ��� ���� üũ �Լ�
bool Character::isDead()
{
    return health <= 0; //ĳ���� ü���� 0���ϸ� true ��ȯ
}

void Character::destroyInstance()
{
    // �ν��Ͻ� valid üũ
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}


