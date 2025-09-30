
// 修改后的Paint.cpp（针对主菜单美观性优化）
#include <graphics.h>   // EGE图形库头文件
#include <cstdio>       // 标准输入输出
#include <ctime>        // 时间相关函数（状态刷新等）
// 自定义模块头文件（包含声明）
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"

#define BTN_START_X  338  // 原270 → 270×1.25=337.5≈338
#define BTN_START_Y  188  // 原150 → 150×1.25=187.5≈188
#define BTN_RANK_X   338  // 原270 → 338
#define BTN_RANK_Y   263  // 原210 → 210×1.25=262.5≈263
#define BTN_SET_X    338  // 原270 → 338
#define BTN_SET_Y    338  // 原270 → 270×1.25=337.5≈338
#define BTN_EXIT_X   338  // 原270 → 338
#define BTN_EXIT_Y   413  // 原330 → 330×1.25=412.5≈413
#define BTN_W        125  // 原100 → 100×1.25=125
#define BTN_H        50   // 原40 → 40×1.25=50

void drawMainMenu() {
// 1. 绘制背景（黑色填充整个窗口，适配800×600）
setfillcolor(BLACK);
bar(0, 0, 800, 600);  // 窗口宽高从640×480改为800×600

// 2. 绘制标题（居中优化，适配新窗口）
setcolor(WHITE);
setfont(45, 0, "宋体");  // 字体按比例放大（原36→45，1.25倍）
char title[] = "贪吃蛇游戏";
int titleWidth = textwidth(title);  // 动态获取文字宽度
int titleX = (800 - titleWidth) / 2;  // 基于新窗口宽度（800）计算居中坐标
outtextxy(titleX, 63, title);  // Y坐标按比例调整（原50→63，1.25倍）

    // 3. 绘制按钮（替换为图片）
    putimage(BTN_START_X, BTN_START_Y, img_start);
    putimage(BTN_RANK_X, BTN_RANK_Y,img_rank);
    putimage(BTN_SET_X, BTN_SET_Y,img_setting);
    putimage(BTN_EXIT_X, BTN_EXIT_Y, img_exit);




/*
    // 3. 绘制按钮（优化文字显示）
    setfillcolor(YELLOW);
    setcolor(DARKGRAY);  // 按钮边框用深灰色
    setfont(18, 0, "宋体");  // 按钮文字使用宋体

    // 开始按钮
    bar(BTN_START_X, BTN_START_Y, BTN_START_X+BTN_W, BTN_START_Y+BTN_H);
    char startText[] = "开始游戏";
    int startTextWidth = textwidth(startText);
    outtextxy(BTN_START_X + (BTN_W - startTextWidth)/2, BTN_START_Y + 10, startText);
    
    // 排行榜按钮
    bar(BTN_RANK_X, BTN_RANK_Y, BTN_RANK_X+BTN_W, BTN_RANK_Y+BTN_H);
    char rankText[] = "排行榜";
    int rankTextWidth = textwidth(rankText);
    outtextxy(BTN_RANK_X + (BTN_W - rankTextWidth)/2, BTN_RANK_Y + 10, rankText);
    
    // 设置按钮
    bar(BTN_SET_X, BTN_SET_Y, BTN_SET_X+BTN_W, BTN_SET_Y+BTN_H);
    char setText[] = "设置";
    int setTextWidth = textwidth(setText);
    outtextxy(BTN_SET_X + (BTN_W - setTextWidth)/2, BTN_SET_Y + 10, setText);
    
    // 退出按钮
    bar(BTN_EXIT_X, BTN_EXIT_Y, BTN_EXIT_X+BTN_W, BTN_EXIT_Y+BTN_H);
    char exitText[] = "退出";
    int exitTextWidth = textwidth(exitText);
    outtextxy(BTN_EXIT_X + (BTN_W - exitTextWidth)/2, BTN_EXIT_Y + 10, exitText);
    */
}
