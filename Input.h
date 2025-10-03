#ifndef INPUT_MODULE_H
#define INPUT_MODULE_H

// ���������ö�٣��׶�1�����˵���ť��
enum ClickType {
    CLICK_NONE,        // �޵��
    CLICK_START,       // ��ʼ��Ϸ
    CLICK_RANKING,     // ���а�
    CLICK_SETTING,     // ����
    CLICK_EXIT,         // �˳�
    
    CLICK_EASY ,     //�Ѷ��������
    CLICK_MEDIUM,
    CLICK_DIFFICULT,
    CLICK_BACK,

    CLICK_RUN
};

// ��������������ص������
ClickType listenMouseClick_Mainmenu();
ClickType listenMouseClick_difficulty();
ClickType listenMouseClick_Run();
void listenKeyPress();
#endif
