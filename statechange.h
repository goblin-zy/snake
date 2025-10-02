#ifndef STATE_MODULE_H
#define STATE_MODULE_H

// 游戏状态枚举（阶段1仅需主菜单相关状态）
enum GameState {
    STATE_MAIN_MENU,        // 主菜单（初始状态）
    STATE_DIFFICULTY_SELECT,// 难度选择（点击“开始”进入）
    STATE_READY,
    STATE_RANKING,          // 排行榜（点击“排行榜”进入）
    STATE_SETTING,          // 设置（点击“设置”进入）
    STATE_EXIT,         // 退出（点击“退出”进入）
    

    STATE_RUNNING  //开始运行 
};

// 切换游戏状态（参数：目标状态）
void switchState(GameState targetState);

#endif
