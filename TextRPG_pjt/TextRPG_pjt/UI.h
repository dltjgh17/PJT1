#pragma once

#include "UIXY.h"
#include "Character.h"
#include "Monster.h"

class UI
{
private:
    /*���� �ν��Ͻ�*/
    UI() = default;
    static std::unique_ptr<UI> instance;

    /*�������� ����*/
    int StageCount = 0;
    int PastStageCount = 0;

    /*�÷��̾� �Է� ����*/
    int ChooseAction = 0;

    /*�α� ����*/
    std::vector<std::string> FullLog;
    std::vector<std::string> BattleLog;
    
public:
    /*���� �ν��Ͻ�*/
    static UI* getInstance();
    UI(const UI&) = delete;
    UI& operator=(const UI&) = delete;
    ~UI() = default;

    void SetCursorPosition(int X, int Y);  // UI ��ġ �� �Լ�
    void PrintStatus(); // ����â UI
    void PrintInventory(); // �κ��丮 UI
    void PrintAction(); // �ൿ ���� ���� UI
    void PrintStage(); // �������� UI
    void DeletePastBattleLog(); // ���� ���� �α� ����
    void PrintBattleLog(); // ���� �α�
    void PrintFullLog(); // ��� ��� �α�


    void AddFullLog(const std::string& log); // Ǯ �α׿� ������ ��� �޾ƿ���
    void AddBattleLog(const std::string& log); // ���� �α׿� ������ ��� �޾ƿ����
     
    void CheckVal(); // ȭ�� UI ������Ʈ �Լ�

    void Input(); // �Է� �Լ�

    //Getter �Լ���
    int GetStageCount() const { return StageCount; }
    int GetChooseAction() const { return ChooseAction; }

    //Setter �Լ�
    void Stage() { ++StageCount; } // �������� ī��Ʈ UP

};
