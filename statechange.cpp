#include"allcpp.h"

void switchState(GameState targetState) {
    // 状态切换前的基础数据重置（阶段1仅处理退出逻辑）
    if (targetState == STATE_EXIT) {
        closegraph();  // 退出时关闭窗口
        exit(0);       // 终止程序
    }
    // 更新当前状态
    g_currentState = targetState;
}
