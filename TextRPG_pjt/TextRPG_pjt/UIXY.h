#pragma once

#ifndef UI_XY_H
#define UI_XY_H

struct UI_XY
{
    static constexpr int POS_STATUS_X = 0;
    static constexpr int POS_STATUS_Y = 0;

    static constexpr int POS_INVENTORY_X = 0;
    static constexpr int POS_INVENTORY_Y = 7;

    static constexpr int POS_SHOP_X = 0;
    static constexpr int POS_SHOP_Y = 12;

    static constexpr int POS_ACTION_X = 0;
    static constexpr int POS_ACTION_Y = 21;

    static constexpr int POS_STAGE_X = 43;
    static constexpr int POS_STAGE_Y = 0;

    static constexpr int POS_BATTLE_TITLE_X = 43;
    static constexpr int POS_BATTLE_TITLE_Y = 25;

    static constexpr int POS_BATTLE_LOG_X = 43;
    static constexpr int POS_BATTLE_LOG_Y = 2;

    static constexpr int POS_PLAYER_SUMMARY_X = 25;
    static constexpr int POS_PLAYER_SUMMARY_Y = 25;

    static constexpr int POS_MONSTER_SUMMARY_X = 70;
    static constexpr int POS_MONSTER_SUMMARY_Y = 25;

    static constexpr int POS_FULL_LOG_X = 96;
    static constexpr int POS_FULL_LOG_Y = 0;
};

#endif