#pragma once
#ifndef UI_H_  
#define UI_H_

#include "Character.h"
#include "UIXY.h"
#include <windows.h>
#include "Monster.h"
#include <memory>

class UI
{
private:
    UI() = default;
    static std::unique_ptr<UI> instance;

    std::vector<std::string> FullLog;
    std::vector<std::string> BattleLog;
    Monster* currentMonster = nullptr;

public:

    static UI* getInstance();
    UI(const UI&) = delete;
    UI& operator=(const UI&) = delete;
    ~UI() = default;

    int StageCount = 0;

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

    void destroyInstance();

    void Stage() { ++StageCount; }

};

#endif