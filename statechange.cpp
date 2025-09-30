#include <graphics.h>   // EGE核心头文件
#include <cstdio>       // 辅助输入输出
#include <ctime>        // 时间相关（状态管理用）
// 自定义模块头文件（按需添加）
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"


// 全局游戏状态（需在main.cpp中定义，此处声明为外部变量）
extern GameState g_currentState;

void switchState(GameState targetState) {
    // 状态切换前的基础数据重置（阶段1仅处理退出逻辑）
    if (targetState == STATE_EXIT) {
        closegraph();  // 退出时关闭窗口
        exit(0);       // 终止程序
    }
    // 更新当前状态
    g_currentState = targetState;
}
