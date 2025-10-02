#ifndef STATE_MODULE_H
#define STATE_MODULE_H

// ��Ϸ״̬ö�٣��׶�1�������˵����״̬��
enum GameState {
    STATE_MAIN_MENU,        // ���˵�����ʼ״̬��
    STATE_DIFFICULTY_SELECT,// �Ѷ�ѡ�񣨵������ʼ�����룩
    STATE_READY,
    STATE_RANKING,          // ���а񣨵�������а񡱽��룩
    STATE_SETTING,          // ���ã���������á����룩
    STATE_EXIT,         // �˳���������˳������룩
    

    STATE_RUNNING  //��ʼ���� 
};

// �л���Ϸ״̬��������Ŀ��״̬��
void switchState(GameState targetState);

#endif
