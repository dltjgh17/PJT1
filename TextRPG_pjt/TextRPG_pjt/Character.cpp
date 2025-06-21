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
        UI* ui = UI::getInstance();
        ui->AddFullLog(name + " : [Level UP!] ");
        ui->AddFullLog(name + " : [new Lv] : " + to_string(level));
        ui->AddFullLog(name + " : [new HP] : " + to_string(health));
        ui->AddFullLog(name + " : [new ATK] : " + to_string(attack));
    }
}
//����ġ ȹ�� �Լ�
void Character::addExp(int amount)
{
    experience += amount; //����ŭ ����ġ ȹ��
    levelUp(); //������ ����, ���⼭ �ؾ��ϳ�? ������ ���⼭ �ϴ°� ���ҵ�

    /*UI*/
    UI* ui = UI::getInstance();
    ui->AddFullLog(name + " : [EXP] :  " + to_string(amount) + " : GET!");
}
//��� ȹ�� �Լ�
void Character::addGold(int amount)
{
    gold += amount; //����ŭ ��� ȹ��

    /*UI*/
    UI* ui = UI::getInstance();
    ui->AddFullLog(name + " : [GOLD] :  " + to_string(amount) + " : GET!");

}
//ü�� ȸ�� �Լ�
void Character::heal(int amount)
{
    health += amount; //����ŭ ü�� ȸ��

    /*UI*/
    UI* ui = UI::getInstance();
    ui->AddFullLog(name + " : [HELALTH] : " + to_string(amount) + " :  HEAL!");

}
//ü�� ���� �Լ�
void Character::takeDamage(int amount)
{
    health -= amount; //����ŭ ü�� ����

    /*UI*/
    UI* ui = UI::getInstance();
    ui->AddBattleLog(name + " : [HELALTH] : " + to_string(amount) + " : LOST!");
}
//������ ȹ�� �Լ�
void Character::addItem(Item* item)
{
    inventory.push_back(item); //���Ϳ� ������ push
    
    /*UI*/
    UI* ui = UI::getInstance();
    ui->AddFullLog(name + " : [ITEM] : " + item->getName() + " : GET");
}

//������ ���� �Լ�
void Character::removeItem(int index)
{

    /*UI ������ ��� �� ���Ž� ������ ���� ����Ǿ�� �մϴ�.*/
    Item* targetItem = inventory[index];
    std::string itemName = targetItem->getName();
    UI* ui = UI::getInstance();
    ui->AddFullLog(name + " : [ITEM] : " + itemName + " : DELETE!");

    delete inventory[index];
    inventory.erase(inventory.begin() + index);

}

//������ ��� �Լ�
void Character::useItem(int index)
{
    if (index <= 0 || index >= inventory.size() + 1) return; //�Է¹��� index�� ��ȿ�� �˻�. ����� �����̱� ������ �κ��丮 ����� 1�� ����(1���� ����)

    /*UI ������ ��� �� ���Ž� ������ ���� ����Ǿ�� �մϴ�.*/
    Item* targetItem = inventory[index - 1];
    std::string itemName = targetItem->getName();
    UI* ui = UI::getInstance();
    ui->AddFullLog(name + " : [ITEM] : " + itemName + " : USE!");

    //���湺��������������ϴ��ڵ�
    // ���� ���� �������� ����ϴ� �ڵ尡 �־�� ������ ui�� �ݿ��� �����մϴ�.
    // �۵��� ���ֽø�˴ϴ�.
    // �۵��ϴ� �ڵ常 ������ ui���� �׳� ȭ�� ��� �����ϸ� �˾Ƽ� �ֽ� ���� �޾ƿɴϴ�.

    inventory.erase(inventory.begin() + index - 1); //�ش� ��ġ�� ������ ����
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

