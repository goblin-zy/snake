#include <graphics.h>   // EGE核心头文件
#include <cstdio>       // 辅助输入输出
#include <ctime>        // 时间相关（状态管理用）
// 自定义模块头文件（按需添加）
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"


// 主菜单按钮坐标（需与drawMainMenu()中的绘制位置完全一致）
#define BTN_START_X  338  // 原270 → 270×1.25=337.5≈338
#define BTN_START_Y  188  // 原150 → 150×1.25=187.5≈188
#define BTN_RANK_X   338  // 原270 → 338
#define BTN_RANK_Y   263  // 原210 → 210×1.25=262.5≈263
#define BTN_SET_X    338  // 原270 → 338
#define BTN_SET_Y    338  // 原270 → 270×1.25=337.5≈338
#define BTN_EXIT_X   338  // 原270 → 338
#define BTN_EXIT_Y   413  // 原330 → 330×1.25=412.5≈413
#define BTN_W        100  
#define BTN_H        40   // 按钮尺寸：100×40

ClickType listenMouseClick() {
    mouse_msg msg;
    ClickType click = CLICK_NONE;

    // 轮询鼠标消息（仅处理左键按下事件）
    while (mousemsg()) {
        msg = getmouse();
        if (msg.is_down() && msg.is_left()) {  // 左键按下时判断坐标
            // 开始按钮
            if (msg.x >= BTN_START_X && msg.x <= BTN_START_X + BTN_W &&
                msg.y >= BTN_START_Y && msg.y <= BTN_START_Y + BTN_H) {
                click = CLICK_START;
            }
            // 排行榜按钮
            else if (msg.x >= BTN_RANK_X && msg.x <= BTN_RANK_X + BTN_W &&
                     msg.y >= BTN_RANK_Y && msg.y <= BTN_RANK_Y + BTN_H) {
                click = CLICK_RANKING;
            }
            // 设置按钮
            else if (msg.x >= BTN_SET_X && msg.x <= BTN_SET_X + BTN_W &&
                     msg.y >= BTN_SET_Y && msg.y <= BTN_SET_Y + BTN_H) {
                click = CLICK_SETTING;
            }
            // 退出按钮
            else if (msg.x >= BTN_EXIT_X && msg.x <= BTN_EXIT_X + BTN_W &&
                     msg.y >= BTN_EXIT_Y && msg.y <= BTN_EXIT_Y + BTN_H) {
                click = CLICK_EXIT;
            }
        }
    }
    return click;
}
