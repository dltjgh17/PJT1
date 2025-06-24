#pragma once

struct UI_XY
{
    //상태창//
    static constexpr int POS_STATUS_X = 0;
    static constexpr int POS_STATUS_Y = 0;

    //인벤토리//
    static constexpr int POS_INVENTORY_X = 0;
    static constexpr int POS_INVENTORY_Y = 7;

    //행동 선택//
    static constexpr int POS_ACTION_X = 0;
    static constexpr int POS_ACTION_Y = 21;

    //스테이지//
    static constexpr int POS_STAGE_X = 43;
    static constexpr int POS_STAGE_Y = 0;

    //배틀 로그(전투 기록)//
    static constexpr int POS_BATTLE_LOG_X = 43;
    static constexpr int POS_BATTLE_LOG_Y = 2;

    //풀 로그(당신의 여정)//
    static constexpr int POS_FULL_LOG_X = 70;
    static constexpr int POS_FULL_LOG_Y = 0;
};
