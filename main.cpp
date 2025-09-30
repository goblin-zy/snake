#include <graphics.h>   // EGE核心头文件
#include <cstdio>       // 辅助输入输出
#include <ctime>        // 时间相关（状态管理用）
// 自定义模块头文件（按需添加）
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"



// 定义全局核心变量（跨模块共享）
GameState g_currentState;  // 当前游戏状态

// 声明主菜单处理函数（阶段1核心逻辑）
void handleMainMenu();

int main() {
    // 1. 初始化：窗口→资源→数据
    initWindow(800,600);    // 创建640×480窗口
    loadResources();         // 加载主菜单图片/字体
    initCoreData();          // 初始化游戏状态为主菜单

    // 2. 主循环（窗口未关闭则持续运行）
    while (is_run()) {
        // 根据当前状态执行对应逻辑（阶段1仅主菜单）
        switch (g_currentState) {
            case STATE_MAIN_MENU:
                handleMainMenu();
                break;
            // 其他状态（难度选择/排行榜等）后续阶段补充
            default:
                break;
        }
        delay_fps(30);  // 控制帧率（30帧/秒，避免CPU占用过高）
    }

    // 3. 释放资源（程序退出）
    releaseResources();
    return 0;
}

// 主菜单逻辑处理（绘制→监听点击→切换状态）
void handleMainMenu() {
    // 步骤1：绘制主菜单界面
    drawMainMenu();

    // 步骤2：监听鼠标点击
    ClickType click = listenMouseClick();

    // 步骤3：根据点击类型切换状态
    switch (click) {
        case CLICK_START:
            switchState(STATE_DIFFICULTY_SELECT);  // 开始→难度选择
            break;
        case CLICK_RANKING:
            switchState(STATE_RANKING);            // 排行榜→排行榜状态
            break;
        case CLICK_SETTING:
            switchState(STATE_SETTING);            // 设置→设置状态
            break;
        case CLICK_EXIT:
            switchState(STATE_EXIT);               // 退出→终止程序
            break;
        default:
            break;  // 无点击则不处理
    }
}
