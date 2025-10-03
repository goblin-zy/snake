#include "allcpp.h"



//主菜单选择 
ClickType listenMouseClick_Mainmenu() {
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


// 首先需要在Input.h的ClickType枚举中添加难度选择相关的点击类型
// 建议在Input.h中补充：
// enum ClickType {
//     ...(原有类型)...
//     CLICK_EASY,       // 简单难度
//     CLICK_MEDIUM,     // 中等难度
//     CLICK_HARD,       // 困难难度
//     CLICK_BACK        // 返回主菜单
// };


// 难度选择界面的鼠标点击监听函数
ClickType listenMouseClick_difficulty(){
    mouse_msg msg;
    ClickType click = CLICK_NONE;  // 默认为无点击

    // 轮询鼠标消息（仅处理左键按下事件）
    while (mousemsg()) {
        msg = getmouse();
        if (msg.is_down() && msg.is_left()) {  // 检测左键按下动作
            // 1. 简单难度按钮检测
            if (msg.x >= BTN_DIFF_X && msg.x <= BTN_DIFF_X + BTN_DIFF_W &&
                msg.y >= BTN_EASY_Y && msg.y <= BTN_EASY_Y + BTN_DIFF_H) {
                click = CLICK_EASY;  // 返回简单难度点击类型
            }
            // 2. 中等难度按钮检测
            else if (msg.x >= BTN_DIFF_X && msg.x <= BTN_DIFF_X + BTN_DIFF_W &&
                     msg.y >= BTN_MEDIUM_Y && msg.y <= BTN_MEDIUM_Y + BTN_DIFF_H) {
                click = CLICK_MEDIUM;  // 返回中等难度点击类型
            }
            // 3. 困难难度按钮检测
            else if (msg.x >= BTN_DIFF_X && msg.x <= BTN_DIFF_X + BTN_DIFF_W &&
                     msg.y >= BTN_HARD_Y && msg.y <= BTN_HARD_Y + BTN_DIFF_H) {
                click = CLICK_DIFFICULT;  // 返回困难难度点击类型
            }
            // 4. 返回按钮检测
            else if (msg.x >= BTN_BACK_X && msg.x <= BTN_BACK_X + BTN_BACK_W &&
                     msg.y >= BTN_BACK_Y && msg.y <= BTN_BACK_Y + BTN_BACK_H) {
                click = CLICK_BACK;  // 返回主菜单点击类型
            }
        }
    }
    return click;
}

ClickType listenMouseClick_Run(){
    mouse_msg msg;
    ClickType click = CLICK_NONE;  // 默认为无点击

    // 轮询鼠标消息（仅处理左键按下事件）
    while (mousemsg()) {
        msg = getmouse();
        if (msg.is_down() && msg.is_left()) {  // 检测左键按下动作

            if (msg.x >= BTN_READY_START_X && msg.x <= BTN_READY_START_X+BTN_READY_START_W &&
                msg.y >= BTN_READY_START_Y && msg.y <= BTN_READY_START_Y + BTN_READY_START_H) {
                click = CLICK_RUN;
            }

        }
    }
    return click;
}
    
// 监听键盘输入，控制蛇的方向   直接改变了方向，所以返回值是void
void listenKeyPress() {
    key_msg key;
    // 检查是否有键盘消息
    if (kbhit()) {
        key = getkey();
        // 只处理按键按下事件
        if (key.msg == key_msg_down) {
            switch (key.key) {
                case VK_UP:    // 上方向键
                    changeDirection(0);
                    break;
                case VK_RIGHT:  // 右方向键
                    changeDirection(1);
                    break;
                case VK_DOWN:  // 下方向键
                    changeDirection(2);
                    break;
                case VK_LEFT:  // 左方向键
                    changeDirection(3);
                    break;
                case VK_ESCAPE: // ESC键暂停游戏
                    // 这里可以添加暂停逻辑
                    break;
            }
        }
    }
}
