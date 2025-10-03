#ifndef INPUT_MODULE_H
#define INPUT_MODULE_H

// 鼠标点击区域枚举（阶段1仅主菜单按钮）
enum ClickType {
    CLICK_NONE,        // 无点击
    CLICK_START,       // 开始游戏
    CLICK_RANKING,     // 排行榜
    CLICK_SETTING,     // 设置
    CLICK_EXIT,         // 退出
    
    CLICK_EASY ,     //难度设置相关
    CLICK_MEDIUM,
    CLICK_DIFFICULT,
    CLICK_BACK,

    CLICK_RUN
};

// 监听鼠标点击，返回点击类型
ClickType listenMouseClick_Mainmenu();
ClickType listenMouseClick_difficulty();
ClickType listenMouseClick_Run();
void listenKeyPress();
#endif
