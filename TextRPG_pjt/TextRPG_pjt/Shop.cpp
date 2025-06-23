#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "UI.h"
#include <limits> 
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
	while (true) 
	{
		system("cls");
		cout << "============================" << endl;
		cout << "             상점            " << endl;
		cout << "============================" << endl;
		cout << "현재 보유 골드 : " << player->getGold() << "G" << endl;
		cout << "[1] 사기" << endl;
		cout << "[2] 팔기" << endl;
		cout << "[0] 상점 나가기" << endl;
		cout << "\n선택: ";

		
		if (!(cin >> choice)) 
		{
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "\n 엔터를 눌러 계속 진행하세요...";
			cin.get();
			continue; 
		}

		if (choice == 1)
		{
			displayBuyMenu(player);
		}
		else if (choice == 2)
		{
			displaySellMenu(player);
		}
		else if (choice == 0) 
		{
			break;
		}
		else { 
			cout << "잘못된 선택입니다. 0, 1, 2 중 하나를 입력해주세요." << endl;
			cout << "\n 엔터를 눌러 계속 진행하세요...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
	}
}

void Shop::displayBuyMenu(Character* player)
{
	int choice = 1;
	while (true)
	{
		system("cls");
		cout << "============================" << endl;
		cout << "      상점 아이템 구매창      " << endl;
		cout << "============================" << endl;
		cout << "현재 보유 골드 : " << player->getGold() << "G" << endl;
		for (int i = 0; i < availableItems.size(); i++)
		{
			cout << "[" << i + 1 << "] " << availableItems[i]->getName() << " (" << availableItems[i]->getBuyPrice() << "G) - " << availableItems[i]->getToolTip() << endl;
		}
		cout << "[0] 상점 메뉴로 돌아가기" << endl;
		cout << "\n 구매할 아이템을 선택하세요 : ";

		
		if (!(cin >> choice)) 
		{
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "\n 엔터를 눌러 계속 진행하세요...";
			cin.get();
			continue; 
		}

		if (choice == 0) 
		{
			break;
		}

		
		if (0 < choice && choice <= availableItems.size())
		{
			if (player->getGold() >= availableItems[choice - 1]->getBuyPrice())
			{
				buyItem(choice - 1, player);
				cout << "성공적으로 구매했습니다!" << endl; 
			}
			else
			{
				cout << "골드가 부족합니다!" << endl;
			}
			
			cout << "\n 엔터를 눌러 계속 진행하세요...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
		else 
		{
			cout << "유효하지 않은 아이템 번호입니다." << endl;
			cout << "\n 엔터를 눌러 계속 진행하세요...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
	}
}

void Shop::displaySellMenu(Character* player)
{
	int choice = 1;
	while (true)
	{
		vector<Item*> inven = player->getInventory();
		system("cls");
		cout << "============================" << endl;
		cout << "         아이템 판매창       " << endl;
		cout << "============================" << endl;
		cout << "          내 인벤토리        " << endl;
		cout << "============================" << endl;
		cout << "현재 보유 골드 : " << player->getGold() << "G" << endl;
		if (inven.empty())
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

		
		if (!(cin >> choice)) 
		{
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n엔터를 눌러서 계속 진행하세요...";
			cin.get();
			continue;
		}

	
		if (choice == 0)
		{
			break;
		}

		
		if (choice > 0 && !inven.empty() && choice <= inven.size())
		{
			player->addGold(inven[choice - 1]->getSellPrice());
			sellItem(choice, player);
			cout << "성공적으로 판매했습니다!" << endl;
		}
		else
		{
			if (inven.empty()) 
			{
				cout << "인벤토리가 비어있어 판매할 아이템이 없습니다." << endl;
			}
			else 
			{
				cout << "유효하지 않은 아이템 번호입니다." << endl;
			}
		}
		
		cout << "\n엔터를 눌러서 계속 진행하세요...";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
}

void Shop::buyItem(const int& slotNum, Character* player)
{
	Item* item = createItemType(availableItems[slotNum]->getItemCode());
	player->addGold(-availableItems[slotNum]->getBuyPrice());
	player->addItem(item);
}

void Shop::sellItem(const int& slotNum, Character* player)
{
	if (!player->getInventory().empty())
	{
		player->removeItem(slotNum);
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