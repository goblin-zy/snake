#ifndef INPUT_MODULE_H
#define INPUT_MODULE_H

// ���������ö�٣��׶�1�����˵���ť��
enum ClickType {
    CLICK_NONE,        // �޵��
    CLICK_START,       // ��ʼ��Ϸ
    CLICK_RANKING,     // ���а�
    CLICK_SETTING,     // ����
    CLICK_EXIT         // �˳�
};

// ��������������ص������
ClickType listenMouseClick();

#endif
