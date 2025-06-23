#pragma once
#ifndef UI_H_  
#define UI_H_
#include <windows.h>
#include <memory>
#include "UIXY.h"
#include "Character.h"
#include "Monster.h"

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
    void PrintAction();
    void PrintStage();
    void PrintPlayerSummry();
    void PrintBattleLog();
    void PrintFullLog();

    void CheckVal();

    void AddFullLog(const std::string& log);

    void AddBattleLog(const std::string& log);

    //void SetMonster(Monster* m);
    //void PrintMonsterSummary();

    void destroyInstance();

    void Stage() { ++StageCount; }

};

#endif