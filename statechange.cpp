#include"allcpp.h"

// 在statechange.cpp中补充状态切换时的清理逻辑
void switchState(GameState targetState) {
    // 状态切换前的清理工作
    if (targetState == STATE_MAIN_MENU) {
        // 回到主菜单时重置游戏状态
        resetScore();
        // 可以根据需要添加其他重置逻辑
    }
    
    if (targetState == STATE_EXIT) {
        closegraph();
        exit(0);
    }
    g_currentState = targetState;
}
