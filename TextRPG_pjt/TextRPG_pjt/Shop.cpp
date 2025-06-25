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
	// ���� ����
	int choice = 1;
	while (true) 
	{
		system("cls");
		cout << "============================" << endl;
		cout << "             ����            " << endl;
		cout << "============================" << endl;
		cout << "���� ���� ��� : " << player->getGold() << "G" << endl;
		cout << "[1] ���" << endl;
		cout << "[2] �ȱ�" << endl;
		cout << "[0] ���� ������" << endl;
		cout << "\n����: ";

		
		if (!(cin >> choice)) 
		{
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "\n ���͸� ���� ��� �����ϼ���...";
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
			cout << "�߸��� �����Դϴ�. 0, 1, 2 �� �ϳ��� �Է����ּ���." << endl;
			cout << "\n ���͸� ���� ��� �����ϼ���...";
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
		cout << "      ���� ������ ����â      " << endl;
		cout << "============================" << endl;
		cout << "���� ���� ��� : " << player->getGold() << "G" << endl;
		for (int i = 0; i < availableItems.size(); i++)
		{
			cout << "[" << i + 1 << "] " << availableItems[i]->getName() << " (" << availableItems[i]->getBuyPrice() << "G) - " << availableItems[i]->getToolTip() << endl;
		}
		cout << "[0] ���� �޴��� ���ư���" << endl;
		cout << "\n ������ �������� �����ϼ��� : ";

		
		if (!(cin >> choice)) 
		{
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "\n ���͸� ���� ��� �����ϼ���...";
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
				cout << "���������� �����߽��ϴ�!" << endl; 
			}
			else
			{
				cout << "��尡 �����մϴ�!" << endl;
			}
			
			cout << "\n ���͸� ���� ��� �����ϼ���...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
		else 
		{
			cout << "��ȿ���� ���� ������ ��ȣ�Դϴ�." << endl;
			cout << "\n ���͸� ���� ��� �����ϼ���...";
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
		cout << "         ������ �Ǹ�â       " << endl;
		cout << "============================" << endl;
		cout << "          �� �κ��丮        " << endl;
		cout << "============================" << endl;
		cout << "���� ���� ��� : " << player->getGold() << "G" << endl;
		if (inven.empty())
		{
			cout << "������ �ִ� �������� �����ϴ�." << endl;
		}
		else
		{
			for (int i = 0; i < inven.size(); i++)
			{
				cout << "[" << i + 1 << "] " << inven[i]->getName() << " (" << inven[i]->getSellPrice() << "G) - " << inven[i]->getToolTip() << endl;
			}
		}
		cout << "[0] ���� �޴��� ���ư���" << endl;
		cout << "\n�Ǹ��� �������� ������ : ";

		
		if (!(cin >> choice)) 
		{
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n���͸� ������ ��� �����ϼ���...";
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
			cout << "���������� �Ǹ��߽��ϴ�!" << endl;
		}
		else
		{
			if (inven.empty()) 
			{
				cout << "�κ��丮�� ����־� �Ǹ��� �������� �����ϴ�." << endl;
			}
			else 
			{
				cout << "��ȿ���� ���� ������ ��ȣ�Դϴ�." << endl;
			}
		}
		
		cout << "\n���͸� ������ ��� �����ϼ���...";
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
		// ��� �߰�
	default: return nullptr;
	}
	return nullptr;
}