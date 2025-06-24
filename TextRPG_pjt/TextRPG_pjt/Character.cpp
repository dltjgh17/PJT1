#include "Character.h"
#include "Item.h"
#include "UI.h"
#include "Title.h"

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
        health = maxHealth; //�ִ�ü�±��� ȸ��
        attack += 5; //���ݷ� (���� * 5) ��ŭ ����

        /*UI*/
        UI* InterFace = UI::getInstance();
        InterFace->AddFullLog(name + " : [���� ��!] ");
        InterFace->AddFullLog(name +  " : " + to_string(level) + " ������ �Ǿ����ϴ�.");
        InterFace->AddFullLog(name + " : �ִ� ü���� " + to_string(health) + " �� �Ǿ����ϴ�.");
        InterFace->AddFullLog(name + " : ���ݷ��� " + to_string(attack) + " �� �Ǿ����ϴ�.");
    }
}
//����ġ ȹ�� �Լ�
void Character::addExp(int amount)
{
    experience += amount; //����ŭ ����ġ ȹ��
    levelUp(); //������ ����, ���⼭ �ؾ��ϳ�? ������ ���⼭ �ϴ°� ���ҵ�

    /*UI*/
    UI* InterFace = UI::getInstance();
    InterFace->AddFullLog(name + " : [����ġ] :  " + to_string(amount) + " : ȹ��!");
}
//��� ȹ�� �Լ�
void Character::addGold(int amount)
{
    gold += amount; //����ŭ ��� ȹ��

    /*UI*/
    UI* InterFace = UI::getInstance();
    if (amount > 0)
    InterFace->AddFullLog(name + " : [���] :  " + to_string(amount) + " : ȹ��!");
    else if (amount < 0)
    InterFace->AddFullLog(name + " : [���] :  " + to_string(amount) + " : ����!");

}
//ü�� ȸ�� �Լ�
void Character::heal(int amount)
{
    if (maxHealth <= health + amount) health = maxHealth; //�ִ�ü���� �Ѵ� ȸ�� ����
    else health += amount; //�ƴҰ�� ����ŭ ü�� ȸ��

    /*UI*/
    UI* InterFace = UI::getInstance();
    InterFace->AddFullLog(name + " : [ü��] : " + to_string(amount) + " :  ȸ��!");

}
//���ݷ� ���� �Լ�
void Character::increaseAtk(int amount)
{
    attack += amount; //����ŭ ���ݷ� ����

    /*UI*/
    UI* InterFace = UI::getInstance();
    InterFace->AddFullLog(name + " : [���ݷ�] : " + to_string(amount) + " :  ���!"); //��³��� ���Ƿ� ���� �����ߴµ� �ٽ� �ٲټŵ� �˴ϴ�

}
//ü�� ���� �Լ�
void Character::takeDamage(int amount)
{
    health -= amount; //����ŭ ü�� ����

    /*UI*/
    UI* InterFace = UI::getInstance();
    InterFace->AddBattleLog(name + " : [ü��] : " + to_string(amount) + " : ����!");
}
//������ ȹ�� �Լ�
void Character::addItem(Item* item)
{
    inventory.push_back(item); //���Ϳ� ������ push
    
    /*UI*/
    UI* InterFace = UI::getInstance();
    InterFace->AddFullLog(name + " : [������] : " + item->getName() + " : ȹ��!");
}

//������ ���� �Լ�
void Character::removeItem(int index)
{
    /*UI ������ ��� �� ���Ž� ������ ���� ����Ǿ�� �մϴ�.*/
    Item* targetItem = inventory[index - 1];
    std::string itemName = targetItem->getName();
    UI* InterFace = UI::getInstance();
    InterFace->AddFullLog(name + " : [������] : " + itemName + " : ����!");

    inventory.erase(inventory.begin() + index - 1);
    delete targetItem;
}

//������ ��� �Լ�
void Character::useItem(int index)
{
    if (index <= 0 || index >= inventory.size() + 1) return; //�Է¹��� index�� ��ȿ�� �˻�. ����� �����̱� ������ �κ��丮 ����� 1�� ����(1���� ����)

    /*UI ������ ��� �� ���Ž� ������ ���� ����Ǿ�� �մϴ�.*/
    Item* targetItem = inventory[index - 1];
    std::string itemName = targetItem->getName();
    UI* InterFace = UI::getInstance();
    InterFace->AddFullLog(name + " : [������] : " + itemName + " : ���!");

    targetItem->Use(this); //������ ���
    removeItem(index); //����� ������ ����
}

//ĳ���� ��� ���� üũ �Լ�
bool Character::isDead()
{
    // return health <= 0; //ĳ���� ü���� 0���ϸ� true ��ȯ
    return 0;
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

