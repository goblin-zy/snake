#ifndef STATE_MODULE_H
#define STATE_MODULE_H

// ��Ϸ״̬ö�٣��׶�1�������˵����״̬��
enum GameState {
    STATE_MAIN_MENU,        // ���˵�����ʼ״̬��
    STATE_READY,
    STATE_RANKING,          // ���а񣨵�������а񡱽��룩
    STATE_SETTING,          // ���ã���������á����룩
    STATE_EXIT,         // �˳���������˳������룩

    STATE_RUNNING, //��ʼ���� 

    STATE_PAUSED,       // ��ͣ״̬
    STATE_GAME_OVER,   // ��Ϸ����״̬
};

// �л���Ϸ״̬��������Ŀ��״̬��
void switchState(GameState targetState);

#endif
