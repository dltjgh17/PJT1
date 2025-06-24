#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

#include <iostream>

using namespace std;

Shop::Shop()
{
	Item* slot1 = new HealthPotion;
	Item* slot2 = new AttackBoost;
	availableItems.push_back(slot1);
	availableItems.push_back(slot2);
}

void Shop::displayItems(Character* player)
{
	// 구매 상점
	int choice = 1;
	while (choice)
	{
		showMain(player);

		while (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			showMain(player);
		}

		if (choice == 1)
		{
			displayBuyMenu(player);
		}
		else if (choice == 2)
		{
			displaySellMenu(player);
		}
	}
}

void Shop::displayBuyMenu(Character* player)
{
	int choice = 1;
	while (choice)
	{
		showSell(player);
		while (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			showSell(player);
		}

		//아이템구매처리//
		if (0 < choice && choice <= availableItems.size())
		{
			if (player->getGold() >= availableItems[choice - 1]->getBuyPrice())
			{
				buyItem(choice - 1, player);
			}
			else
			{
				cout << "골드가 부족합니다!" << endl;
			}
		}
	}
}


void Shop::displaySellMenu(Character* player)
{
	int choice = 1;
	while (choice)
	{
		showBuy(player);
		while (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			showBuy(player);
		}

		// 선택한 인덱스의 아이템 판매 함수 호출
		if (isdigit(choice) && choice > 0 && 0 < player->getInventory().size() && choice <= player->getInventory().size()) // 인벤토리가 비어있을 경우 인벤토리에 접근 못하도록 예외처리
		{
			player->addGold(player->getInventory()[choice - 1]->getSellPrice()); // 판매시 골드 증가
			sellItem(choice, player); // 인벤토리에서 제거
		}
	}
}

void Shop::showMain(Character* player)
{
	system("cls");
	cout << "============================" << endl;
	cout << "             상점            " << endl;
	cout << "============================" << endl;
	cout << "현재 보유 골드 : " << player->getGold() << "G" << endl;
	cout << "[1] 사기" << endl;
	cout << "[2] 팔기" << endl;
	cout << "[0] 상점 나가기" << endl;
	cout << "행동을 선택하세요 : ";
}

void Shop::showSell(Character* player)
{
	vector<Item*> inven = player->getInventory();
	system("cls");
	cout << "============================" << endl;
	cout << "         아이템 판매창       " << endl;
	cout << "============================" << endl;
	cout << "          내 인벤토리        " << endl;
	cout << "============================" << endl;
	cout << "현재 보유 골드 : " << player->getGold() << "G" << endl;

	if (!inven.size()) // 인벤이 빈 경우
	{
		cout << "가지고 있는 아이템이 없습니다." << endl;
	}
	else
	{
		for (int i = 0; i < inven.size(); i++)
		{
			cout << "[" << i + 1 << "] " << inven[i]->getName() << " (" << inven[i]->getSellPrice() << "G) - " << inven[i]->getToolTip() << endl;
		}
	}
	cout << "[0] 상점 메뉴로 돌아가기" << endl;
	cout << "\n판매할 아이템을 고르세요 : ";
}

void Shop::showBuy(Character* player)
{
	vector<Item*> inven = player->getInventory();
	system("cls");
	cout << "============================" << endl;
	cout << "         아이템 판매창       " << endl;
	cout << "============================" << endl;
	cout << "          내 인벤토리        " << endl;
	cout << "============================" << endl;
	cout << "현재 보유 골드 : " << player->getGold() << "G" << endl;

	if (!inven.size()) // 인벤이 빈 경우
	{
		cout << "가지고 있는 아이템이 없습니다." << endl;
	}
	else
	{
		for (int i = 0; i < inven.size(); i++)
		{
			cout << "[" << i + 1 << "] " << inven[i]->getName() << " (" << inven[i]->getSellPrice() << "G) - " << inven[i]->getToolTip() << endl;
		}
	}
	cout << "[0] 상점 메뉴로 돌아가기" << endl;
	cout << "\n판매할 아이템을 고르세요 : ";
}


void Shop::buyItem(const int& slotNum, Character* player)
{
	Item* item = createItemType(availableItems[slotNum]->getItemCode());

	player->addGold(-availableItems[slotNum]->getBuyPrice());
	player->addItem(item);
}

void Shop::sellItem(const int& slotNum, Character* player)
{
	if (!player->getInventory().empty()) // 인벤토리가 빈 공간이 아닌경우
	{
		player->removeItem(slotNum); // 인덱스 위치의 아이템 제거 함수 호출
	}
}

Item* Shop::createItemType(const ItemCode& code)
{
	switch (code)
	{
	case ItemCode::ITEM_HEALTH_POTION: return new HealthPotion();
	case ItemCode::ITEM_ATTACK_BOOST: return new AttackBoost();
	// 계속 추가
	default: return nullptr;
	}
	return nullptr;
}
