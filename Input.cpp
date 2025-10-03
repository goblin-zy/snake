#include "allcpp.h"



//���˵�ѡ�� 
ClickType listenMouseClick_Mainmenu() {
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


// ������Ҫ��Input.h��ClickTypeö��������Ѷ�ѡ����صĵ������
// ������Input.h�в��䣺
// enum ClickType {
//     ...(ԭ������)...
//     CLICK_EASY,       // ���Ѷ�
//     CLICK_MEDIUM,     // �е��Ѷ�
//     CLICK_HARD,       // �����Ѷ�
//     CLICK_BACK        // �������˵�
// };


// �Ѷ�ѡ�������������������
ClickType listenMouseClick_difficulty(){
    mouse_msg msg;
    ClickType click = CLICK_NONE;  // Ĭ��Ϊ�޵��

    // ��ѯ�����Ϣ����������������¼���
    while (mousemsg()) {
        msg = getmouse();
        if (msg.is_down() && msg.is_left()) {  // ���������¶���
            // 1. ���ѶȰ�ť���
            if (msg.x >= BTN_DIFF_X && msg.x <= BTN_DIFF_X + BTN_DIFF_W &&
                msg.y >= BTN_EASY_Y && msg.y <= BTN_EASY_Y + BTN_DIFF_H) {
                click = CLICK_EASY;  // ���ؼ��Ѷȵ������
            }
            // 2. �е��ѶȰ�ť���
            else if (msg.x >= BTN_DIFF_X && msg.x <= BTN_DIFF_X + BTN_DIFF_W &&
                     msg.y >= BTN_MEDIUM_Y && msg.y <= BTN_MEDIUM_Y + BTN_DIFF_H) {
                click = CLICK_MEDIUM;  // �����е��Ѷȵ������
            }
            // 3. �����ѶȰ�ť���
            else if (msg.x >= BTN_DIFF_X && msg.x <= BTN_DIFF_X + BTN_DIFF_W &&
                     msg.y >= BTN_HARD_Y && msg.y <= BTN_HARD_Y + BTN_DIFF_H) {
                click = CLICK_DIFFICULT;  // ���������Ѷȵ������
            }
            // 4. ���ذ�ť���
            else if (msg.x >= BTN_BACK_X && msg.x <= BTN_BACK_X + BTN_BACK_W &&
                     msg.y >= BTN_BACK_Y && msg.y <= BTN_BACK_Y + BTN_BACK_H) {
                click = CLICK_BACK;  // �������˵��������
            }
        }
    }
    return click;
}

ClickType listenMouseClick_Run(){
    mouse_msg msg;
    ClickType click = CLICK_NONE;  // Ĭ��Ϊ�޵��

    // ��ѯ�����Ϣ����������������¼���
    while (mousemsg()) {
        msg = getmouse();
        if (msg.is_down() && msg.is_left()) {  // ���������¶���

            if (msg.x >= BTN_READY_START_X && msg.x <= BTN_READY_START_X+BTN_READY_START_W &&
                msg.y >= BTN_READY_START_Y && msg.y <= BTN_READY_START_Y + BTN_READY_START_H) {
                click = CLICK_RUN;
            }

        }
    }
    return click;
}
    
// �����������룬�����ߵķ���   ֱ�Ӹı��˷������Է���ֵ��void
void listenKeyPress() {
    key_msg key;
    // ����Ƿ��м�����Ϣ
    if (kbhit()) {
        key = getkey();
        // ֻ�����������¼�
        if (key.msg == key_msg_down) {
            switch (key.key) {
                case VK_UP:    // �Ϸ����
                    changeDirection(0);
                    break;
                case VK_RIGHT:  // �ҷ����
                    changeDirection(1);
                    break;
                case VK_DOWN:  // �·����
                    changeDirection(2);
                    break;
                case VK_LEFT:  // �����
                    changeDirection(3);
                    break;
                case VK_ESCAPE: // ESC����ͣ��Ϸ
                    // ������������ͣ�߼�
                    break;
            }
        }
    }
}
