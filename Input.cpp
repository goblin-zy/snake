#include <graphics.h>   // EGE����ͷ�ļ�
#include <cstdio>       // �����������
#include <ctime>        // ʱ����أ�״̬�����ã�
// �Զ���ģ��ͷ�ļ���������ӣ�
#include "Init.h"
#include "Input.h"
#include "Paint.h"
#include "statechange.h"


// ���˵���ť���꣨����drawMainMenu()�еĻ���λ����ȫһ�£�
#define BTN_START_X  338  // ԭ270 �� 270��1.25=337.5��338
#define BTN_START_Y  188  // ԭ150 �� 150��1.25=187.5��188
#define BTN_RANK_X   338  // ԭ270 �� 338
#define BTN_RANK_Y   263  // ԭ210 �� 210��1.25=262.5��263
#define BTN_SET_X    338  // ԭ270 �� 338
#define BTN_SET_Y    338  // ԭ270 �� 270��1.25=337.5��338
#define BTN_EXIT_X   338  // ԭ270 �� 338
#define BTN_EXIT_Y   413  // ԭ330 �� 330��1.25=412.5��413
#define BTN_W        100  
#define BTN_H        40   // ��ť�ߴ磺100��40

ClickType listenMouseClick() {
    mouse_msg msg;
    ClickType click = CLICK_NONE;

    // ��ѯ�����Ϣ����������������¼���
    while (mousemsg()) {
        msg = getmouse();
        if (msg.is_down() && msg.is_left()) {  // �������ʱ�ж�����
            // ��ʼ��ť
            if (msg.x >= BTN_START_X && msg.x <= BTN_START_X + BTN_W &&
                msg.y >= BTN_START_Y && msg.y <= BTN_START_Y + BTN_H) {
                click = CLICK_START;
            }
            // ���а�ť
            else if (msg.x >= BTN_RANK_X && msg.x <= BTN_RANK_X + BTN_W &&
                     msg.y >= BTN_RANK_Y && msg.y <= BTN_RANK_Y + BTN_H) {
                click = CLICK_RANKING;
            }
            // ���ð�ť
            else if (msg.x >= BTN_SET_X && msg.x <= BTN_SET_X + BTN_W &&
                     msg.y >= BTN_SET_Y && msg.y <= BTN_SET_Y + BTN_H) {
                click = CLICK_SETTING;
            }
            // �˳���ť
            else if (msg.x >= BTN_EXIT_X && msg.x <= BTN_EXIT_X + BTN_W &&
                     msg.y >= BTN_EXIT_Y && msg.y <= BTN_EXIT_Y + BTN_H) {
                click = CLICK_EXIT;
            }
        }
    }
    return click;
}
