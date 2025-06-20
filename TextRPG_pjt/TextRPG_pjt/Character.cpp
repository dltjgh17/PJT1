#include "Character.h"
#include "Item.h"
#include "UI.h"
#include "Title.h"

//초기값은 nullptr로 초기화
Character* Character::instance = nullptr;
//클래스 생성자
Character::Character(const std::string& name)
    : name(name), level(1), health(200), maxHealth(200), attack(30), experience(0), gold(0) {} //초기화 리스트로 변수 초기화

// 소멸자
Character::~Character()
{
    // 동적할당한 인벤토리 아이템들 메모리 해제
    for (Item* i : inventory)
    {
        delete i;
    }
    // 인벤토리 벡터 비우기 (안지우면 dangling pointer가 됨)
    inventory.clear();
}

//캐릭터는 단 하나만 존재해야함
Character* Character::getInstance(const std::string& name) 
{
    if (instance == nullptr) //캐릭터가 존재하지 않으면
    {
        instance = new Character(name); //한번만 생성함
    }
    return instance; //그 이후부터는 같은 인스턴스 반환
}

void Character::displayStatus() 
{
    //UI쪽에서 이미 구현한듯
}

//레벨업 함수
void Character::levelUp() 
{
    if (level >= 10) return; //최대 레벨 10 제한

    while (experience >= 100 && level < 10) //조건을 만족하는 만큼 레벨업 실행
    {
        experience -= 100; //레벨업 하는 만큼 경험치 제거
        level++; //레벨 +1
        maxHealth += 20; //최대체력 (레벨 * 20) 만큼 증가
        health += maxHealth; //최대체력까지 회복
        attack += 5; //공격력 (레벨 * 5) 만큼 증가

        UI* ui = UI::getInstance();
        Character* p = Character::getInstance();
        std::vector<std::string>* FullLogPtr = ui->GetFullLogPtr();
        ui->AddFullLog(p->getName() + "이(가) 레벨이 " + std::to_string(p->getLevel()) + "이 되었습니다!");
        ui->AddFullLog(p->getName() + "이(가) 공격력이 " + std::to_string(p->getAttack()) + "이 되었습니다!");
        ui->AddFullLog(p->getName() + "이(가) 최대 체력이 " + std::to_string(p->getHealth()) + "이 되었습니다!");
    }
}
//경험치 획득 함수
void Character::addExp(int amount)
{
    experience += amount; //값만큼 경험치 획득
    levelUp(); //레벨업 실행, 여기서 해야하나? 싶은데 여기서 하는게 편할듯
    UI* ui = UI::getInstance();
    Character* p = Character::getInstance();
    ui->AddFullLog(p->getName() + "의 경험치가 " + std::to_string(amount) + "이 올랐습니다!");
    ui->AddFullLog(p->getName() + "의 경험치가 " + std::to_string(p->getAttack()) + "이되었습니다!");
}
//골드 획득 함수
void Character::addGold(int amount)
{
    gold += amount; //값만큼 골드 획득
    UI* ui = UI::getInstance();
    Character* p = Character::getInstance();
    ui->AddFullLog(p->getName() + " 이(가) " + std::to_string(amount) + " 골드 획득했습니다");
    ui->AddFullLog(p->getName() + " 이(가) " + std::to_string(p->getGold()) + " 골드 보유 중입습니다");
}
//체력 회복 함수
void Character::heal(int amount)
{
    health += amount; //값만큼 체력 회복
    UI* ui = UI::getInstance();
    Character* p = Character::getInstance();
    ui->AddFullLog(p->getName() + " 이(가) " + std::to_string(amount) + " 체력 회복했습니다");
    ui->AddFullLog(p->getName() + " 의 현재 체력은 " + std::to_string(p->getHealth()) + " 입니다");

}
//체력 감소 함수
void Character::takeDamage(int amount)
{
    health -= amount; //값만큼 체력 감소
    UI* ui = UI::getInstance();
    Character* p = Character::getInstance();
    ui->AddFullLog(p->getName() + " 이(가) " + std::to_string(amount) + " 체력 감소습니다");
    ui->AddFullLog(p->getName() + " 의 현재 체력은 " + std::to_string(p->getHealth()) + " 입니다");
}
//아이템 획득 함수
void Character::addItem(Item* item)
{
    inventory.push_back(item); //벡터에 아이템 push
    UI* ui = UI::getInstance();
    ui->AddFullLog("아이템을 획득했습니다");
}

//아이템 제거 함수
void Character::removeItem(int index)
{
    UI* ui = UI::getInstance();
    ui->AddFullLog("아이템이 제거됩니다");

    delete inventory[index];
    inventory.erase(inventory.begin() + index);

}

//아이템 사용 함수
void Character::useItem(int index)
{
    if (index <= 0 || index >= inventory.size() + 1) return; //입력받은 index의 유효성 검사. 사용자 기준이기 때문에 인벤토리 사이즈에 1을 더함(1부터 시작)

    //대충뭔가아이템을사용하는코드

    int NumberPlz = inventory.size()/2;

    UI* ui = UI::getInstance();
    Character* p = Character::getInstance();
    std::vector<Item*> What = p->getInventory();
    std::string itemName = What[NumberPlz]->getName();
    ui->AddFullLog(p->getName() + " 이(가) " + itemName + " 을(를) 사용했습니다");

    inventory.erase(inventory.begin() + index - 1); //해당 위치의 아이템 삭제
}
//캐릭터 사망 여부 체크 함수
bool Character::isDead()
{
    // return health <= 0; //캐릭터 체력이 0이하면 true 반환
    return 0;
    Title* Title = Title::getInstance();
    Title->GameOver();
    
}

void Character::destroyInstance()
{
    // 인스턴스 valid 체크
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}


