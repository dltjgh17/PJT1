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

    /*���ӿ� �ʿ��� ��� �ý��� ����*/
    Title& MainTitle; // <-- ���⼭�� ���� �մϴ�.
    UI& InterFace;
    Character& Player;
    Shop& MyShop;

    GameManager() : // <-- ������ �ʱ�ȭ ����Ʈ ����
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