#pragma once

#include "UIXY.h"
#include "Character.h"
#include "Monster.h"

class UI
{
private:
    /*단일 인스턴스*/
    UI() = default;
    static std::unique_ptr<UI> instance;

    /*스테이지 변수*/
    int StageCount = 0;
    int PastStageCount = 0;

    /*플레이어 입력 변수*/
    int ChooseAction = 0;

    /*로그 변수*/
    std::vector<std::string> FullLog;
    std::vector<std::string> BattleLog;
    
public:
    /*단일 인스턴스*/
    static UI* getInstance();
    UI(const UI&) = delete;
    UI& operator=(const UI&) = delete;
    ~UI() = default;

    void SetCursorPosition(int X, int Y);  // UI 위치 값 함수
    void PrintStatus(); // 상태창 UI
    void PrintInventory(); // 인벤토리 UI
    void PrintAction(); // 행동 유형 선택 UI
    void PrintStage(); // 스테이지 UI
    void DeletePastBattleLog(); // 이전 전투 로그 삭제
    void PrintBattleLog(); // 전투 로그
    void PrintFullLog(); // 모든 기록 로그


    void AddFullLog(const std::string& log); // 풀 로그에 저장할 기록 받아오기
    void AddBattleLog(const std::string& log); // 전투 로그에 저장할 기록 받아오기용
     
    void CheckVal(); // 화면 UI 업데이트 함수

    void Input(); // 입력 함수

    //Getter 함수들
    int GetStageCount() const { return StageCount; }
    int GetChooseAction() const { return ChooseAction; }

    //Setter 함수
    void Stage() { ++StageCount; } // 스테이지 카운트 UP

};
