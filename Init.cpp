#include <graphics.h>   // EGE核心头文件
#include <cstdio>       // 辅助输入输出
#include <ctime>        // 时间相关（状态管理用）
// 自定义模块头文件（按需添加）
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"

extern GameState g_currentState;

    PIMAGE img_start;
    PIMAGE img_rank;
    PIMAGE img_setting;
    PIMAGE img_exit;


void initWindow(int width, int height) {
    setinitmode(0);
    initgraph(width, height);
    setcaption("贪吃蛇 - 主菜单");
}

void loadResources() {
//默认设置，有关于图片之类。 

    img_start=newimage();
    img_rank=newimage();
    img_setting=newimage();
    img_exit=newimage();

    getimage(img_start,"btn_start.png");
    getimage(img_rank,"btn_rank.png");
    getimage(img_setting,"btn_setting.png");
    getimage(img_exit,"btn_exit.png");
    
}

void initCoreData() {
    g_currentState = STATE_MAIN_MENU;  // 初始化状态
}

void releaseResources() {
	delimage(img_start);
	delimage(img_rank);
	delimage(img_setting);
	delimage(img_exit);
	cleardevice(); 
    closegraph();
}
