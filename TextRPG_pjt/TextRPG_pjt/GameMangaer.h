#pragma once

#include "SingleTonTemplate.h"
#include "UI.h"
#include "Title.h"
#include "Shop.h"
#include "Character.h"

#include <iostream>

class GameManager : public Singleton<GameManager>
{
private:
    friend class Singleton<GameManager>;

    /*게임에 필요한 모든 시스템 선언*/
    Title& MainTitle; // <-- 여기서는 선언만 합니다.
    UI& InterFace;
    Character& Player;
    Shop& MyShop;

    GameManager() : // <-- 생성자 초기화 리스트 시작
        MainTitle(Title::getInstance()),
        InterFace(UI::getInstance()),
        Character Player();
        Shop MyShop;
    {
    }

    ~GameManager()
    {

    }
};