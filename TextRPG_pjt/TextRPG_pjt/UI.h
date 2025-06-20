#pragma once
#ifndef UI_H_  
#define UI_H_

#include "Character.h"
#include "UIXY.h"
#include <windows.h>
#include "Monster.h"

class UI
{
private:

    std::vector<std::string> FullLog;
    std::vector<std::string> BattleLog;
    Monster* currentMonster = nullptr;

public:

    void SetCursorPosition(int X, int Y);
    void PrintStatus();
    void PrintInventory();
    void PrintIsShop();
    void PrintAction();
    void PrintStage();
    void PrintPlayerSummry();
    void PrintBattleLog();
    void PrintFullLog();

    void CheckVal();

    void AddFullLog(const std::string& log);
    std::vector<std::string>* GetFullLogPtr();

    void AddBattleLog(const std::string& log);
    std::vector<std::string>* GetBattleLogPtr();

    void SetMonster(Monster* m);
    void PrintMonsterSummary();
};

#endif